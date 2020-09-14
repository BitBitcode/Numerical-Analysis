// 1、二分法求方程根


#include<stdio.h>
#include<math.h>
#define PRECISION (0.001)	// 设置精度


// 【数学函数】教材 P23 例2.1
double function_1(double x)
{
	double y = 0;
	y = x * x * x + 4 * x * x - 10;
	return y;
}


// 【数学函数】教材 P 例



// 【通用函数】起到传递参数的作用，可以不用修改主函数中的代码，直接修改此处调用的数学表达式函数即可
// 【注意】如果不声明，则只能定义在最后（否则本函数调用的其他函数会无法识别）
double f(double x_value)
{
	return function_1(x_value);
}


// 【主函数】
int main()
{
	float a = 0;		// 区间左端点
	float b = 0;		// 区间右端点
	int select = 0;		// 
	float m = 0;		// 区间中点
	float e_y = 1;		// y的绝对误差限

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
		m = a + (b - a) / 2;		// 或者：m = (a + b) / 2
		printf("m = %f\n", m);
		printf("f(a) = %f\n", f(a));
		printf("f(m) = %f\n", f(m));
		printf("f(b) = %f\n", f(b));

		if (f(a) * f(m) < 0)
		{
			
			b = m;
			printf("【1】\n");
		}
		else if (f(m) * f(b) < 0)
		{
			a = m;
			printf("【2】\n");
		}
		else if (f(m) == 0)
		{
			printf("【3】\n");
			break;
		}
		else
		{
			printf("【错误】\n\n");
		}
		
		e_y = abs(f(m) - 0);
	} while (e_y > PRECISION); 

	printf("\n【完成】\n满足设定精度的数值解为：x = %0.3f\n", m);
	printf("误差为：f(x) - 0 = %f\n", e_y);

	return 0;
}