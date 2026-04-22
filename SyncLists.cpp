// https://open.kattis.com/problems/synchronizinglists

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

int main() {
    int N, T = 0;
    while (++T) {
        cin >> N;

        if (!N)
            break;

        if (T > 1)
            cout << endl; // para separar cada test case
        
        vi L1(N), L2(N), R(N);
        map<int, int> indices;

        int val;
        for (int i = 0; i < N; i++) {
            cin >> val;
            L1[i] = val;
            indices[val] = i;
        }

        for (int i = 0; i < N; i++) {
            cin >> val;
            L2[i] = val;
        }

        sort(L1.begin(), L1.end());
        sort(L2.begin(), L2.end());

        for (int i = 0; i < N; i++)
            R[indices[L1[i]]] = L2[i];
        
        for (int v : R)
            cout << v << endl;
    }

    return 0;
}