/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int queue[numsSize];
    int front = 0, rear = -1;//队首和队尾
    int left = 0, right = 0; //窗口下标
    while(right < numsSize)
    {
        while(rear>=front && nums[right]>queue[rear])
            rear--;
        queue[++rear] = nums[right++];
        if(left+k<=right)
        {
            if(nums[left]==queue[front])
                front++;
            else
                nums[left] = queue[front];
            left++;
        }
    }
    *returnSize = numsSize-k+1;
    return nums;
}