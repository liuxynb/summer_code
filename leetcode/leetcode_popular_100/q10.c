
int subarraySum(int* nums, int numsSize, int k)
{
    if(nums == NULL || numsSize <= 0)
    {
        //robust
        return 0;
    }
    int count = 0;
    int *sum = (int *)malloc((numsSize + 1)*sizeof(int));
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i<numsSize;i++)
    {
        
        sum[i+1] = sum[i] + nums[i];
        for(int j=0;j<=i;j++)
        {
            if(sum(i+1) - sum[j] == k)
            {
                count++;
            }
        }
    }
}