// https://open.kattis.com/problems/firefly

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

int main() {

    int N, H;
    cin >> N >> H;

    vi stalactites(H), stalagmites(H), total(H);

    for (int i = 0; i < N; i++) {
        int sz;
        cin >> sz;
        
        if (i & 1)
            stalactites[H - sz]++;
        else
            stalagmites[sz - 1]++;
    }

    for (int i = 1; i < H; i++) {
        stalactites[i] += stalactites[i - 1];
        stalagmites[H - i - 1] += stalagmites[H - i];

        total[i] += stalactites[i];
        total[H - i - 1] += stalagmites[H - i - 1];
    }

    total[0] += stalactites[0];
    total[H - 1] += stalagmites[H - 1];

    int minVal = 500001; // H <= 500000
    int cantLvls = 0;

    for (int lvl : total) {
        if (lvl < minVal) {
            minVal = lvl;
            cantLvls = 1;
        }
        else if (lvl == minVal)
            cantLvls++;
    }
    
    cout << minVal << " " << cantLvls << endl;    

    return 0;
}