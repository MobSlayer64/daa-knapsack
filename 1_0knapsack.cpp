#include<iostream>
using namespace std;

class sack 
{
private:
    int n, W;
    int weight[10];
    int profit[10];
    int B[100][100];

public:
    void input() 
    {
        cout << "Enter number of items : " << endl;
        cin >> n;

        cout << "Enter profits of the items : " << endl;
        for(int i = 0; i < n; i++) 
        {
            cin >> profit[i];
        }

        cout << "Enter weights of the items : " << endl;
        for(int i = 0; i < n; i++) 
        {
            cin >> weight[i];
        }

        cout << "Enter maximum capacity : " << endl;
        cin >> W;
    }

    void knapsacksolve() 
    {
        for (int i = 0; i <= n; i++) 
        {
            for (int w = 0; w <= W; w++) 
            {
                B[i][w] = 0;
            }
        }

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 0; j <= W; j++) 
            {
                if (weight[i - 1] <= j) 
                {
                    if (profit[i - 1] + B[i - 1][j - weight[i - 1]] > B[i - 1][j]) 
                    {
                        B[i][j] = profit[i - 1] + B[i - 1][j - weight[i - 1]];
                    } else 
                    {
                        B[i][j] = B[i - 1][j];
                    }
                } else 
                {
                    B[i][j] = B[i - 1][j];
                }
            }
        }
    }

    void backtrackItems()
    {
        int selected[10];
        int count = 0;
        int i = n;
        int j = W;

        while (i > 0 && j >= 0)
        {
            if (B[i][j] != B[i - 1][j])
            {
                selected[count++] = i - 1;
                j -= weight[i - 1];
            }
            i--;
        }

        cout << "\nSelected items for maximum profit (1-based index): ";
        if (count == 0)
        {
            cout << "None";
        }
        else
        {
            for (int k = count - 1; k >= 0; k--)
            {
                cout << (selected[k] + 1) << " ";
            }
        }

        int totalWeight = 0;
        int totalProfit = 0;

        for (int k = 0; k < count; k++)
        {
            totalWeight += weight[selected[k]];
            totalProfit += profit[selected[k]];
        }

        cout << "\nTotal selected weight = " << totalWeight;
        cout << "\nTotal selected profit = " << totalProfit << endl;
    }

    void display() 
    {
        cout << "\nDP Table:\n\n";

        cout << "    ";
        for(int j = 0; j <= W; j++) 
        {
            cout << j << "   ";
        }
        cout << endl;

        for(int i = 0; i <= n; i++) 
        {
            cout << i << " | ";
            for(int j = 0; j <= W; j++) 
            {
                cout << B[i][j] << "   ";
            }
            cout << endl;
        }

        cout << "\nMaximum value in knapsack = " << B[n][W] << endl;
        backtrackItems();
    }
};

int main() 
{
    sack obj;
    obj.input();
    obj.knapsacksolve();
    obj.display();
    return 0;
}