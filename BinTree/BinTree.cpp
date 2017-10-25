#include "BinTree.h"

/*************************************************
初始化二叉树
**************************************************/
void InitBinTree(BinTree * t)
{
	t->_root = NULL;
	t->_size = 0;
}

/*************************************************
返回该树所有节点数
**************************************************/
int const size(BinTree* t)
{
	return t->_size;
}

/*************************************************
判断该树是否为空树
**************************************************/
bool const Empty(BinTree * t)
{
	return t->_size==0;
}

/*************************************************
删除以p结点为根节点的所有子孙结点
**************************************************/
int remove(BinTree * t, BinNodePosi p)
{
	int n = size(p);
	t->_size -= n;
	return n;		//返回删除的结点个数
}

/*************************************************
返回根节点地址
**************************************************/
BinNodePosi const root(BinTree* t)
{
	return t->_root;
}

/*************************************************
插入根节点
**************************************************/
BinNodePosi insertRoot(BinTree * t,ElemType e)
{
	t->_size++;
	t->_root = (BinNode*)malloc(sizeof(BinNode));
	t->_root->parent = NULL;
	t->_root->lChild = NULL;
	t->_root->rChild = NULL;
	t->_root->data = e;
	return t->_root;
}

/*************************************************
将新节点作为p结点的右孩子插入
**************************************************/
BinNodePosi insertAsRC(BinTree * t, BinNodePosi p,ElemType e)
{
	t->_size++;
	return insertAsRC(p, e);
}

/*************************************************
层序遍历
**************************************************/
void TravLeave(BinTree* t)
{
	Enqueue<BinNodePosi> Q;
	Q.enqueue(t->_root);
	while (!Q.empty()) {
		BinNodePosi x = Q.dequeue();
		visit(x->data);
		if (HasChild(x)) {
			if (x->lChild)Q.enqueue(x->lChild);
			if(x->rChild)Q.enqueue(x->rChild);
		}
	}
}

/*************************************************
先序遍历的递归实现
**************************************************/
void TravPre(BinNodePosi p)
{
	if (!p)return;
	visit(p->data);
	TravPre(p->lChild);
	TravPre(p->rChild);
}

/*************************************************
先序遍历的迭代实现
**************************************************/
void TravPre_iter(BinNodePosi p)
{
	Stack<BinNodePosi>* S=new Stack<BinNodePosi>;
	while (true) {
		while (p) {
			visit(p->data);
			S->push(p->rChild);
			p = p->lChild;
		}
		if (S->empty())break;
		p = S->pop();
	}
}

/*************************************************
中序遍历的递归实现
**************************************************/
void TravIn(BinNodePosi p)
{
	if (!p)return;
	TravIn(p->lChild);
	visit(p->data);
	TravIn(p->rChild);

}

/*************************************************
中序遍历的迭代实现
**************************************************/
void TravIn_iter(BinNodePosi p) 
{
	Stack<BinNodePosi>* S=new Stack<BinNodePosi>;
	while (true) {		
		if (p) {							//如果p结点不为空  //一直向左孩子遍历，直到左孩子为空
			S->push(p);						//将p结点压入栈
			p = p->lChild;					//p指向其左孩子，栈顶为左孩子为空的结点
		}
		else if (!S->empty()) {
			p = S->pop();					//弹出栈顶（左孩子为空的结点）
			visit(p->data);
			p = p->rChild;
		}
		else {
			break;
		}
	}
}
/*************************************************
后序遍历的递归实现
**************************************************/
void TravPost(BinNodePosi p)
{
	if (!p)return;
	TravPost(p->lChild);
	TravPost(p->rChild);
	visit(p->data);
}

/*************************************************
后序遍历的迭代实现
**************************************************/
void TravPost_iter(BinNodePosi p)
{
	Stack<BinNodePosi> *S=new Stack<BinNodePosi>;
	if (p)S->push(p);			//根节点入栈
	while (!S->empty()) {
		if (S->top() != p->parent) {
			while (BinNodePosi x = S->top()) {
				if (x->lChild) {						//如果x结点的左孩子存在
					if (x->rChild)S->push(x->rChild);	//若有右孩子，优先入栈
					S->push(x->lChild);					//然后转至左孩子
				}
				else {
					S->push(x->rChild);
				}
			}
			S->pop();		//弹出栈顶的空节点
		}
		p = S->pop(); visit(p->data);
	}
}
/*************************************************
访问
**************************************************/
void visit(ElemType e)
{
	printf("%c", e);
}

/*************************************************
将新节点作为p结点的左孩子插入
**************************************************/
BinNodePosi insertAsLC(BinTree * t, BinNodePosi p,ElemType e)
{
	t->_size++;
	return insertAsLC(p,e);
}
