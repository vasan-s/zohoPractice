/*
Print  1st maximum count and  worst minimum count of characters in a string alternatively;

SAMPLE INPUT:
 
      abcccdefgccghi

SAMPLE OUTPUT:
   
     cccccaggbidhef

steps:
1. create an array that stores the occrence of char and copy it to another array.
2. Initialize max element as -1, and find the max element and sort it descending order store it to pos array.
      a. if the occurence value is same then sort based on char value in descending order
3. Now for example: input: abcd then pos[] = {d, c, b, a}
4. print it alternatively like print first then last, print second then second last...so on( ex: output: abcd ==> d a c b
  Another example: input: abcccdefgccghi -----> pos[] = {5,2,1,1,1,1} ie. {cccccc,gg,i,h,f,e,d,b,a}
                    output: cccccc a gg b i  h e f

*/


#include<stdio.h>
#include<string.h>

int main()
{
int max,x_pos1,x_pos2;
max=0;
char s[]="abcd";
int hash1[26]={0};
int hash[26]={0};
int pos[26]={0};
int j=0;
char ch1,ch2;
for(int i=0;i<strlen(s);i++)
  { hash[s[i]%97]++;
  hash1[s[i]%97]++;
  }
for(int k =0;k<26;k++)
{
  max=-1;     
 for(int i=0;i<26;i++)
   { 
     if(max<=hash[i] && hash[i]!=-1 && hash[i])
     {  
          if(max<hash[i])
          {
             x_pos1=i;
             max=hash[i];
             pos[j]=x_pos1;
          }
          else if(max==hash[i])
          {
             x_pos2=i;
             ch1=x_pos2+97;
             ch2=x_pos1+97;
          
             if(ch1>ch2)
                  { 
                    pos[j]=x_pos2;
                  }
                   
             else
                  { 
                    pos[j]=x_pos1;
                  }
                  
                   x_pos1=x_pos2;
          }
      }
    } 
  ++j;
  hash[x_pos1]=-1;
 }
for(int k =0;k<j+1;k++)
{
   if(pos[k])
     {
     while(hash1[pos[k]])
       { printf("%c",pos[k]+97); hash1[pos[k]]--;}
     while(hash1[pos[j]])
        { printf("%c",pos[j]+97); hash1[pos[j]]--;}
        j--;
     }
   else break; 
}
return 0;
}
