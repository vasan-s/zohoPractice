/*
Given a series of numbers with only 3 and 4.Your task is very simple i.e.. find the nth number in the series. 
First few numbers in the number system are: 
3, 4, 33, 34, 43, 44, 333, 334, 343, 344, 433, 434, 443, 444, 3333, 3334, 3343, 3344……..

I/P: 6
op: 44

*/


#include <stdio.h>
#include <math.h>

int main()
{
    int i,j,n,temp,digit;
    char str[10];
    scanf("%d",&n);
    digit = log2(n+1);
    printf("%d digit number\n",digit);
    temp = pow(2,digit)-1;
    printf("temp= %d\n",temp);
    n = n-temp;
    for(i =0; i < digit; i++)
    {
        if(n%2==0)
            str[i] = '3';
        else
            str[i] = '4';
        n /= 2;
    }
    for(j = i-1;j>=0;j--)
    {
        printf("%c",str[j]);
    }
    return 0;
}
