 ///
 /// @file    inline.h
 /// @author  ICIOfg
 /// @date    2018-04-10 20:38:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#ifndef __INLINE_H__
#define __INLINE_H__
//inline函数与带参数的宏定义的区别
//
//1.带参数的宏定义也是简单的字符串替换
//		一般要给参数带上括号，防止表达式参数替换时因为乘除加减运算规则
//		改变原计划运算顺序
//		例如：1+2*3和（1+2）*（3）
//2.inline函数还是一个函数，有函数的检查机制，使用起来更安全，推荐使用

#define Max(x,y) ((x) > (y) ? (x) : (y))
#define getvalue(x, y) ((x) * (y))

inline
int func( int x, int y)
{
	return x * y;
}

#endif
