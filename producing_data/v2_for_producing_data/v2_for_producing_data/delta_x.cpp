#include <cmath>
#include <math.h>
#include <time.h>
#define E_DELTA 0   //抖动量期望
#define D_DELTA 3  //抖动量方差

void UNIFORM(double *p);
#define PI  3.14159
double delta_x() {
	int i, j;
	double A, B, C, E, D, r;
	double uni[2];
	double *p;
	//srand((unsigned)time(NULL));  //随机数种子采用系统时钟
	E = E_DELTA; D = D_DELTA;//均值与方差赋值
	UNIFORM(&uni[0]);  //调用UNIFORM函数产生2个均匀分布的随机数并存入数组nui[2]
	A = sqrt((-2)*log(uni[0]));
	B = 2 * PI*uni[1];
	C = A * cos(B);
	r = E + C * D;    //E,D分别是期望和方差
	return r;
}