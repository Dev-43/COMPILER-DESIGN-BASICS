#ifndef TOKEN_HPP
#define TOKEN_HPP
 #include <string>

 enum TokenType {
    NUMBER,
    Plus,
    Minus,
    Multiply,
    Divide,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    End
 };

 struct Token {
    TokenType type;
    std::string value;
 };

 #endif