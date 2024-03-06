import numpy as np


import torch
import torch.nn.functional as F
from torch import nn
import math

# 在计算自注意力的时候，首先计算每个元素的 Query 和所有其他元素的 Key 之间的相似度（通常用点积来计算），
# 然后对相似度进行, softmax(行方向上)操作得到权重，最后将这个权重应用到每个元素的 Value 上，再将所有元素的加权 Value 求和
# 就得到了当前元素的输出。
class SimpleAttention(nn.Module):
    def __init__(self, dim, num_heads):
        super().__init__()
        self.num_heads = num_heads
        self.dim = dim  # dim是特征长度
        self.head_dim = dim // num_heads

    def forward(self, query, key, value, mask=None):
        B, _, N = query.size()  # N是序列长度

        # 将输入的Q、K、V拆分为多头。 num_heads多头、 head_dim每个头的特征维度、 N是序列长度
        query = query.view(B, self.num_heads, self.head_dim, N)
        key = key.view(B, self.num_heads, self.head_dim, N)
        value = value.view(B, self.num_heads, self.head_dim, N)


        # 计算注意力分数。计算query和key的点积（dot product）。点积是相似性度量方法，
        # 我们使用点积来衡量query和每个key之间的相似性，相似性越高，对应的value在最终的注意力输出中的权重就越大。
        # sqrt这部分是在对点积的结果进行缩放（scaling），用于防止点积的结果过大，导致softmax函数的梯度过小，从而影响模型的训练。
        attn_scores = torch.matmul(query, key.transpose(-2, -1)) / math.sqrt(self.head_dim)

        # 如果提供了mask，将其应用到注意力分数上
        if mask is not None:
            attn_scores = attn_scores.masked_fill(mask == 0, float('-inf'))

        # 计算注意力权重
        attn_weights = F.softmax(attn_scores, dim=-1)

        # 计算加权的V
        output = torch.matmul(attn_weights, value)

        # 合并多头
        output = output.contiguous().view(B, -1, N)

        return output


# 创建一个示例的多通道二维图片数据（4x4 像素，3个通道）
query = np.random.rand(3, 12, 12).astype(np.float32)
key = np.random.rand(3, 12, 12).astype(np.float32)
value = np.random.rand(3, 12, 12).astype(np.float32)

# 执行池化操作
SimpleAttention2 = SimpleAttention(dim=64, num_heads=8)
results = SimpleAttention2(query, key, value)

# 打印卷积结果
print(results.shape)