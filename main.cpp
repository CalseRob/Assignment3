#include <iostream>
#include <stack>
#include <string>
#include "MyQueue.cpp"

 //Function to check if the given expression has balanced parenthesis
  bool isBalanced(const std::string& expr){
    std::stack<char>s;
    for(char c : expr){
      //If the character is an opening parenthesis, push it onto the stack
      if(c == '(' || c == '[' || c == '{'){
        s.push(c);
      }
      
      //If the character is a closing parenthesis and the stack is empty, the parenthesis are not balanced
      else if(c == ')' || c == ']' || c == '}'){
        if(s.empty()){
          return false;
        }
      }
      //If the top of the stack matches the corresponding opening, pop it off the stack 
      char top = s.top();
      if(( c == ')' && top == '(' ) || (c == ']' && top == '[') || (c == '}' && top == '{')){
        s.pop();
      }
        
      else{
      //If the top of the stack doesnt match, the parenthese are not balanced
        return false;
        
     }

    if(s.empty()){
      return false;
    }

    }
  }
    
  //Function to get the precedence of an operator
  int precedence(char op){
    switch (op){
      case '+':
      case '-':
        return 1;
      case '*':
      case '/':
      case '%':
        return 2;
      default: 
        return 0;
    }
  }

   //Function to convert infix expression to postfix expression
  std::string infixToPostfix(const std::string& expr){
  std::string postfix;
  std::stack<char> s;

    for (char c : expr){
    //If the character is an opernd, add it to the postfix expression
      if(std::isalnum(c)){
        postfix += c;
      }

      else if (c == '('){
        //If the character is an opening paranthesis, push it onto the stack
        s.push(c);
      }
      else if (c == '['){
        s.push(c);
      }

      else if (c == '{'){
        s.push(c);
      }
    }

    return postfix;
    
  }
    
int main(){
  MyQueue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  std::cout << "Front element: " << q.peek() << std::endl;
  std::cout << "Queue size: " << q.size() << std::endl;

  q.dequeue();
  std::cout << "Front element: " << q.peek() << std::endl;
  std::cout << "Queue size: " << q.size() << std::endl;

  std::string expr;
  std::cout << "Enter an infix expression";
  std::cin >> expr;

    //If the expression is not balanced, print an error message
  if(!isBalanced(expr)){
    std::cout << "The expression is not balanced and is therefore invalid" << std::endl;
  }

  else{
    //If the expression is balanced, convert it to postfix
    std::string postfix = infixToPostfix(expr);
    std::cout << "Postfix expression: " << postfix << std::endl;
  }

};

 
