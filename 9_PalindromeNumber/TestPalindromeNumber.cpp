//TestPalindromeNumber.cpp
//8/10/2022

/*
9. Palindrome Number
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is a palindrome while 123 is not.
 
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include <iostream>
#include <algorithm>

using namespace std;


bool isPalindrome(int x) {
        string str = to_string(x);
        string strReverse = str;
        reverse(strReverse.begin(), strReverse.end());
            
        if(str == strReverse){
            return 1;
        }else{
            return 0;
        }            
};


int main() {
    
	/*Test for isPalindrome function */
	//Test 1
	if(true == isPalindrome(121)){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	//Test 2
	if(false == isPalindrome(-121)){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	//Test 3
	if(false == isPalindrome(10)){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	return 0;
}