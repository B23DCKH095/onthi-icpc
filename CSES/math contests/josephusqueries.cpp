#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// Define a matrix type
using Matrix = vector<vector<ll>>;

// Function to multiply two matrices under MOD
Matrix multiply(const Matrix &A, const Matrix &B) {
    int size = A.size();
    Matrix result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

// Function to compute matrix exponentiation (A^n)
Matrix matrix_pow(Matrix A, ll power) {
    int size = A.size();
    Matrix result(size, vector<ll>(size, 0));
    // Initialize result as identity matrix
    for (int i = 0; i < size; ++i) {
        result[i][i] = 1;
    }
    while (power > 0) {
        if (power % 2 == 1) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        power /= 2;
    }
    return result;
}

// Function to compute the number of ways to get sum n
ll solve(ll n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    // The transition matrix M is 6x6
    Matrix M = {
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}
    };

    // The initial vector is [dp[5], dp[4], dp[3], dp[2], dp[1], dp[0]]
    // For n <= 6, we can compute directly
    vector<ll> dp = {0, 0, 0, 0, 0, 1}; // dp[0] = 1
    for (int i = 1; i <= 6; ++i) {
        dp[i % 6] = 0;
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i % 6] = (dp[i % 6] + dp[(i - j) % 6]) % MOD;
            }
        }
        // Update the dp array in a circular manner
    }

    if (n <= 5) {
        return dp[n % 6];
    }

    // For n > 5, we use matrix exponentiation
    Matrix M_pow = matrix_pow(M, n - 5);
    // The result is the first element of M_pow * initial_vector
    ll ans = 0;
    for (int k = 0; k < 6; ++k) {
        ans = (ans + M_pow[0][k] * dp[(5 - k) % 6]) % MOD;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}