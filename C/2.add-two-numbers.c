/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.89%)
 * Likes:    7280
 * Dislikes: 1888
 * Total Accepted:    1.3M
 * Total Submissions: 3.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef int bool;

#define NULL 0
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
 };
#if 0
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    bool bFalg = false;
    int iAdd = 0;

    struct ListNode* stAddTemp = NULL;
    struct ListNode* stAdd = NULL;
    struct ListNode* stAddHead = NULL;
        
    struct ListNode* stL1;
    struct ListNode* stL2;

    stL1 = l1;
    stL2 = l2;
        
    while(stL1 != NULL && stL2 != NULL){
        stAddTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
        stAddTemp->next = NULL;

        if(bFalg){
             iAdd = stL1->val + stL2->val + 1;
             bFalg = false;
        }
        else{
            iAdd = stL1->val + stL2->val;
        }
       
        if(iAdd > 9){
            stAddTemp->val = iAdd % 10;
            bFalg = true;
        }
        else{
            stAddTemp->val = iAdd;
        }

        if(stAddHead == NULL){
            stAddHead = stAddTemp;
            stAdd = stAddTemp;
        }
        else{
            stAdd->next = stAddTemp;
            stAdd = stAdd->next;
        }

        stL1 = stL1->next;
        stL2 = stL2->next;
    }

    while(stL1 != NULL){
        stAddTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
        stAddTemp->next = NULL;

        if(bFalg){
            iAdd = stL1->val + 1; 
            bFalg = false;         
        }
        else{
            iAdd = stL1->val;
        }  

        if(iAdd > 9){
            stAddTemp->val = iAdd % 10;
            bFalg = true;
        }
        else
        {
            stAddTemp->val = iAdd;
        }     
        
        stAdd->next = stAddTemp;
        stAdd = stAdd->next;

        stL1 = stL1->next;
    }

    while(stL2 != NULL){
        stAddTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
        stAddTemp->next = NULL;

       if(bFalg){
            iAdd = stL2->val + 1; 
            bFalg = false;         
        }
        else{
            iAdd = stL2->val;
        }  

        if(iAdd > 9){
            stAddTemp->val = iAdd % 10;
            bFalg = true;
        }
        else
        {
            stAddTemp->val = iAdd;
        }     

        stAdd->next = stAddTemp;
        stAdd = stAdd->next;

        stL2 = stL2->next;
    }   

    if(bFalg && stL1 == NULL && stL2 == NULL){
        stAddTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
        stAddTemp->next = NULL;

        stAddTemp->val = 1;
        stAdd->next = stAddTemp;
        stAdd = stAdd->next;
    }
    
    return stAddHead;
}

#endif

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    bool bFalg = false;
    int iAdd = 0;
    int il1,il2;

    struct ListNode* stAddTemp = NULL;
    struct ListNode* stAdd = NULL;
    struct ListNode* stAddHead = NULL;
        
    struct ListNode* stL1 = NULL;
    struct ListNode* stL2 = NULL;

    stL1 = l1;
    stL2 = l2;

    while(stL1 != NULL || stL2 != NULL){
        stAddTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
        il1 = (stL1 != NULL) ? stL1->val : 0;
        il2 = (stL2 != NULL) ? stL2->val : 0;

        iAdd = (bFalg) ? (il1 + il2 + 1) : (il1 + il2);
        bFalg = false;

        if(iAdd > 9){
            stAddTemp->val = iAdd % 10;
            bFalg = true;
        }
        else{
            stAddTemp->val = iAdd;
        }

        if(stAddHead == NULL){
            stAddHead = stAddTemp;
            stAdd = stAddTemp;
        }
        else{
            stAdd->next = stAddTemp;
            stAdd = stAdd->next;
        }

        if(stL1 != NULL){
            stL1 = stL1->next;
        }
        if(stL2 != NULL){
            stL2 = stL2->next;
        }
    }    

    if(bFalg){
         stAddTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
        stAddTemp->next = NULL;

        stAddTemp->val = 1;
        stAdd->next = stAddTemp;
        stAdd = stAdd->next;
    }
    
    return stAddHead;
}

// @lc code=end

