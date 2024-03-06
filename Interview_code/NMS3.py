import numpy as np

def non_max_sppse(pre_box, threshold=0.2):
    for object_name, bbox in pre_box.items():
        bbox_array = np.array(bbox, np.float32)

        # 计算所有框的面积
        x1, y1, x2, y2, source = bbox_array[:, 0], bbox_array[:, 1], bbox_array[:, 2], bbox_array[:, 3], bbox_array[:, 4]
        areas = (x2 - x1 + 1) * (y2 - y1 + 1)

        # 对置信度进行排序
        order = source.argsort()[::-1]
        keep = []

        while order.size > 0:
            i = order[0]
            keep.append(i)

            xx1 = np.maximum(x1[i], x1[order[1:]])
            yy1 = np.maximum(y1[i], y1[order[1:]])
            xx2 = np.minimum(x2[i], x2[order[1:]])
            yy2 = np.minimum(y2[i], y2[order[1:]])

            inter = np.maximum(0, (xx2 - xx1 + 1)) * np.maximum(0, (yy2 - yy1 + 1))
            iou = inter / (areas[i] + areas[order[1:]] - inter)

            indexs = np.where(iou < threshold)[0] + 1
            order = order[indexs]

        bbox = bbox_array[keep]
        pre_box[object_name] = bbox.tolist()
        pre_box = pre_box
    return pre_box



pre_box = {"dog": [[2, 8, 4, 15, 0.5], [3, 12, 5, 17, 0.1], [3, 9, 4, 15, 0.3], [3, 10, 5, 18, 0.6], [2, 15, 4, 23, 0.8]]}
a = non_max_sppse(pre_box, 0.2)
print(a)