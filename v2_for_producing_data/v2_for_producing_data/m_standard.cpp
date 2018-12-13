//以下函数生成标准路径坐标并且写入standard_label.txt
#include <iostream>
#include "node.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#define PI 3.14159
#include <iomanip>
#include <stdlib.h>

using namespace std;


int making_standard_label() {
	cout << "this is making standard label" << endl;
	ofstream txt("standard_label.txt");
	ofstream standard_csv("standard_csv.csv");
	if (txt) { cout << "生成标准路径txt成功" << endl << endl; }
	if (!txt) { cout << "生成标准路径txt失败" << endl; return -1; }
	for (int i = 0; i <= 36; i++) {
		node *new_node = new node;
		new_node->def_x_label(3133.00);
		double templ = (1843 - 532) / 36.00;
		new_node->def_y_label(1843.00 - i * templ);
		txt << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
		standard_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
		delete new_node;
	}
	for (int j = 1; j <= 70; j++) {
		node *new_node = new node;
		new_node->def_y_label(532.00);
		double templ = (3133 - 532) / 70.00;
		new_node->def_x_label(3133 - j * templ);
		txt << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
		standard_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
		delete new_node;

	}
	for (int i = 1; i <= 36; i++) {
		node *new_node = new node;
		new_node->def_x_label(532);
		double templ = (1843 - 532) / 36.00;
		new_node->def_y_label(532 + i * templ);
		txt << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
		standard_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
		delete new_node;
	}
	for (int j = 1; j <= 70; j++) {
		node *new_node = new node;
		new_node->def_y_label(1843);
		double templ = (3133 - 532) / 70.00;
		new_node->def_x_label(532 + j * templ);
		txt << new_node->show_x_label() << "\t" << new_node->show_y_label() << endl;
		standard_csv << new_node->show_x_label() << "," << new_node->show_y_label() << endl;
		delete new_node;

	}    return 0;
}