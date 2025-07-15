#ifndef PARSER_HPP
#define PARSER_HPP
#include "lexer.hpp"
#include "token.hpp"
#include <memory>
#include<stdexcept>
#include <string>
using namespace std;

struct ASTNode{
    string value;
    shared_ptr<ASTNode> left;
    shared_ptr<ASTNode> right;
    ASTNode(string value, shared_ptr<ASTNode> left, shared_ptr<ASTNode> right)
    : value(value), left(left), right(right) {}

};

class Parser {
    public:
        explicit Parser(Lexer& lexer);
        shared_ptr<ASTNode> parse();
    private:
        Lexer& lexer;
        Token currentToken;

        void eat(TokenType type);
        shared_ptr<ASTNode> factor(); //handle numbers & Parentheses()
        shared_ptr<ASTNode> term(); // handle * & /
        shared_ptr<ASTNode> expr(); // handle + & -
};

inline Parser::Parser(Lexer& lexer): lexer(lexer), currentToken(lexer.next_token()){}

inline void Parser::eat(TokenType type){
    if(currentToken.type == type) 
        currentToken = lexer.next_token();
    else
        throw runtime_error("Unnexpected token"+currentToken.value);
}

inline shared_ptr<ASTNode> Parser::factor(){
    if (currentToken.type == TokenType::LEFT_PAREN) {
        eat(TokenType::LEFT_PAREN);
        auto node = expr();
        eat(TokenType::RIGHT_PAREN);
        return node;
    }

    else if (currentToken.type == TokenType::NUMBER){
        string value = currentToken.value;
        eat(TokenType::NUMBER);
        return make_shared<ASTNode>(value,nullptr,nullptr); 
    }
    else {
        string op= currentToken.value;
        if (currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus) {
            eat(currentToken.type);
            auto node = factor();
            auto zero = make_shared<ASTNode>("0", nullptr, nullptr);
            return make_shared<ASTNode>(op, zero, node); // Unary operator
        }
    }
    
    throw runtime_error("Unexpected token"+currentToken.value);
}

inline shared_ptr<ASTNode> Parser::term(){
    auto node=factor();
    while(currentToken.type == TokenType::Multiply || currentToken.type == TokenType::Divide){
        string op = currentToken.value;
        eat(currentToken.type);
        auto right = factor();
        node = make_shared<ASTNode>(ASTNode{op,node,right});
    }
    return node;
}

inline shared_ptr<ASTNode> Parser::expr(){
    auto node = term();
    while(currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus){
        string op = currentToken.value;
        eat(currentToken.type);
        auto right = term();
        node = make_shared<ASTNode>(ASTNode{op,node,right});
    }
    return node;
}

inline shared_ptr<ASTNode> Parser::parse(){
    return expr();
}
#endif