#include<stdlib.h>
#include<stdio.h>

struct ListNode{
	int val;
	struct ListNode *next;
}

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
	struct ListNode *prev, *curr, *prec;
	prev = NULL;
	curr = head;
	prec = head -> next;
	while(prec != NULL){
		curr -> next = prev;
		prev = curr;
		curr = prec;
		prec = prec -> next;
	}
    curr -> next = prev;
    return curr;
}
