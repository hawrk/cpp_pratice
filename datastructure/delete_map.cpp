/*
 * delete_map.cpp
 *
 *  Created on: 2017年3月15日
 *      Author: hawrk
 *      Desc:删除map 元素导致iterator失效的问题
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc,char* argv[])
{
	map<int,int> mapdata;
	map<int,int>::iterator iter;

	for(int i = 1;i <= 20; i++)
	{
		mapdata[i] = i+1;
	}
	//print map
	for(iter = mapdata.begin();iter != mapdata.end();iter++)
	{
		cout<<"map["<<iter->first<<"] = "<<iter->second<<endl;
	}

	//删除值为3的倍数的数
	for(iter = mapdata.begin();iter != mapdata.end();)   //注意：iter++不能放在这里了
	{
		if(iter->second %3 == 0)  //如果要删除键为3倍数的，改为 iter->first % 3 == 0
		{
			mapdata.erase(iter++);  //这里先保存iter的指向，然后删除后，再移向下一个元素
		}
		else
			iter++;   //否则直接 后移
	}

	//print after delete data
	cout<<"after delete data"<<endl;
	for(iter = mapdata.begin();iter != mapdata.end();iter++)
	{
		cout<<"map["<<iter->first<<"] = "<<iter->second<<endl;
	}

}



