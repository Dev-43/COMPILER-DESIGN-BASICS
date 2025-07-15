#ifndef LEXER_HPP
#define LEXER_HPP
 #include "token.hpp"
 #include <cctype>
 #include <stdexcept>
 using namespace std;


 class Lexer {
    public:
        explicit Lexer(const string &input);
        Token next_token();

    private:
        string input;
        size_t pos = 0;
        char current_char;

        void advance();
        Token number();
        void skip_whitespace();
 };

inline Lexer::Lexer(const string &input) : input(input), current_char(input[pos]) {}

inline void Lexer::advance() {
    pos++;
    current_char=(pos <input.size()) ? input[pos] : '\0';
}

inline void Lexer::skip_whitespace() {
    while(isspace(current_char) && current_char!='\0') {
        advance();
    }
}

inline Token Lexer::number() {
    string result;
    while(isdigit(current_char)  && current_char!='\0') {
        result+=current_char;
        advance();
    }
    return Token{TokenType::NUMBER, result};

}

inline Token Lexer::next_token() {
    while(current_char!='\0') {
        if(isspace(current_char)) {
            skip_whitespace();
            continue;
        }
        else if (isdigit(current_char)) {
            return number();
        }
        switch(current_char) {
            case '+':
                advance();
                return Token{TokenType::Plus, "+"};
            case '-':
                advance();
                return Token{TokenType::Minus, "-"};
            case '*':
                advance();
                return Token{TokenType::Multiply, "*"};
            case '/':
                advance();
                return Token{TokenType::Divide, "/"};
            case '(':
                advance();
                return Token{TokenType::LEFT_PAREN, "("};
            case ')':
                advance();
                return Token{TokenType::RIGHT_PAREN, ")"};
            case '{':
                advance();
                return Token{TokenType::LEFT_BRACE, "{"};
            case '}':
                advance();
                return Token{TokenType::RIGHT_BRACE, "}"};
            default:
                throw runtime_error("Invalid Character: " + string(1, current_char));
        }
    }
    return Token{TokenType::End, ""};
}
#endif