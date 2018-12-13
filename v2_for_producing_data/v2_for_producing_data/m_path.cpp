
#include <iostream>
#include <fstream>
#include "node.h"
#include <string>
#include <cmath>
#include "math.h"
#define PI 3.14159
#define SCALE 0.040171821
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

double delta_x();
string int_to_string(int a);
int making_num_steps(int x_or_y);
int making_theta_num(int standard_num);
const double long_step= 36.8;//设置标准步长数

int making_four_path(int set_theta1, int set_theta2, int set_theta3,int times) {
	double vertex_1_x, vertex_1_y, vertex_2_x, vertex_2_y,vertex_3_x,vertex_3_y;
	double vertex_1_x2, vertex_1_y2, vertex_2_x2, vertex_2_y2,vertex_3_x2, vertex_3_y2;
	int i, j,c;
	cout << "this is making four path function !" << endl;
	for(c=0;c<times;c++)
	{
		ofstream new_csv("machine_csv"+int_to_string(c)+".csv");
		if (new_csv) { cout << "--------------------------生成模拟路径csv成功-----------------------" << endl << endl; }
		if (!new_csv) { cout << "生成模拟路径csv失败" << endl; return -1; }
		//将随机生成角度步骤放到循环里面，保证每一组角度偏差是随机的
		int theta1 = making_theta_num(set_theta1);
		int theta2 = making_theta_num(set_theta2);
		int theta3 = making_theta_num(set_theta3);
		//生成当前走的步数
		int n1 = making_num_steps(0);
		int n2 = making_num_steps(1);
		//写入固定右下角坐标
		new_csv << 3133* SCALE << "," << 1843 * SCALE << ","<<3133 * SCALE <<","<<1843 * SCALE <<endl;
		//生成第一段
		for (i = 1; i <= n1; i++) {
			//机器数据部分
			node *new_node = new node;
			new_node->def_x_label(3133.00 + delta_x());
			new_node->def_y_label(1834.00 - long_step * i + delta_x());
			new_csv << new_node->show_x_label()* SCALE << "," << new_node->show_y_label() * SCALE << ",";
			if (i == n1) vertex_1_x2 = new_node->show_x_label(); vertex_1_y2 = new_node->show_y_label();
			delete new_node;
			//new_node = NULL;

			//标准数据部分
			node *new_node = new node;
			new_node->def_x_label(3133.00);
			new_node->def_y_label(1843.00 - i * long_step);
			new_csv << new_node->show_x_label() * SCALE << "," << new_node->show_y_label() * SCALE << endl;
			if (i == n1) vertex_1_x = new_node->show_x_label(); vertex_1_y = new_node->show_y_label();
			delete new_node;
			//new_node= NULL;

		
		}

		//生成第二段
		for (j = 1; j <= n2; j++) {
			node  *new_node2 = new node;
			new_node2->def_x_label(vertex_1_x2 + (j*long_step + delta_x())*sin(theta1*PI / 180));
			new_node2->def_y_label(vertex_1_y2 + (j*long_step + delta_x())*cos(theta1*PI / 180));
			if (j == n2) vertex_2_x2 = new_node2->show_x_label();  vertex_2_y2 = new_node2->show_y_label();
			new_csv << new_node2->show_x_label()* SCALE << "," << new_node2->show_y_label() * SCALE << ",";
			delete new_node2;
			//new_node = NULL;

			node *new_node = new node;
			new_node->def_y_label(vertex_1_y);
			new_node->def_x_label(vertex_1_x - j * long_step);
			if (j == n2) vertex_2_x = new_node->show_x_label();  vertex_2_y = new_node->show_y_label();
			new_csv << new_node->show_x_label()* SCALE << "," << new_node->show_y_label() * SCALE <<endl;
			delete new_node;
			//new_node = NULL;
			
		}

		//生成第三段
		for (i = 1; i <= n1; i++) {
			node *new_node = new node;
			new_node->def_x_label(vertex_2_x2 + (i*long_step + delta_x())*sin((theta2 + theta1)*PI / 180));
			new_node->def_y_label(vertex_2_y2 - (i*long_step + delta_x())*cos((theta1 + theta2)*PI / 180));
			if (i == n1) vertex_3_x2 = new_node->show_x_label(); vertex_3_y2 = new_node->show_y_label();
			new_csv << new_node->show_x_label() * SCALE << "," << new_node->show_y_label() * SCALE << ",";
			delete new_node;

			node *new_node = new node;
			new_node->def_x_label(vertex_2_x);
			new_node->def_y_label(vertex_2_y + i * long_step);
			new_csv << new_node->show_x_label() * SCALE << "," << new_node->show_y_label() * SCALE <<endl;
			if (i == n1) vertex_3_x = new_node->show_x_label(); vertex_3_y = new_node->show_y_label();
			delete new_node;
			//new_node = NULL;
			
		}
		//生成第四段
		for (j = 1; j <= n2; j++) {
			node *new_node2 = new node;
			new_node2->def_x_label(vertex_3_x2 + (j*long_step + delta_x())*sin((theta1 + theta2 + theta3)*PI / 180));
			new_node2->def_y_label(vertex_3_y2 + (j*long_step + delta_x())*cos((theta1 + theta2 + theta3)*PI / 180));
			new_csv << new_node2->show_x_label()* SCALE << "," << new_node2->show_y_label()* SCALE << ",";
			delete new_node2;
			//new_node= NULL;

			node *new_node = new node;
			new_node->def_y_label(vertex_3_y);
			new_node->def_x_label(vertex_3_x + j * long_step);
			new_csv << new_node->show_x_label()* SCALE << "," << new_node->show_y_label() * SCALE << endl;
			delete new_node;
			//new_node = NULL;
	    }
	}
	cout <<
		"-------------------------------------------------------------------------------------------------------------"<<endl<<
		"------------------------------------------生成所有路径完毕！-------------------------------------------------" << endl<<
		"-------------------------------------------------------------------------------------------------------------" << endl;
	return 0;
}
