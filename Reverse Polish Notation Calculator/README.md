# Reverse Polish Notation Calculator

This project is a fully functional version of a Reverse Polish Notation (RPN) Calculator, created using native C++ programming in the command line. Similar to the original programming of the RPN Calculator, this project uses a stack to input and output the equation variables through the calculator. The RPN Calculator has proven to be useful throughout the years since the equation formatting does not use parenthesis. For example, the infix expression (3 × 4) + (5 × 6) becomes 3 4 × 5 6 × + in reverse Polish notation.

## Motivation

The motivation behind this project was to implement a calculator that uses postfix notation for arithmetic operations, demonstrating the use of stack data structure and native C++ code.

## Screenshots

<img src="https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/cf8534a2-7a57-4473-b021-a4fcf04ac8e6" width="200" />
<img src="https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/2d73c47c-2e06-4b85-ab9c-8689cc072784" width="200" />

## Features

This project is a skeleton of a Reverse Polish Notation Calculator, including all of the original features. This means the code is highly manageable and can easily have a more robust Graphical User Interface added on. For more information on the specifics of the origin and usage of the Reverse Polish Notation Calculator, please visit [Wolfram Math-World - Reverse Polish Notation]([https://code.visualstudio.com/docs/cpp/config-mingw](https://mathworld.wolfram.com/ReversePolishNotation.html)) 

## Installation

### Windows:

Follow this tutorial to setup a C++ environment: [Visual Studio Code - C++ and Mingw-w64](https://code.visualstudio.com/docs/cpp/config-mingw)  
Then continue with the following Linux code.

### Ubuntu and Linux

```
g++ -Wall *.cpp -o rpnCalculator
./rpnCalculator
```
## Tests

An example equation looks like this: `123.45 67.4 + 18.34 *`
