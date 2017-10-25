#include "BinNode.h"

/*************************************************
���½ڵ���Ϊp�������Ӳ���
**************************************************/
BinNodePosi insertAsLC(BinNodePosi p,ElemType e)
{
	p->lChild = (BinNode*)malloc(sizeof(BinNode));
	p->lChild->data = e;
	p->lChild->parent = p;
	p->lChild->lChild = NULL;
	p->lChild->rChild = NULL;
	return p->lChild;
}

/*************************************************
���½ڵ���Ϊp�����Һ��Ӳ���
**************************************************/
BinNodePosi insertAsRC(BinNodePosi p,ElemType e)
{
	p->rChild = (BinNode*)malloc(sizeof(BinNode));
	p->rChild->data = e;
	p->rChild->parent = p;
	p->rChild->lChild = NULL;
	p->rChild->rChild = NULL;
	return p->rChild;
}

/*************************************************
�ж�p����Ƿ�Ϊ���ڵ�
**************************************************/
bool IsRoot(BinNodePosi p)
{
	return (p->parent) ? true : false;
}

/*************************************************
�ж�p����Ƿ�Ϊ����
**************************************************/
bool IsLChild(BinNodePosi p)
{
	return (!IsRoot(p) && ((p) == (p)->parent->lChild));
}

/*************************************************
�ж�p����Ƿ�Ϊ�Һ���
**************************************************/
bool IsRChild(BinNodePosi p)
{
	return (!IsRoot(p) && ((p) == (p)->parent->lChild));
}

/*************************************************
�ж�p����Ƿ��к��ӽ��
**************************************************/
bool HasChild(BinNodePosi p)
{
	return (p->lChild || p->rChild);
}

/*************************************************
�ж�p���Ϊ��������������Ŀ
**************************************************/
int size(BinNodePosi p)
{
	int s = 1;
	if (p->lChild)s += size(p->lChild);
	if (p->rChild)s += size(p->rChild);
	return s;
}
