/*
 * vector_for.cpp
 *
 *  Created on: 2017年6月13日
 *      Author: hawrk
 *      Desc:for(auto& element） for(auto element)前者快一秒左右 的时间
 */
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int main(int argc,char* argv[])
{

	clock_t start,end;
	double total_time;
	start = clock();


	vector<string> str_vec;
	string input = "aaaaaaabbbb";
	for(int i = 0;i < 100000000;i++)
	{
		str_vec.push_back(input);
	}

	//range for
	for(auto& element : str_vec)   //用 auto& element会快一点点，所以如果vector 里面的元素不是基本数据类型的话，用auto& 会快一点点
	{
		string out = element + "1111";

	}

	end = clock();
	total_time = (double)(end - start)/CLOCKS_PER_SEC;
	cout<<"total_time =["<<total_time<<"]s"<<endl;

	return 0;
}



