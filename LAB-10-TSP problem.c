#include <stdio.h>
#include <limits.h>

#define V 4  // Number of cities

// Function to find the minimum cost path using Dynamic Programming
int tsp(int dist[V][V], int dp[V][1 << V], int pos, int mask) {
    // All cities visited, return to start
    if (mask == (1 << V) - 1) {
        return dist[pos][0];
    }

    // Return memoized result if already computed
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INT_MAX;

    // Try all unvisited cities
    for (int city = 0; city < V; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(dist, dp, city, mask | (1 << city));
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    // Memoize and return result
    dp[pos][mask] = ans;
    return ans;
}

void solveTSP(int dist[V][V]) {
    int dp[V][1 << V];

    // Initialize dp table with -1
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (1 << V); j++) {
            dp[i][j] = -1;
        }
    }

    // Start from city 0 with only city 0 visited
    int minCost = tsp(dist, dp, 0, 1);
    printf("Minimum cost to complete the tour: %d\n", minCost);
}

int main() {
    int dist[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    solveTSP(dist);

    return 0;
}
