// li thuyet.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include<iostream>
using namespace std;
//quan he bao ham:
	//- compesition(thanh phan): hinh thoi đặc huong ve class bao ham, hủy hàm cha -> hủy luôn hàm con (dùng thông thường)
	//- aggregation(ket hop): hinh thoi rỗng (trăng) huong ve class bao ham, hủy hàm cha -> hàm con không hủy
class B {
public:
	B() {
		cout << "\nTao B";
	};
	~B() {
		cout << "\nHuy B";
	};
};
class A {
public:
	int x = 5;
	B* b;
	A() {
		cout << "\nTao A";
		b = new B();// nen dat ben trong de de quan ly ->tranh ro bo nho
	}
	~A() {
		cout << "\nHuy A";
		//delete b;//neu muon huy ca b -> theo quan he component (huy 1 class -> huy luon class chua no) (quan he thanh phan) -> hinh thoi dac
	}
};
int main(int argc, char* argv[])
{
	A a;
	return 0;
}