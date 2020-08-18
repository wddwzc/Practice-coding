
torch.autograd

Torch.Tensor是程序包的中心类。如果将其属性.requires_grad设置为True，它将开始跟踪对其的所有操作。

调用.backward()并自动计算所有梯度。该张量的梯度将累积到.grad属性中。

tensor如果是标量，无须参数；如果不是，则需要指定梯度参数来指定张量的形状

调用.detach() 将张量从计算历史中分离出来，并防止跟踪将来的计算。

调用.requires_grad_(...) 改变张量的 requires_grad flag，默认为false

with torch.no_grad(): 为了防止跟踪历史记录（和使用内存），这在评估模型时特别有用，因为模型可能具有可训练的参数，且require_grad = True，但我们不需要梯度

张量和函数相互连接并建立一个非循环图，该图对完整的计算历史进行编码。每个张量都有一个.grad_fn属性，该属性引用创建了张量的函数（用户创建的张量除外-它们的grad_fn为None）

A typical training procedure for a neural network is as follows:

1. Define the neural network that has some learnable parameters (or weights)
2. Iterate over a dataset of inputs
3. Process input through the network
4. Compute the loss (how far is the output from being correct)
5. Propagate gradients back into the network’s parameters
6. Update the weights of the network, typically using a simple update rule: weight = weight - learning_rate * gradient

LeNet示例：
```python
import torch
import torch.nn as nn
import torch.nn.functional as F


class Net(nn.Module):

    def __init__(self):
        super(Net, self).__init__()
        # 1 input image channel, 6 output channels, 3x3 square convolution
        # kernel
        self.conv1 = nn.Conv2d(1, 6, 3)
        self.conv2 = nn.Conv2d(6, 16, 3)
        # an affine operation: y = Wx + b
        self.fc1 = nn.Linear(16 * 6 * 6, 120)  # 6*6 from image dimension
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):
        # Max pooling over a (2, 2) window
        x = F.max_pool2d(F.relu(self.conv1(x)), (2, 2))
        # If the size is a square you can only specify a single number
        x = F.max_pool2d(F.relu(self.conv2(x)), 2)
        x = x.view(-1, self.num_flat_features(x))
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return x

    def num_flat_features(self, x):
        size = x.size()[1:]  # all dimensions except the batch dimension
        num_features = 1
        for s in size:
            num_features *= s
        return num_features


net = Net()
input = torch.randn(1, 1, 32, 32)
out = net(input)    # callback forward()

target = torch.randn(10)
target = target.view(1, -1)
criterion = nn.MSELoss()
loss = criterion(output, target)    # calculate the loss between output and target

net.zero_grad() # Zero the gradient buffers of all parameters, else grad will be accumulated to existing grad
out.backward(torch.randn(1, 10))    # backprops with random gradients:
loss.backward()     # backprops with loss

# 计算基于当前梯度调整后的参数
learning_rate = 0.01
for f in net.parameters():
    f.data.sub_(f.grad.data * learning_rate)
# torch提供了一些更新规则，如下为使用SGD
import torch.optim as optim
optimizer = optim.SGD(net.parameters(), lr=0.01)
optimizer.step()    # Does the update
```

上文提及的类型
1. torch.Tensor-一个多维数组，支持诸如backward（）之类的autograd操作。 还保持张量梯度。
2. nn.Module-神经网络模块。 方便的参数封装方式，并带有将它们移动到GPU，导出，加载等的辅助工具。
3. nn.Parameter-一种Tensor，在将其作为属性分配给Module时会自动注册为参数。 
4. autograd.Function-实现autograd操作的正向和反向定义。每个Tensor操作都会创建至少一个Function节点，该节点连接到创建Tensor并对其历史进行编码的函数。


加载数据集：

python库加载 -> numpy array -> torch.*Tensor

torchvision: torchvision.datasets torch.utils.data.DataLoader

