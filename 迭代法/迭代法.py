# 牛顿迭代法
# 【问题中涉及的方程】
# 1
# 原方程
def f_1(x):
    y = 2*x**3 + x - 8
    return y

# 导数
def f_diff_1(x):
    y = 6*x**2 + 1
    return y

# 2
# 原方程
def f_2(x):
    y = x**3 + 4*x**2 - 10
    return y

# 导数
def f_diff_2(x):
    y = 3*x**2 + 8*x
    return y

E = 0.001 # 精度（误差限）
x_0 = 1.5 # 初值

# 牛顿迭代格式
def Newton_iteration(x, m=1):
    """
    【函数】
    
    功能：牛顿迭代法

    参数：
    + x：[float 浮点型] 第n次迭代值
    + x：[int 整型] 重根、下山系数
    
    返回值：
    + [float 浮点型] 第n+1次迭代值
    """
    x_next = x - m*(f_1(x)/f_diff_1(x))
    return x_next

x_n = x_0
x_l = 0
while(abs(x_n - x_l) >= E):
    x_l = x_n
    x_n = Newton_iteration(x_n)
    print("[Runing]")
# x_next = Newton_iteration(1.36523)
print("数值解为：", x_n)