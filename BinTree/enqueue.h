/*******************************************************************
*  �ļ�����: enqueue.h
*  ��Ҫ����: ���л��������ʵ��
*
*  ��������: 2017��9��28��
*  ��    ��: �� ��
*  ˵    ��:
*
*  �޸�����:
*  ��    ��: �� ��
*  ˵    ��:
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
