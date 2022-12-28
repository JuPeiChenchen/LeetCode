/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> even(A.size() / 2); // 初始化就确定数组大小，节省开销
        vector<int> odd(A.size() / 2);
        vector<int> result(A.size());
        int evenIndex = 0;
        int oddIndex = 0;
        int resultIndex = 0;
        // 把A数组放进偶数数组，和奇数数组
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) even[evenIndex++] = A[i];
            else odd[oddIndex++] = A[i];
        }
        // 把偶数数组，奇数数组分别放进result数组中
        for (int i = 0; i < evenIndex; i++) {
            result[resultIndex++] = even[i];
            result[resultIndex++] = odd[i];
        }
        return result;
    }
};
/*class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> result(A.size());
        int evenIndex = 0;  // 偶数下标
        int oddIndex = 1;   // 奇数下标
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                result[evenIndex] = A[i];
                evenIndex += 2;
            }
            else {
                result[oddIndex] = A[i];
                oddIndex += 2;
            }
        }
        return result;
    }
};*/
/*class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddIndex = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] % 2 == 1) { // 在偶数位遇到了奇数
                while(A[oddIndex] % 2 != 0) oddIndex += 2; // 在奇数位找一个偶数
                swap(A[i], A[oddIndex]); // 替换
            }
        }
        return A;
    }
};*/
// @lc code=end

