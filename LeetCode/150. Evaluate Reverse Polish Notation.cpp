// DATE: 30-JAN-2024
// Question URL: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

// Question: 150. Evaluate Reverse Polish Notation
// Description: You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

//              Evaluate the expression. Return an integer that represents the value of the expression.

//              Note that:

//              The valid operators are '+', '-', '*', and '/'.
//              Each operand may be an integer or another expression.
//              The division between two integers always truncates toward zero.
//              There will not be any division by zero.
//              The input represents a valid arithmetic expression in a reverse polish notation.
//              The answer and all the intermediate calculations can be represented in a 32-bit integer.

// Approach: 1. Use stack to store numbers then pop top two numbers when encountered an operator. Perform operationa and store result into stack.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i][tokens[i].length()-1] - '0' >= 0 && tokens[i][tokens[i].length()-1] - '0' <= 9){
                s.push(stoi(tokens[i]));
            }
            else{
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();

                if(tokens[i] == "+") s.push(a + b);
                else if(tokens[i] == "-") s.push(a - b);
                else if(tokens[i] == "*") s.push(a * b);
                else s.push(a / b);
            }

        }
        
        return s.top();
    }
};