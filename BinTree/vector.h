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
	T& operator[](Rank r)const { return _elem[r]; } //运算符[]的重载
	Rank insert(Rank r, T const &e);
	int remove(Rank lo,Rank hi);					//返回删除区间大小
	Rank find(T const &e, Rank lo, Rank hi)const;	//返回数组下标。若有好几个，返回最后匹配的位置
	T remove(Rank r);							
	int size()const { return _size; }				//返回数组长度
	void change(Rank r, T const &e);				//改变数组下标为r的元素的值
	bool empty() { return _size <= 0; }				//判断是否为空

protected:
	int max(int a, int b);
	void expand();
private:
	T* _elem;							//基址
	int _capacity;						//容量
	Rank _size;							//长度
};

//是否需要扩容
template<typename T>
void Vector<T>::expand() {
	if (_size < _capacity) return;
	_capacity = max(_capacity, DEFAULT_CAPACITY);
	T *oldElem = _elem;
	_elem = new T[_capacity <<= 1];		//容量变为原来的2倍
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template<typename T>
int Vector<T>::max(int a, int b) {
	return a > b ? a : b;
}

//插入
template<typename T>
Rank Vector<T>::insert(Rank r, T const &e) {
	expand();									//是否需要扩容
	for (int i = _size; i > r; i--) {
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
	_size++;
	return r;
}

//删除区间元素
template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo;
	return hi - lo;
}

//查找
template<typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi)const {
	while ((lo < hi--) && (e != _elem[hi]));	//从后向前遍历，返回靠后的匹配项
	return hi;
}

//删除单个元素
template<typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);							//删除单个元素，可以视为删除区间的特例
	return e;
}

//改变元素
template<typename T>
void Vector<T>::change(Rank r, T const &e) {
	_elem[r] = e;
}