/******************************************************************* 
 *  �ļ�����: 
 *  ��Ҫ����: 
 *   
 *  ��������: 
 *  ��    ��: �� ��
 *  ˵    ��: 
 *   
 *  �޸�����: 
 *  ��    ��: 
 *  ˵    ��: 
 ******************************************************************/

#include "Polynomica.h"
#include<iostream>

using namespace std;

int main() {
	float coe, index;
	Polynomica<float> poly1,poly2;
	cout << "�������һ������ʽ��ϵ����ָ��:" << endl;
	while (cin >> coe >> index) {
		poly1.insertAsLast(coe, index);
	}
	cin.clear();
	cin.ignore();
	cout << "������ڶ�������ʽ��ϵ����ָ��:" << endl;
	while (cin >> coe >> index) {
		poly2.insertAsLast(coe, index);
	}
	PolyPosition(float) f = poly1.first();
	PolyPosition(float) f2 = poly2.first();
	poly1.polyAdd(f, poly1.size(), poly2, f2, poly2.size());
	//poly1.polySub(f, poly1.size(), poly2, f2, poly2.size());
	int n = poly1.size();
	cout << n<<" "<<poly2.size()<<endl;
	/*cout << "��Ӻ�Ķ���ʽ��ϵ����ָ��Ϊ:" << endl;
	for (int i = 0; i < n; i++) {
		cout <<poly1.first()->coefficient << " "<<poly1.first()->index<<" ";
		poly1.remove(poly1.first());
	}*/
	cout << "�����Ķ���ʽ��ϵ����ָ��Ϊ:" << endl;
	for (int i = 0; i < n; i++) {
		cout << poly1.first()->coefficient << " " << poly1.first()->index << " ";
		poly1.remove(poly1.first());
	}
	//cout << poly1.first()->coefficient << endl;

	system("pause");
}