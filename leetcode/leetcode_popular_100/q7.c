//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
int trap(int *height, int heightSize)
{
    int left = 0, right = heightSize - 1;
    int capacity = 0;
    int leftMax = 0, rightMax = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= leftMax)
            {
                leftMax = height[left];
            }
            else
            {
                capacity += leftMax - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= rightMax)
            {
                rightMax = height[right];
            }
            else
            {
                capacity += rightMax - height[right];
            }
            right--;
        }
    }

    return capacity;
}