/*
 * @author Samarth Agarwal
 *
 * Binary Exponentiation is used to find 
 * x raised to power y modulo p in O(log y) time.
 *
 * Raising a to the power of n is expressed naively as multiplication by a 
 * done n−1 times: a^n = a * a * ... * a. However, this approach is not 
 * practical for large a or n.
 *
 * Now a^(b + c) = (a^b) * (a^c) and a^(2b) = (a^b)^2.
 *
 * The idea of binary exponentiation is, that we split the work using the 
 * binary representation of the exponent.
 */

#include <iostream>

using namespace std;

/*
 * Time complexity: O(log(y))
 * Space Complexity: O(1)
 */
int bin_expo(int x, int y, int p) {
	int res = 1;

	x %= p;

	while (y) {
		if (y % 2)
			res = ((long long)res * x) % p;

		x = ((long long)x * x) % p;
		y /= 2;
	}

	return res;
}

int main() {
	int x = 456454;
	int y = 14885545;
	int p = 1000000007;

	int x_raised_y = bin_expo(x, y, p);

	cout << x_raised_y << endl;
}
