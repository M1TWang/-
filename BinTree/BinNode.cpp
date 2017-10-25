#include "BinNode.h"

/*************************************************
将新节点作为p结点的左孩子插入
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
将新节点作为p结点的右孩子插入
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
判断p结点是否为根节点
**************************************************/
bool IsRoot(BinNodePosi p)
{
	return (p->parent) ? true : false;
}

/*************************************************
判断p结点是否为左孩子
**************************************************/
bool IsLChild(BinNodePosi p)
{
	return (!IsRoot(p) && ((p) == (p)->parent->lChild));
}

/*************************************************
判断p结点是否为右孩子
**************************************************/
bool IsRChild(BinNodePosi p)
{
	return (!IsRoot(p) && ((p) == (p)->parent->lChild));
}

/*************************************************
判断p结点是否有孩子结点
**************************************************/
bool HasChild(BinNodePosi p)
{
	return (p->lChild || p->rChild);
}

/*************************************************
判断p结点为根结点的子孙结点数目
**************************************************/
int size(BinNodePosi p)
{
	int s = 1;
	if (p->lChild)s += size(p->lChild);
	if (p->rChild)s += size(p->rChild);
	return s;
}
