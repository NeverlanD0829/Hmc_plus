import numpy as np

def corr2d(X, K, bias=None, stride=1, padding=0):
    h, w = K.shape
    # 计算输出矩阵的大小
    out_h = (X.shape[0] - h + 2 * padding) // stride + 1
    out_w = (X.shape[1] - w + 2 * padding) // stride + 1

    # 构建输出矩阵
    Y = np.zeros(out_h, out_w)

    # 添加填充
    X_padded = np.pad(X, (padding, padding, padding, padding))

    # 滑动，并进行求值
    for i in range(0, X_padded.shape[0] - h + 1, stride):
        for j in range(0, X_padded.shape[1] - w + 1, stride):
            Y[i // stride, j // stride] = (X_padded[i:i + h, j:j + w] * K).sum()

    # 添加偏置项
    if bias is not None:
        Y += bias

    return Y

# kernel_size = (1, 2)
# conv_layer = Conv2D(kernel_size)

X = np.ones((6, 8))
X[:, 2:6] = 0

K = np.tensor([[1.0, -1.0]])
Y = corr2d(X, K)

x =
out = corr2d(x)
print(out.shape)