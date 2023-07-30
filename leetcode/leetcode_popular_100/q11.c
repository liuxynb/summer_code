typedef struct
{
    // key 用于存储累积和，value 用于存储具有该累积和的子数组计数
    int key;
    int value;
    UT_hash_handle hh;
} HASH_TABLE;


int subarraySum(int* nums, int numsSize, int k)
{
    HASH_TABLE* hp = NULL;
    HASH_TABLE* p = NULL;
    p = malloc(sizeof(HASH_TABLE));
    p->key = 0;
    p->value = 1;
    //使用 "uthash" 库中的 "HASH_ADD_INT" 宏将其添加到哈希表 "hp" 中
    HASH_ADD_INT(hp, key, p);
    int cur = 0;
    int ret = 0;
    for(int i = 0; i<numsSize; i++)
    {
        cur += nums[i];
        int sub = cur - k;
        HASH_FIND_INT(hp, &sub, p);
        if(p != NULL)
        {
            ret += p->value;
        }
        //如果哈希表中已经存在该累积和，则将其计数递增。
        //否则，创建一个新的节点，并将其添加到哈希表中。
        HASH_FIND_INT(hp, &cur, p);
        if(p == NULL)
        {
            p = malloc(sizeof(HASH_TABLE));
            p->key = cur;
            p->value = 0;
            HASH_ADD_INT(hp, key, p);
        }
        ++(p->value);
    }
    return ret;
}
