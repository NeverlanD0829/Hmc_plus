def bubble_sort(arr):
    n = len(arr)
    # 遍历所有数组元素
    for i in range(n-1):
        # 最后 i 个元素已经排序，不需要再比较
        for j in range(0, n-i-1):
            # 如果元素大于下一个元素，则交换它们
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# 示例
my_list = [64, 34, 25, 12, 22, 11, 90]
bubble_sort(my_list)
print("排序后的数组:", my_list)
