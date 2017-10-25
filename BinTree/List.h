/*******************************************************************
*  文件名称: List.h
*  简要描述: List模板的声明与实现
*
*  创建日期: 2017年9月21日
*  作    者: 幽 人
*  说    明:
*
*  修改日期:
*  作    者:
*  说    明:
******************************************************************/

#pragma once
#include<iostream>
#include"ListNode.h"

template<typename T> class List {
private:
	int _size; ListPosition(T) header;ListPosition(T) trailer;//规模，头哨兵，尾哨兵
public:
	List() {
		init();
	}
	~List() {
		delete header, trailer;
	}
	//List(List<T> const & L);

	int size() { return _size; }
	bool empty() { return _size <= 0; }
	ListPosition(T) first() const { return header->backNode; }
	ListPosition(T) last() const { return trailer->preNode; }
	ListPosition(T) find(T const &e, int n, ListPosition(T) p)const;

	ListPosition(T) insertAsFirst(T const & e); //将e当作首节点插入
	ListPosition(T) insertAsLast(T const & e); //将e当作末节点插入
	ListPosition(T) insertBefore(ListPosition(T) p, T const & e); //将e当作p的前驱插入
	ListPosition(T) insertAfter(ListPosition(T) p, T const & e); //将e当作p的后继插入

	void clear();
	T remove(ListPosition(T) p);
	void merge(ListPosition(T)& p, int m, List<T>& L, ListPosition(T)& q, int n);
protected:
	void init();
	/*int clear();
	
	void mergeSort(ListPosition(T)&, int);*/
};

template<typename T>
ListPosition(T) List<T>::find(T const & e, int n, ListPosition(T) p) const
{
	while (0 < n--) {
		if (e == (p = p->preNode)->data) return p;
	}
	return 0;
}
template<typename T>
ListPosition(T) List<T>::insertAsFirst(T const & e)
{
	_size++;
	return header->insertAsBack(e);
}

template<typename T>
ListPosition(T) List<T>::insertAsLast(T const & e)
{
	_size++;
	return trailer->insertAsPre(e);
}

template<typename T>
ListPosition(T) List<T>::insertBefore(ListPosition(T) p, T const & e)
{
	_size++;
	return p->insertAsPre(e);
}

template<typename T>
ListPosition(T) List<T>::insertAfter(ListPosition(T) p, T const & e)
{
	_size++;
	return p->insertAsBack(e);
}

template<typename T>
inline void List<T>::clear()
{
	while (0<_size) {
		remove(header->backNode);
	}
}

template<typename T>
inline T List<T>::remove(ListPosition(T) p)
{
	T e = p->data;
	p->preNode->backNode=p->backNode;
	p->backNode->preNode = p->preNode;
	delete p; _size--;
	return e;
}

template<typename T>
void List<T>::merge(ListPosition(T)& p, int n, List<T>& L, ListPosition(T)& q, int m)
{
	ListPosition(T) pp = p->preNode;
	while (0 < m) {
		if ((0 < n) && p->data <= q->data)
		{
			if (q == (p = p->backNode)) break; n--;
		}
		else {
			insertBefore(p, L.remove((q = q->backNode)->preNode)); m--;
		}
	}
	p = pp->backNode;
}

template<typename T>
void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->backNode = trailer; header->preNode = NULL;
	trailer->preNode = header; trailer->backNode = NULL;
	_size = 0;
}