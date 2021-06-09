#include<stdlib.h>
#include<stdio.h>

struct ListNode {
	int val;
    struct ListNode *next;
};
struct ListNode* Reverse(struct ListNode *head, int len){
	if(len == 1)
		return head;
	struct ListNode *prev, *curr, *prec;
	prev = NULL;
	curr = head;
	prec = head -> next;
	while(prec != NULL){
		curr -> next = prev;
		prev = curr;
		curr = prec;
		prec = prec -> next;
		printf("aaa%d\n",curr -> val);
	}
	//printf("111111111");
	curr -> next = prev;
	return curr;
}

bool isPalindrome(struct ListNode* head){
	if(head == NULL){
		return true;
	}
	if(head -> next == NULL)
		return true;
	int len = 1;
	struct ListNode *tmp, *rev, *tmpHead;
	tmp = head;
	tmpHead = head;
	while(tmp -> next != NULL){
		tmp = tmp -> next;
		//printf("%d\n", tmp -> val);
		len++;
	}
	printf("%d\n", len);
	tmp = head;
	if(len == 2 || len == 3){
		tmp = head -> next;
	}
	else{
		for(int i = 1; i < len / 2; i++){
			tmp = tmpHead -> next;
			tmpHead = tmpHead -> next;
		}
	}
	if(len % 2 == 1){
		tmp = tmp -> next;
	}
	rev = tmp;
	tmp = Reverse(rev, len / 2);
	/*if(tmp -> val != head -> val)
		return false;*/
	while(tmp != NULL && head != NULL){
		if(tmp -> val != head -> val)
			return false;
		printf("%d...%d\n", tmp -> val, head -> val);
		tmp = tmp -> next;
		head = head -> next;
	}
	return true;
}

int main(){
	struct ListNode n1, n2, n3, n4, n5, n6;
	n1.val = 1;
	n1.next = &n2;		
	n2.val = 0;
	n2.next = &n3;
	n3.val = 3;
	n3.next = &n4;
	n4.val = 4;
	n4.next = &n5;;
	n5.val = 0;
	n5.next = &n6;;
	n6.val = 1;
	n6.next = NULL;
	printf("%d", isPalindrome(&n1));
	return 0;
}
