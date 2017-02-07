/*
 * quick_sort.cpp
 *
 *  Created on: 2017年2月6日
 *      Author: hawrk
 *      Desc:快速排序
 */
void quicksort(int a[],int left,int right)
{
	int i,j,t,temp;  //i为左起基准点，j为右起基准点，temp为哨兵
	if(left > right)
	{
		return;
	}
	//设置基准点和哨兵
	i = left;
	j = right;
	temp = a[left];

	while(i != j)
	{
		//从右边起
		while(a[j] >= temp && i<=j)
		{
			j--;
		}
		//左边
		while(a[i] <= temp && i<j)
		{
			i++;
		}
		//交换
		if(i<j)
		{
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}
	//基准数归位
	a[left] = a[i];
	a[i] = temp;

	//递归实现
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);

}



