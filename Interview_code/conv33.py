import numpy as np


def conv2d(inputs, kernels, padding, bias, stride):
    c, w, h = inputs.shape
    #     inputs_pad = np.zeros((c,w+2*padding,h+2*padding))
    #     inputs_pad[:, padding:w+padding, padding:h+padding] = inputs
    #     print(inputs_pad.shape, '\n', inputs_pad)
    #     inputs = inputs_pad
    inputs = np.pad(inputs, ((0, 0), (1, 1), (1, 1)))  ## 可以直接用np.pad函数实现pad
    kernels_num, kernel_size = kernels.shape[0], kernels.shape[2]

    outputs = np.ones(
        (kernels_num, (w - kernel_size + 2 * padding) // stride + 1, (h - kernel_size + 2 * padding) // stride + 1))
    for i in range(0, w - kernel_size + 2 * padding + 1, stride):
        for j in range(0, h - kernel_size + 2 * padding + 1, stride):
            outputs[:, i // stride, j // stride] = np.sum(
                np.multiply(kernels, inputs[:, i:i + kernel_size, j:j + kernel_size]), axis=(1, 2, 3)) + bias
    return outputs


inputs = np.ones((16, 9, 9))
kernels = np.ones((25, 16, 3, 3))
bias = np.arange(1, kernels.shape[0] + 1)
stride = 2
padding = 1
outputs = conv2d(inputs, kernels, padding, bias, stride)
print("input{}".format(inputs.shape))
print("kenerls{}, stride{}".format(kernels.shape, stride))
print("output{}".format(outputs.shape))
print(outputs)
