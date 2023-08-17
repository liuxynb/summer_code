bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int i = matrixSize-1;
    int j = 0;
    while(i>=0 && j<*matrixColSize)
    {
        if(target < matrix[i][j])
            i--;
        else if(target > matrix[i][j])
            j++;
        else 
            return true;
    }
    return false;
}