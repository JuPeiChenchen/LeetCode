/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int flag = 0;
        int flag1 = 0;
        if(arr.size() == 1) {
            return false;
        }
        for(int i = 1; i < arr.size(); i++) {
            if(flag == 0 && arr[i] > arr[i - 1]) {
                flag1 = 1;
                continue;
            }
            else if(flag == 1 && arr[i] < arr[i - 1]) {
                continue;
            }
            else if(flag == 0  && flag1 == 1 && arr[i] < arr[i - 1]) {
                flag = 1;
            }
            else {
                return false;
            }
        }
        if(flag == 0) {
            return false;
        }
        return true;
    }
};
/*class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int left = 0;
        int right = A.size() - 1;

        // 注意防止越界
        while (left < A.size() - 1 && A[left] < A[left + 1]) left++;

        // 注意防止越界
        while (right > 0 && A[right] < A[right - 1]) right--;

        // 如果left或者right都在起始位置，说明不是山峰
        if (left == right && left != 0 && right != A.size() - 1) return true;
        return false;
    }
};*/
// @lc code=end

