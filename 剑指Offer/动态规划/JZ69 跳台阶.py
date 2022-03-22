#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param number int整型 
# @return int整型
#
class Solution:
    def jumpFloor(self , number: int) -> int:
        # write code here
        if number==0:
            return 0
        elif number==1:
            return 1
        elif number==2:
            return 2
        else: # number>=3
            low_floor=1 # 动态规划初始化，初始化低一级台阶和低二级台阶
            high_floor=2
            number=number-2
            while number:  # 按动态规划进行迭代
                number=number-1
                current_floor=low_floor+high_floor
                low_floor=high_floor
                high_floor=current_floor
            return high_floor