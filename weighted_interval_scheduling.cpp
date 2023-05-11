#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// define a job structure
struct Job {
    int start, end, weight;
};

// sort jobs by their end times
bool compare(Job j1, Job j2) {
    return j1.end < j2.end;
}

// find the latest job that doesn't conflict with the given job
int latestNonConflict(vector<Job>& jobs, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (jobs[j].end <= jobs[i].start) {
            return j;
        }
    }

    return -1;
}

// find the maximum weight that can be obtained by selecting a subset of jobs
int weightedIntervalScheduling(vector<Job>& jobs) {
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), compare);

    // initialize memoization table
    vector<int> memo(n);
    memo[0] = jobs[0].weight;

    for (int i = 1; i < n; i++) {
        int inclProfit = jobs[i].weight;
        int l = latestNonConflict(jobs, i);

        if (l != -1) {
            inclProfit += memo[l];
        }

        memo[i] = max(inclProfit, memo[i - 1]);
    }

    return memo[n - 1];
}

int main() {
    vector<Job> jobs = {
        {1, 3, 5},
        {2, 5, 6},
        {4, 6, 5},
        {6, 7, 4},
        {5, 8, 11},
        {7, 9, 2}
    };

    cout << "Maximum weight: " << weightedIntervalScheduling(jobs) << endl;

    return 0;
}
