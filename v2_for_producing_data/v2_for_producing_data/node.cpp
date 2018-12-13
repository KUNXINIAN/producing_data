//
//  node.cpp
//  project_making_trace_data
//
//  Created by 李坤鑫 on 2018/10/22.
//  Copyright © 2018年 李坤鑫. All rights reserved.
//
#include "node.h"

double node::show_x_label() {
	return x;
};

double node::show_y_label() {
	return y;
};

void node::def_x_label(double a) {
	x = a;
};

void node::def_y_label(double b) {
	y = b;
};
