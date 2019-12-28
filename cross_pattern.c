/*
Print the word with odd letters as

P         M
 R      A
   O  R
     G
  O    R
 R       A
P          M 

Algorithm
1. loop through 0 to n.
2. if i < j
    i.  print i spaces then print i'th char.
    ii. print j-i-1 spaces then print j'th char.
3. if i == j 
     i. print i spaces then print i'th element.
 4. if i > j
     i.  print j spaces then j'th char
     ii. print i-j-1 spaces then i'th char.

*/

#include <stdio.h>
#include <string.h>


void printPattern(char str[], int n);

int main() {
	char str[100];
	printf("Enter your string\n");
	scanf("%s",str);
	printPattern(str, strlen(str));
	
	return 0;
}

void printPattern(char str[], int n) {
	for(int i = 0, j = n-1; i < n, j >= 0; i++, j--) {
			
			if(i < j) {
				// initial spaces
				for(int k = 0; k < i; k++)
					printf(" ");
				
				printf("%c",str[i]);	// starting element
				//middle spaces
				for(int k = 0; k < j-i-1; k++)
					printf(" ");
				
				printf("%c\n",str[j]); // last element
			}
				
			if(i == j) {
				for(int k = 0; k < i; k++) 
					printf(" ");
				printf("%c\n",str[i]);
			}
			
			if(i > j) {
				for(int k = 0; k < j; k++)
					printf(" ");
				printf("%c",str[j]);
				
				for(int k = 0; k < i-j-1; k++)
					printf(" ");
				printf("%c\n",str[i]);
			}
	}
				
}
					
			
	
	
	
