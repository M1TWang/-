/******************************************************************* 
 *  文件名称: PolyNode.h
 *  简要描述: 多项式中单项的类的声明与实现
 *   
 *  创建日期: 2017年10月16日
 *  作    者: 幽 人
 *  说    明: 
 *   
 *  修改日期: 
 *  作    者: 
 *  说    明: 
 ******************************************************************/  
#define PolyPosition(T) PolyNode<T>*

template<typename T> class PolyNode {
public:
	T coefficient;  //系数
	T index;		//指数
	PolyPosition(T) preNode; //前驱结点
	PolyPosition(T) backNode;//后继结点

public:
	PolyNode(){}
	PolyNode(T _coe,T _index, PolyPosition(T) p = 0, PolyPosition(T) s = 0)
		:coefficient(_coe),index(_index), preNode(p), backNode(s) {}//构造函数

	PolyPosition(T) insertAsPre(T const &coe,T const &index); //在该节点之前插入
	PolyPosition(T) insertAsBack(T const &coe,T const & index); //在该节点之后插入

};

template<typename T>
inline PolyPosition(T) PolyNode<T>::insertAsPre(T const & coe,T const & index)
{
	PolyPosition(T) x = new PolyNode(coe,index, preNode, this);
	preNode->backNode = x;
	preNode = x;				//双向
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
