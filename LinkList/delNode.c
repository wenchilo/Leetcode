#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

void deleteNode(struct ListNode* node){
	node.val = node.next.val;
	node.next = node.next.next;
}

int main(){
	struct ListNode node_1, node_2, node_3, node_4;
	node_1.val = 4;
	node_1.next = & node_2;
	node_2.val = 5;
	node_2.next = & node_3;
	node_3.val = 1;
	node_3.next = & node_4;
	node_4.val = 9;
}
