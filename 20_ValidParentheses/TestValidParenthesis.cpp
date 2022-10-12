//TestValidParenthesis.cpp
//11/10/2022

/*
20. Valid Parenthesis
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string s) {
    string stack = "";
    for(char word : s){
        if(stack.empty())
            stack.push_back(word);
        else if((stack.back() == '(' && word == ')') || (stack.back() == '{' && word == '}') ||(stack.back() == '[' && word == ']'))
            stack.pop_back();
        else
           stack.push_back(word);
    }
    if(stack.empty())
        return 1;
    return 0;
}

int main() {
    
	/*Test for isValid function */
	//Test 1
	string str1 = "()";
	if(isValid(str1) == 1){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	//Test 2
	string str2 = "()[]{}";
	if(isValid(str2) == 1){
		cout << "Test 2: Pass" << endl;
	}else{
		cout << "Test 2: Fail" << endl;
	}

	//Test 3
	string str3 = "(]";
	if(isValid(str3) == 0){
		cout << "Test 2: Pass" << endl;
	}else{
		cout << "Test 2: Fail" << endl;
	}
	
	return 0;
}