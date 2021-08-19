/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left=0,right=letters.size()-1;
        int mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(letters[mid]>target)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        //其实在这里直接判断right就可以了，不需要下面那么复杂
        return letters[right]>target?letters[right]:letters[0];
        /*
        if(letters[right]<=target)
        {
            while(right+1<=letters.size()-1)
            {
                if(letters[right+1]>target)
                {
                    return letters[right+1];
                }
                else
                {
                    right++;
                }
            }
                return letters[0];
        }
        else 
        {
            return letters[right];
        }*/
    }
};
// @lc code=end

