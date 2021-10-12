#include <stdio.h>

#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *arr = malloc(numsSize * sizeof(int));
    
    int i = 0;
    int j =0;
    int flag;
    int n =1;
    while(n <=numsSize)
    {
     for(i =0; i<numsSize; i++)
     {
        if(n == nums[i])
        {
            flag = 1;  
          //  printf("found\n");
        }
        
     }
     if(flag !=1)
     {
         printf("%d\n",n);
         arr[j] = n;
         j++;
     }
     else
     {
         flag = 0;
     }
     n++;
     

    }
    printf("arr is %d %d\n", arr[0],arr[1]);
return arr;
    
}
int find_index_largest(int *a, int size)
{
int i =0;
int max = 0;
int index;
printf("%d\n", a[i]);

for(i=0; i<10; i++)
{
	if(a[i] >max)
	{
		max = a[i];
                index =i;

	}
}
return index;
}

void find_if_duplicates(int *a, int size)
{
	int i ,j =0,index;

	for(i =0; i<size ; i++)
	{
		for(j = i+1; j<size ; j++)
		{
			if(a[i] == a[j])
			{
				index = j;
				break;
			}
		}
	}
	 printf("duplicate found at index %d\n",index);

}

int * insert_ele(int *a,int ele, int size,int pos)
{
    //static int b[11];
    int *b = (int *)malloc(size+5);
    b = a;
    for(int i=size; i>=pos ;i--)
    {
	    b[i] = b[i-1];
    }
    b[pos-1] = ele;

    return b;
        

}

int *remove_dup(int *a, int size)
{
   int *b = (int *)malloc(size-1);
    b = a;
   int i =0;
    for(int j =1 ; j <size; j++)
    {
        if(b[j] !=b[i])
        {
            i++;
            b[i] = b[j];
        }
    }
    return b;
}

int *del_ele(int *a, int pos, int size)
{
	int *b = (int *)malloc(size-1);
    b = a;
    for(int i=pos; i<size-1 ;i++)
    {
            b[i] = b[i+1];
    }
    return b;

}

/* Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121] */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){

    int *arr = malloc(numsSize * sizeof(int));
    int temp;
    for(int i =0;  i<numsSize ;i++)
    {
        arr[i] = nums[i] * nums[i];
        printf("%d",arr[i]);
        
    }
    

    for(int i =0; i<numsSize; i++)
    {
        for(int j =i+1; j<numsSize; j++)
        {
            if(arr[i] > arr[j])
            {
              temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
            }
            }
    }
    *returnSize = numsSize;
    return arr;
}

/* Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array. 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 */


int majorityElement(int* nums, int numsSize){
    int i = 0;
    int target;
    int count =0;
    int n = numsSize;
    int res = 0;
    if(numsSize == 1)
    {
        res = nums[0];
    }
    while(n > 0 )
    {
     target = nums[i];
     printf("target is %d\n", target);
        for(i = i; i<=(n+1); i++)
        {
            if(nums[i] == target)
            {
            printf("target count %d\n %d\n", target, nums[i]);
                count++;
            }
        }
        printf("count is %d\n", count);
           if(count > numsSize/2)
        {
           printf("coint %d\n",count);
            res = target;
            break;
            
        }
        else
        {
            count =0;
            i = numsSize -n +1;
            printf("i is %d\n",i);
            n = n-1;
            printf("n is %d\n",n);
        }
     
    }
    return res;

}


/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4]. */

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
int *arr = malloc(numsSize * sizeof(int));

int i =0;
int j =0;
arr[0] = -1;
arr[1] = -1;
int retsize = 2;
    for(i =0; i<numsSize; i++)
    {
        if(nums[i] == target)
        {
         arr[j] = i;
         j++;       
        }

    }
    
    *returnSize = retsize;
    return arr;
}
int* plusOne(int* digits, int digitsSize){
    int *digits1;
    digits1 = (int *)malloc(sizeof(digitsSize+1));
    digits1= digits;
    int carry;
    
      if(digits1[0]+1 > 9)
      {
          carry = 1;
          digits1[0] =0;
      }
      else
      {
          carry =0;
          digits1[0] = digits1[0] +1;
      }
    
    for(int i =1 ; i<digitsSize; i++)
    {
      if(carry)
      {
          if(digits1[i]+1 >9)
          {
              carry = 1;
              digits1[i] =0;
          }
          else
          {
              digits1[i] = digits1[i] +1;
              carry =0;
          }
      }
    }

      
    
 return digits1;

}


/*Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

Example 1:


Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
*/

int diagonalSum(int** mat, int matSize, int* matColSize){
    
int sum =0;
int i,j =0;
int size = *matColSize;
    
   // sum = mat[i][j] + mat[i+1][j+1] + mat[i+2][j+2] + mat[i][j+2] + mat[i+2][j];
    for( i=0; i<matSize; i++)
    {
        for( j=0 ; j<size; j++)
        {
            printf("ele are %d\n",mat[i][j]);
            
            if(i == j)
            {
                sum = sum + mat[i][j];
            }
            if((i+j)==matSize-1 && i!=j)
            {
                sum = sum+ mat[i][j];
            }
            

        }
    }
    return sum;
}


void mularray(int *a, int row, int col)
{
   int i,j;
   for(i =0;i<row ; i++)
   {
     for(j=0; j<col ; j++)
     {
       printf("elements are %d\n",*((a+i*col) + j));
       }
   }
   
}
   
int main()
{
  int b[2][2] = {{0,1},{2,2}};
	int a[10]= {2,2,2,1,1};
	int i =0, res;
	int *r ;
 
  mularray((int*)b,2,2);
	for(i =0 ; i<10 ; i++)
	{
		printf("array is %d\n",a[i]);
	}                                                        
  int *ret = &i;
//  r = searchRange(a,5,6,ret);
  i = majorityElement(a,5);
 printf("return is %d\n", i);
 // r = findDisappearedNumbers(a,2,0);
//  printf("changed array is %d\n %d\n",r[0], r[1]);

/*	res = find_index_largest(a,10);
        find_if_duplicates(a,10);
        //r = insert_ele(a,2,10,2);
	r = del_ele(a,2,10);
        for(i =0 ; i<9 ; i++)
        {
               printf("changed array is %d\n",r[i]);
        }

	r= remove_dup(a,10);
  a[0] = 9;
  a[1] = 9;
  a[2] = 1;
  a[3] = 2;
  a[4] = 9;
  r = plusOne(a,5);
  for(i =0 ; i<5 ; i++)
        {
               printf("removed duplicates is %d\n",r[i]);
        }
       */ 

}


  
