/*
 * testcpp.cpp
 *
 *  Created on: 2016-7-8
 *      Author: hawrk
 */

#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

class MyClass
{
public:
	MyClass(int ref):m_ref(ref) {}  //这里进行初始化
	void print()
	{
		cout<<"m_ref = "<<m_ref<<endl;
	}
private:
	int& m_ref;  //数据成员为引用的时候，必须在初始化列表中进行初始化
};

int main(int argc,char* argv[])
{

	MyClass myclass(8);
	myclass.print();

	return 0;
}


