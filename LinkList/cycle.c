#include<stdlib.h>
#include<stdio.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head){
	if(head == NULL)
		return false;
	struct ListNode *tmp, *tmphead;
	tmp = head;
	while(head -> next && head -> next -> next){
		head = head -> next -> next;
		tmp = tmp -> next;
		if(tmp == head)
			return true;
	}
	return false;
}

int main(){
	struct ListNode n1, n2, n3, n4;
	n1.val = 3;
	n1.next = &n2;
	n2.val = 2;
	n2.next = &n3;
	n3.val = 0;
	n3.next = &n4;
	n4.val = 4;
	n4.next = NULL;
	printf("%d", hasCycle(&n1));
	return 0;
}

