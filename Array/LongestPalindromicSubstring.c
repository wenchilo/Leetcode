#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPal(char *s, int left, int right){
    while(left >= 0 && right < strlen(s)){
        if(s[left] == s[right]){
            --left;
            ++right;
        }
        else
            break;
    }
    return right - left - 1;
}

char * longestPalindrome(char * s){
    int oddlen = 0, evenlen = 0, maxOddEven, maxlen = 0, palStart;
    char *rlt;
    if(strlen(s) == 0)
        return rlt;
    for(int i = 0; i < strlen(s); i++){
        oddlen = isPal(s, i, i);
        evenlen = isPal(s, i, i + 1);
        maxOddEven = (oddlen > evenlen) ? oddlen : evenlen;
        if(maxOddEven > maxlen){
            maxlen = maxOddEven;
            palStart = i - (maxlen - 1) / 2;
        }
    }
    rlt = (char *)malloc((maxlen) * sizeof(char));
    printf("%d, %d", palStart, maxlen);
    //strncpy(rlt, s + palStart, maxlen);
    return rlt;
}

int main(){
    char *s = "babad";
    char *rlt = longestPalindrome(s);
    for(int i = 0; i < strlen(rlt); i++){
        //printf("%d", strlen(rlt));
        printf("%c", rlt[i]);
    }
    return 0;
}
