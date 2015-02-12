//	Problem: Two Sum
//	Author: Perry1990
//	Runtime: 26ms
class Solution {
private:
    unordered_map<int, int> m;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size(); i ++)
        {
            m.insert(pair<int, int>(numbers[i], i + 1));
        }
        int i = 1;
        for (vector<int>::iterator it = numbers.begin(); it < numbers.end(); it ++)
        {
            unordered_map<int, int>::iterator it_m = m.find(target - *it);
            if (it_m != m.end() && i != it_m->second)
            {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(it_m->second);
                if (ans[0] > ans[1])
                {
                    int tmp = ans[0];
                    ans[0] = ans[1];
                    ans[1] = tmp;
                }
                return ans;
            }
            i ++;
        }
    }
};
