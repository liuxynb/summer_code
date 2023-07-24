/*
 * 2023/07/13
 */
 /*
     给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
     请你设计并实现时间复杂度为 O(n) 的算法解决此问题。


     示例 1：
     输入：nums = [100,4,200,1,3,2]
     输出：4
     解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

     示例 2：
     输入：nums = [0,3,7,2,5,8,4,6,0,1]
     输出：9
  */
#include<stdio.h>
#include<stdlib.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
typedef struct node
{
    int val;//val就是存储的数组值
    int flag;//记忆化搜索储存的值
    struct node* next; //重复(conflict)
}hash_node;

int hash_value(int key)
{
    if (key < 0)
        key = -key;
    return key % 100003;
}
int dfs_search(int key, hash_node* hash[])
{
    int j = hash_value(key);
    hash_node* p = hash[j];
    while (p != NULL && p->val != key)
        p = p->next;
    if (p == NULL)
        return 0;
    else if (p->flag != 0)
        return p->flag;
    else
    {
        p->flag = dfs_search(key + 1, hash) + 1;
        return p->flag;
    }
}
void insert_hash(int key, hash_node* hash[])
{
    int j = hash_value(key);
    hash_node* p = (hash_node*)malloc(sizeof(hash_node));
    p->val = key;
    p->flag = 0;
    p->next = hash[j];
    hash[j] = p;
}
int longestConsecutive(int* nums, int numSize)
{
    hash_node* hash[100003];
    for (int i = 0; i < 100003; i++)
        hash[i] = NULL;
    for (int i = 0; i < numSize; i++)
        insert_hash(nums[i], hash);
    int max = 0, count;
    for (int i = 0; i < numSize; i++)
    {
        count = 1;
        count = dfs_search(nums[i], hash);
        max = MAX(count, max);
    }
    return max;
}
int main(void)
{
    int len = 0, nums[100001];
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &nums[i]);
    }
    int ans = longestConsecutive(nums, len);
    printf("%d", ans);
    return 0;

}