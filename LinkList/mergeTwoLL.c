#include<stdlib.h>
#include<stdio.h>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(l1 == NULL && l2 ==NULL){
        return NULL;
    }
    else if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    struct ListNode *l3, *rlt;
	if(l1 -> val <= l2 -> val){
		l3 = l1;
		l1 = l1 -> next;
	}
	else{
		l3 = l2;
		l2 = l2 -> next;
	}
    rlt = l3;
	while(l1 != NULL || l2 != NULL){
        if(l2 == NULL){
            l3 -> next = l1;
			l1 = l1 -> next;
            l3 = l3 -> next;
            continue;
		}
        if(l1 == NULL){
            l3 -> next = l2;
			l2 = l2 -> next;
            l3 = l3 -> next;
            continue;
		}
		if(l1 -> val <= l2 -> val){
			l3 -> next = l1;
			l1 = l1 -> next;
            l3 = l3 -> next;
		}
		else{
			l3 -> next = l2;
			l2 = l2 -> next;
            l3 = l3 -> next;
		}
	}
	return rlt;
}
