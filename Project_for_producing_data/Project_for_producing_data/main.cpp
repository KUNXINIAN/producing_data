//
//  main.cpp
//  project_making_trace_data
//
//  Created by 李坤鑫 on 2018/10/22.
//  Copyright © 2018年 李坤鑫. All rights reserved.
//


#include <iostream>
#include "node.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#define PI  3.14159
#include <iomanip>
#include <stdlib.h>

#define N1 36//以下四个数定义四段路径分别走的步数
#define N2 70
#define N3 36
#define N4 70
#define TIMES 10 //定义生成仿真数据条数

using namespace std;

int making_gauss_num(int mean, int var, int num_br);//生成随机数函数声明
int  making_theta_num(int standard_num);
void UNIFORM(double *);  //UINFORM函数声明
int making_standard_label();//生成标准路径函数声明
int making_four_path(int theta1, int theta2, int theta3, int n1, int n2, int n3, int n4, int times);//生成四段路径函数声明
double delta_x();//生成抖动量函数


int main() {
	srand((unsigned)time(NULL));//将srand置于循环外部
	//生成标准路径作为LABEL，写入txt
	making_standard_label();
	//生成模拟角度
	int theta1 = making_theta_num(-90);
	int theta2 = making_theta_num(-90);
	int theta3 = making_theta_num(-90);
	//生成四段路径坐标，从（3133，1843）开始，到（3133，532）两点应固定，坐标点加上高斯噪声抖动,仿真结果写入csv文件
	making_four_path(theta1,theta2,theta3,N1,N2,N3,N4,TIMES);
	system("pause");
}