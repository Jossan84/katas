//TestSearchInsertionPosition.cpp
//18/10/2022

/*
35. Search Insertion Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int numsSize =nums.size();
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target)
            return i;
        if(nums[i] > target)    
            return i;
          
    }
    return numsSize;
};

int main() {
    
	/*Test for searchInsert function */
	//Test 1
	vector<int> nums = {1,3,5,6};
	int target = 5;
	if(2 == searchInsert(nums, target)){
		cout << "Test 1: Pass" << endl;
	}
	else{
		cout << "Test 1: Fail" << endl;
	}	


	//Test 2
	target = 2;
	if(1 == searchInsert(nums, target)){
		cout << "Test 2: Pass" << endl;
	}
	else{
		cout << "Test 2: Fail" << endl;
	}	

	//Test 3
	target = 7;
	if(4 == searchInsert(nums, target)){
		cout << "Test 3: Pass" << endl;
	}
	else{
		cout << "Test 3: Fail" << endl;
	}	
	
	
	return 0;
}