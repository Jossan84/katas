//TestTwoSum.cpp
//27/09/2022

/*
1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> indexs;
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < nums.size(); j++){
                if(j != i)
                    if((nums[i] + nums[j]) == target){
                        indexs.push_back(i); 
                        indexs.push_back(j);
                        return indexs;
                    }        
            }
        return indexs;
};


int main() {
    
	/*Test for twoSum function */
	//Test 1
	vector<int> nums1{2,7,11,15};
	int target1 = 9;
	vector<int> sol1{0, 1};
	vector<int> result1;
	result1 =  twoSum(nums1, target1);
	if(result1 == sol1){
		cout << "Test 1: Pass" << endl;
	}else{
		cout << "Test 1: Fail" << endl;
	}
	
	//Test 2
	vector<int> nums2{3,2,4};
	int target2 = 6;
	vector<int> sol2{1, 2};
	vector<int> result2;
	result2 =  twoSum(nums2, target2);
	if(result2 == sol2){
		cout << "Test 2: Pass" << endl;
	}else{
		cout << "Test 2: Fail" << endl;
	}
	
	//Test 3
	vector<int> nums3{3,3};
	int target3 = 6;
	vector<int> sol3{0, 1};
	vector<int> result3;
	result3 =  twoSum(nums3, target3);
	if(result3 == sol3){
		cout << "Test 3: Pass" << endl;
	}else{
		cout << "Test 3: Fail" << endl;
	}
	
	return 0;
}