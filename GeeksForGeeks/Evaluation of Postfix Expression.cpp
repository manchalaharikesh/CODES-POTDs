// DATE: 28-FEB-2025
// Question URL: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
// Question: Evaluation of Postfix Expression
// Description: You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

//              Key Details:

//              The valid operators are '+', '-', '*', and '/'.
//              Each operand is guaranteed to be a valid integer or another expression.
//              The division operation between two integers always rounds the result towards zero, discarding any fractional part.
//              No division by zero will occur in the input.
//              The input is a valid arithmetic expression in Reverse Polish Notation.
//              The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
// Approach: 1. While iterating the postfix expression from left to right, push the numbers into stack (handle multiple digits and -ve numbers as in code)
//              Now if we get any operator we need to perform it on the last two numbers we found and if we found x, y, operator then we apply it x (operator) y right!!
//              So, the first top element in stack is y and second top element in stack is x, and also store the result into stack again
//              Continue the same until arr is completed, Now you have  to be left with only one element in stack which needs to be returned.

class Solution {
    public:
      int evaluate(vector<string>& arr) {
          stack<int> st;
          int a, b;
          bool neg = false;
          
          for(int i = 0; i < arr.size(); i++){
              if(arr[i]=="+") {
                   a = st.top(); st.pop();
                   b = st.top(); st.pop();
                   st.push(a+b);
              }
              else if(arr[i]=="-"){ a = st.top(); st.pop();
                   b = st.top(); st.pop();
                   st.push(b-a);}
              else if(arr[i] == "*"){ a = st.top(); st.pop();
                   b = st.top(); st.pop();
                   st.push(a*b);}
              else if(arr[i]=="/"){ a = st.top(); st.pop();
                   b = st.top(); st.pop();
                   st.push(b/a);}
              else{
                  string s = arr[i];
                  a = 0;
                  neg = false;
                  for(int j = 0; j < s.length(); j++){
                      if(s[j] == '-'){ neg = true;
                          continue;
                      }
                      a = a*10 + s[j] - '0';
                  }
                  st.push(neg ? -a : a);
              }
          }
          
          return st.top();
      }
  };