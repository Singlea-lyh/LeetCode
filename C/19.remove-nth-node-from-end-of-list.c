/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.86%)
 * Likes:    2824
 * Dislikes: 202
 * Total Accepted:    559.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int iInterval = 0;
    struct ListNode* pstNode = head;
    struct ListNode* pstRemoveNode = head;
    struct ListNode* pstRemovePre = head;
    struct ListNode* pstReturn = head;

    if(NULL == head || n < 0){
        return head;
    }

    if(pstNode->next == NULL && n == 1){
        return NULL;
    }
    if(pstNode->next == NULL && n == 0){
        return head;
    }

    while(NULL != pstNode -> next){
        if(iInterval < n - 1){
            pstNode = pstNode->next;
            iInterval++;
        }
        else{
            pstNode = pstNode->next;
            if(pstRemoveNode == head){
                pstRemoveNode = pstRemoveNode->next;
            }
            else{
                pstRemoveNode = pstRemoveNode->next;
                pstRemovePre = pstRemovePre->next;
            }
        }
    }

    if(iInterval < n - 1){
        return head;
    }

    if(pstRemovePre == head && pstRemoveNode == head && iInterval == n - 1){
        pstReturn = pstReturn->next;
        free(pstRemoveNode);
    }
    else{
        pstRemovePre->next = pstRemoveNode->next;
        free(pstRemoveNode);
    }

    return pstReturn;

}


int main(){
    int aiVaule[] = {1,2,3,4,5};
    int iVauleSize = 5;
    int iRemoveNode = 2;
    struct ListNode* pstListHead = NULL;
    struct ListNode* pstListTemp = NULL;
    struct ListNode* pstReturn = NULL; 

    for(int i = 0; i < iVauleSize; ++i){
        struct ListNode* pstTemp = (struct ListNode*) malloc(sizeof(struct ListNode));
        pstTemp->val = aiVaule[i];
        pstTemp->next = NULL;
        if(pstListHead == NULL){
            pstListHead = pstTemp;
            pstListTemp = pstTemp;
        }
        else{
            pstListTemp->next = pstTemp;
            pstListTemp = pstTemp;
        }       
    }
    
    pstListTemp = pstListHead;
    while(pstListTemp){
        printf("%d, ", pstListTemp->val);
        pstListTemp = pstListTemp->next;  
    }
    printf("\n");

    pstReturn = removeNthFromEnd(pstListHead, iRemoveNode);

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

