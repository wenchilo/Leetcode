#include<stdlib.h>
#include<stdio.h>

struct ListNode{
	int val;
	struct ListNode *next;
}

struct ListNode* removeNthFromEnd(ListNode* head, int n){
	struct ListNode tmpNode;
	head -> next = tmpNode; 
	int len = 0;
	while(tmpNode != NULL)
		len++;
	for(int i = 0; i < len - n; i++){
		tmpNode = tmpNode -> next;
	}
	tmpNode -> val = tmpNode -> next -> val;
	tmpNode -> next = tmpNode -> next -> next;

	return head;
}

int main(){
	
}
