#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	//typedef struct ListNode listnode;
	int l1_num, l2_num, carry = 0, sum = 0;
	printf("13");
	struct ListNode *current;
    current = (struct ListNode *)malloc(sizeof(struct ListNode));
    current -> val = 0;
    current -> next = NULL;
	//printf("16");
	struct ListNode *root;
    root = current;
    
	while(l1 || l2){
        //printf("while");
		if(l1 == NULL){
			l1_num = 0;
		}
		else{
			l1_num = l1 -> val;
			l1 = l1 -> next;
		}
		if(l2 == NULL){
			l2_num = 0;
		}
		else{
			l2_num = l2 -> val;
			l2 = l2 -> next;
		}
        printf("%d\n", l1_num);
		sum = (l1_num + l2_num + carry) % 10;
		carry = (l1_num + l2_num + carry) / 10;
		current -> val = sum;
        //printf("%d,", current -> val);
        current -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
        //current -> next -> next = NULL;
        
		if(l1 == NULL && l2 == NULL)
			break;
       current = current -> next;
	}
    if(carry != 0){
        current -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current -> next -> next = NULL;
        current -> next -> val = carry;
        current -> next -> next = NULL;
    }
    else
        current -> next = NULL;
    printf("out");
	return root;
	
}

int main(){
	printf("49");
	//typedef struct ListNode listnode;
	struct ListNode l1_1, l1_2, l1_3, l2_1, l2_2, l2_3;
	printf("51");
	l1_1.val = 2;
	l1_1.next = &l1_2;
	l1_2.val = 4;
	l2_2.next = &l1_3;
	l1_3.val = 3;
	l1_3.next = NULL;
	l2_1.val = 5;
	l2_1.next = &l1_2;
	l2_2.val = 6;
	l2_2.next = &l1_3;
	l2_3.val = 4;
	l2_3.next = NULL;
	printf("63");
	addTwoNumbers(&l1_1, &l2_1);
	return 0;
}
