/******************************************************************* 
 *  �ļ�����: Polynomica.h
 *  ��Ҫ����: ��������Ķ���ʽ���������ʵ��
 *   
 *  ��������: 2017��10��16��
 *  ��    ��: �� ��
 *  ˵    ��: 
 *   
 *  �޸�����: 
 *  ��    ��: 
 *  ˵    ��: 
 ******************************************************************/  

#include "PolyNode.h"

template<typename T> class Polynomica :public PolyNode<T>
{
private:
	int _size; PolyPosition(T) header; PolyPosition(T) trailer;//��ģ��ͷ�ڱ���β�ڱ�
public:
	Polynomica() {
		header = new PolyNode<T>;
		trailer = new PolyNode<T>;
		header->backNode = trailer; header->preNode = 0;
		trailer->preNode = header; trailer->backNode = 0;
		_size = 0;
	}
	~Polynomica() {			//�������� ɾ��ͷ�ڱ���β�ڱ�
		delete header, trailer;
	}
	int size() { return _size; }
	bool empty() { return _size <= 0; }							//�ж��Ƿ�Ϊ��
	PolyPosition(T) first() const { return header->backNode; }	//���ص�һ�����
	PolyPosition(T) last() const { return trailer->preNode; }	//�������һ�����

	PolyPosition(T) insertAsLast(T const & coe,T const & index); //��e����ĩ�ڵ����
	PolyPosition(T) insertBefore(PolyPosition(T) p, T const & coe,T const & index); //��e����p��ǰ������
	 void remove(PolyPosition(T) p);

	void polyAdd(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n);
	void polySub(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n);
};

//β������
template<typename T>
inline PolyPosition(T) Polynomica<T>::insertAsLast(T const & coe,T const & index)
{
	_size++;
	return trailer->insertAsPre(coe,index);
}

//������p���֮ǰ
template<typename T>
inline PolyPosition(T) Polynomica<T>::insertBefore(PolyPosition(T) p, T const & coe,T const & index)
{
	_size++;
	return p->insertAsPre(coe,index);
}

//ɾ�����p
template<typename T>
inline void Polynomica<T>::remove(PolyPosition(T) p)
{
	p->preNode->backNode = p->backNode;
	p->backNode->preNode = p->preNode;
	delete p; _size--;
}

//һԪ����ʽ�ļӷ�
template<typename T>//p������m�������q������n�������ж���ʽ�������
inline void Polynomica<T>::polyAdd(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n)
{
	PolyPosition(T) pp = p->preNode;
	while (n > 0) {
		if ((m > 0) && p->index <= q->index) {
			if (p->index == q->index) {				//����ָ���ж�
				p->coefficient += q->coefficient;
				if (p->coefficient == 0) {			//���ָ�����Ϊ�㣬ɾ���ýڵ�
					p = p->backNode;
					q = q->backNode;
					remove(p->preNode);

					n--;
					m--;
				}
				else {								//������ϵ����Ϊ�㣬�����ڵ��������
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
		else {								//���n<0������q->index < p->index�����q������pǰ��
			insertBefore(p, q->coefficient,q->index);
			q = q->backNode;
			n--;
		}
	}
	p = pp->backNode; //��p��ԭʼ��ַ��ԭ
}

//һԪ����ʽ�����
template<typename T>//p������m�������q������n�������ж���ʽ�������
inline void Polynomica<T>::polySub(PolyPosition(T)& p, int m, Polynomica<T>& L, PolyPosition(T)& q, int n)
{
	PolyPosition(T) pp = p->preNode;
	while (n > 0) {
		if ((m > 0) && p->index <= q->index) {          //����ڵ�������Χ��
			if (p->index == q->index) {
					p->coefficient -= q->coefficient;
					if (p->coefficient == 0) {			//���ָ�����Ϊ�㣬ɾ���ýڵ�
						p = p->backNode;
						q = q->backNode;
						remove(p->preNode);
						n--;
						m--;
					}
					else {								//��������Ϊ�㣬�����ýڵ��������
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
		else {				//���n<0������q->index < p->index�����q������pǰ��
			insertBefore(p, -1*(q->coefficient), q->index);
			q = q->backNode;
			n--;
		}
	}
	p = pp->backNode;      //��p��ԭʼ��ַ��ԭ
}
