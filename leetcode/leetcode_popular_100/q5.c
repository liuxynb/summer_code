// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。
// 说明：你不能倾斜容器。
int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize-1;
    int capacity = 0;
    while(left < right)
    {
        int min_lf = fmin(height[left], height[right]);//取短边
        capacity = fmax(capacity, (right - left) * min_lf); // 求此时最大面积
        if(height[left] > height[right])
            right--;
        else 
            left++;
    }
    return capacity;
}