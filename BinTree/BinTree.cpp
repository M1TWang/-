#include "BinTree.h"

/*************************************************
��ʼ��������
**************************************************/
void InitBinTree(BinTree * t)
{
	t->_root = NULL;
	t->_size = 0;
}

/*************************************************
���ظ������нڵ���
**************************************************/
int const size(BinTree* t)
{
	return t->_size;
}

/*************************************************
�жϸ����Ƿ�Ϊ����
**************************************************/
bool const Empty(BinTree * t)
{
	return t->_size==0;
}

/*************************************************
ɾ����p���Ϊ���ڵ������������
**************************************************/
int remove(BinTree * t, BinNodePosi p)
{
	int n = size(p);
	t->_size -= n;
	return n;		//����ɾ���Ľ�����
}

/*************************************************
���ظ��ڵ��ַ
**************************************************/
BinNodePosi const root(BinTree* t)
{
	return t->_root;
}

/*************************************************
������ڵ�
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
���½ڵ���Ϊp�����Һ��Ӳ���
**************************************************/
BinNodePosi insertAsRC(BinTree * t, BinNodePosi p,ElemType e)
{
	t->_size++;
	return insertAsRC(p, e);
}

/*************************************************
�������
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
��������ĵݹ�ʵ��
**************************************************/
void TravPre(BinNodePosi p)
{
	if (!p)return;
	visit(p->data);
	TravPre(p->lChild);
	TravPre(p->rChild);
}

/*************************************************
��������ĵ���ʵ��
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
��������ĵݹ�ʵ��
**************************************************/
void TravIn(BinNodePosi p)
{
	if (!p)return;
	TravIn(p->lChild);
	visit(p->data);
	TravIn(p->rChild);

}

/*************************************************
��������ĵ���ʵ��
**************************************************/
void TravIn_iter(BinNodePosi p) 
{
	Stack<BinNodePosi>* S=new Stack<BinNodePosi>;
	while (true) {		
		if (p) {							//���p��㲻Ϊ��  //һֱ�����ӱ�����ֱ������Ϊ��
			S->push(p);						//��p���ѹ��ջ
			p = p->lChild;					//pָ�������ӣ�ջ��Ϊ����Ϊ�յĽ��
		}
		else if (!S->empty()) {
			p = S->pop();					//����ջ��������Ϊ�յĽ�㣩
			visit(p->data);
			p = p->rChild;
		}
		else {
			break;
		}
	}
}
/*************************************************
��������ĵݹ�ʵ��
**************************************************/
void TravPost(BinNodePosi p)
{
	if (!p)return;
	TravPost(p->lChild);
	TravPost(p->rChild);
	visit(p->data);
}

/*************************************************
��������ĵ���ʵ��
**************************************************/
void TravPost_iter(BinNodePosi p)
{
	Stack<BinNodePosi> *S=new Stack<BinNodePosi>;
	if (p)S->push(p);			//���ڵ���ջ
	while (!S->empty()) {
		if (S->top() != p->parent) {
			while (BinNodePosi x = S->top()) {
				if (x->lChild) {						//���x�������Ӵ���
					if (x->rChild)S->push(x->rChild);	//�����Һ��ӣ�������ջ
					S->push(x->lChild);					//Ȼ��ת������
				}
				else {
					S->push(x->rChild);
				}
			}
			S->pop();		//����ջ���Ŀսڵ�
		}
		p = S->pop(); visit(p->data);
	}
}
/*************************************************
����
**************************************************/
void visit(ElemType e)
{
	printf("%c", e);
}

/*************************************************
���½ڵ���Ϊp�������Ӳ���
**************************************************/
BinNodePosi insertAsLC(BinTree * t, BinNodePosi p,ElemType e)
{
	t->_size++;
	return insertAsLC(p,e);
}
