#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param numbers int整型一维数组 
# @return bool布尔型
#
class Solution:
    def IsContinuous(self , numbers: List[int]) -> bool:
        sort_numbers=sorted(numbers)
        numbers_len=len(numbers)
        count_zero=0
        for i in range(numbers_len):
            if sort_numbers[i]==0:
                count_zero=count_zero+1
            else:
                break
        if count_zero==numbers_len:  #全是零
            return True

        pre_num=sort_numbers[count_zero] #记录前一个数字
        start=count_zero+1
        while start<numbers_len:
            if pre_num+1==sort_numbers[start]: #相邻两个数字连续
                pre_num=sort_numbers[start]
                start=start+1
            else: #相邻数字不连续，看是否有零可以替代
                if count_zero>0:
                    count_zero=count_zero-1
                    pre_num=pre_num+1
                else:#相邻数字不连续也没有零来替代
                    return False
        
        return True

                