"""
实现浮点数的平方根，可使用二分法/牛顿迭代法来逼近
牛顿迭代法思路：使用输入浮点数的一半做初始猜测值，可选其他，但初始值影响收敛速度。
    然后使用牛顿迭代公式进行计算，直到达到足够的精度后，停止迭代。最终return得到的平方值。
erf
"""

#牛顿迭代法
# def square_root(number):
#     if number<0:
#         return "检查输入不能是负数。"
#     guess=number/2.0
#     #迭代计算
#     while abs(guess*guess-number)>1e-9:
#         guess=(guess+number/guess)/2.0
#     return guess

#二分法
def square_root(number):
    if number<0:
        return "输入不能为负数,重新输入!"
    low,high=0,number
    while abs(low*low-number)>1e-9:
        mid=(low+high)/2.0
        mid_square=mid*mid
        if mid_square<number:
            low=mid
        else:
            high=mid
    return low

number=float(input("请输入一个浮点数："))
result=square_root(number)
print(f"{number}的平方根是{result}")