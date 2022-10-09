//TestRomanToInteger.cpp
//9/10/2022

/*
13. Roman to integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII,
which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, 
the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is
before the five we subtract it making four. The same principle applies to the number nine, which is 
written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <iostream>

using namespace std;

int getValueOfRomanNumber(char romanNumber){
    int value = 0;
    switch(romanNumber) {
        case 'I':
            value = 1;
            break;
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;                    
        default:
            return 0;
    }
	return value;
};

int romanToInt(string s) {
    int num = 0;
    for(char& word : s){
        int currentNum = getValueOfRomanNumber(word);
        int nextNum = getValueOfRomanNumber(*(&word + 1));
        if(currentNum >= nextNum){
            num += currentNum;
        }else{
            num -= currentNum;
        }
    }
    return num;
};

int main() {
    
	/*Test for romanToInt function */
	//Test 1
	if(3 == romanToInt("III")){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	//Test 2
	if(58 == romanToInt("LVIII")){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	//Test 3
	if(1994 == romanToInt("MCMXCIV")){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	return 0;
}