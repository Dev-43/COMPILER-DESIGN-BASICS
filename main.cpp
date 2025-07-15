#include "lexer.hpp"
#include "parser.hpp"
#include "eval.hpp"
#include <conio.h>
#include <iostream>

int main() {
    string input;
    cout<<"Press ESC to exit\n";
     while(true){
        cout << "Enter arithmetic expression: ";
        if(_getch()==27) { // Escape key to exit
            cout << "Exiting..." << endl;
            break;
        }
        getline(cin, input);

        if(_getch()==27) { // Escape key to exit
            cout << "Exiting..." << endl;
            break;
        }
        try {
            Lexer lexer(input);
            Parser parser(lexer);
            auto ast = parser.parse();
            cout<<"Evaluating\n";
            int result = Evaluator::evaluate(ast);
            cout << "Result: " << result << endl;
        } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        }
        }

    return 0;
}
