import numpy as np


def batch_norm(inputs, gamma, beta, eps):
    """
    批量归一化操作。N, C, H, W样本数可以看做N*H*W，CNN中，BN通常在每个通道上独立进行
    inputs: 输入数据，形状为 (N, C, H, W)
    gamma: 缩放因子，形状为 (C,)
    beta: 偏移因子，形状为 (C,)
    eps: 防止除0的小数值
    """
    N, C, H, W = inputs.shape

    # 在N、H和W的维度上计算每个通道的均值和方差
    mean = np.mean(inputs, axis=(0, 2, 3), keepdims=True)  # (1,C,1,1)
    var = np.var(inputs, axis=(0, 2, 3), keepdims=True)

    # 计算归一化的输入。eps防止除0
    inputs_norm = (inputs - mean) / np.sqrt(var + eps)

    # 缩放和偏移
    outputs = gamma * inputs_norm + beta

    return outputs

# 举例
inputs = np.random.rand(64, 3, 128, 128)  # 64 samples, 3 channels, 128x128 feature maps

gamma = 0.5
beta = 0.2
eps = 2e-12

outputs = batch_norm(inputs, gamma, beta, eps)
print('输出：', outputs.shape)