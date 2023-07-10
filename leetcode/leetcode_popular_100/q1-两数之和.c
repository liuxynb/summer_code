/*
2023/7/6
leetcode 1
 */
/*快排＋二分查找*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp(const int *a, const int *b)
{
    return a[0] - b[0];
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int arr[numsSize][2];
    for(int i = 0; i<numsSize; i++)
    {
        arr[i][0] = nums[i];
        arr[i][1] = i;//此为该值所对应的下标
    }

    qsort(arr, numsSize, sizeof(arr[0]), cmp);
    for(int i = 0; i<numsSize; i++)
    {
        int left = 0; int right = numsSize - 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(arr[mid][0] == target - nums[i] && arr[mid][1] != i)
            {
                *returnSize = 2;
                int *ret = (int *)malloc(sizeof(int)*2);
                ret[0] = i;
                ret[1] = arr[mid][1];
                return ret;
            }
            else if(arr[mid][0]>target - nums[i])
                right = mid - 1;
            else 
                left = mid + 1;
        }
    }
    *returnSize = 0;
    return NULL;
}

















/**/