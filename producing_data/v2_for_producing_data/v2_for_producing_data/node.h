#pragma once//
//  node.hpp
//  project_making_trace_data
//
//  Created by 李坤鑫 on 2018/10/22.
//  Copyright © 2018年 李坤鑫. All rights reserved.
//

#ifndef node_h
#define node_h

#include <stdio.h>
class node {
public:
	double show_x_label();
	double show_y_label();
	void def_x_label(double a = 0);
	void def_y_label(double b = 0);
private:
	double x = 0.0;
	double y = 0.0;

};

#endif /* node_hpp */

