import numpy

# 二维输出
A_matrix = numpy.mat("1,2,3; 4,5,2; 7,8,9")
B_matrix = numpy.mat("1,2,3; 4,5,2; 7,8,9")
print("原矩阵：\n", A_matrix.A)

# 转置矩阵
A_matrix_T = A_matrix.T
print("转置矩阵为：\n", A_matrix_T)

# 共轭转置矩阵
A_matrix_H = A_matrix.H
print("共轭转置矩阵为：\n", A_matrix_H)

# 逆矩阵
A_matrix_N = A_matrix.I
print("逆矩阵为：\n", A_matrix_N)

# 矩阵乘法
A_nm = numpy.mat("1,2,3; 4,5,6; 7,8,9")
B_kl = numpy.mat("7,8,9; 1,2,3; 4,5,6")
# 方法一：已经定义为矩阵的情况下，直接用乘号
print("矩阵乘法A*B = \n", A_nm*B_kl)
# 方法二：如果没有定义为矩阵，而是定义为二维数组，但需要用矩阵的乘法（而不是简单的对应元素相乘），那么需要用dot()
A = numpy.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])
B = numpy.array([
    [7, 8, 9],
    [1, 2, 3],
    [4, 5, 6]
])
print("二维数组对应相乘：\n", A*B)
print("二维数组矩阵乘法dot(A,B) = \n", numpy.dot(A,B))