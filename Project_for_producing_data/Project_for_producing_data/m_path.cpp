
#include <iostream>
#include <fstream>
#include "node.h"
#include <string>
#include <cmath>
#include "math.h"
#define PI 3.14159
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>
double delta_x();
using namespace std;

int making_four_path(int theta1, int theta2, int theta3,int n1,int n2,int n3,int n4,int times) {
	double vertex_1_x, vertex_1_y, vertex_2_x, vertex_2_y;
	int i, j;
	double long_1 = double(1311 / n1);
	double long_2 = double(2601 / n2);
	cout << "this is making four path" << endl;

		ofstream txt_2("machine_label.txt");
		ofstream new_csv("machine_csv.csv");
		if (txt_2) { cout << "生成模拟路径txt成功" << endl << endl; }
		if (!txt_2) { cout << "生成模拟路径txt失败" << endl; return -1; }
		if (new_csv) { cout << "生成模拟路径csv成功" << endl << endl; }
		if (!new_csv) { cout << "生成模拟路径csv失败" << endl; return -1; }
		//写入固定右下角坐标
		txt_2 << 3133 << "\t" << 1843 << endl;
		new_csv << 3133 << "," << 1843 << endl;

		//生成第一段
		for (i = 1; i < n1; i++) {
			node *new_node = new node;
			new_node->def_x_label(3133.00 + delta_x());
			new_node->def_y_label(1834.00 - long_1 * i + delta_x());
			txt_2 << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
			new_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
			delete new_node;
		}
		//写入固定右上角坐标
		txt_2 << 3133 << "\t" << 532 << endl;
		new_csv << 3133 << "," << 532 << endl;

		//生成第二段
		for (j = 1; j <= n2; j++) {
			node  *new_node = new node;
			new_node->def_x_label(3133.00 + (j*long_2 + delta_x())*sin(theta1*PI /180));
			new_node->def_y_label(532.00 + (j*long_2 + delta_x())*cos(theta1*PI / 180));
			if (j == 70) vertex_1_x = new_node->show_x_label(); vertex_1_y = new_node->show_y_label();
			txt_2 << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
			new_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
			delete new_node;
		}

		//生成第三段
		for (i = 1; i <= n3; i++) {
			node *new_node = new node;
			new_node->def_x_label(vertex_1_x + (i*long_1 + delta_x())*sin((theta2 + theta1)*PI / 180));
			new_node->def_y_label(vertex_1_y - (i*long_1 + delta_x())*cos((theta1 + theta2)*PI / 180));
			if (i == 36) vertex_2_x = new_node->show_x_label(); vertex_2_y = new_node->show_y_label();
			txt_2 << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
			new_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
			delete new_node;
		}
		//生成第四段
		for (j = 1; j <= n4; j++) {
			node *new_node = new node;
			new_node->def_x_label(vertex_2_x + (j*long_2 + delta_x())*sin((theta1 + theta2 + theta3)*PI / 180));
			new_node->def_y_label(vertex_2_y + (j*long_2 + delta_x())*cos((theta1 + theta2 + theta3)*PI / 180));
			txt_2 << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
			new_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
			delete new_node;
		}
	

	cout << "生成四段路径完毕！" << endl;
	return 0;
}
