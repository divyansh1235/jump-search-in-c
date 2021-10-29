//jump search 
// it is only workable when array is sorted
//it takes jump of m, where m is any arbitary no. between 0 and array size (n)
//time complexity of jump search O(n/m+m-1)
// this time complexity is minimum when m=(n)^0.5

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    return a;
}
int jump_search(int a[],int x,int n)
{
    int m,i,gap=0,prev_num=0,index;
    //jump value or jump step
    m=sqrt(n);
    //checking search number at step is greater than elements at gap like 0,gap,2*gap
    gap=m;
    while(a[min(gap,n)-1]<x)
    {
        //previous number 
         prev_num=gap;
        //adding step to gap
        gap+=prev_num;
        //checking whether x is greater than the last element of array if it statisfies than return -1
        if(prev_num>=n)
        {
            return -1;
        }
    }
   
    index=prev_num;
    //checking if search number is present in between prev_num and gap
    while(a[index]<x)
    {
      //increamenting index 
        index++;
        if(index==(min(gap,n)))
        {
            return -1;
        }
    }
    //checking if search number is present at array at a index
    if(a[index]==x)
    {
        return index;
    }
    //check search number is not present 
    return -1;
}

int main()
{
   //example of sorted array
   int a[10]={0,2,2,5,7,8,9,11,12,19};
   //search number
   int x=2,i;
   //passing the array and search number and n
   i=jump_search(a,x,10);
   //print index of the search element 
   printf("%d",i);
    return 0;
}