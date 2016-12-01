/*
 * callxredis.cpp
 *
 *  Created on: 2016年12月1日
 *      Author: hawrk
 *      Desc :模拟调用xredis C++接口，在实际项目中，只需要导入头文件 xRedisClient.h 和共享库 libxredis.so ，
 *            然后依赖库加上 -lxredis -lhiredis 即可
 */

#include "xRedisClient.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

//g++ -o callxredis callxredis.cpp -L./ -lxredis -lhiredis -lpthread

#define MAXLEN  10

enum {
 CACHE_TYPE_1,
 CACHE_TYPE_2,
 CACHE_TYPE_MAX,
};

RedisNode RedisList1[1]=
{
    {0,"127.0.0.1", 6379, "", 8, 5, 0}
};

string GetTime()
{
	time_t timep;
	time(&timep);

	struct tm stTm;
	memset(&stTm,0x00,sizeof(stTm));
	char str[21] = {0};
	localtime_r(&timep,&stTm);
	sprintf(str,"%04d%02d%02d%02d%02d%02d",
			stTm.tm_year + 1900,stTm.tm_mon + 1,stTm.tm_mday,stTm.tm_hour,stTm.tm_min,stTm.tm_sec);

	return string(str);

}

int S2I(string& str)
{
	int iresult = 0;
	stringstream sstream;
	if(0 == str.length())
	{
		return 0;
	}
	sstream.str("");
	sstream<<str;
	sstream>>iresult;

	return iresult;
}

string I2S(int inum)
{
	string result;
	stringstream sstream;

	sstream.str("");
	sstream<<inum;
	sstream>>result;

	return result;
}

unsigned int APHash(const char *str) {
    unsigned int hash = 0;
    int i;
    for (i=0; *str; i++) {
        if ((i&  1) == 0) {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        } else {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }
    return (hash&  0x7FFFFFFF);
}

int main(int argc,char* argv[])
{
	cout<<"test pres0-MAXLEN"<<endl;
	string curr_time = GetTime();
	cout<<"current time:"<<curr_time<<endl;

    xRedisClient xRedis;
    xRedis.Init(CACHE_TYPE_MAX);
    xRedis.ConnectRedisCache(RedisList1, 1, CACHE_TYPE_1);

	for(int i = 0;i < MAXLEN;i++)
	{
		string key = I2S(i);
		string value_time = GetTime();
	    RedisDBIdx dbi(&xRedis);
	    dbi.CreateDBIndex(key.c_str(), APHash, CACHE_TYPE_1);
	    bool bRet = xRedis.set(dbi, key.c_str(), value_time.c_str());
	    if(bRet){
	        cout<<"set key["<<key<<"] success!"<<endl;
	    } else {
	    	cout<<"set key["<<key<<"] error:["<<dbi.GetErrInfo()<<"]"<<endl;
	    }
	    sleep(1);
	}


}


