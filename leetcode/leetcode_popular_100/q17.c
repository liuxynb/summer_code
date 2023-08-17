//对号入座
int firstMissingPositive(int* nums, int numsSize)
{
    for(int i = 1; i < numsSize; i++)
    {
        while(nums[i]>=1 && nums[i]<=numsSize && nums[i]!=nums[nums[i]-1])
        {
            int swap = nums[i];
            nums[i] = nums[swap-1];
            nums[swap-1] = swap;
        }
    }
    //假如没有符合条件值，则返回numsSize+1：
    int ans = numsSize+1;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i]!=i+1)
        {
            ans = i+1;
            break;
        }
    }
    return ans;
}