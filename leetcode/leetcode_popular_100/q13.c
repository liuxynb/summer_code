int maxSubArray(int* nums, int numsSize)
{
    int pre_sum = nums[0], max_num = nums[0];
    for(int i = 1; i<numsSize; i++)
    {
        if(pre_sum<0)
        {
            pre_sum = nums[i];
        }
        else 
        {
            pre_sum += nums[i];
        }
        max_num = max_num>pre_sum?max_num:pre_sum;
    }
    return max_num;
}