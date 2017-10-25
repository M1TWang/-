/******************************************************************* 
 *  文件名称: BinNode.h
 *  简要描述: 树结点的声明
 *   
 *  创建日期: 2017年10月21日
 *  作    者: 幽 人
 *  说    明: 
 *   
 *  修改日期: 
 *  作    者: 
 *  说    明: 
 ******************************************************************/  
#include<stdio.h>
#include<stdlib.h>
#define BinNodePosi BinNode*
#define ElemType char

struct BinNode {
	ElemType data;
	BinNodePosi parent;		//父结点指针
	BinNodePosi lChild;		//左孩子指针
	BinNodePosi rChild;		//右孩子指针
};

BinNodePosi insertAsLC(BinNodePosi p,ElemType e);	//将新节点作为p结点的左孩子插入
BinNodePosi insertAsRC(BinNodePosi p,ElemType e);	//将新节点作为p结点的右孩子插入
bool IsRoot(BinNodePosi p);							//判断是否为根节点
bool IsLChild(BinNodePosi p);						//判断是否为左孩子
bool IsRChild(BinNodePosi p);						//判断是否为右孩子
bool HasChild(BinNodePosi p);						//判断是否有孩子结点
int size(BinNodePosi p);							//返回以p结点为根节点的所有子孙结点的数目