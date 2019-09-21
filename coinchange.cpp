#include<bits/stdc++.h>

using namespace std;

int coinchange_per(vector<int> &coins, int amt)
{
    // amt is the amount to be paid 
    vector<int> strg(amt+1, 0);
    strg[0] =1;

    for(int i=1; i<=amt; i++)
    {
       for(int j=0; j<coins.size(); j++){
           if(i>= coins[j])
           {
               strg[i] += strg[i - coins[j]];
           }
       }
        
    }
    return strg[amt];
}

int coinchange_comb(vector<int> &coins, int amt)
{
    // amt is the amount to be paid 
    vector<int> strg(amt+1, 0);
    strg[0] =1;

    for(int j=0; j<coins.size(); j++)
    {
       for(int i=1; i<=amt; i++ ){
           if(i>= coins[j])
           {
               strg[i] += strg[i - coins[j]];
           }
       }
        
    }
    return strg[amt];
}

int main(int argc, char** argv){

     vector<int> coins{2,5,3};
     cout<<"no. of combinations : "<< coinchange_comb(coins, 7)<<endl;
     cout<<"no. of permutations : "<< coinchange_per(coins, 7)<<endl;
}
