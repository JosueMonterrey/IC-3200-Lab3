// https://open.kattis.com/problems/speed

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

double calc(vi& D, vi& S, const int N, const double c) {
    double r = 0.00;
    for (int i = 0; i < N; i++)
        r += D[i] / (S[i] + c);
    
    return r;
}

int main() {

    int N, T;
    cin >> N >> T;

    vi D(N), S(N);
    int minS = 10000;
    for (int i = 0; i < N; i++) {
        cin >> D[i] >> S[i];
        if (S[i] < minS)
            minS = S[i];
    }
    
    double inf = -minS, sup = 2000000.0;

    while (sup - inf >= 1e-6) {
        double c = (sup + inf) / 2;

        double t = calc(D, S, N, c);
        if (t > T)
            inf = c;
        else
            sup = c;
    }

    cout << fixed << setprecision(9) << sup << endl;

    return 0;
}