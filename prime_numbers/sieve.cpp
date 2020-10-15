/*
 * @author Samarth Agarwal
 *
 * Sieve of Eratosthenes is an algorithm for finding all the prime numbers in 
 * a segment [1;n] using O(n log log n) operations.
 *
 * At the beginning we write down all numbers between 2 and n. We mark all 
 * proper multiples of 2 (since 2 is the smallest prime number) as composite.
 * Then we find the next number that hasn't been marked as composite, in this 
 * case it is 3. Which means 3 is prime, and we mark all proper multiples 
 * of 3 as composite. The next unmarked number is 5, which is the next prime 
 * number, and we mark all proper multiples of it. And we continue this 
 * procedure until we processed all numbers in the row.
 *
 *
 * The idea behind is this: A number is prime, if none of the smaller prime 
 * numbers divides it. Since we iterate over the prime numbers in order, we 
 * already marked all numbers, who are divisible by at least one of the prime
 * numbers, as divisible. Hence if we reach a cell and it is not marked, then 
 * it isn't divisible by any smaller prime number and thus has to be prime.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Time complexity: O(n log log n)
 * Space Complexity: O(n)
 */
vector<bool> sieve(int n) {
	bool is_composite[n+1] = {[0] = true, [1] = true};

	for (int i = 2; i <= n; ++i)
	    if (!is_composite[i])
	        for (int j = 2 * i; j <= n; j += i) {
	            /*
	             * We can add any calculation relavant to sieve in this loop.
	             * For example, if we change the data-type of `is_prime` 
	             * to int, then we can also store smallest prime factor for 
	             * any number by slightly modifying this algorithm.
	       	     */ 
			    is_composite[j] = true;
			}

	vector<bool> is_prime(n + 1, true);
	for (int i = 0; i <= n; ++i)
	    is_prime[i] = !is_composite[i];

	return is_prime;
}

int main() {
	int n = 20;

	auto is_prime = sieve(n);

	for (int i = 1; i <= n; ++i) 
		cout << i << " " << is_prime[i] << endl;
}
