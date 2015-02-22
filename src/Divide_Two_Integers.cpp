//	Problem	:	Divide Two Integers
//	Author	:	perry1990
//	Date	:	2015/2/21
//	Runtime	:	16 ms
/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend1, int divisor1) {
        long dividend = dividend1, divisor = divisor1;
		if (divisor == 0) return INT_MAX;
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		long flag = (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) ? -1 : 1;
		if (dividend < 0) dividend = - dividend;
		if (divisor < 0) divisor = - divisor;
		long quotient = 0, nDivisor = divisor;
		while (nDivisor << 1 <= dividend)
			nDivisor <<= 1;
		while (nDivisor >= divisor)
		{
			if (nDivisor <= dividend)
			{
				quotient = (quotient << 1) + 1;
				dividend -= nDivisor;
			}
			else 
				quotient <<= 1;
			nDivisor >>= 1;
		}
		return (int)quotient * flag;
    }
};