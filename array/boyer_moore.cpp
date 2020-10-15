/*
 * @author Rohit Ashiwal
 *
 * Boyer-Moore algorithm is used to find the
 * majority element in the given array.
 * 
 * It is a two step process:
 *  1. Getting the majority element
 *  2. Verifying that it is indeed the majority
 *     element
 */

#include <iostream>
#include <vector>

using namespace std;

int find_candidate(const vector<int>& A) {
    auto idx = 0U, count = 1U;

    for (auto i = 1U; i < A.size(); ++i) {
        A[idx] == A[i] ? ++count : --count;

        if (!count) {
            idx = i;
            count = 1;
        }
    }

    return A[idx];
}

bool is_majority(const vector<int>& A, int candidate) {
    auto count = 0U;

    for (auto i = 0U; i < A.size(); ++i)
        if (A[i] == candidate)
            ++count;

    // Majority is defined as strictly greater than size / 2
    if (count > A.size() / 2)
        return true;
    return false;
}

int boyer_moore(const vector<int>& A) {
    // Step 1: Find the majority element
    auto candidate = find_candidate(A);

    // Step 2: Verification
    auto res = is_majority(A, candidate);

    if (res)
        return candidate;
    /*
     * Handle the case when the candidate is not majority
     * according to the question
     */
    return -1;
}

int main(void) {
    vector<int> A = { 3, 6, 3, 2, 3 };

    auto majority = boyer_moore(A);

    cout << majority << endl;
}
