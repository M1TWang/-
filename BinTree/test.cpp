/******************************************************************* 
 *  文件名称: 测试文件
 *  简要描述: 
 *   
 *  创建日期: 
 *  作    者: 幽 人
 *  说    明: 
 *   
 *  修改日期: 
 *  作    者: 幽 人
 *  说    明: 
 ******************************************************************/ 
#define _CRT_SECURE_NO_WARNINGS
#include"BinTree.h"

int main()
{
	BinTree *tree=(BinTree*)malloc(sizeof(BinTree));
	InitBinTree(tree);
	printf("请输入根节点的值：");
	char c;
	scanf_s("%c", &c);
	getchar();
	BinNodePosi root=insertRoot(tree,c);
	BinNodePosi rl=insertAsLC(root, 'b');
	BinNodePosi rr=insertAsRC(root, 'c');
	TravLeave(tree);
	printf("\n");
	TravPre(root);
	printf("\n");
	TravPre_iter(root);
	printf("\n");
	TravIn(root);
	printf("\n");
	TravIn_iter(root);
	printf("\n");
	TravPost(root);
	printf("\n");
	TravPost_iter(root);
	printf("\n");
	/*printf("%c %c %c", root->data, root->lChild->data, root->rChild->data);
	printf("%c %c",rl->parent->data,rr->parent->data);*/

	system("pause");
}