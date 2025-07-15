#ifndef EVAL_hpp
#define EVAL_hpp
#include "parser.hpp"
#include <memory>
#include <string>
using namespace std;

class Evaluator{
    public:
    static int evaluate(const shared_ptr<ASTNode>& node);
};

inline int Evaluator::evaluate(const shared_ptr<ASTNode>& node) {
    if (!node->left && !node->right) {
    if (isdigit(node->value[0]) || (node->value[0] == '-' && node->value.size() > 1))
        return stoi(node->value); // valid number
    throw runtime_error("Invalid leaf node: " + node->value);
}

    
    int left = evaluate(node->left);
    int right = evaluate(node->right);
    string op = node->value;
    if (node->value == "+") return left + right;
    if (node->value == "-") return left - right;
    if (node->value == "*") return left * right;
    if (node->value == "/") {
        if (right == 0) throw runtime_error("Division by zero");
        return left / right;
    }
    if (node->value.empty()){
        throw runtime_error("Empty Value");
    }
    throw runtime_error("Unknown operator: " + op);
}
#endif