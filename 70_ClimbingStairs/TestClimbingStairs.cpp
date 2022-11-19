//TestClimbingStairs.cpp
//19/11/2022

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include <iostream>

using namespace std;

int climbStairs(int n) {
	
	// Fibonacci
    int f0 = 0;
    int f1 = 1;
    int next;
    for(int i = 0; i < n; i++){
        next = f0 + f1;
        f0 = f1;
        f1 = next;
    } 
    return next;
};

int main() {
    
	/*Test for climbStairs function */
	//Test 1
	if(1 == climbStairs(1)){
		cout << "Test 1: Pass" << endl;
	}
	else{
		cout << "Test 1: Fail" << endl;
	}	

	//Test 2
	if(2 == climbStairs(2)){
		cout << "Test 2: Pass" << endl;
	}
	else{
		cout << "Test 2: Fail" << endl;
	}	

	//Test 3
	if(1836311903 == climbStairs(45)){
		cout << "Test 3: Pass" << endl;
	}
	else{
		cout << "Test 3: Fail" << endl;
	}	

	return 0;
}