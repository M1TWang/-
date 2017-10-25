#pragma once
typedef int Rank; 
#define DEFAULT_CAPACITY 3

template<typename T> class Vector {
public:
	Vector(int c=DEFAULT_CAPACITY){
		_elem = new T[_capacity = c];
		_size = 0;
	}
	~Vector() {
		delete[] _elem;
	}
	T& operator[](Rank r)const { return _elem[r]; } //�����[]������
	Rank insert(Rank r, T const &e);
	int remove(Rank lo,Rank hi);					//����ɾ�������С
	Rank find(T const &e, Rank lo, Rank hi)const;	//���������±ꡣ���кü������������ƥ���λ��
	T remove(Rank r);							
	int size()const { return _size; }				//�������鳤��
	void change(Rank r, T const &e);				//�ı������±�Ϊr��Ԫ�ص�ֵ
	bool empty() { return _size <= 0; }				//�ж��Ƿ�Ϊ��

protected:
	int max(int a, int b);
	void expand();
private:
	T* _elem;							//��ַ
	int _capacity;						//����
	Rank _size;							//����
};

//�Ƿ���Ҫ����
template<typename T>
void Vector<T>::expand() {
	if (_size < _capacity) return;
	_capacity = max(_capacity, DEFAULT_CAPACITY);
	T *oldElem = _elem;
	_elem = new T[_capacity <<= 1];		//������Ϊԭ����2��
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template<typename T>
int Vector<T>::max(int a, int b) {
	return a > b ? a : b;
}

//����
template<typename T>
Rank Vector<T>::insert(Rank r, T const &e) {
	expand();									//�Ƿ���Ҫ����
	for (int i = _size; i > r; i--) {
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
	_size++;
	return r;
}

//ɾ������Ԫ��
template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo;
	return hi - lo;
}

//����
template<typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi)const {
	while ((lo < hi--) && (e != _elem[hi]));	//�Ӻ���ǰ���������ؿ����ƥ����
	return hi;
}

//ɾ������Ԫ��
template<typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);							//ɾ������Ԫ�أ�������Ϊɾ�����������
	return e;
}

//�ı�Ԫ��
template<typename T>
void Vector<T>::change(Rank r, T const &e) {
	_elem[r] = e;
}