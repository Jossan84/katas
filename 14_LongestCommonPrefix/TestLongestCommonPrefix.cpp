//TestLongestCommonPrefix.cpp
//11/10/2022

/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
        return "";
        
    string prefix = strs[0];
    for(int i = 0; i < strs.size(); i++){
        while(strs[i].find(prefix, 0) != 0){
        // while(strs[i].indexOf(prefix) != 0){
            prefix = prefix.substr(0, prefix.length() - 1);
            if(prefix.empty())
                return "";
        }
    }
    return prefix;
}

int main() {
    
	/*Test for longestCommonPrefix function */
	//Test 1
	vector<string> str1 = {"flower","flow","flight"};
	string sol1 = "fl";
	string result1 = longestCommonPrefix(str1);
	if(sol1.compare(result1) == 0){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	//Test 2
	vector<string> str2 = {"dog","racecar","car"};
	string sol2 = "";
	string result2 = longestCommonPrefix(str2);
	if(result2.empty()){
		cout << "Test 2: Pass" << endl;
	}else{
		cout << "Test 2: Fail" << endl;
	}
	
	return 0;
}