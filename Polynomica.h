/******************************************************************* 
 *  文件名称: Polynomica.h
 *  简要描述: 基于链表的多项式类的声明与实现
 *   
 *  创建日期: 2017年10月16日
 *  作    者: 幽 人
 *  说    明: 
 *   
 *  修改日期: 
 *  作    者: 
 *  说    明: 
 ******************************************************************/  

#include "PolyNode.h"

template<typename T> class Polynomica :public PolyNode<T>
{
private:
	int _size; PolyPosition(T) header; PolyPosition(T) trailer;//规模，头哨兵，尾哨兵
public:
	Polynomica() {
		header = new PolyNode<T>;
		trailer = new PolyNode<T>;
		header->backNode = trailer; header->preNode = 0;
		trailer->preNode = header; trailer->backNode = 0;
		_size = 0;
	}
	~Polynomica() {			//析构函数 删除头哨兵，尾哨兵
		delete header, trailer;
	}
	int size() { return _size; }
	bool empty() { return _size <= 0; }							//判断是否为空
	PolyPosition(T) first() const { return header->backNode; }	//返回第一个结点
	PolyPosition(T) last() const { return trailer->preNode; }	//返回最后一个结点

	PolyPosition(T) insertAsLast(T const & coe,T const & index); //将e当作末节点插入
	PolyPosition(T) insertBefore(PolyPosition(T) p, T const & coe,T const & index); //将e当作p的前驱插入
	 void remove(PolyPosition(T) p);

	void polyAdd(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n);
	void polySub(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n);
};

//尾部插入
template<typename T>
inline PolyPosition(T) Polynomica<T>::insertAsLast(T const & coe,T const & index)
{
	_size++;
	return trailer->insertAsPre(coe,index);
}

//插入在p结点之前
template<typename T>
inline PolyPosition(T) Polynomica<T>::insertBefore(PolyPosition(T) p, T const & coe,T const & index)
{
	_size++;
	return p->insertAsPre(coe,index);
}

//删除结点p
template<typename T>
inline void Polynomica<T>::remove(PolyPosition(T) p)
{
	p->preNode->backNode = p->backNode;
	p->backNode->preNode = p->preNode;
	delete p; _size--;
}

//一元多项式的加法
template<typename T>//p结点向后m个结点与q结点向后n个结点进行多项式相加运算
inline void Polynomica<T>::polyAdd(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n)
{
	PolyPosition(T) pp = p->preNode;
	while (n > 0) {
		if ((m > 0) && p->index <= q->index) {
			if (p->index == q->index) {				//进行指数判断
				p->coefficient += q->coefficient;
				if (p->coefficient == 0) {			//如果指数相加为零，删除该节点
					p = p->backNode;
					q = q->backNode;
					remove(p->preNode);

					n--;
					m--;
				}
				else {								//如果相加系数不为零，保留节点继续运算
					p = p->backNode;
					q = q->backNode;
					m--;
					n--;
				}
			}
			else {
				if (q == (p = p->backNode))break;
				m--;
			}
		}
		else {								//如果n<0，或者q->index < p->index将结点q插入结点p前面
			insertBefore(p, q->coefficient,q->index);
			q = q->backNode;
			n--;
		}
	}
	p = pp->backNode; //将p的原始地址还原
}

//一元多项式的相减
template<typename T>//p结点向后m个结点与q结点向后n个结点进行多项式相减运算
inline void Polynomica<T>::polySub(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n)
{
	PolyPosition(T) pp = p->preNode;
	while (n > 0) {
		if ((m > 0) && p->index <= q->index) {          //如果节点在链表范围内
			if (p->index == q->index) {
					p->coefficient -= q->coefficient;
					if (p->coefficient == 0) {			//如果指数相减为零，删除该节点
						p = p->backNode;
						q = q->backNode;
						remove(p->preNode);
						n--;
						m--;
					}
					else {								//如果相减不为零，保留该节点进行运算
						p = p->backNode;
						q = q->backNode;
						m--;
						n--;
					}
			}
			else {
				if (q == (p = p->backNode))break;
				m--;
			}
		}
		else {				//如果n<0，或者q->index < p->index将结点q插入结点p前面
			insertBefore(p, -1*(q->coefficient), q->index);
			q = q->backNode;
			n--;
		}
	}
	p = pp->backNode;      //将p的原始地址还原
}
