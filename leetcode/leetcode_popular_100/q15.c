void swap(int *a, int *b)
{
    int ex = *a;
    *a = *b;
    *b = ex;
}
void reverse(int *a, int start, int end)
{
    while(start < end)
    {
        swap(&a[start], &a[end]);
        start++; end--;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}