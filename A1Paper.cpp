// https://open.kattis.com/problems/a1paper

#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define A2_LONG_SIDE 0.5946035575
#define A2_SHORT_SIDE 0.4204482076

using namespace std;

int main() {
    int N;
    cin >> N;

    vi A(N - 1);
    for (int& a : A)
        cin >> a;
    
    
    double tape = 0.0;
    bool isPossible = false;
    int needed = 2;
    double longSide = A2_LONG_SIDE, shortSide = A2_SHORT_SIDE;
    
    for (int i = 0; i < N; i++) {
        tape += (needed / 2) * longSide;

        ll available = A[i];
        if (available >= needed) {
            isPossible = true;
            break;
        }

        needed = (needed - available) * 2;

        double temp = longSide;
        longSide = shortSide;
        shortSide = temp / 2.0;
    }

    if (isPossible)
        cout << fixed << setprecision(9) << tape << endl;
    else
        cout << "impossible" << endl;

    return 0;
}