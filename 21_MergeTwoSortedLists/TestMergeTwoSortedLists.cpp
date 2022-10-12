//TestMergeTwoSortedLists.cpp
//12/10/2022

/*
21. Merge two sorted lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* newNode(int val)
{
    struct ListNode* temp = new ListNode;
    temp->val = val;
    temp->next = NULL;
    return temp;
};

ListNode* mergeUtil(ListNode* h1, ListNode* h2)
{
    // If only one node in first list
    // simply point its head to second list
    if (!h1->next) 
    {
        h1->next = h2;
        return h1;
    }

    // Initialize current and next pointers 
    // of both lists
    ListNode* curr1 = h1, 
            * next1 = h1->next;
    ListNode* curr2 = h2, 
            * next2 = h2->next;

    while (next1 && curr2) 
    {
        // if curr2 lies in between curr1 
        // and next1 then do curr1->curr2->next1
        if ((curr2->val) >= (curr1->val) && 
            (curr2->val) <= (next1->val)) 
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            // now let curr1 and curr2 to point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else 
        {
            // if more nodes in first list
            if (next1->next) 
            {
                next1 = next1->next;
                curr1 = curr1->next;
            }

            // else point the last node of 
            // first list to the remaining 
            // nodes of second list
            else 
            {
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
    ListNode* mergedList = new ListNode;
     
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    
    if (list1->val < list2->val)
        return mergeUtil(list1, list2);
    else
        return mergeUtil(list2, list1);        
};

void printList(ListNode* list){
	while (list != NULL) 
    {
        printf("%d  ", list->val);
        list = list->next;
    }
	printf("\n");
};


int main() {
    
	/*Test for isValid function */
	//Test 1
	ListNode* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(4);

	ListNode* list2 = newNode(1);
    list2->next = newNode(3);
    list2->next->next = newNode(4);
	
	ListNode* result1 = new ListNode;
	result1 = mergeTwoLists(list1, list2);
	vector<int> sol1 = {1, 1, 2, 3, 4, 4};
	for(int i = 0; i < sol1.size(); i++){
		if(sol1[i] == result1->val){
			result1 = result1->next;
			if(i == sol1.size() - 1 )
				cout << "Test 1: Pass" << endl;
		}else{
			cout << "Test 1: Fail" << endl;
			break;
		}		
	}
	
	return 0;
}