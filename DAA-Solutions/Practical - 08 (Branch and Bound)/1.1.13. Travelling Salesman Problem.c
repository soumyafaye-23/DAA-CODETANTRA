#include <stdio.h>

#define MAX_N 20
#define INF 1e9

int n;
int dist[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Bitmask DP function to find the optimal TSP cost
int tsp(int mask, int u) {
    // If all cities have been visited, return to the starting city (0)
    if (mask == (1 << n) - 1) {
        if (dist[u][0] == -1) return INF;
        return dist[u][0];
    }

    // Return cached result if already calculated
    if (dp[mask][u] != -1) {
        return dp[mask][u];
    }

    int ans = INF;
    for (int v = 0; v < n; v++) {
        // If city v has not been visited yet
        if (!(mask & (1 << v))) {
            // Check if there is a direct connection to city v
            if (dist[u][v] != -1) {
                ans = min(ans, dist[u][v] + tsp(mask | (1 << v), v));
            }
        }
    }

    return dp[mask][u] = ans;
}

int main() {
    if (scanf("%d", &n) != 1) return 0;

    // Read the cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Initialize the memoization table with -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the tour from city 0 with mask tracking city 0 as visited (bit value 1)
    int result = tsp(1, 0);

    printf("%d\n", result);

    return 0;
}
