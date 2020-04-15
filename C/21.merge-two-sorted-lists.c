/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (51.78%)
 * Likes:    3627
 * Dislikes: 540
 * Total Accepted:    905.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//     struct ListNode* pstReturn = NULL;
//     struct ListNode* pstReturnTemp = NULL;
//     struct ListNode* pstL1Temp = l1;
//     struct ListNode* pstL2Temp = l2;

//     while(pstL1Temp != NULL && pstL2Temp != NULL){
//         struct ListNode* pstTemp = NULL;
//         if(pstL1Temp->val < pstL2Temp->val){
//             pstTemp = pstL1Temp;
//             pstL1Temp = pstL1Temp->next;

//         }
//         else{
//             pstTemp = pstL2Temp;
//             pstL2Temp = pstL2Temp->next;
//         }
//         if(pstReturn == NULL){
//             pstReturn = pstTemp;
//             pstReturnTemp = pstTemp;            
//         }
//         else{
//             pstReturnTemp->next = pstTemp;
//             pstReturnTemp = pstTemp;
//         }
//     }

//     while(pstL1Temp != NULL){
//         if(pstReturn == NULL){
//             pstReturn = pstL1Temp;
//             pstReturnTemp = pstL1Temp;            
//         }
//         else{
//             pstReturnTemp->next = pstL1Temp;
//             pstReturnTemp = pstL1Temp;
//         }
//         pstL1Temp = pstL1Temp->next;
//     }
//     while(pstL2Temp != NULL){
//         if(pstReturn == NULL){
//             pstReturn = pstL2Temp;
//             pstReturnTemp = pstL2Temp;            
//         }
//         else{
//             pstReturnTemp->next = pstL2Temp;
//             pstReturnTemp = pstL2Temp;
//         }
//         pstL2Temp = pstL2Temp->next;
//     }
    
//     return pstReturn;
// }

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }

    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}


int main(){
    int aiVaule1[] = {1,2,4};
    int aiVaule2[] = {1,3,4};
    int iVauleSize1 = 3;
    int iVauleSize2 = 3;

    struct ListNode* pstListHead1 = NULL;
    struct ListNode* pstListHead2 = NULL;
    struct ListNode* pstListTemp = NULL;
    struct ListNode* pstReturn = NULL; 

    for(int i = 0; i < iVauleSize1; ++i){
        struct ListNode* pstTemp = (struct ListNode*) malloc(sizeof(struct ListNode));
        pstTemp->val = aiVaule1[i];
        pstTemp->next = NULL;
        if(pstListHead1 == NULL){
            pstListHead1 = pstTemp;
            pstListTemp = pstTemp;
        }
        else{
            pstListTemp->next = pstTemp;
            pstListTemp = pstTemp;
        }       
    }

    for(int i = 0; i < iVauleSize2; ++i){
        struct ListNode* pstTemp = (struct ListNode*) malloc(sizeof(struct ListNode));
        pstTemp->val = aiVaule2[i];
        pstTemp->next = NULL;
        if(pstListHead2 == NULL){
            pstListHead2 = pstTemp;
            pstListTemp = pstTemp;
        }
        else{
            pstListTemp->next = pstTemp;
            pstListTemp = pstTemp;
        }       
    }
    
    pstListTemp = pstListHead1;
    while(pstListTemp){
        printf("%d, ", pstListTemp->val);
        pstListTemp = pstListTemp->next;  
    }
    printf("\n");

    pstListTemp = pstListHead2;
    while(pstListTemp){
        printf("%d, ", pstListTemp->val);
        pstListTemp = pstListTemp->next;  
    }
    printf("\n");

    pstReturn = mergeTwoLists(pstListHead1, pstListHead2);

    pstListTemp = pstReturn;
    while(pstListTemp){
        printf("%d, ", pstListTemp->val);
        pstListTemp = pstListTemp->next;  
    }
    printf("\n");

    pstListTemp = pstReturn;
    while(pstListTemp){
        struct ListNode* pstFreeTemp = pstListTemp;
        pstListTemp = pstListTemp->next; 
        free(pstFreeTemp);  
    }

    return 0;
}


// @lc code=end

