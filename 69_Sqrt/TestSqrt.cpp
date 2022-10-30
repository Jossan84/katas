//TestSqrt.cpp
//30/10/2022

/*
69. Square root
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 
2 is returned.
*/

#include <iostream>

using namespace std;

int mySqrt(int x) {
        
    if (x < 2) return x;
        
    int end = x / 2;
        
    int start = 1;
        
    while (start <= end) {
        unsigned long long mid = (start + end) / 2;
        if (mid*mid > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return end;
};

int main() {
    
	/*Test for Sqrt function */
	//Test 1
	if(2 == mySqrt(4)){
		cout << "Test 1: Pass" << endl;
	}
	else{
		cout << "Test 1: Fail" << endl;
	}	

	//Test 2
	if(2 == mySqrt(8)){
		cout << "Test 2: Pass" << endl;
	}
	else{
		cout << "Test 2: Fail" << endl;
	}	

	//Test 3
	cout << mySqrt(2147395600) << endl;
	if(46340 == mySqrt(2147395600)){
		cout << "Test 3: Pass" << endl;
	}
	else{
		cout << "Test 3: Fail" << endl;
	}	

	return 0;
}