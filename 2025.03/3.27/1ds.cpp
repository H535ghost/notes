#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    set<int> a_candidates;
    int max_k = F / 100;
    for (int x = 0; x <= max_k; ++x) {
        for (int y = 0;; ++y) {
            int k = A * x + B * y;
            int a = 100 * k;
            if (a > F) break;
            a_candidates.insert(a);
        }
    }

    vector<int> possible_a(a_candidates.begin(), a_candidates.end());

    int max_c = F;
    vector<bool> dp(max_c + 1, false);
    dp[0] = true;
    for (int i = 1; i <= max_c; ++i) {
        if (i >= C && dp[i - C]) dp[i] = true;
        if (i >= D && dp[i - D]) dp[i] = true;
    }

    vector<int> possible_c;
    for (int i = 0; i <= max_c; ++i) {
        if (dp[i]) possible_c.push_back(i);
    }
    sort(possible_c.rbegin(), possible_c.rend());

    int best_total = 0, best_sugar = 0;
    double best_conc = -1;

    for (int a : possible_a) {
        int max_sugar = min(a * E / 100, F - a);
        if (max_sugar < 0) continue;

        int current_c = 0;
        for (int c : possible_c) {
            if (c <= max_sugar) {
                current_c = c;
                break;
            }
        }

        int total = a + current_c;
        if (total == 0) continue;

        double conc = static_cast<double>(current_c) / total;
        if (conc > best_conc || (conc == best_conc && total > best_total)) {
            best_conc = conc;
            best_total = total;
            best_sugar = current_c;
        }
    }

    cout << best_total << " " << best_sugar << endl;

    return 0;
}