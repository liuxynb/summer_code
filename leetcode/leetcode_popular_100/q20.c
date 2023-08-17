void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    //转置
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=i;j<(*matrixColSize);j++)
        {
            int swap=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=swap;
        }
    }
    //按中心对称轴对称翻转
    int left = 0, right = (*matrixColSize)-1;
    while(left<right)
    {
        for(int i = 0;i<matrixSize;i++)
        {
            int swap = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = swap;
        }
        left++; right--;
    }
    

}