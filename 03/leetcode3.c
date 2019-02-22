#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int curlen = 0, maxlen = 0, totallen;
    int table[256];
    int i;
    int left = 0;

    memset(table,-1,sizeof(table));
    totallen = strlen(s);
    for(i = 0; s[i] != '\0'; i ++)
    {
        if(table[s[i]] != -1 && left < (table[s[i]] + 1))
        {
            left = table[s[i]] + 1;
        }
        curlen = i - left + 1;
        if(curlen > maxlen)
        {
            maxlen = curlen;
        }
        table[s[i]] = i;
        printf("i:%d\n",i);
        printf("left:%d\n",left);
    }

    return maxlen;
}

int main() {

//    char s[] = "abcdefghiadsdhajdasdsa";
//    char s[] = "abcabcabcda";
    char s[] = "abcdefghiadsdhajdasdsa";

    int maxlen = lengthOfLongestSubstring(s);

    printf("%d",maxlen);

    return 0;
}
