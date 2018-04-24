 ///
 /// @file    Line.h
 /// @author  ICIOfg
 /// @date    2018-04-18 22:19:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;


#ifndef __LINE_H__
#define __LINE_H__

class Line
{
	public:
		Line(int x1, int y1, int x2, int y2);
		~Line();

		void display() const;
	private:
		//设计模式之pimpl
		//1，实现信息隐藏
		//2，当库需要升级时，可以以最小代价完成库的升级
		//3，减小编译依赖
		
		class LineImpl; //类的前向声明
	private:
		LineImpl * pImpl;
};

#endif

