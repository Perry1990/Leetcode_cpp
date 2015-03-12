//	Problem	:	Pow(x, n)
//	Author	:	perry1990
//	Date	:	2015/3/11
//	Runtime	:	6 ms
/*
Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
        int sign = n>0 ? 1 : -1;
		n = abs(n);
		double ans = 1;
		while(n > 0)
		{
			if (n % 2)
				ans *= x;
			n /= 2;
			x *= x;
		}
		if (sign < 0) ans = 1 / ans;
		return ans;
    }
};