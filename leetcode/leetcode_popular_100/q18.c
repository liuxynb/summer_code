void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int m = matrixSize;
    int n = *matrixColSize;
    int hash_r[m], hash_c[n];
    memset(hash_r, 0, sizeof(hash_r)); 
    memset(hash_c, 0, sizeof(hash_c)); 
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j]==0)
            {
                hash_r[i]=1;
                hash_c[j]=1;
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(hash_r[i] || hash_c[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}