/*
 * binary_search.cpp
 *
 *  Created on: 2017年1月18日
 *      Author: hawrk
 *      Desc:二分查找，前提：元素必须有序
 */
/*
 * 七大查找算法
 * 1.顺序查找   （不要求有序，一个一个找，复杂度O(n)
 * 2.二分查找  (从中间开始比较，必须有序，复杂度O（log n)
 *    3.差值查找  （从比较接近目标值的数开始查找，是二分查找的改进版 log2(log2 n)）
 *    4.奜波那奇查找 （从黄金分割点查找0.618 ，也是二分查找的改进版 log2 n）
 * 5.树表查找  （基于二叉树的查找算法，log n)
 * 6.块查找 （就是分为m块，然后顺序查找）
 * 7.哈希查找 （把下标与其值对应起来，是一种空间换时间的查找算法）
 */

#include <iostream>

//循环版本:
int binary_serach(int* a,int n,int value)
{
	int low  = 0;
	int high = n -1;
	while(low <= high)
	{
		///int mid = (low+high)/2;
		//优化    low+high 数据量可能会导致溢出
		int mid = (high - low)/2 + low;
		if(a[mid] == value)
		{
			return mid;
		}
		else if(a[mid] < value)
		{
			low = mid + 1;  //low = mid + 1  //目标值在右边 ，a[mid]不等于目标了，所以可以向右前进一位
		}
		else
			high = mid - 1;  //high = mid-1  //目标值在左边，a[mid]不等 于了，可以向左缩小一位
	}
	return -1;  //没找到
}

//递归版本
int birany_search_re(int a[],int low,int high,int value)
{
	if(low <= high)
	{
		int mid = (high - low)/2 + low;
		if(a[mid] == value)
		{
			return mid;
		}
		else if(a[mid] < value)  //目标值在右边
		{
			return birany_search_re(a,mid+1,high,value);
		}
		else
		{
			return birany_search_re(a,low,mid-1,value);
		}
	}
	else
		return -1;

}

