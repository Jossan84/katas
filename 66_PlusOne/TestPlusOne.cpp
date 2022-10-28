//TestPlusOne.cpp
//27/10/2022

/*
66. Plus one
You are given a large integer represented as an integer array digits, where each digits[i] is the ith
digit of the integer. The digits are ordered from most significant to least significant in left-to-right order.
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int num = 0;
	int carring = 1;
	vector<int> result;
	
	for(int i = digits.size() - 1; i >= 0 ; i--){
		
		num += (carring + digits.at(i));
		
		if (num > 9){
			carring = 1;
			result.push_back(0);
		}
		else{
			carring = 0;
			result.push_back(num);
		} 
		num = 0;
	}
	
	if(carring == 1)
		result.push_back(1);
	
	reverse(result.begin(), result.end());
	return result;
};

int main() {
    
	/*Test for plusOne function */
	//Test 1
	vector<int> digits1 = {1, 2, 3};
	vector<int> solution1 = {1,2,4};
	if(solution1 == plusOne(digits1)){
		cout << "Test 1: Pass" << endl;
	}
	else{
		cout << "Test 1: Fail" << endl;
	}	


	//Test 2
	vector<int> digits2 = {4, 3, 2, 1};
	vector<int> solution2 = {4, 3, 2, 2};
	if(solution2 == plusOne(digits2)){
		cout << "Test 2: Pass" << endl;
	}
	else{
		cout << "Test 2: Fail" << endl;
	}	

	//Test 3
	vector<int> digits3 = {9};
	vector<int> solution3 = {1, 0};
	if(solution3 == plusOne(digits3)){
		cout << "Test 3: Pass" << endl;
	}
	else{
		cout << "Test 3: Fail" << endl;
	}

	//Test 4
	vector<int> digits4 = {9,8,7,6,5,4,3,2,1,0};
	vector<int> solution4 = {9,8,7,6,5,4,3,2,1,1};
	if(solution4 == plusOne(digits4)){
		cout << "Test 4: Pass" << endl;
	}
	else{
		cout << "Test 4: Fail" << endl;
	}

	//Test 5
	vector<int> digits5 = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
	vector<int> solution5 = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,7};
	if(solution5 == plusOne(digits5)){
		cout << "Test 5: Pass" << endl;
	}
	else{
		cout << "Test 5: Fail" << endl;
	}

	return 0;
}