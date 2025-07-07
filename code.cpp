#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;

int main() {
    const ll M = 100;
    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
    
    cout << "Số ngẫu nhiên B trong [0, " << M-1 << "]: " << B << endl;
    return 0;
}