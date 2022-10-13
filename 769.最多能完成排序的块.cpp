/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
//各个块排序后组合与原数组升序排序后的结果一样
class Solution {
public:
    int result = 1;
    vector<vector<int>> vec;
    void traversal(vector<int>& arr, int startIndex) {
        if(startIndex == arr.size()) {
            /*if(vec.size() == 1) {
                result = 1;
                return;
            }*/
            /*for(int i = 0; i < vec.size(); i++) {
                for(int j = 0; j < vec[i].size(); j++) {
                    cout<<vec[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"+++++"<<endl;*/
            for(int i = 0; i < vec.size() - 1; i++) {
                if(vec[i][vec[i].size() - 1] > vec[i + 1][0]) {
                    return;
                }
                //cout<<vec.size()<<"  "<<vec[i].size()<<endl;
                
            }
            //cout<<vec.size()<<endl;
            if(vec.size() > result) result = vec.size();
            return;
        }
        for(int i = startIndex; i < arr.size(); i++) {
            
            vector<int> a;
            //cout<<i - startIndex + 1<<endl;
            for(int j = startIndex; j < i + 1; j++) {
                //cout<<arr[j];
                a.push_back(arr[j]);
            }
            //cout<<endl;
            //cout<<a.size()<<endl;
            sort(a.begin(), a.end());
            vec.emplace_back(a);
            traversal(arr, i + 1);
            vec.pop_back();
        }
    }
    int maxChunksToSorted(vector<int>& arr) {
        traversal(arr, 0);
        return result;
    }
};
// @lc code=end

