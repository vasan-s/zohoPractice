/*
Enter number                                                                                                                    
11
ouput:
- - - - - - - - - - k-                                                                                                          
- - - - - - - - - k-j-k-                                                                                                        
- - - - - - - - k-j-i-j-k-                                                                                                      
- - - - - - - k-j-i-h-i-j-k-                                                                                                    
- - - - - - k-j-i-h-g-h-i-j-k-                                                                                                  
- - - - - k-j-i-h-g-f-g-h-i-j-k-                                                                                                
- - - - k-j-i-h-g-f-e-f-g-h-i-j-k-                                                                                              
- - - k-j-i-h-g-f-e-d-e-f-g-h-i-j-k-                                                                                            
- - k-j-i-h-g-f-e-d-c-d-e-f-g-h-i-j-k-                                                                                          
- k-j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j-k-                                                                                        
k-j-i-h-g-f-e-d-c-b-a-b-c-d-e-f-g-h-i-j-k-                                                                                      
- k-j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j-k-                                                                                        
- - k-j-i-h-g-f-e-d-c-d-e-f-g-h-i-j-k-                                                                                          
- - - k-j-i-h-g-f-e-d-e-f-g-h-i-j-k-                                                                                            
- - - - k-j-i-h-g-f-e-f-g-h-i-j-k-                                                                                              
- - - - - k-j-i-h-g-f-g-h-i-j-k-                                                                                                
- - - - - - k-j-i-h-g-h-i-j-k-                                                                                                  
- - - - - - - k-j-i-h-i-j-k-                                                                                                    
- - - - - - - - k-j-i-j-k-                                                                                                      
- - - - - - - - - k-j-k-                                                                                                        
- - - - - - - - - - k- 
*/

#include <stdio.h>


int main()
{
int n,i,j,k,x=1,y=0,z=0;
printf("Enter number\n");        	
scanf("%d",&n);
char ch = (n-1)+97;
for(i = 0; i < n; i++) //print first 11 Line
{
y=0;z=0;
for(k=0;k<n-i-1;k++)
{
printf("- ");
}
for( j = 0; j < x; j++)
{
if(j<x/2)
{
printf("%c-",ch-y);
y++;
z = y;
}
else
{
printf("%c-",ch-z);
z--;
}
}
x += 2;
printf("\n");
}
x  -= 4;   //end of first half x = 23, it needs to be 19 before startinig of nexxt half
for(i= 0;i<n-1;i++)  //print next half
{
z=0,y=0;
for(k=0;k<=i;k++)
{
printf("- ");
}
for(j = 0; j < x; j++)
{
if(j <x/2)
{
printf("%c-", ch-y);
y++;
z=y;
}
else
{
printf("%c-",ch-z);
z--;
}
}
x -= 2;
printf("\n");
}

return 0;
}
