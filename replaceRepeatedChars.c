/*
Write a program to replace the characters in a given word such that there should be only one occurrence of a character (Irrespective of the case) in the given word. If there are multiple occurrences, then that should be replaced with the next character. Case of the letter should be maintained while replacing i.e., capital 'A' should be replaced by 'B' and not 'b' - Zoho Interview Questions

Input 1
Java1146

Output 1
Javb1246

Input2
BusRoute112

Output2
BusRovte123

Input3
aBuzZ9900

Output3
aBuzC9012



steps:
1 Find the existance of each char's. and replace it with next char
for aBuzZ9900 -> str[0] ->a -> num = 0; exist[0] = 1
                 str[1] ->B -> num = 1; exist[1] = 1
                 str[2] ->u -> num = 20; exist[20] = 1
                 str[3] ->z -> num = 25; exist[25] = 1
                 str[4] -> Z -> num = 25; (make)num = -1; loop(presented chars; ++num) -> end of loop num = 2 (0,1 has value in its pos); then add it to char 'A' -> 'C'; exist[num] = 1; 
                 str[5] -> 9 -> num = 36; exist[36] = 1
                 str[5] -> 9 -> num = 36; (make) num = 25; loop(presented char; ++num) -> ens of loop num = 26; add it to 22 -> 48 -> '0'; exist[num] = 1;
                 str[6] -> 0 -> num = 26; pos=26 already present so, loop(presented char,++num); num = 27; ans = 49; exist[27] = 1
                 str[7] -> 0 -> num = 26; pos = 26&27 present so loop; num = 28; ans = 50; exist[28] = 1
                 
                 //ouput: aBuzC9012





*/





#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    gets(str);
    char exist[36] = {0};
    int n,num, i;
    n = strlen(str);
    for(i = 0; i < n; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') 
        {
            num = str[i] - 'A';
            if(exist[num]) 
            {
                if(str[i] == 'Z')
                    num = -1;
                while(exist[++num]){}
                exist[num] = 1;
                str[i] = num+'A';
            }
            else
                exist[num] = 1;
        
        }
        else if(str[i] >= 'a' && str[i] <= 'z') 
        {
            num = str[i] - 'a';
            if(exist[num]) 
            {
                if(str[i] == 'z')
                    num = -1;
                while(exist[++num]){}
                exist[num] = 1;
                str[i] = num + 'a';
            }
            else
                exist[num] = 1;
        }
        else if(str[i] >= '0' && str[i] <= '9') 
        {
            num = str[i] - 22;
            if(exist[num]) 
            {
                if(str[i] == '9')
                    num = 25;
                while(exist[++num]){}
                exist[num] = 1;
                str[i] = num+22;
            }
            else
                exist[num] = 1;
        }
    }
    puts(str);
    return 0;
}
