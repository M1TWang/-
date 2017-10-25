/******************************************************************* 
 *  �ļ�����: BinNode.h
 *  ��Ҫ����: ����������
 *   
 *  ��������: 2017��10��21��
 *  ��    ��: �� ��
 *  ˵    ��: 
 *   
 *  �޸�����: 
 *  ��    ��: 
 *  ˵    ��: 
 ******************************************************************/  
#include<stdio.h>
#include<stdlib.h>
#define BinNodePosi BinNode*
#define ElemType char

struct BinNode {
	ElemType data;
	BinNodePosi parent;		//�����ָ��
	BinNodePosi lChild;		//����ָ��
	BinNodePosi rChild;		//�Һ���ָ��
};

BinNodePosi insertAsLC(BinNodePosi p,ElemType e);	//���½ڵ���Ϊp�������Ӳ���
BinNodePosi insertAsRC(BinNodePosi p,ElemType e);	//���½ڵ���Ϊp�����Һ��Ӳ���
bool IsRoot(BinNodePosi p);							//�ж��Ƿ�Ϊ���ڵ�
bool IsLChild(BinNodePosi p);						//�ж��Ƿ�Ϊ����
bool IsRChild(BinNodePosi p);						//�ж��Ƿ�Ϊ�Һ���
bool HasChild(BinNodePosi p);						//�ж��Ƿ��к��ӽ��
int size(BinNodePosi p);							//������p���Ϊ���ڵ���������������Ŀ