/******************************************************************* 
 *  �ļ�����: BinTree.h
 *  ��Ҫ����: ������������
 *   
 *  ��������: 2017��10��21��
 *  ��    ��: �� ��
 *  ˵    ��: 
 *   
 *  �޸�����: 
 *  ��    ��: �� ��
 *  ˵    ��: 
 ******************************************************************/  

#include"BinNode.h"
#include"enqueue.h"
#include"stack.h"

struct BinTree {
	int _size;					//��ģ
	BinNodePosi _root;			//���ڵ�
};

void InitBinTree(BinTree* t);			//��ʼ��������
//void updateHeight(BinTree* t, BinNodePosi p);
int const size(BinTree* t);				//�������ڵ�����
bool const Empty(BinTree* t);			//�ж��Ƿ�Ϊ����
int remove(BinTree* t, BinNodePosi p);	//ɾ�����ڵ�Ϊp������
BinNodePosi const root(BinTree* t);		//��ȡ���ڵ�
BinNodePosi insertRoot(BinTree* t,ElemType e);	//������ڵ�
BinNodePosi insertAsLC(BinTree* t, BinNodePosi p,ElemType e); //��p�������Ӳ����½ڵ�
BinNodePosi insertAsRC(BinTree* t, BinNodePosi p,ElemType e); //��p�����Һ��Ӳ����½ڵ�
void TravLeave(BinTree* t);		//�������
void TravPre(BinNodePosi p);			//�������
void TravPre_iter(BinNodePosi p);
void TravIn(BinNodePosi p);			//�������
void TravIn_iter(BinNodePosi p);
void TravPost(BinNodePosi p);		//�������
void TravPost_iter(BinNodePosi p);
void visit(ElemType e);