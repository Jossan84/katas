//TestLengthOfLastWord.cpp
//18/10/2022

/*
58. LengthOfLastWord
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int count = 0;
	bool flag = 0;
	
	if(s.length() == 1 && s[0] != ' ')
        return 1;
	
	for(int i = s.length()-1; i >= 0; i--){
		
		if(s[i] != ' ' && flag == 0)
			flag = 1;	
		
		if(s[i] == ' ' && flag == 1){
			flag = 0;
			return count;
		}
		
		if(flag == 1)
			count++;

		if(i == 0)
			return count;
	}
};

int main() {
    
	/*Test for lengthOfLastWord function */
	//Test 1
	string str1 = "Hello World";
	if(5 == lengthOfLastWord(str1)){
		cout << "Test 1: Pass" << endl;
	}
	else{
		cout << "Test 1: Fail" << endl;
	}	


	//Test 2
	string str2 = "   fly me   to   the moon  ";
	int num = lengthOfLastWord(str2);
	if(4 == num){
		cout << "Test 2: Pass" << endl;
	}
	else{
		cout << "Test 2: Fail" << endl;
	}	

	//Test 3
	string str3 = "luffy is still joyboy";
	if(6 == lengthOfLastWord(str3)){
		cout << "Test 3: Pass" << endl;
	}
	else{
		cout << "Test 3: Fail" << endl;
	}

	//Test 4
	string str4 = "a";
	if(1 == lengthOfLastWord(str4)){
		cout << "Test 4: Pass" << endl;
	}
	else{
		cout << "Test 4: Fail" << endl;
	}	

	//Test 5
	string str5 = "a ";
	if(1 == lengthOfLastWord(str5)){
		cout << "Test 5: Pass" << endl;
	}
	else{
		cout << "Test 5: Fail" << endl;
	}	

	return 0;
}