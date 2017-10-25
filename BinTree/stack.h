/******************************************************************* 
 *  �ļ�����: stack.h
 *  ��Ҫ����: ջ��������ʵ��,size(),empty()��ֱ��ʹ�ã��������ַΪջ�׵�ַ��
 *			 ֻ�к�塣
 *   
 *  ��������: 2017��9��23��
 *  ��    ��: �� ��
 *  ˵    ��: 
 *   
 *  �޸�����: 
 *  ��    ��: �� ��
 *  ˵    ��: 
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