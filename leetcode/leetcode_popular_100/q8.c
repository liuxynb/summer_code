/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/
// int lengthOfLongestSubstring(char * s)
// {
//     int hash[128] = {0};
//     int max = 0;
//     for(int i = 0, j = 0; i<strlen(s); i++)
//     {
//         hash[s[i]]++;
//         while(hash[s[i]]>1)
//             hash[s[j++]]--;
//         max = max < (i-j+1)?(i-j+1):max;
//     }
//     return max;
// }
int lengthOfLongestSubstring(char * s)
{
    int i=0, j=0, max=0, index[128]={0};
    for(;s[i]!='\0';i++)
    {
        if(index[s[i]] > j)
        {
            max = max>(i-j)?max:(i-j);
            j = index[s[i]];
        }
        index[s[i]] = i+1; //index用于记录字符串中每个ASCII字符（字符的范围是0到127）在字符串中最近一次出现的位置（索引）。
    }
    return max>(i-j)?max:(i-j);
}