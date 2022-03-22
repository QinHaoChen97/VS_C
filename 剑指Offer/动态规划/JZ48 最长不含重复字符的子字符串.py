# https://www.nowcoder.com/practice/48d2ff79b8564c40a50fa79f9d5fa9c7?tpId=13&tqId=2276769&ru=/practice/2237b401eb9347d282310fc1c3adb134&qru=/ta/coding-interviews/question-ranking
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串
# @return int整型
#
# https://www.nowcoder.com/practice/48d2ff79b8564c40a50fa79f9d5fa9c7?tpId=13&tqId=2276769&ru=/practice/2237b401eb9347d282310fc1c3adb134&qru=/ta/coding-interviews/question-ranking
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串
# @return int整型
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0

        start=0
        end=0
        hashtable={}
        s_len=len(s)
        max_len=0

        for i in range(s_len):
            if s[i] not in hashtable or hashtable[s[i]]<start: #未出现过或出现过但不在当前的字符串内
                hashtable[s[i]]=i
                end=i
                max_len=max(max_len,end-start+1)
            else:
                start=hashtable[s[i]]+1
                end=i
                hashtable[s[i]]=i
                max_len=max(max_len,end-start+1)

                    
        
        return max_len

        
        

        
        
