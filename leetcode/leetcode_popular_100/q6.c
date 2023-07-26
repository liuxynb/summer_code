/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 * 你返回所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
// int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
// {
//     qsort(nums, numsSize, sizeof(int), compare);
//     int capacity = 16;
//     int **result = malloc(sizeof(int *) * capacity);
//     *returnSize = 0;
//     for (int i = 0; i < numsSize - 2; i++)
//     {
//         // 跳过重复的元素
//         if (i > 0 && nums[i] == nums[i - 1])
//             continue;
//         int left = i + 1, right = numsSize - 1;
//         while (left < right)
//         {
//             int sum = nums[left] + nums[right] + nums[i];
//             if (sum == 0)
//             {
//                 // 符合题意
//                 if (*returnSize == capacity)
//                 {
//                     // 需要扩容
//                     capacity *= 2;
//                     result = realloc(result, sizeof(int *) * capacity);
//                 }
//                 result[*returnSize] = malloc(sizeof(int) * 3);
//                 result[*returnSize][0] = nums[i];
//                 result[*returnSize][1] = nums[left];
//                 result[*returnSize][2] = nums[right];
//                 (*returnSize)++;
//                 // 跳过重复的元素
//                 while (left < right && nums[left] == nums[left + 1])
//                     left++;
//                 while (left < right && nums[right] == nums[right - 1])
//                     right--;
//                 left++;
//                 right--;
//             }
//             else if (sum < 0)
//                 left++;
//             else
//                 right--;
//         }
//     }
//     // 设置返回结果的列数为 3
//     *returnColumnSizes = malloc(*returnSize * sizeof(int));
//     for (int i = 0; i < *returnSize; i++)
//     {
//         (*returnColumnSizes)[i] = 3;
//     }
//     return result;
// }
/*
 *better way
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = numsSize;
    int **result = (int **)malloc(capacity * sizeof(int *));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++)
    {
        // 跳过重复的元素
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = -nums[i];
        int left = i + 1, right = numsSize - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum == target)
            {
                // 符合题意
                if (*returnSize == capacity)
                {
                    // 需要扩容
                    capacity *= 2;
                    result = (int **)realloc(result, capacity * sizeof(int *));
                }

                result[*returnSize] = (int *)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;

                // 跳过重复的元素
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
    }

    // 设置返回结果的列数为 3
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = 3;
    }
    return result;
}