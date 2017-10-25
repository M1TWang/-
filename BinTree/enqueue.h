/*******************************************************************
*  文件名称: enqueue.h
*  简要描述: 队列基于链表的实现
*
*  创建日期: 2017年9月28日
*  作    者: 幽 人
*  说    明:
*
*  修改日期:
*  作    者: 幽 人
*  说    明:
******************************************************************/

#include "List.h"

template<typename T> class Enqueue : public List<T>{
public:
	void enqueue(T const& e);
	T dequeue();
	T& front();
};

template<typename T>
inline void Enqueue<T>::enqueue(T const & e)
{
	insertAsLast(e);
}

template<typename T>
inline T Enqueue<T>::dequeue()
{
	return remove(this->first());
}

template<typename T>
inline T & Enqueue<T>::front()
{
	return this->first()->data;
}
