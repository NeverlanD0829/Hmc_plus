"""
类，功能：函数接受模型输出结果，该结果每次是0或1，做一个平滑操作，包含当前结果在内的历史5次结果，若超过3次大于等于1，返回true，否则
"""

class SmoothOperator:
    def __init__(self):
        self.history=[]

    def smooth_result(self,current_result):
        self.history.append(current_result)

        if len(self.history)>5:
            self.history.pop(0)

        if sum(self.history)>=3:
            return True
        else:
            return False
        
#案例
Smooth_operator=SmoothOperator()
history_results=[0,1,1,0,1]

for result in history_results:
    is_smoothed=Smooth_operator.smooth_result(result)
    print(f"Current result:{result},Smoothed result:{is_smoothed}")