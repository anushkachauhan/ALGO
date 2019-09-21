#include <bits/stdc++.h>

using namespace std;

vector<int> LIS(vector<int> &arr)
{
    vector<int> lis_count(arr.size(), 1);
    int lis_max = 1;
    int max_idx = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis_count[i] = max(lis_count[i], lis_count[j] + 1);
                //    max_idx = lis_count[i] > lis_count[j] ? i : j;
            }
        }
        lis_max = max(lis_max, lis_count[i]);
    }

    // for(int i=0; i<lis_count.size(); i++)
    // {
    //     cout<<lis_count[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"maximum count for LIS is : "<<lis_max<<endl;
    // // cout<<"maximum idx for LIS is : "<<max_idx<<endl;
    return lis_count;
}

vector<int> LDS(vector<int> &arr)
{
    vector<int> lis_count(arr.size(), 1);
    int lds_max = 1;
    int max_idx = 0;

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        for (int j = arr.size() - 1; j >= i; j--)
        {
            if (arr[i] > arr[j])
            {
                lis_count[i] = max(lis_count[i], lis_count[j] + 1);
                //    max_idx = lis_count[i] > lis_count[j] ? i : j;
            }
        }
        lds_max = max(lds_max, lis_count[i]);
    }

    // for(int i=0; i<lis_count.size(); i++)
    // {
    //     cout<<lis_count[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"maximum count for LDS is : "<<lds_max<<endl;
    // // cout<<"maximum idx for LIS is : "<<max_idx<<endl;
    return lis_count;
}

int bitonic(vector<int> &arr)
{
    //    for(int i =0; i<)
    vector<int> ldCount = LDS(arr);
    vector<int> liCount = LIS(arr);
    int mymax=1;
    for(int i = 0; i < arr.size(); i++)
    {
        /* code */
        mymax=max(mymax,ldCount[i]+liCount[i]-1);
    }

    return mymax;
    
}

int main(int argc, char **argv)
{
    vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    // LIS(arr);
    // cout << endl;
    // LDS(arr);
    cout<<bitonic(arr)<<endl;
}