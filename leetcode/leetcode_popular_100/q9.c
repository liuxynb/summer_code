/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
438. 找到字符串中所有字母异位词
中等
1.2K
相关企业
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
*/
int* findAnagrams(char * s, char * p, int* returnSize)
{
    int s_len = strlen(s), p_len = strlen(p);
    int left = 0, right = p_len - 1;
    int *result = malloc(sizeof(int)*s_len);
    //排除p比s长的情况
    if(s_len < p_len)
    {
        *returnSize = 0;
        return result;
    }
    int count = 0;
    int s_hash[26] = {0}, p_hash[26] = {0};
    for(int i = 0; i<p_len; i++)
    {
        // 初始化
        p_hash[p[i] - 'a']++;
        s_hash[s[i] - 'a']++;
    }
    for(int left = 0; left<=s_len - p_len; left++)
    {
        for(int i = 0; i<26; i++)
        {
            if(p_hash[i] != s_hash[i])
            {
                break;
            }
            if(i == 25)
            {
                result[count++] = left;
            }
        }
        s_hash[s[left] - 'a']--;
        if(left + p_len < s_len)
        {
            s_hash[s[left + p_len] - 'a']++;
        }
    }
    *returnSize = count;
    return result;
}