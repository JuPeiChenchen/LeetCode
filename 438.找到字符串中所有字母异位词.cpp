// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = p.length();
        int a[26] = {0};
        //int b[n];
        if(s.length() < p.length()) {
            return result;
        }
        //sort(p.begin(), p.end());

        for(int i = 0; i < p.length(); i++) {
            a[p[i] - 'a']++;
        }
        for(int i = 0; i <= s.length() - p.length();i++) {
            string q(s.substr(i, p.length())) ;
            int b[26] = {0};
            //sort(q.begin(), q.end());
            int j;
            for(j = 0; j < p.length(); j++) {
                b[q[j] - 'a']++;
            }
            int flag = 0;
            for(j = 0; j < 26; j++) {
                if(a[j] != b[j]) {
                    //cout<<a[j]<<b[j]<<endl;
                    flag = -1;
                    break;
                }
            }
            if(flag == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};
/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        int l = 0, r = -1;
        vector<int> freq_s(26, 0), freq_p(26, 0), res;
        // 初始化代码值
        for( int i = 0 ; i < p.size() ; i++ ){
            freq_p[p[i] - 'a' ]++;
            freq_s[s[++r] - 'a' ]++;
        }
        if ( freq_s == freq_p )
            res.push_back( l );
        // 固定长度的滑动窗口
        while( r < s.size()-1 ){
            freq_s[s[++r] - 'a' ]++;
            freq_s[s[l++] - 'a' ]--;
            if ( freq_s == freq_p )
                res.push_back( l );
        }
        return res;
    }
};*/
// @lc code=end

