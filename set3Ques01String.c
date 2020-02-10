/*
Write a program to give the following output for the given input

Eg 1: Input: a1b10
       Output: abbbbbbbbbb
Eg: 2: Input: b3c6d15
          Output: bbbccccccddddddddddddddd


*/


#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    int i=0,last=0,n=0;
    fgets(str,5,stdin);
    int len = strlen(str);
    for(i = 0; i < len;i++) 
    {
        
        if(str[i] < '0' || str[i] > '9') 
        {   // if it is chracter and not an integer then just print it and continue
            printf("%c",str[i]);
            continue;
        }
        for(last=i;(str[i]>='0' && str[i]<='9')&&str[i];i++)  
        {
            n = n*10+(str[i]-'0');
        }
        i--;
        if(last) //if first elelment is number then do nothing just n=0, else
        {
            for(n-=1;n;n--) // loop through to 'n' and print char that is last-1
            {
                printf("%c",str[last-1]);
            }
        }
        
        n=0;
    }

    return 0;
}
