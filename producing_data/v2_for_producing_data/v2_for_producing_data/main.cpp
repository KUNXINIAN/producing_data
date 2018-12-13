//
//  main.cpp
//  project_making_trace_data
//
//  Created by 李坤鑫 on 2018/10/22.
//  Copyright © 2018年 李坤鑫. All rights reserved.
//
//版本2，生成标准数据路径为随机矩形
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------->在main.cpp里修改 生成文件数量值 TIMES；delta_x.cpp里修改抖动量 期望、方差；num_of_gauss.cpp里修改 偏转角方差<-------------------------------------

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "node.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#define TIMES 10 //定义生成仿真数据条数
using namespace std;

int making_four_path(int theta1, int theta2, int theta3,int times);//生成四段路径函数声明

int main() {
	srand((unsigned)time(NULL));
	//生成四段路径坐标，从（3133，1843）开始固定，坐标点加上高斯噪声抖动,仿真结果写入csv文件
	making_four_path(-90,-90,-90,TIMES);
	system("pause");
}