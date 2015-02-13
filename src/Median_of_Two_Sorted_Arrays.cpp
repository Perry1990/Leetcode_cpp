//	Problem	:	Median of Two Sorted Arrays
//	Author	:	perry1990
//	Date	:	2015/2/12
//	Runtime	:	61 ms
/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) {
            int *tmpArry = A; A = B; B = tmpArry;
            int tmp = m; m = n; n = tmp;
        }
        
        if (m + n < 20) {
            vector<int> vec;
            for (int i = 0; i < m; i ++)
                vec.push_back(A[i]);
            for (int i = 0; i < n; i ++)
                vec.push_back(B[i]);
            sort(vec.begin(), vec.end());
            return (vec[(n + m - 1) / 2] + vec[(m + n) / 2]) / 2.0;
        }
        int crnt_A = m / 2, crnt_B = (m + n - 1) / 2 - crnt_A;
        int upper_A = m - 1, lower_A = 0;
        while (upper_A - 1 > lower_A)
        {
            if (A[crnt_A] < B[crnt_B])
            {
                lower_A = crnt_A;
                crnt_A = (upper_A + lower_A) / 2;
                int diff = crnt_A - lower_A;
                crnt_B -= diff;
            }
            else {
                upper_A = crnt_A;
                crnt_A = (upper_A + lower_A) / 2;
                int diff = upper_A - crnt_A;
                crnt_B += diff;
            }
        }
        if (A[crnt_A] > B[crnt_B])
        {
            int sum = m + n;
            if (n - m <= 1)
            {
                if (n == m) return (A[m - 1] + B[0]) / 2.0;
                else return B[0];
            }
            else return (B[(sum - 1) / 2] + B[sum / 2]) / 2.0;
        }
        else if (A[crnt_A + 1] < B[crnt_B - 1])
        {
            int sum = m + n;
            if (n - m <= 1)
            {
                if (n == m) return (A[m - 1] + B[0]) / 2.0;
                else return B[0];
            }
            else return (B[(sum - 1) / 2 - m] + B[sum / 2 - m]) / 2.0;
        }
        else {
            vector<int> tmpArry;
            tmpArry.push_back(A[crnt_A]);
            tmpArry.push_back(A[crnt_A + 1]);
            tmpArry.push_back(B[crnt_B]);
            tmpArry.push_back(B[crnt_B - 1]);
            sort(tmpArry.begin(), tmpArry.end());
            if ((m + n) % 2 == 1)
                return tmpArry[1];
            else return (tmpArry[1] + tmpArry[2]) / 2.0;
        }
    }
};