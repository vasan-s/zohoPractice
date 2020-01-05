/*
input: number of lines ex: 8
output:
 1  
 11  
 21  
 1211  
 111221  
 312211  
 13112221  
 1113213211 

steps:
1. This is look and say sequence. it will say number of digit it has previous step
2. Make NUM as 1 (starting value) then loop through until LINE_NUM
      a.  print the NUM
      b. Run a Loop until its not ZERO.... 
            i.    Find the last digit then eliminate the last digit make count as 1(count of last digit as of now 1)
            ii.   Run a loop to find its repetition count by eliminating last digits.
            iii.  NEWNUM will be the (((count of digit)*(10)+digit)*added more digits)+NEWNUM
For example:
Line Num : output   ;  Explanation

Line 1   : 1

Line 2   : one 1's.  ;  temp = 1(num=1/10=> 0), 1 repeated only one time.ie. output:11


Line 3   : two 1's.  ;  temp = 1(num =11/10=>1), 1 repeated two time(num=1/10=>0), newnum=21


Line 4   : one 2's one 1's  ; temp = 1(num =21/10=> 2), 1 repeated only one time(inner loop wont change num)(j=1), newnum=11 ==>
                                (again outter loop)2 repeated only once(num=2/10=> 0)(j=100) ==> 12*100 => 1200+11 => 1211


Line 5   : one 1's one 2 two 1's   ; temp = 1(num=1211/10=> 121), 1 repeated twice from last(inner loop --> num=121/10=> 12)(j=1), 
                                      newnum=21 ==> 2 repeated once(num=12/10=> 1)(inner loop wont change num)(j*100)==>
                                        ==>12*100 = 1200+21 ==> 1221 ==> 1 repeated once(out loop-->(num=1/10=> 0)(j=10000), 
                                        newmum ==> 11*10000 ==> 110000+1221 ==> 111221

Note: ( It calculate newnum from last to fist )

*/





#include <stdio.h>

int main()
{
    int i=0,j=0,count=0,temp=0;
    int num = 1,newnum = 0;
    for(i = 0; i < 8; i++)
    {
        j=1;    
        newnum = 0; 
        printf("%d\n",num);
        while(num)
        {
            temp = num%10;      // read from last digit...
            num /= 10;          // eliminate last digit
            count = 1;          // count of last digit 1;
            while(temp==(num%10))   // if last digit repeated last-1 position then count incremented till repetition
            {
                count++;            // calculate repeated digit count
                num /= 10;          // eleminate last digit 
            }
            newnum += (((count*10)+temp)*j);    // make newnum by calculating the count of last digit
            j *= 100;       // add two more digit to store as much as possible
        }
        num = newnum;       // make num as newnum to proceed further with newnum
    }
    return 0;
}
