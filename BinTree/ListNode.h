/*******************************************************************
*  �ļ�����: ListNode.h
*  ��Ҫ����: ����ڵ�ṹ���������ʵ��
*
*  ��������: 2017��9��21��
*  ��    ��: �� ��
*  ˵    ��:
*
*  �޸�����:
*  ��    ��:
*  ˵    ��:
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
	preNode = x;				//˫��
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
