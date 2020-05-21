/*
 * @lc app=leetcode id=42 lang=c
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (47.20%)
 * Likes:    6438
 * Dislikes: 112
 * Total Accepted:    479.6K
 * Total Submissions: 1M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int recurrence(int* piHeight, int iLeft, int iRight){
    int iReturn = 0;
    int iHeight = 0;
    int iLength = 0;
    int iStart = iLeft, iEnd = iRight;

    if(iEnd - iStart <= 1){
        return 0;
    }

    iHeight = (piHeight[iStart] <= piHeight[iEnd])? piHeight[iStart]: piHeight[iEnd];
    iLength = iEnd - iStart - 1;
    iReturn = iHeight * iLength;

    if(piHeight[iStart] <= piHeight[iEnd]){
        while (iStart < iEnd + 1){
            if(iStart == iLeft || iStart == iEnd){
                piHeight[iStart] -= iHeight;
                ++iStart;
                continue;
            }
            else{
                if(piHeight[iStart] > 0){
                    iReturn -= ((iHeight < piHeight[iStart])? iHeight : piHeight[iStart]);
                    if(piHeight[iStart] >= iHeight){
                        piHeight[iStart] -= iHeight;
                    }
                    else{
                        piHeight[iStart] = 0;
                    }    
                }
                ++iStart;
            } 
        }        
    }
    else{
        while ((iStart - 1) < iEnd){
            if(iEnd == iRight  || iEnd == iStart){
                piHeight[iEnd] -= iHeight;
                --iEnd;
                continue;
            }
            else{
                if(piHeight[iEnd] > 0){
                    iReturn -= ((iHeight < piHeight[iEnd])? iHeight : piHeight[iEnd]);
                    if(piHeight[iEnd] >= iHeight){
                        piHeight[iEnd] -= iHeight;
                    }
                    else{
                        piHeight[iEnd] = 0;
                    }
                }     
                --iEnd;
            }  
        }        

    }

    iStart = iLeft;
    iEnd = iRight;

    while((iEnd - iStart > 1) &&  piHeight[iStart] == 0){
        ++iStart;
    }
    while((iEnd - iStart > 1) &&  piHeight[iEnd] == 0){
        --iEnd;
    }

    iReturn += recurrence(piHeight, iStart, iEnd);

    return iReturn;
}


int trap(int* height, int piHeightSize){
    int iStart = 0;
    int iEnd = piHeightSize - 1;
    int iPreEnd = 0;
    int iTotle = 0;
    int iReturn = 0;
    
    if(piHeightSize < 3){
        return iReturn;
    }

    while((iEnd - iStart > 1) &&  height[iStart] == 0){
        ++iStart;
    }
    while((iEnd - iStart > 1) &&  height[iEnd] == 0){
        --iEnd;
    }

    iReturn += recurrence(height, iStart, iEnd);

    return iReturn;
}

int main(){
    int iReturn = 0;
    int pipiHeight[] = {4,2,3};
    int ipiHeightSize = 3;

    iReturn = trap(pipiHeight, ipiHeightSize);

    printf("%d\n", iReturn);

    return 0;
}

// @lc code=end

