#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head){
    typedef struct ListNode listnode;
    listnode *odd, *even;
    odd = head;
    even = head -> next;
    /*while(odd -> next -> next != NULL){
        printf("%d,", odd -> val);
        odd -> next = odd -> next -> next;
        odd = odd -> next;
    }*/
    while(even -> next -> next != NULL){
        odd -> next = even;
        even = even -> next -> next;
        even = even -> next;
    }
    odd -> next = NULL;
    return head;
}

int main(){
	struct ListNode l1_1, l1_2, l1_3, l1_4, l1_5;
	l1_1.val = 2;
	l1_1.next = &l1_2;
	l1_2.val = 4;
	l1_2.next = &l1_3;
	l1_3.val = 3;
	l1_3.next = &l1_4;
	l1_4.val = 5;
	l1_4.next = &l1_5;
	l1_5.val = 6;
	l1_5.next = NULL;

	oddEvenList(&l1_1);
	return 0;
}

 