/*
Given a two dimensional array of string like

  <”luke”, “shaw”>
  <”wayne”, “rooney”>
  <”rooney”, “ronaldo”>
  <”shaw”, “rooney”> 

Where the first string is “child”, second string is “Father”. 
And given “ronaldo” we have to find his no of grandchildren Here “ronaldo” has 2 grandchildren and 1 great grand child. 
So our output should be 3.

/*





#include <stdio.h>
#include <string.h>



void countGrandChild(char child[], int n);
struct family {
    char father[50];
    char child[50];
}f[10];
int count = 0;
int main ()
{
    char arr[50][2],name[50];
    int len = 0;
    printf("Enter length of family tree\n");
    scanf("%d",&len);
    printf(" Enter names of child and father one by one\n");
    for(int i = 0; i < len; i++) {
        scanf("%s",f[i].child);
        scanf("%s",f[i].father);
    }
    printf("Enyter Name of parent\n");
    scanf("%s",name);
    for(int i = 0; i < len; i++) {
        if( strcmp(f[i].father,name) == 0 ) 
            countGrandChild(f[i].child, len);
    }
    printf("%d",count);
  return 0;
}

void countGrandChild(char child[],int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(strcmp(f[i].father,child) == 0 ) {
            count++;
            countGrandChild(f[i].child, n);
        }
            
    }
    return;
}
