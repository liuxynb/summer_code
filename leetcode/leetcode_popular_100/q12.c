char * minWindow(char * s, char * t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);
    if(s_len<t_len)
    {
        // never exists
        return "";
    }
    int target_hash[128] = {0}; // ASCII code
    // 统计t的字符分布
    int total = t_len;
    for(int i=0; i<t_len; i++)
    {
        target_hash[t[i]]++;
    }
    int current_hash[128] = {0};
    int cur_num = 0;
    int start = -1, min = INT_MAX;
    int left = 0, right = 0;
    while(right < s_len)
    {
        char c = s[right];
        if(target_hash[c] == 0)
        {
            right++;
            continue;
        }
        current_hash[c]++;
        //还没有凑齐某字符c时：
        if(current_hash[c] <= target_hash[c])
        {
            cur_num++;
        }
        //还没有到达target字符串之长度
        if(cur_num<total)
        {
            right++;
            continue;
        }
        //此时需要收缩左边界
        for(int i = left; i<=right; i++)
        {
            char d = s[i];
            if(target_hash[d] == 0)
            {
                continue;
            }
            current_hash[d]--;
            if(current_hash[d]<target_hash[d])
            {
                left = i;
                break;
            }
        }
        //此时找到的子串是[left, right]
        if(right-left+1<min)
        {
            min = right-left+1;
            start = left;
        }
        left++; right++;//滑动窗口来寻找更优之结果
        cur_num--;
        //continue;
    }
    if(start == -1)
        return "";
    //利用原字符串导出结果
    s[start+min] = '\0'; 
    return &s[start];
}












