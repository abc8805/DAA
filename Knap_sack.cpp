#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)   
    {
        for (j = 0; j <= W; j++)  
        {
            if (i == 0 || j == 0)   
                K[i][j] = 0;
            else if (wt[i - 1] <= j) 
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]); 
            else
                K[i][j] = K[i - 1][j]; 
        }
    }
    return K[n][W];
}
int main()
{
// ---------------------------------------------------------------------------------
    // cout << "Enter the number of items in a Knapsack:";
    // int n, W;
    // cin >> n;
    // int val[n], wt[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter value and weight for item " << i << ":";
    //     cin >> val[i];
    //     cin >> wt[i];
    // }
    // cout << "Enter the capacity of knapsack";
    // cin >> W;

// -------------------------------------------------------------------------------

    int W = 5, n = 4;
    int wt[] = {2,3,4,5};
    int val[] = {3,4,5,6};

    cout << "Maximum Profit :" << knapSack(W, wt, val, n);
    return 0;
}
