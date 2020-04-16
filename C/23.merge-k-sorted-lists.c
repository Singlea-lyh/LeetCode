/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (38.64%)
 * Likes:    4090
 * Dislikes: 261
 * Total Accepted:    586.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

}


int main(){
    int aiVaule1[] = {1,4,5};
    int aiVaule2[] = {1,3,4};
    int aiVaule3[] = {1,6};
    int iVauleSize1 = 3;
    int iVauleSize2 = 3;
    int iVauleSize3 = 2;

    int iListsSize = 3;

    struct ListNode* pstListHead1 = NULL;
    struct ListNode* pstListHead2 = NULL;
    struct ListNode* pstListHead3 = NULL;
    struct ListNode** ppstList = NULL;
    struct ListNode* pstListTemp = NULL;
    struct ListNode* pstReturn = NULL; 

    ppstList =(struct ListNode**)malloc(sizeof(struct ListNode*) * (iListsSize)) ;

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

    for(int i = 0; i < iVauleSize3; ++i){
    struct ListNode* pstTemp = (struct ListNode*) malloc(sizeof(struct ListNode));
        pstTemp->val = aiVaule2[i];
        pstTemp->next = NULL;
        if(pstListHead3== NULL){
            pstListHead3 = pstTemp;
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

    pstListTemp = pstListHead3;
    while(pstListTemp){
        printf("%d, ", pstListTemp->val);
        pstListTemp = pstListTemp->next;  
    }
    printf("\n");

    ppstList[0] = pstListHead1;
    ppstList[1] = pstListHead2;
    ppstList[2] = pstListHead3;

    pstReturn = mergeKLists(ppstList, iListsSize);

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

