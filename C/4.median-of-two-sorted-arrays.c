/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (28.50%)
 * Likes:    6130
 * Dislikes: 938
 * Total Accepted:    610.7K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
     int iNumMid1, iNumMid2;
    
    int iFront1, iFront2, iRear1, iRear2;

    iFront1 = iFront2 = 0;
    iRear1 = nums1Size - 1;
    iRear2 = nums2Size - 1;


    while(iFront1 < iRear1 || iFront2 < iRear2){
        iNumMid1 = (iFront1 != iRear1) ? ((iFront1 + iRear1) /2) : iFront1;
        iNumMid2 = (iFront2 != iRear2) ? ((iFront2 + iRear2) /2) : iFront2;

        if(nums1[iNumMid1] < nums2[iNumMid2]){
            iFront1 = iNumMid1;
            iRear2 = iNumMid2;
        }
        else if(nums1[iNumMid1] > nums2[iNumMid2]){
            iRear1 = iNumMid1;
            iFront2 = iNumMid2;
        }
        else{
            return nums1[iRear1];
        }
    }

    return (nums1[iNumMid1] + nums2[iNumMid2]) / 2;

}


// @lc code=end

