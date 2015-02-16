//	Problem	:	Container With Most Water
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	155 ms
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    struct node {
        int pos, height;
    };
    
    static bool comp(node a, node b)
    {
        return (a.height > b.height);
    }
    
    int maxArea(vector<int> &height) {
        int max_area = 0, area;
        map<int, int> m;
        node *node_list;
        node_list = new node[height.size()];
        
        for (int i = 0; i < height.size(); i ++)
        {
            node_list[i].height = height[i];
            node_list[i].pos = i;
        }
        sort(node_list, node_list + height.size(), comp);
        
        m[node_list[0].pos] = node_list[0].height;
        for (int i = 1; i < height.size(); i ++)
        {
            area = abs((m.begin())->first - node_list[i].pos) * node_list[i].height;
            if (area > max_area)
			{
				max_area = area;
			}
            area = abs((m.rbegin())->first - node_list[i].pos) * node_list[i].height;
            if (area > max_area)
			{
				max_area = area;
			}
            m[node_list[i].pos] = node_list[i].height;
        }
		delete node_list;
        return max_area;
    }
};