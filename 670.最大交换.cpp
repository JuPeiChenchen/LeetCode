/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    bool cmp1(int x,int y)
    {
    return x > y;
    }
    int maximumSwap(int num) {
        int a[9] = {0};
        int i = 0;
        while(num != 0) {
            a[i] = num % 10;
            num = num / 10;
            i++;
        }
        int k = i - 1;
        for (int j = 0; j < i / 2; j++, k--) {
            int s = a[j];
            a[j] = a[k];
            a[k] = s;
        }
        int b[9] = {0};
        for (int j = 0; j < i; j++) {
            b[j] = a[j];
        }
        sort(b, b + i, greater<int>());
        int p = 0;
        for (int j = 0; j < i; j++)
        {
            if(b[j] != a[j])
            {
                p = j;
                break;
            }
        }
        /*for(int j = 0; j < i; j++) {
            cout<<b[j]<<endl;
        }*/
        int q = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(a[j] == b[p]) {
                q = j;
                break;
            }
        }
        int w = a[p];
        a[p] = b[p];
        a[q] = w;
        int result = a[0];
        for(int j = 1; j < i; j++)
        {
            result = result * 10 + a[j];
        }
        return result;
    }
};
// @lc code=end

