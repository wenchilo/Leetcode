#include<stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
    int len_a = 0, len_b = 0, dist;
    struct ListNode *tmpA = headA, *tmpB = headB;
    while(tmpA != NULL){
        tmpA = tmpA -> next;
        len_a++;
    }
    while(tmpB != NULL){
        tmpB = tmpB -> next;
        len_b++;
    }
    dist = (len_a > len_b) ? (len_a - len_b) : (len_b - len_a);
    int remain = (len_a > len_b) ? len_b : len_a;
    if(len_a > len_b){
        for(int i = 0; i < dist; i++){
            headA = headA -> next;
        }
    }
    if(len_b > len_a){
        for(int i = 0; i < dist; i++){
            headB = headB -> next;
        }
    }
    for(int i = 0; i < remain; i++){
        if(headA == headB)
            return headA;
        headA = headA -> next;
        headB = headB -> next;
    }
    return NULL;
}
