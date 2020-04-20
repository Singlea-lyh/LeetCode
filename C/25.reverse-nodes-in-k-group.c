/*
 * @lc app=leetcode id=25 lang=c
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (40.08%)
 * Likes:    1851
 * Dislikes: 346
 * Total Accepted:    247K
 * Total Submissions: 612.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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

// struct ListNode* reverseKNode(struct ListNode* pstNodeHead, int k){
//     struct ListNode* pstReturn = NULL;
//     struct ListNode* pstHeadTemp = NULL;
//     struct ListNode* pstNodeNext = NULL;
//     struct ListNode* pstTemp = NULL;
//     int i = 0;

//     pstTemp = pstNodeHead;

//     // while(pstTemp != NULL && i < k){
//     //     struct ListNode* pstExtra = (struct ListNode*)malloc(sizeof(struct ListNode));
//     //     if(pstHeadTemp == NULL){
//     //         pstHeadTemp = pstTemp;

//     //     }
//     //     pstExtra->next = pstTemp->next;
//     //     pstExtra->val = pstTemp->val;

//     //     pstTemp = pstTemp->next;
//     //     ++i;
//     // }

//     i = 0;
//     pstTemp = pstNodeHead;
//     pstNodeNext = pstNodeHead;

//     while(pstNodeNext != NULL && i < k){   
//         pstNodeNext = pstTemp->next;
//         ++i;
//         if(pstReturn == NULL){
//             pstReturn = pstTemp;
//         }
//         else{
//             pstTemp->next = pstReturn;
//             pstReturn = pstTemp;
//         }

//          pstTemp = pstNodeNext;
//     }
   

//     // i = 0;
//     // pstTemp = pstHeadTemp;

//     // while(pstTemp != NULL && i < k){
//     //     struct ListNode* pstTempDel = pstTemp;
//     //     pstTemp = pstTemp->next;
//     //     free(pstTempDel);

//     // }


//     return pstReturn;
// }


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* pstReturn = NULL;
    struct ListNode* pstNodePre = NULL;
    struct ListNode* pstNodeEnd = NULL;
    struct ListNode* pstTemp = NULL;
    int i = 0;

    pstTemp = head;

    while(pstTemp != NULL &&  i < k){
        pstTemp = pstTemp->next;
        ++i;
    }

    if(i < k){
        return head;
    }

    pstTemp = reverseKGroup(pstTemp, k);
    while(i > 0){
        struct ListNode* pstTempNode = head->next;
        head->next = pstTemp;
        pstTemp = head;
        head = pstTempNode;
        --i;
    }

    pstReturn = pstTemp;

    return pstReturn;
}


int main(){
    int aiVaule1[] = {1, 2, 3, 4};
    int iVauleSize1 = 4;
    int iKNum = 2;


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
    printf(" \n");
    printf(" aaa \n");


    pstReturn = reverseKGroup(pstListHead1, iKNum);

    pstListTemp = pstReturn;
    while(pstListTemp){
        printf("%d, ", pstListTemp->val);
        pstListTemp = pstListTemp->next;  
    }
    printf("\n");
    printf(" bbb \n");

    pstListTemp = pstReturn;
    while(pstListTemp){
        struct ListNode* pstFreeTemp = pstListTemp;
        pstListTemp = pstListTemp->next; 
        free(pstFreeTemp);  
    }

    return 0;
}



// @lc code=end

