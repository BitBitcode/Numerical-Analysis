

def matrix_multiplication(A, B):
    """
    【函数】
    
    功能：计算矩阵乘法

    参数：
    + A：[list 二维列表] 矩阵A的二维列表
    + B：[list 二维列表] 矩阵B的二维列表
    
    返回值：
    + [list 二维列表] 相乘后的矩阵
    2020.12.20
    """
    m = len(A)  # 获取A矩阵的行数
    n = len(B[1])  # 获取B矩阵的列数
    # 考虑加入检验矩阵格式是否正确的代码
    S = []
    i = 0
    j = 0
    for i in range(m):
        S.append([])
        for j in range(n):
            S[i].append(0)
    if(m != n):
        print("【ERROR】乘法错误，行列数不满足要求！")
    elif(m == n):
        i = 0
        j = 0
        while(i<m):
            j = 0
            while(j<n):
                k = 0
                while(k<m):
                    S[i][j] = S[i][j] + A[j][k]*B[k][i]
                    k = k + 1
                j = j + 1
            i = i + 1
    return S

a11 = 1
a12 = 2
a13 = 3
a21 = 4
a22 = 5
a23 = 6
a31 = 7
a32 = 8
a33 = 9

A = [[a11, a12, a13],
    [a21, a22, a23],
    [a31, a32, a33]]

B = [[a11, a21, a31],
    [a12, a22, a32],
    [a13, a23, a33]]

AB = matrix_multiplication(A, B)

# 打印为二维形式
i = 0
j = 0
m = len(AB)
for i in range(m):
    print(AB[i])
    i = i + 1