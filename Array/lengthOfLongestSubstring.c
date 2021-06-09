#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    if(len == 0)
        return 0;
    if(len == 1)
        return 1;
    int flag = 0; 
    int subIndex = 0, subLen = 0, tmpLen = 0;
    for(int i = subIndex; i < len; i++){
    //printf("i = %d,", i);
        for(int j = subIndex; j < i; j++){
            //printf("j = %d\n", j);
            if(s[i] == s[j]){
                if(tmpLen > subLen)
                    subLen = tmpLen;
                tmpLen = 0;
                subIndex = j + 1;
                i = subIndex - 1;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            tmpLen++;
            //printf("tmplen = %d\n", tmpLen);
        }
        flag = 0;
    }
    if(tmpLen > subLen)
        subLen = tmpLen;
    return subLen;
}


int main()
{
    char s[] = "bbb"; 
    printf("%d", lengthOfLongestSubstring(s));
    return 0;
}
