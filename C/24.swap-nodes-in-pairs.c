/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (48.75%)
 * Likes:    1921
 * Dislikes: 159
 * Total Accepted:    434.5K
 * Total Submissions: 887.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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


// struct ListNode* swapPairs(struct ListNode* head){
//     struct ListNode* pstReturn;
//     struct ListNode* pstTemp;
//     struct ListNode* pstTempPre;

//     if(head == NULL || head->next == NULL){
//         return head;
//     }

//     pstTemp = head;
//     pstTempPre = head;
    
//     while(pstTemp != NULL && pstTemp->next != NULL){
//         struct ListNode* pstFirst = pstTemp;
//         struct ListNode* pstSecond = pstTemp->next;
//         pstTemp = pstTemp->next->next;

//         if(pstFirst == head){
//             pstFirst->next = pstSecond->next;
//             pstSecond->next = pstFirst;
//             pstReturn = pstSecond;
//             pstTempPre = pstFirst;            
//         }
//         else{
//             pstFirst->next = pstSecond->next;
//             pstSecond->next = pstFirst;
//             pstTempPre->next = pstSecond;
//             pstTempPre = pstFirst;
//         }
//     }

//     return pstReturn;
// }

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* pstReturn;
    struct ListNode* pstFirst;
    struct ListNode* pstSecond;

    if(head == NULL || head->next == NULL){
        return head;
    }

    pstFirst = head;
    pstSecond = head->next;

    pstFirst->next = swapPairs(pstSecond->next);
    pstSecond->next = pstFirst;

    pstReturn = pstSecond;

    return pstReturn;
}


int main(){
    int aiVaule1[] = {1, 2, 3, 4};
    int iVauleSize1 = 4;


    int iListsSize = 3;

    struct ListNode* pstListHead1 = NULL;
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
    pstListTemp = pstListHead1;
    while(pstListTemp){
        printf("%d, ", pstListTemp->val);
        pstListTemp = pstListTemp->next;  
    }
    printf("\n");


    pstReturn = swapPairs(pstListHead1);

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

