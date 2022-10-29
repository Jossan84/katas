//TestAddBinary.cpp
//29/10/2022

/*
67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

string addBinary(string a, string b) {
	
	if(a == "0" && b == "0")
        return "0";
	
	if(a.length() > b.length())
		return addBinary(b, a);
	
	int diff = b.length() - a.length();
	
	string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');
    a = padding + a;
    
	char carry = '0';
	string result;
	
	for (int i = a.length() - 1; i >= 0; i--) {
        // This if condition solves 110 111 possible cases
        if (a[i] == '1' && b[i] == '1') {
            if (carry == '1'){
                result.push_back('1');
  			    carry = '1';
			}else{
			result.push_back('0');
			carry = '1';
			}
        }
        // This if condition solves 000 001 possible cases
        else if (a[i] == '0' && b[i] == '0') {
            if (carry == '1'){
                result.push_back('1');
				carry = '0';
            }else{
                result.push_back('0');
				carry = '0';
			}
		}
        // This if condition solves 100 101 010 011 possible cases
        else if (a[i] != b[i]) {
            if (carry == '1'){
                result.push_back('0');
				carry = '1';
            }else{
                result.push_back('1');
				carry = '0';
			}
        }
    }
  
    // If at the end there is carry then just add it to the result
    if (carry == '1')
        result.push_back(carry);
    
    reverse(result.begin(), result.end());
  
    // To remove leading zeroes
    int i = 0;
	while(result.at(i) != '1'){
		result.erase(result.begin() + i,
                     result.begin() + i + 1);
	}
	return result;
	
};

int main() {
    
	/*Test for addBinary function */
	//Test 1
	string a1 = "11";
	string b1 = "1";
	string solution1 = "100";
	if(solution1 == addBinary(a1, b1)){
		cout << "Test 1: Pass" << endl;
	}
	else{
		cout << "Test 1: Fail" << endl;
	}	


	//Test 2
    string a2 = "1010";
	string b2 = "1011";
	string solution2 = "10101";
	if(solution2 == addBinary(a2, b2)){
		cout << "Test 2: Pass" << endl;
	}
	else{
		cout << "Test 2: Fail" << endl;
	}	

	//Test 3
    string a3 = "0";
	string b3 = "0";
	string solution3 = "0";
	if(solution3 == addBinary(a3, b3)){
		cout << "Test 3: Pass" << endl;
	}
	else{
		cout << "Test 3: Fail" << endl;
	}	

	//Test 4
    string a4 = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
	string b4 = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
	string solution4 = "110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000";
	if(solution4 == addBinary(a4, b4)){
		cout << "Test 4: Pass" << endl;
	}
	else{
		cout << "Test 4: Fail" << endl;
	}	

	return 0;
}