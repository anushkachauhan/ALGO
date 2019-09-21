// COUNT PALLINDROMIC SUBSEUENCES

#include<bits/stdc++.h>

using namespace std;

int cps(string str)
{
    vector<vector<int>> strg(str.size(), vector<int>(str.size(),0));
    //// this storage is having the count of palindromes occured

    for(int gap = 0; gap<str.size(); gap++)
    {
        for(int i =0, j= i+gap ; j<str.size() ; i++, j++)
        {
            if(gap == 0)
            {
               strg[i][j] = 1;
            }
            // if matched
           else  if(str[i] == str[j])
            {
                strg[i][j] = strg[i][j-1] + strg[i+1][j] +1;

            } 
            else
            {
                strg[i][j] = strg[i][j-1] + strg[i+1][j] - strg[i+1][j-1];
            }
            
        }
    }


      for(int i=0; i< strg.size(); i++)
    {
        for(int j=0; j< strg[0].size(); j++)
        {
            cout<<strg[i][j]<<" ";
        }
        cout<<endl;
    }    

    return strg[0][str.size()-1];
}

int main(int argc, char** argv)
{
    string str = "acbkca";

    cout<<cps(str);
}