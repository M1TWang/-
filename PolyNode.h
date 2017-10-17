/******************************************************************* 
 *  �ļ�����: PolyNode.h
 *  ��Ҫ����: ����ʽ�е�������������ʵ��
 *   
 *  ��������: 2017��10��16��
 *  ��    ��: �� ��
 *  ˵    ��: 
 *   
 *  �޸�����: 
 *  ��    ��: 
 *  ˵    ��: 
 ******************************************************************/  
#define PolyPosition(T) PolyNode<T>*

template<typename T> class PolyNode {
public:
	T coefficient;  //ϵ��
	T index;		//ָ��
	PolyPosition(T) preNode; //ǰ�����
	PolyPosition(T) backNode;//��̽��

public:
	PolyNode(){}
	PolyNode(T _coe,T _index, PolyPosition(T) p = 0, PolyPosition(T) s = 0)
		:coefficient(_coe),index(_index), preNode(p), backNode(s) {}//���캯��

	PolyPosition(T) insertAsPre(T const &coe,T const &index); //�ڸýڵ�֮ǰ����
	PolyPosition(T) insertAsBack(T const &coe,T const & index); //�ڸýڵ�֮�����

};

template<typename T>
inline PolyPosition(T) PolyNode<T>::insertAsPre(T const & coe,T const & index)
{
	PolyPosition(T) x = new PolyNode(coe,index, preNode, this);
	preNode->backNode = x;
	preNode = x;				//˫��
	return x;
}

template<typename T>
inline PolyPosition(T) PolyNode<T>::insertAsBack(T const & coe,T const & index)
{
	PolyPosition(T) x = new PolyNode(coe,index,this, backNode);
	backNode->preNode = x;
	backNode = x;
	return x;
}
