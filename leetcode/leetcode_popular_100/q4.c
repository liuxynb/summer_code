/*
 *给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 *请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 */
void moveZeroes(int* nums, int numsSize){
    int left = 0; 
    for(int right = 0; right < numsSize; right++)
    {
        if(nums[right]!=0)
        {
            nums[left++] = nums[right];
        }
    }
    for(;left<numsSize;left++)
    {
        nums[left] = 0;
    }
}