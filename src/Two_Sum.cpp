//	Problem	:	Two Sum
//	Author	:	perry1990
//	Date	:	2015/2/12
//	Runtime	:	26 ms
/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

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
