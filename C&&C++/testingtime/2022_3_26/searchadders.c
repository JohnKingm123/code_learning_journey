#include<stdio.h>
#include<stdlib.h>


/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


//函数原型 返回值returnSize必须动态分配默认长度为2,一直必定存在结果，返回下标
int* twoSum(int* nums, int numsSize, int target)
{
    int *returnSize;
    returnSize=(int*)malloc(2);
for(int i=0;i<numsSize;i++)
{
    for(int j=i+1;j<numsSize;j++)
    {   
        if(nums[i]+nums[j]==target)
        {
            returnSize[0]=i;
            returnSize[1]=j;
            return returnSize;
        }
    }
}


}

int main()
{
int numsSize=0;
int target=0;
scanf("%d",&numsSize);
scanf("%d",&target);
int *nums;
int returnSize[2]={0};
nums = (int *)malloc(numsSize);
int *res;

int i=0;
while(i<numsSize)
{
scanf("%d",&nums[i]);
i++;
}



res=twoSum(nums,numsSize,target);

printf("%d %d\n",res[0],res[1]);

free(nums);

    return 0;
}