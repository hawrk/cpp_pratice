/*
 * delete_vector.cpp
 *
 *  Created on: 2017年3月15日
 *      Author: hawrk
 *      Desc:vector 删除元素导致 vector iterator 失效的问题
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> IntArray;

 int main(int argc,char* argv[])
 {
	 IntArray array;
	 for (int i = 1;i <= 20 ;i++)
	 {
		 array.push_back(i);
	 }
//	 array.push_back(1);
//	 array.push_back(2);
//	 array.push_back(3);
//	 array.push_back(4);
//	 array.push_back(5);
//	 array.push_back(6);

	 IntArray::iterator iter;
	 //打印vector的值
	 cout<<"befor erase...."<<endl;
	 for( iter = array.begin(); iter != array.end();iter++)
	 {
		 cout<<"array[i] = "<<*iter<<endl;
	 }

	 //删除2的倍数 2,4,6 ...
	 for( iter = array.begin(); iter != array.end(); iter++)
	 {
		 if(*iter %2 == 0)
		 {
			 array.erase(iter);
			 --iter;   //重要：删除一个元素后，vector 后面的元素会向前移，迭代器要往前移，否则会core dump
		 }
	 }
	 cout<<"after erase....."<<endl;
	 //测试删除后的元素
	 for( iter = array.begin(); iter != array.end();iter++)
	 {
		 cout<<"array[i] = "<<*iter<<endl;
	 }
 }

