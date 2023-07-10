
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 方法一：直接两次排序后进行比较
#include <stdio.h>

#define MAX_STR_LEN 100

typedef struct
{
    int index;
    char *str;
} oneStr;

int cmp_char(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int cmp_str(const void *a, const void *b)
{
    return strcmp(((oneStr *)a)->str, ((oneStr *)b)->str);
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    char buffer[strsSize][MAX_STR_LEN];
    oneStr *strbuf = (oneStr *)malloc(sizeof(oneStr) * strsSize);
    for (int i = 0; i < strsSize; i++)
    {
        strcpy(buffer[i], strs[i]);
        strbuf[i].index = i;
        strbuf[i].str = buffer[i];
        qsort(strbuf[i].str, strlen(strbuf[i].str), sizeof(char), cmp_char);
    }
    qsort(strbuf, strsSize, sizeof(oneStr), cmp_str);

    int rowNum = 0, colNum = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    char ***retStr = (char ***)malloc(sizeof(char **) * strsSize);
    retStr[rowNum] = (char **)malloc(sizeof(char *) * strsSize);
    int left = 0;

    for (int right = 0; right < strsSize; right++)
    {
        if (!strcmp(strbuf[left].str, strbuf[right].str))
        {
            // MATCH
            retStr[rowNum][colNum] = (char *)malloc(strlen(strs[strbuf[right].index]) + 1);
            strcpy(retStr[rowNum][colNum], strs[strbuf[right].index]);
            colNum++;
            continue;
        }

        (*returnColumnSizes)[rowNum] = colNum;
        left = right;

        colNum = 0;
        rowNum++;
        retStr[rowNum] = (char **)malloc(sizeof(char *) * strsSize);
        retStr[rowNum][colNum] = (char *)malloc(strlen(strs[strbuf[right].index]) + 1);
        strcpy(retStr[rowNum][colNum], strs[strbuf[right].index]);
        colNum++;
    }

    (*returnColumnSizes)[rowNum] = colNum;
    rowNum++;
    *returnSize = rowNum;

    free(strbuf);
    return retStr;
}



// 方法2：哈希
#define MAXSIZE 997 /* 选取一个质数即可 */
typedef struct Node
{
    char string[101];
    int index;
    struct Node *next; // 保存链表表头
} List;

typedef struct
{
    List *hashHead[MAXSIZE]; // 定义哈希数组的大小
} MyHashMap;

List *isInHash(List *list, char *stringKey)
{
    List *nodeIt = list;
    // 通过链表下遍历
    while (nodeIt != NULL)
    {
        if (strcmp(stringKey, nodeIt->string) == 0)
        {
            return nodeIt;
        }
        nodeIt = nodeIt->next;
    }
    return NULL;
}

MyHashMap *myHashMapCreate()
{
    int i;
    MyHashMap *newHash = (MyHashMap *)malloc(sizeof(MyHashMap));
    /* 对链表的头结点赋初值 */
    for (i = 0; i < MAXSIZE; i++)
    {
        newHash->hashHead[i] = NULL;
    }
    return newHash;
}

int myHashID(char *str)
{
    long h = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        h = (h * 26 % MAXSIZE + str[i] - 'a') % MAXSIZE;
        // 字符串的hashcode, 权为26是因为小写字母，不限制时为128，这样能够让结点尽可能分布均匀，减少地址冲突
        // 取模是为了防止int型溢出
    }
    return h % MAXSIZE;
}

void myHashMapPut(MyHashMap *obj, char *stringKey, int index)
{
    // 一定不再这里面
    // List * it= isInHash(obj->hashHead[key%MAXSIZE],key);
    // if(it != NULL)
    //{
    //     //在表里面更新键值
    //     it->value = value;
    // }
    // else
    {
        // 不在表里面
        List *newNode = (List *)malloc(sizeof(List));
        strcpy(newNode->string, stringKey);
        newNode->next = NULL;
        newNode->index = index;
        if (obj->hashHead[myHashID(stringKey)] != NULL)
        {
            // 当前头链表不为空，则需要将后续的链表接上
            // 需要主要这里表头也代表一个数据的值
            newNode->next = obj->hashHead[myHashID(stringKey)];
        }
        // 修改头链表
        obj->hashHead[myHashID(stringKey)] = newNode;
    }
}

int myHashMapGet(MyHashMap *obj, char *stringKey)
{
    List *it = isInHash(obj->hashHead[myHashID(stringKey)], stringKey);
    if (it != NULL)
    {
        return it->index;
    }
    return -1;
}

void myHashMapFree(MyHashMap *obj)
{
    int i;
    List *freeIt;
    List *curIt;
    for (i = 0; i < MAXSIZE; i++)
    {
        if (obj->hashHead[i] != NULL)
        {
            freeIt = NULL;
            curIt = obj->hashHead[i];

            while (curIt != NULL)
            {
                freeIt = curIt;
                curIt = curIt->next;
                free(freeIt);
            }
            obj->hashHead[i] = NULL;
        }
    }
    free(obj);
}

int compareFunc(void *a, void *b)
{
    if (*(char *)a > *(char *)b)
    {
        return 1;
    }
    return -1;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    // 首先char *** 是三维数组，意思是要将对应的字母异位词放到一起
    // 最大的长度为每个输入的字符串都是不同的
    char ***returnStr = (char ***)malloc(sizeof(char **) * strsSize);
    char tempStr[102]; // 临时使用

    // 返回长度+返回列长度
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    MyHashMap *newHashMap = myHashMapCreate();
    for (int i = 0; i < strsSize; i++)
    {
        strcpy(tempStr, strs[i]);
        // 重排字母，重小到大排列
        qsort(tempStr, strlen(strs[i]), sizeof(char), compareFunc);
        // 检查在哈希表中是否存在
        int row = myHashMapGet(newHashMap, tempStr);
        if (row != -1)
        {
            // 出现在hashMap中
            int col = (*returnColumnSizes)[row];
            returnStr[row][col] = (char *)malloc(sizeof(char) * (strlen(strs[i]) + 1));
            strcpy(returnStr[row][col], strs[i]);
            col++;
            (*returnColumnSizes)[row] = col;
        }
        else
        {
            // 没有出现在hashMap中
            row = *returnSize;
            // 插入hashMap
            myHashMapPut(newHashMap, tempStr, row);

            // 申请最大的空间，防止都是输入都是一样的
            returnStr[row] = (char **)malloc(sizeof(char *) * (strsSize));
            int col = 0;
            returnStr[row][col] = (char *)malloc(sizeof(char) * (strlen(strs[i]) + 1));

            strcpy(returnStr[row][col], strs[i]);
            col++;
            (*returnColumnSizes)[row] = col;
            row++;
            *returnSize = row;
        }
    }
    myHashMapFree(newHashMap);
    return returnStr;
}
