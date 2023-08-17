/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int cmp(const int *a, const int *b)
{
    return *(int *)a - *(int *)b;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int *p_start = (int *)malloc(intervalsSize * sizeof(int));
    int *p_end = (int *)malloc(intervalsSize * sizeof(int));
    int **p_ret = (int **)malloc(sizeof(int *)*intervalsSize);
    int row = 0;
    //初始化return size
    *returnSize = 0;
    for(;row<intervalsSize;row++)
    {
        //为每个节点分配空间
        p_ret[row] = (int *)malloc((*intervalsColSize) * sizeof(int));
        p_start[row] = intervals[row][0];
        p_end[row] = intervals[row][1];
    }
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));
    qsort(p_start, intervalsSize, sizeof(int), cmp);
    qsort(p_end, intervalsSize, sizeof(int), cmp);
    for(row = 0; row<intervalsSize; row++)
    {
        p_ret[*returnSize][0] = p_start[row];
        for(;row<intervalsSize-1;row++)
        {
            if(p_start[row+1]>p_end[row])
            {
                break;
            }
        }
        p_ret[*returnSize][1] = p_end[row];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }
    return p_ret;
    
    
}