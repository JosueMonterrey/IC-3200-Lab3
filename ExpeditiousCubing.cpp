// https://open.kattis.com/problems/expeditiouscubing

#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> LT(4);
    int target;

    double time;
    for (int i = 0; i < 4; i++) {
        cin >> time;
        LT[i] = round(time * 100);
    }
    cin >> time;
    target = round(time * 100);

    sort(LT.begin(), LT.end());

    long long int x1 = LT[0] + LT[1] + LT[2];
    long long int x2 = LT[1] + LT[2] + LT[3];

    if (x1 > 3 * target) {
        cout << "impossible" << endl;
        return 0;
    }

    if (x2 <= 3 * target) {
        cout << "infinite" << endl;
        return 0;
    }
    
    long long int r = 3 * target - LT[1] - LT[2];

    cout << std::fixed << std::setprecision(2) << (double)r / 100.0 << endl;

    return 0;
}