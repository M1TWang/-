/*******************************************************************
*  文件名称: ListNode.h
*  简要描述: 链表节点结构体的声明与实现
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
#define ListPosition(T) ListNode<T>*

template<typename T> class ListNode {
public:
	ListNode() {};
	ListNode(T e, ListPosition(T) p = 0, ListPosition(T) s = 0)
		:data(e), preNode(p), backNode(s){}
	~ListNode() {};
	T data;
	ListPosition(T) preNode;
	ListPosition(T) backNode;

	ListPosition(T) insertAsPre(T const &e);
	ListPosition(T) insertAsBack(T const &e);
};

template<typename T>
ListPosition(T) ListNode<T>::insertAsPre(T const & e)
{
	ListPosition(T) x = new ListNode(e, preNode, this);
	preNode->backNode = x;
	preNode = x;				//双向
	return x;
}


template<typename T>
ListPosition(T) ListNode<T>::insertAsBack(T const & e)
{
	ListPosition(T) x = new ListNode(e, this, backNode);
	backNode->preNode = x;
	backNode = x;
	return x;
}
