
/*


Save the string “WELCOMETOZOHOCORPORATION” in a two dimensional array and search for substring 
like “too” in the two dimensional string both from left to right and from top to bottom.

w	e	L	C	O
M	E	T	O	Z
O	H	O	C	O
R	P	O	R	A
T	I	O	n	  

And print the start and ending index as

Start index : <1,2>

End index: <3, 2>


steps:

1. Get the string from user
2. find row-column using sqrt(strlen(string))
3. check for match 
    i.  left to right by keeping row as constant and incrementing column
    ii. top to bottom by keeping col as constant and incrementing row
3. print start and end index

*/







#include <stdio.h>
#include <string.h>
#include <math.h>

int rc = 0;   // make global for passing length

void checkMatch(char strArr[][rc], char match[]);

void searchMatch(char strArr[][rc],int row, int col, char match[]);
int main()
{
    char str[100];
    printf("Enter your string\n");
    scanf("%s",str);
    int n = strlen(str), k = 0;
    
    if( n == ( (int)(sqrt(n)) * (int)(sqrt(n)) ) )   // if perfect square row-column = sqrt(n)
        rc = (int)( sqrt(n) );
    else
        rc = (int)( sqrt(n) ) + 1;
    char strArr[rc][rc];    // declare array size
    for (int i = 0; i < rc; i++) {
        for (int j = 0; j < rc; j++) {
                strArr[i][j] = str[k++];
        }
    }
    for (int i = 0; i < rc; i++) {
        for (int j = 0; j < rc; j++) {
            if(strArr[i][j] !='\0')
                printf("%c ",strArr[i][j]);
        }
        printf("\n");
    }
    char match[50];
    printf("Enter your matching string\n");
    scanf("%s",match);
    checkMatch(strArr, match);
    return 0;
}


void checkMatch(char strArr[][rc], char match[]) {
    
    for(int i = 0; i < rc; i++) {
        for(int j = 0; j < rc; j++) {
            if(strArr[i][j] == match[0]) {
                searchMatch(strArr, i, j, match); // search for substring
            }
        }
    }
    
    return;
}


void searchMatch(char strArr[][rc],int row, int col, char match[]) {
    // row  from left to right
    int i = 0, k = 0,found = 0;
    for(i = col; i < rc; i++) {
        if(k < strlen(match)) { // check for match length exceed
            if(strArr[row][i] == match[k++]) 
                found++; // increment found 
            else {
                found = 0; // make found 0 again  
                break;
            }
        }
        else
            break;
    }
    if(found == strlen(match)) {  // substring is true found matches len(match)
        printf("From left to riht\n");
        printf("start index: <%d, %d>\n end index: <%d, %d>\n",row,col,row,i-1);
    }
    // intialize again for top to bottom check
    found = 0; 
    k = 0;
    // column check from top to bottom
    for(i = row; i < rc; i++) {
        if(k < strlen(match)) {
            if(strArr[i][col] == match[k++]) 
                found++;
            else {
                found = 0;
                break;
            }    
        }
        else
            break;
    }
    if(found == strlen(match)) {
        printf("From top to bottom\n");
        printf("start index: <%d, %d>\n end index: <%d, %d>\n",row,col,i-1,col);
    }
    return;
}
