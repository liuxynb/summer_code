/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const int dirx[4] = { 0, 1, 0, -1 };
const int diry[4] = { 1, 0, -1, 0 };
bool isLegal(int x, int y, int dx, int dy, int matrixSize, int *matrixColSize, int **visited)
{
    int xx = x + dx;
    int yy = y + dy;
    if(xx<0 || xx >= matrixSize || yy<0 || yy>=(*matrixColSize) || visited[xx][yy])
        return false;
    return true;
}
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    //初始化返回数组并维护当前赋值位置idx
    *returnSize = matrixSize * (*matrixColSize);
    int *ra = (int *)malloc(sizeof(int)*(*returnSize));
    int ra_idx = 0;
    //初始化访问标记数组
    int **visited = (int **)malloc(sizeof(int *)*matrixSize);
    for(int i=0; i<matrixSize; i++)
    {
        visited[i] = (int *)malloc(sizeof(int) * (*matrixColSize));
        memset(visited[i], 0, sizeof(int)*(*matrixColSize));
    }
    int x = 0;
    int y = -1;
    int turn = 0;
    while(1)
    {
        int dx = dirx[turn%4];
        int dy = diry[turn%4];
        int flag = 0;
        while(isLegal(x, y, dx, dy, matrixSize, matrixColSize, visited))
        {
            flag = 1;
            x+=dx;
            y+=dy;
            visited[x][y] = 1;
            ra[ra_idx++] = matrix[x][y];
        }
        if(!flag)
        {
            break;
        }
        //一个方向走不动需要换向走不动
        turn++;
    }
    return ra;
}