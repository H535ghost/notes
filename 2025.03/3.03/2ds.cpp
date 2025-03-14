#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    int d;
    int b;
};

bool compare(const Task& a, const Task& b) {
    return a.d < b.d;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Task> tasks;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        if (A > M) continue; // Skip jobs that can't be completed
        tasks.push_back({M - A, B});
    }
    // Sort tasks by their latest possible start day (d)
    sort(tasks.begin(), tasks.end(), compare);
    
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to track the smallest reward
    
    for (const auto& task : tasks) {
        int d_i = task.d;
        int b_i = task.b;
        if (pq.size() <= d_i) {
            pq.push(b_i);
        } else {
            if (pq.top() < b_i) {
                pq.pop();
                pq.push(b_i);
            }
        }
    }
    
    long long sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum << endl;
    return 0;
}