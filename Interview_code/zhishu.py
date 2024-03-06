def cal_zhishu(n):
    out_put = []
    for i in range(1, n + 1):
        for j in range(2, i):
            if i % j == 0:
                break
        else:
            out_put.append(i)
    return out_put

n = 2
print(cal_zhishu(n))