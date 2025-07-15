# 🧮 Simple Arithmetic Expression Compiler

**Internship Project – CODTECH IT SOLUTIONS**  
**Name:** Devesh Laxman Dolas  
**Intern ID:** CT04DG2484  
**Domain:** C++ Programming  
**Duration:** 4 Weeks  
**Mentor:** Neela Santosh  

---

## 🚀 Project Overview

This is a modular C++ compiler that parses and evaluates basic arithmetic expressions. It demonstrates the key phases of compilation:

- ✅ Lexical analysis  
- ✅ Recursive descent parsing  
- ✅ Abstract Syntax Tree (AST) construction  
- ✅ Evaluation of expressions  

This compiler was built for the **Compiler Design Basics** internship track and runs fully via CLI. It is lightweight, beginner-friendly, and can be executed independently on any Windows system without needing a C++ compiler.

---

## 🎯 Key Features

- Supports arithmetic operators: `+`, `-`, `*`, `/`
- Handles parentheses and operator precedence
- Accepts unary expressions like `-5`, `+(3)`
- Detects invalid syntax and unsupported characters
- Evaluates expressions using AST traversal
- ESC key support to exit instantly
- Modular file structure: `lexer`, `parser`, `eval`

---

## 📂 File Structure

  ArithmeticCompiler/
├── main.cpp         // User interaction and loop control
├── token.hpp        // Token definitions
├── lexer.hpp        // Lexical tokenizer
├── parser.hpp       // Recursive descent parser → AST
├── eval.hpp         // AST-based evaluator
├── README.md        // Documentation

---

## 🖥️ How to Run (Executable)

No compiler? No problem.

Just double-click the provided `ExpressionCompiler.exe` and start typing expressions.

### ✔️ Compatible with:
- **All modern Windows devices**
- **No need to install C++**
- **No source files required**

### 💡 Tip:
Press `ESC` at any time to quit instantly.

---

## 📊 Example Inputs

| Expression                            | Output        |
|---------------------------------------|---------------|
| `(2 + 3) * 4`                         | `Result: 20`  |
| `-5 + (+2)`                           | `Result: -3`  |
| `-(-2 + 1) + 4`                       | `Result: 5`   |
| `-(3 + 5) * (2 - (-1))`               | `Result: -24` |
| `5 / 0`                               | `Error: Division by zero`  
| `2 $ 3`                               | `Error: Wrong expression`

---
## Ouputs

## 📚 Learning Outcomes

This project is ideal for understanding:
- Compiler architecture and control flow
- Tokenization and lexical analysis
- Recursive descent parsing methodology
- AST construction and traversal
- Real-time error handling and edge cases

---

## 🔮 Future Enhancements

- Floating-point number support  
- Variable assignment (`a = 5`)  
- Built-in math functions (`sqrt(9)`)  
- AST visualization in CLI or GUI  
- Removal of `_getch()` for cross-platform use  

---

## 📬 Contact & Credits

Built by **Devesh Laxman Dolas**  
📧 Email: `deveshdolas9@gmail.com`  

---


