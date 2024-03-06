import numpy as np

def IoU_cal(box1, box2):
    x1 = max(box1[0], box2[0])
    y1 = max(box1[1], box2[1])
    x2 = min(box1[2], box2[2])
    y2 = min(box1[3], box2[3])

    inter = max(0, x2 - x1) * max(0, y2 - y1)

    areas1 = (box1[2] - box1[0]) * (box1[3] - box1[1])
    areas2 = (box2[2] - box2[0]) * (box2[3] - box2[1])

    iou = inter / (areas1 + areas2 - inter)

    return iou

pre_box1 = [2, 9, 4, 15, 0.5]
pre_box2 = [3, 7, 6, 10, 0.5]

a = IoU_cal(pre_box1, pre_box2)
print(a)