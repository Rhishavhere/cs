// Simple Floyd Warshall Algorithm

#include <stdio.h>

#define INF 999

int main() {
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter adjacency matrix:\n");

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            // Replace 0 with INF except diagonal
            if(i != j && a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    // Floyd Warshall Logic
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }

            }
        }
    }

    // Output
    printf("\nShortest Path Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(a[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}



// Simple Warshall's Algorithm

#include <stdio.h>

int main() {

    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter adjacency matrix:\n");

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Warshall's Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);

            }
        }
    }

    // Output
    printf("\nTransitive Closure Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}



// Simple Dijkstra Algorithm

#include <stdio.h>

#define INF 999

int main() {

    int n, i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter cost matrix:\n");

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[n], visited[n];

    // Initialize
    for(i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    // Dijkstra Logic
    for(i = 0; i < n - 1; i++) {

        int min = INF, u;

        // Find minimum distance vertex
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for(j = 0; j < n; j++) {

            if(!visited[j] && dist[j] > dist[u] + cost[u][j]) {
                dist[j] = dist[u] + cost[u][j];
            }

        }
    }

    // Output
    printf("\nShortest distances from source:\n");

    for(i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}



// Simple 0/1 Knapsack using Dynamic Programming

#include <stdio.h>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {

    int n, i, w, cap;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    printf("Enter profits:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &cap);

    int dp[n+1][cap+1];

    // Build DP table
    for(i = 0; i <= n; i++) {

        for(w = 0; w <= cap; w++) {

            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            else if(weight[i-1] <= w) {

                dp[i][w] = max(
                    dp[i-1][w],
                    profit[i-1] + dp[i-1][w - weight[i-1]]
                );
            }

            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][cap]);

    return 0;
}



// Simple Fractional Knapsack using Greedy Method

#include <stdio.h>

typedef struct {
    int profit, weight;
    float ratio;
} Item;

int main() {

    int n, i, j, cap;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item item[n];

    // Input profits
    printf("Enter profits:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &item[i].profit);
    }

    // Input weights and calculate ratio
    printf("Enter weights:\n");
    for(i = 0; i < n; i++) {

        scanf("%d", &item[i].weight);

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d", &cap);

    // Sort by profit/weight ratio
    for(i = 0; i < n-1; i++) {

        for(j = i+1; j < n; j++) {

            if(item[i].ratio < item[j].ratio) {

                Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float totalProfit = 0;

    // Greedy selection
    for(i = 0; i < n; i++) {

        if(cap >= item[i].weight) {

            totalProfit += item[i].profit;
            cap -= item[i].weight;
        }

        else {

            totalProfit += item[i].ratio * cap;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}




// Simple Subset Sum using Backtracking

#include <stdio.h>

int set[20], x[20];
int n, target;

void subset(int sum, int k) {

    // If target found
    if(sum == target) {

        printf("{ ");

        for(int i = 0; i < k; i++) {
            if(x[i] == 1)
                printf("%d ", set[i]);
        }

        printf("}\n");
        return;
    }

    // Try remaining elements
    for(int i = k; i < n; i++) {

        if(sum + set[i] <= target) {

            x[i] = 1;

            subset(sum + set[i], i + 1);

            x[i] = 0; // backtrack
        }
    }
}

int main() {

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nPossible subsets are:\n");

    subset(0, 0);

    return 0;
}



// Simple N-Queens (single final print)

#include <stdio.h>

int x[10], n;

// Check safe position
int place(int k, int i) {

    for(int j = 1; j < k; j++) {

        // Same column
        if(x[j] == i)
            return 0;

        // Diagonal check
        if((x[j] - i == j - k) ||
           (x[j] - i == k - j))
            return 0;
    }

    return 1;
}

// Recursive function
int nQueen(int k) {

    for(int i = 1; i <= n; i++) {

        if(place(k, i)) {

            x[k] = i;

            // Solution found
            if(k == n)
                return 1;

            // Place next queen
            if(nQueen(k + 1))
                return 1;
        }
    }

    return 0;
}

int main() {

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if(nQueen(1)) {

        printf("\nSolution:\n");

        for(int i = 1; i <= n; i++) {
            printf("Queen %d -> (%d,%d)\n",
                   i, i, x[i]);
        }
    }

    else {
        printf("No solution");
    }

    return 0;
}