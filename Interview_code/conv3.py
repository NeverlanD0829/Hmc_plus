import numpy as np


def conv2d(inputs, kernels, bias, stride, padding):
    # 获取输入数据和卷积核的形状
    H, W = inputs.shape
    F, HH, WW = kernels.shape

    # 对输入数据进行填充。在第一个轴（通常是通道轴）上不进行填充，在第二个轴和第三个轴（通常是高度和宽度轴）上在开始和结束位置都填充padding个值。
    inputs_pad = np.pad(inputs, ((padding, padding), (padding, padding)))

    # 初始化输出数据，卷积后的图像size大小
    H_out = 1 + (H + 2 * padding - HH) // stride
    W_out = 1 + (W + 2 * padding - WW) // stride
    outputs = np.zeros((F, H_out, W_out))

    # 进行卷积操作
    for i in range(H_out):
        for j in range(W_out):  # 找到out图像对于的原始图像区域，然后对图像进行sum和bias
            inputs_slice = inputs_pad[i*stride: i*stride+HH, j*stride: j*stride+WW]
            outputs[:, i, j] = np.sum(inputs_slice * kernels, axis=(1, 2)) + bias
            # axis=(1, 2, 3)表示在通道、高度和宽度这三个轴上进行求和。
    return outputs

# 创建一个示例的多通道二维图片数据（4x4 像素，3个通道）
image = np.random.rand(8, 8).astype(np.float32)

# 定义 两个 多通道 的卷积核（滤波器）与定义偏置
kernel = np.random.rand(128, 5, 5).astype(np.float32)
bias = np.random.rand(128,).astype(np.float32)

# 执行多通道卷积操作
result = conv2d(image, kernel, bias, stride=1, padding=0)

# 打印卷积结果
print(result.shape)