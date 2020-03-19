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
/*
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

*/
/*
double findMidArray(int* nums1, int iNum1, int nums1Size, int* nums2, int iNum2, int nums2Size, int iDelnum){
    double dReturn;
    int iSumNum;
    int iTemp1, iTemp2;
    int iMidDel = 0;
    int iMidTemp = 0;

    iSumNum = nums1Size + nums2Size;

    if(nums1Size - iNum1 == 0){
        dReturn = (iSumNum % 2)?(nums2[iNum2+iDelnum]):((nums2[iNum2+iDelnum-1] + nums2[iNum2+iDelnum]) / 2.0);
    }
    else if(nums2Size - iNum2 == 0){
        dReturn = (iSumNum % 2)?(nums1[iNum1+iDelnum]):((nums1[iNum1+iDelnum-1] + nums1[iNum1+iDelnum]) / 2.0);
    }
    else if(iDelnum == 0){
        if(iSumNum % 2){
            dReturn = (nums1[iNum1] <= nums2[iNum2]) ? nums1[iNum1] : nums2[iNum2];
        }
        else{
            if(nums1[iNum1] < nums2[iNum2]){
                iTemp1 = nums1[iNum1];
                ++iNum1;
                if(nums1Size - iNum1 != 0 ){
                    iTemp2 = (nums1[iNum1] < nums2[iNum2]) ? nums1[iNum1] : nums2[iNum2];
                }
                else{
                    iTemp2 = nums2[iNum2];
                }
            }
            else if(nums1[iNum1] > nums2[iNum2]){
                iTemp1 = nums2[iNum2];
                ++iNum2;
                 if(nums2Size - iNum2 != 0 ){
                    iTemp2 = (nums1[iNum1] < nums2[iNum2]) ? nums1[iNum1] : nums2[iNum2];
                }
                else{
                    iTemp2 = nums1[iNum1];
                }
            }
            else{
                iTemp1 = nums1[iNum1];
                iTemp2 = nums2[iNum2];
            }
            dReturn = (iTemp1 + iTemp2) / 2.0;
        }
    }
    else{
        if(iDelnum == 1){
            if(nums1[iNum1] < nums2[iNum2]){
                ++iNum1;
            }
            else{
                ++iNum2;
            }
        }
        else{
            iMidTemp = iDelnum / 2;
            if((nums1Size - iNum1) >= iMidTemp && (nums2Size - iNum2) >= iMidTemp){
                if(nums1[iNum1 + iMidTemp - 1] < nums2[iNum2 + iMidTemp - 1]){
                    iNum1 += iMidTemp;
                }
                else{
                    iNum2 += iMidTemp;
                }
                iMidDel = iMidTemp;
            }
            else if((nums1Size - iNum1) < iMidTemp){
                iMidDel = nums1Size - iNum1;
                if(nums1[nums1Size - 1] < nums2[iNum2 + iMidDel - 1]){
                    iNum1 = nums1Size;
                }
                else{
                    iNum2 += iMidDel;
                }
            }
            else if((nums2Size - iNum2) < iMidTemp){
                iMidDel = nums2Size - iNum2;
                if(nums2[nums2Size - 1] < nums1[iNum1 + iMidDel - 1]){
                    iNum2 = nums2Size;
                }
                else{
                    iNum1 += iMidDel;
                }
            }
            iDelnum -= iMidDel;
            dReturn = findMidArray(nums1, iNum1, nums1Size, nums2, iNum2, nums2Size, iDelnum);
        }
    }
    return dReturn;

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int iNum1, iNum2;
    int iSumNum;
    double dReturn = 0.0;
    int iDelNum = 0;
    
    iNum1 = iNum2 = 0;
    iSumNum = nums1Size + nums2Size;

    if(iSumNum % 2){
         iDelNum = iSumNum / 2;
    }
    else{
        iDelNum = (iSumNum / 2) - 1;
    }

    dReturn = findMidArray(nums1, iNum1, nums1Size, nums2, iNum2, nums2Size, iDelNum);

    return dReturn;
}

*/
/*
#define MIN(a, b)  ((a < b) ? a : b)
#define MAX(a, b)  ((a < b) ? b : a)

double findKTh(int* nums1, int iStart1, int iEnd1, int *nums2, int iStart2, int iEnd2, int iKTh){
    int iLen1 = iEnd1 - iStart1 + 1;
    int iLen2 = iEnd2 - iStart2 + 1;

    if(iLen1 > iLen2) return findKTh(nums2, iStart2, iEnd2, nums1, iStart1, iEnd1, iKTh);
    if(iLen1 == 0) return nums2[iStart2 + iKTh -1];

    // if(iKTh == 1){
    //     if(nums1[iStart1] < nums2[iStart2]){
    //         return nums1[iStart1];
    //     }
    //     else
    //     {
    //         return nums2[iStart2];
    //     }
    // }
    if(iKTh == 1) return ((nums1[iStart1] < nums2[iStart2]) ? nums1[iStart1] : nums2[iStart2]);

    // int i1 = ((iLen1 < (iKTh / 2)) ? iLen1 : (iKTh / 2));
    // int j1 = ((iLen2 < (iKTh / 2)) ? iLen2 : (iKTh / 2));
    
    // int i = iStart1 + i1 - 1;
    // int j = iStart2 + j1 - 1;

    int i = iStart1 + ((iLen1 < (iKTh / 2)) ? iLen1 : (iKTh / 2)) - 1;
    int j = iStart2 + ((iLen2 < (iKTh / 2)) ? iLen2 : (iKTh / 2)) - 1; 


    if(nums1[i] > nums2[j]){
        return findKTh(nums1, iStart1, iEnd1, nums2, j + 1, iEnd2, iKTh -(j - iStart2 + 1));
    }
    else{
        return findKTh(nums1, i + 1, iEnd1, nums2, iStart2, iEnd2, iKTh -(i - iStart1 + 1));
    }

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int iTotalNum;
    int iLeft, iRight;

    iTotalNum = nums1Size + nums2Size;

    iLeft = (iTotalNum + 1) / 2;
    iRight = (iTotalNum + 2) / 2;

    return (findKTh(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, iLeft)
         + findKTh(nums1, 0, nums1Size - 1, nums2, 0, nums2Size -1 , iRight)) / 2.0;
}
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int iSplit1, iSplit2;
    int iSumLen = 0;
    int iMaxLeft, iMinRight;
    int iMin, iMax;

    if(nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    iMin = 0, iMax = nums1Size;
    iSplit1 = iSplit2 = 0;
    iMaxLeft = iMinRight = 0;
    iSumLen = nums1Size + nums2Size;

    while(iMin <= iMax){
        iSplit1 = (iMin + iMax) / 2;
        iSplit2 = (iSumLen + 1) / 2 - iSplit1;

        if(iSplit1 > iMin && nums1[iSplit1 -1] > nums2[iSplit2]){
            iMax = iSplit1 - 1;
        }
        else if(iSplit1 < iMax && nums2[iSplit2 - 1] > nums1[iSplit1]){
            iMin = iSplit1 + 1;
        }
        else{
            if(iSplit1 == 0){
                iMaxLeft = nums2[iSplit2 - 1];
            }
            else if(iSplit2 == 0){
                iMaxLeft = nums2[iSplit1 - 1];
            }
            else{
                iMaxLeft = (nums1[iSplit1 - 1] > nums2[iSplit2 - 1]) ? nums1[iSplit1 - 1] : nums2[iSplit2 - 1];
            }
            if(iSumLen % 2) {
                return iMaxLeft;
            }

            if(iSplit1 == nums1Size){
                iMinRight = nums1[iSplit2];
            }
            else if(iSplit2 == nums2Size){
                iMinRight = nums1[iSplit1];
            }
            else{
                iMinRight = (nums1[iSplit1] < nums2[iSplit2]) ? nums1[iSplit1] : nums2[iSplit2];
            }

            if (iSumLen % 2 == 0){
                return (iMaxLeft + iMinRight) / 2.0;
            }
        }
    }


}

int main(){
    int aiNum1[4] = {2, 3, 4, 5};
    int aiNum2[1] = {1};

    double fReturn = findMedianSortedArrays(aiNum1, 4, aiNum2, 1);

    printf("%f\n", fReturn);

    return 0;
}

// @lc code=end

