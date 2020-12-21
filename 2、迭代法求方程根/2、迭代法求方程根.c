// 2、迭代法求方程根


#include<stdio.h>
#include<math.h>
#define PRECISION (0.000001)	// 设置精度


// 【数学函数 1】教材 P23 例2.1
double function_1(double x)
{
	double y = 0;
	y = x * x * x + 4 * x * x - 10;
	return y;
}


// 【数学函数 2】教材 P 例
double function_2(double x)
{
	double y = 0;
	y = x;		// 修改此处的表达式即可
	return y;
}



// 【通用函数】起到传递参数的作用，可以不用修改主函数中的代码，直接修改此处调用的数学表达式函数即可
// 【注意】如果不声明，则只能定义在最后（否则本函数调用的其他函数会无法识别）
double f(double x_value)
{
	return function_1(x_value);		// 修改此处调用的数学函数来求解不同的方程
}


// 【主函数】
int main()
{
	float a = 0;		// 区间左端点
	float b = 0;		// 区间右端点
	int select = 0;		// 
	float m = 0;		// 区间中点
	float e_y = 1;		// y的绝对误差限
	int k = 0;			// 循环次数

RE: // 循环标签
	printf("请输入隔根区间 [a,b] 的端点值\n");
	printf("a = ");
	scanf_s("%f", &a);
	printf("b = ");
	scanf_s("%f", &b);

	// 判别用户输入的区间是否有根
	if (f(a) * f(b) < 0)
	{
		printf("\n【核对】将在 [%f,%f] 区间求解，当前精度设置为：%f\n", a, b, PRECISION);
		printf("确认请按 1，重新输入请按 2\n");
		scanf_s("%d", &select);
		if (select == 2)
		{
			goto RE;	// 重新输入
		}
		else if (select == 1)
		{
			printf("请稍后。。。\n\n");
		}
	}
	else if (f(a) * f(b) >= 0)
	{
		printf("【错误】该区间没有根，请重现输入！\n\n");
		goto RE;	// 重新输入
	}

	// 二分法
	do
	{
		k++;		// 循环次数记录
		m = a + (b - a) / 2;		// 或者：m = (a + b) / 2
		printf("【%d】\n", k);
		printf("m = %f\n", m);
		printf("f(a) = %f\n", f(a));
		printf("f(m) = %f\n", f(m));
		printf("f(b) = %f\n", f(b));

		if (f(a) * f(m) < 0)
		{

			b = m;
		}
		else if (f(m) * f(b) < 0)
		{
			a = m;

		}
		else if (f(m) == 0)
		{
			break;
		}
		else
		{
			printf("【错误】\n\n");
		}

		//e_y = abs((f(m) * 100000000 - 0));
		e_y = abs((m - 1.3647461) * 100000000);	// 乘以一个大数，否则小数点后位数过多，无法计算（避免很小的数相减）

	} while (e_y > PRECISION * 100000000);

	printf("\n【完成】\n满足设定精度的数值解为：x = %f\n", m);
	printf("误差为：f(x) - 0 = %f * 10^-8\n", e_y);
	printf("循环次数（k）为：%d\n", k);

	return 0;
}