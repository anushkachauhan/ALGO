#include <bits/stdc++.h>

using namespace std;

void bigsq(vector<vector<int>> &sq)
{
    vector<vector<int>> strg(sq.size(), vector<int>(sq[0].size(), 0));

    int myres = 0;

    for (int i = strg.size() - 1; i >= 0; i--)
    {
        for (int j = strg[0].size() - 1; j >= 0; j--)
        {
            if (i == strg.size() - 1 && j == strg[0].size() - 1)
            {
                strg[i][j] = sq[i][j];
            }
            else if (i == strg.size() - 1)
            {
                strg[i][j] = sq[i][j];
            }
            else if (j == strg[0].size() - 1)
            {
                strg[i][j] = sq[i][j];
            }
            else
            {
                if (sq[i][j] == 1)
                {
                    strg[i][j] = min(strg[i][j + 1], min(strg[i + 1][j + 1], strg[i + 1][j])) + 1;
                    myres = max(myres, strg[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < strg.size(); i++)
    {
        for (int j = 0; j < strg[0].size(); j++)
        {
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    cout << myres << endl;
}

int main(int argc, char **argv)
{
    vector<vector<int>> sq{
        {0, 1, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {1, 1, 0, 0, 0, 1, 1}};

    bigsq(sq);
}