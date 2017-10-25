/******************************************************************* 
 *  文件名称: stack.h
 *  简要描述: 栈的声明与实现,size(),empty()可直接使用，以数组基址为栈底地址，
 *			 只有后插。
 *   
 *  创建日期: 2017年9月23日
 *  作    者: 幽 人
 *  说    明: 
 *   
 *  修改日期: 
 *  作    者: 幽 人
 *  说    明: 
 ******************************************************************/  

#include "vector.h"

template<typename T> class Stack :public Vector<T> {
public:
	void push(T const &e) { insert(size(), e); }
	T pop() {
		return remove(size() - 1);
	}
	T& top() { return (*this)[size() - 1]; }
};