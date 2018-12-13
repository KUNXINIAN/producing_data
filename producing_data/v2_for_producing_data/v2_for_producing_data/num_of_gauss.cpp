#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#define PI 3.14159
#define VAR_THETA 3  //偏转角方差
#include <iomanip>
#include <stdlib.h>

using namespace std;
void UNIFORM(double *);
int making_gauss_num(int mean, int var);
//以下函数生成高斯随机数，输入期望与方差，输出整数
int making_gauss_num(int mean, int var)//输入均值 方差
{
	int i, j;
	double A, B, C, E, D, r;
	double uni[2];
	double *p;
	//srand((unsigned)time(NULL));  //随机数种子采用系统时钟
	E = mean; D = var;
	UNIFORM(&uni[0]);  //调用UNIFORM函数产生2个均匀分布的随机数并存入数组nui[2]
	A = sqrt((-2)*log(uni[0]));
	B = 2 * PI*uni[1];
	C = A * cos(B);
	r = floor(E + C * D);    //E,D分别是期望和方差
	return r;
}
//以下函数为生成高斯数需要的函数
void UNIFORM(double *p)
{
	int i, a;
	double f;
	int x = 0;
	for (i = 0; i < 2; i++, x = x + 689)
	{
		a = rand() + x;  //加上689是因为系统产生随机数的更换频率远远不及程序调用函数的时间
		a = a % 1000;
		f = (double)a;
		f = f / 1000.0;
		*p = f;
		p++;
	}
}
//以下函数输入90度角度，输出带有噪声偏差的角度
int making_theta_num(int standard_num) {
	cout << "this is making theta nums" << endl;
	int num_real_steps = 0;
	cout << "本次输入标准角度为" << standard_num << endl;
	//使用高斯噪声对标准角度偏移
	num_real_steps = making_gauss_num(standard_num, VAR_THETA);
	cout << "本次输出仿真角度为" << num_real_steps << endl << endl;
	return num_real_steps;
}
//以下函数输入竖直或者横向行走，输出选择的步数,0为竖直方向，1为横向方向
int making_num_steps(int x_or_y) {
	//竖直方向上只能走35或者36步,横向只能走70步；
	int n1 = 0;
	if (x_or_y == 0) {
		if (making_gauss_num(0, 3) >= 0) {
			n1 = 35;
			cout << "竖直方向走了35步！！" << endl;
			return n1;
		}
		else {
			n1 = 36;
			cout << "竖直方向走了36步！！" << endl;
			return n1;
		}
	}
	if (x_or_y == 1) {
		n1 = 70;
		return n1;
	}
}