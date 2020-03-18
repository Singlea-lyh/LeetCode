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

/*
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
*/

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int iNum1, iNum2;
    int iSumNum;
    int iMid, iMidTemp, iDelNum;
    double dReturn = 0.0;

    iSumNum = nums1Size + nums2Size;
    iNum1 = iNum2 = 0;
    iDelNum = 0;

    iMid = iMidTemp = iSumNum / 2;

    if(nums1Size == 0){
        dReturn = (nums2Size % 2) ? (nums2[nums2Size / 2]):((nums2[nums2Size / 2] + nums2 [(nums2Size / 2) - 1]) / 2.0) ;
        return dReturn;
    }
    else if(nums2Size == 0){
        dReturn = (nums1Size % 2) ? (nums1[nums1Size / 2]):((nums1[nums1Size / 2] + nums1[(nums1Size / 2) - 1]) / 2.0) ;
        return dReturn;
    }

    while(iNum1 < nums1Size && iNum2 < nums2Size && iDelNum < iMid){
        iMidTemp = iMidTemp / 2;

        if(iMidTemp == 0){
            break;
        }

        if(iNum1 + iMidTemp <= nums1Size && iNum2 + iMidTemp <= nums2Size){
            if(nums1[iNum1+iMidTemp - 1] <= nums2[iNum2+iMidTemp - 1]){
                iNum1 += iMidTemp;
            }
            else{
                iNum2 += iMidTemp;
            }
            iDelNum += iMidTemp;
            //iMidTemp = iMid - iDelNum;
        }
        else if(iNum1 + iMidTemp >= nums1Size){
            if(nums1[nums1Size - 1] < nums2[iNum2 + iMidTemp -1]){
                iNum1 = nums1Size - 1;
                iDelNum += (nums1Size - iNum1);
                //iMidTemp = iMid - iDelNum;

            }
            else{
                iNum2 += iMidTemp;
                iDelNum += iMidTemp;
                //iMidTemp = iMid - iDelNum;
            }
        }
        else if(iNum2 + iMidTemp >= nums2Size){
            if(nums2[nums2Size - 1] < nums1[iNum1 + iMidTemp - 1]){
                iNum2 = nums2Size - 1;
                iDelNum += (nums2Size - iNum2);
                //iMidTemp = iMid -iDelNum;
            }
            else{
                iNum1 += iMidTemp;
                //iDelNum += iMidTemp;
                
            }
        }  
        iMidTemp = iMid - iDelNum;
    }

    iMidTemp /= 2;

    if((iMid - iDelNum == 1) && (iSumNum % 2 == 1)){
       if(iNum1 < nums1Size && iNum2 < nums2Size){
          if(nums1[iNum1] < nums2[iNum2]){
              ++iNum1;
          }
          else if(nums1[iNum1] > nums2[iNum2]){
              ++iNum2;
          }
       } 
       else if(iNum1 < nums1Size){
           ++iNum1;
       }
       else if(iNum2 < nums2Size)
       {
           ++iNum2;
       }
       
    }

    if(iNum1 < nums1Size && iNum2 < nums2Size){
        if(nums1[iNum1] <= nums2[iNum2]){
            if(iSumNum % 2){
                dReturn = nums1[iNum1];
            }
            else{
                if(iNum1 + 1 < nums1Size){
                    if(nums1[iNum1 + 1] < nums2[iNum2]){
                        dReturn = (nums1[iNum1] + nums1[iNum1 + 1]) / 2.0;
                    }
                    else{
                        dReturn = (nums1[iNum1] + nums2[iNum2]) / 2.0; 
                    }
                }
                else{
                      dReturn = (nums1[iNum1] + nums2[iNum2]) / 2.0;
                }
            }
        }
        else if(nums1[iNum1] > nums2[iNum2]){
            if(iSumNum % 2){
                dReturn = nums2[iNum2];
            }
            else{
                if(iNum2 + 1 < nums2Size){
                    if(nums2[iNum2 + 1] < nums1[iNum1]){
                        dReturn = (nums2[iNum2] + nums2[iNum2 + 1]) / 2.0;
                    }
                    else{
                        dReturn = (nums1[iNum1] + nums2[iNum2]) / 2.0; 
                    }
                }
                else
                {
                    dReturn = (nums1[iNum1] + nums2[iNum2]) / 2.0;
                }
            }
        }
        else{
            dReturn = nums1[iNum1];
        }
    }
    else if(iNum1 < nums1Size){
        if(iSumNum % 2){
            dReturn = nums1[iNum1 + iMidTemp];
        }
        else{
            dReturn = (nums1[iNum1 + iMidTemp] + nums1[iNum1 + iMidTemp + 1]) / 2.0;
        }

    }
    else{
        if(iSumNum % 2){
            dReturn = nums2[iNum2 + iMidTemp];
        }
        else{
            dReturn = (nums2[iNum2 + iMidTemp] + nums2[iNum2 + iMidTemp + 1]) / 2.0;
        }
    }

    return dReturn;
}



int main(){
    int aiNum1[4] = {2, 3, 4, 5};
    int aiNum2[1] = {1};

    double fReturn = findMedianSortedArrays(aiNum1, 4, aiNum2, 1);

    printf("%f\n", fReturn);

    return 0;
}

// @lc code=end

