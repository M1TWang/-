/******************************************************************* 
 *  文件名称: BinTree.h
 *  简要描述: 二叉树的声明
 *   
 *  创建日期: 2017年10月21日
 *  作    者: 幽 人
 *  说    明: 
 *   
 *  修改日期: 
 *  作    者: 幽 人
 *  说    明: 
 ******************************************************************/  

#include"BinNode.h"
#include"enqueue.h"
#include"stack.h"

struct BinTree {
	int _size;					//规模
	BinNodePosi _root;			//根节点
};

void InitBinTree(BinTree* t);			//初始化二叉树
//void updateHeight(BinTree* t, BinNodePosi p);
int const size(BinTree* t);				//二叉树节点总数
bool const Empty(BinTree* t);			//判断是否为空树
int remove(BinTree* t, BinNodePosi p);	//删除根节点为p的子树
BinNodePosi const root(BinTree* t);		//获取根节点
BinNodePosi insertRoot(BinTree* t,ElemType e);	//插入根节点
BinNodePosi insertAsLC(BinTree* t, BinNodePosi p,ElemType e); //以p结点的左孩子插入新节点
BinNodePosi insertAsRC(BinTree* t, BinNodePosi p,ElemType e); //以p结点的右孩子插入新节点
void TravLeave(BinTree* t);		//层序遍历
void TravPre(BinNodePosi p);			//先序遍历
void TravPre_iter(BinNodePosi p);
void TravIn(BinNodePosi p);			//中序遍历
void TravIn_iter(BinNodePosi p);
void TravPost(BinNodePosi p);		//后序遍历
void TravPost_iter(BinNodePosi p);
void visit(ElemType e);