
/*

Given a set of numbers like <10, 36, 54,89,12> we want to find sum of weights based on the following conditions
    1. 5 if a perfect square
    2. 4 if multiple of 4 and divisible by 6
    3. 3 if even number
    
    

Steps:

1. create a struct set that is used to store value and  its weight
2. Assign each value of array in set.value and its weight based on conditions
    i. if value is not fit in given condition weight = 0.
3. sort using any sorting algorithm (Recommended: Merge sort)
    i. if weight of two elements is equal sort based on value.
    ii. else based on  weight.



*/



#include <stdio.h>
#include <math.h>
struct set {
    int num;
    int weight;
};

void sortWeight(struct set set[], int n);

int main()
{
    struct set set[10];
    int n;
    printf("Enter N number\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d numbers",n);
    
    //get n numbers
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }

    // set numbers to set.num
    for(int i = 0; i < n; i++) {
        set[i].num = arr[i];
    }
    
    
    // assign weight to each element 
    for(int i = 0; i < n; i++) {
        if(set[i].num == ( (int)(sqrt(set[i].num)) * (int)(sqrt(set[i].num)) ))
            set[i].weight = 5;
        else if( ( ((set[i].num) >>2) <<2  == set[i].num ) && ( set[i].num / 6 == 0 ) )
            set[i].weight = 4;
        else if( ( set[i].num % 2 ) == 0 )
            set[i].weight = 3;
        else
            set[i].weight = 0;
        
    }
    sortWeight(set,n);
    for(int i = 0; i < n; i++) {
        printf("<%d, %d>",set[i].num, set[i].weight);
    }
    

    return 0;
}

// use merge sort for better performance
void sortWeight(struct set set[], int n) {
    struct set temp;
    for(int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(set[i].weight > set[j].weight) {
                temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
            else if(set[i].weight == set[j].weight){
                if(set[i].num > set[j].num) {
                    temp = set[i];
                    set[i] = set[j];
                    set[j] = temp;
                }
            
            }
        }
    }
    return;
}
