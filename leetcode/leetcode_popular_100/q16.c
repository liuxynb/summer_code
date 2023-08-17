/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//此算法空间复杂度为O(n),时间复杂度为O(n);
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    if(nums == NULL || numsSize<0 || returnSize == NULL)
    {
        return NULL;
    }
    int *ans = (int *)malloc(numsSize * sizeof(int));
    // prefix:前缀  suffix:后缀
    int prefix[numsSize], suffix[numsSize];
    //第一个数没有前缀,最后一个数没有后缀
    prefix[0] = 1;
    suffix[numsSize-1] = 1;
    for(int i=1; i<numsSize; i++)
    {
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    for(int i = numsSize-2; i>=0; i--)
    {
        suffix[i] = suffix[i+1] * nums[i+1];
    }
    for(int i = 0; i<numsSize; i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }
    *returnSize = numsSize;
    return ans;
}