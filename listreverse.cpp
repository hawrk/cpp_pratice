/*
 * listreverse.cpp
 *
 *  Created on: 2017-2-16
 *      Author: hawrk
 *      Desc:单链表reverse
 *
 */

#include <iostream>

struct List {
	int num;
	List* next;
};

List* reverse(List* head)
{
	if(NULL == head)
	{
		return NULL;
	}
	List *pre = head;
	List *cur = pre->next;  //置当前节点
	List *next = NULL;

	while(cur != NULL)
	{
		next = cur->next;
		cur->next = pre;   //当前节点反转
		pre = cur;        //两个节点后移
		cur = next;
	}
	//处理首末节点
	head->next = NULL;
	head = pre;   //因为cur为NULL了退出来了，所以head要指向前一个节点
	return head;

}



