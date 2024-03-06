import numpy as np

def max_pooling(inputs, pool_size, stride):
    """
    最大池化操作
    inputs: 输入数据，形状为 (C, H, W)
    pool_size: 池化核的大小
    stride: 步长
    """
    C, H, W = inputs.shape

    # 初始化输出数据
    H_out = (H - pool_size) // stride + 1
    W_out = (W - pool_size) // stride + 1
    outputs = np.zeros((C, H_out, W_out))

    # 进行最大池化操作
    for i in range(H_out):
        for j in range(W_out):
            inputs_slice = inputs[:, i*stride:i*stride+pool_size, j*stride:j*stride+pool_size]
            outputs[:, i, j] = np.max(inputs_slice, axis=(1, 2))         # 最大池化
            # outputs[:, i, j] = np.mean(inputs_slice, axis=(1, 2))        # 平均池化

    return outputs


# 创建一个示例的多通道二维图片数据（4x4 像素，3个通道）
image = np.random.rand(3, 12, 12).astype(np.float32)

# 定义 池化核大小
pool_size = 2

# 执行池化操作
result = max_pooling(image, pool_size, stride=2)

# 打印卷积结果
print(result.shape)