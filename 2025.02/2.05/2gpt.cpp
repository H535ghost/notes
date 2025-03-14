#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct Cake {
    long long x, y, z;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Cake> cakes(N);
    for (int i = 0; i < N; ++i) {
        cin >> cakes[i].x >> cakes[i].y >> cakes[i].z;
    }

    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long max_sum = 0;

    // Generate all 8 combinations of signs
    for (int sx : {1, -1}) {
        for (int sy : {1, -1}) {
            for (int sz : {1, -1}) {
                // Create a vector of pairs (weight, index)
                vector<pair<long long, int>> temp;
                for (int i = 0; i < N; ++i) {
                    long long weight = sx * cakes[i].x + sy * cakes[i].y + sz * cakes[i].z;
                    temp.emplace_back(weight, i);
                }
                // Sort in descending order of weight
                sort(temp.begin(), temp.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
                    return a.first > b.first;
                });

                // Take first M elements
                long long sum_x = 0, sum_y = 0, sum_z = 0;
                for (int i = 0; i < M && i < temp.size(); ++i) {
                    int idx = temp[i].second;
                    sum_x += cakes[idx].x;
                    sum_y += cakes[idx].y;
                    sum_z += cakes[idx].z;
                }

                long long current = abs(sum_x) + abs(sum_y) + abs(sum_z);
                if (current > max_sum) {
                    max_sum = current;
                }
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}


