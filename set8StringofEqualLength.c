/*
Two strings of equal length are given print the mismatched ones.
I/P: a b c d e f g h i
      a b d e e g g i i
O/P: cd , de //when two char are mismatched they should be printed together.
      f , g
      h , i

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* str1= (char*)malloc(sizeof(char));
    char* str2 = (char*)malloc(sizeof(char));
    scanf("%s",str1);
    scanf("%s",str2);
    int i = 0, j = 0;
    for(i=0; i < strlen(str1); i++)
    {
        if(str1[i] != str2[i])
        {
            for(j=i;( str1[j] != str2[j] ) && ( j<strlen(str1));j++)
                printf("%c",str1[j]);
            printf(",");
            for(;i<j;i++)
                printf("%c",str2[i]);
            printf("\n");
        }
    }
    printf("Hello World");
    free(str1);
    free(str2);
    return 0;
}

