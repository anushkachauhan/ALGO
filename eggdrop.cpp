#include<bits/stdc++.h>

using namespace std;

void eggd(int floors, int eggs)
{
    vector<vector<int>> strg(eggs+1, vector<int>(floors+1, 0));

   for(int e =1; e<= eggs; e++)
   {
       for(int f = 0; f<=floors; f++)
       {
           if(e == 1 || f == 0 || f == 1)
           {
               strg[e][f] = f;
           }
           else
           {
               strg[e][f] = INT_MAX;
               for(int k=1; k<=f; k++)
               {
                   int eb =strg[e-1][k-1]; //  agar mera egg break kr jata hai toh hum niche wale floor check karenge or 1 egg kam ho jayega as it broke
                   int es = strg[e][f-k]; // agar survive kr raha hai toh no of e toh same rahege and we've to check for the rest above floors

                   int bl = max(eb, es);  //  this badluck will have the max of our X and $ attempt
                   strg[e][f] = min(strg[e][f], bl); // gauranteed 
               }
               strg[e][f]++;
           }
           
       }
   }

       for(int i=0; i < strg.size(); i++)
       {
           for(int j =0; j< strg[0].size(); j++)
           {
               cout<<strg[i][j]<<" ";
           }
           cout<<endl;
       }
    cout<<strg[eggs][floors];
}

int main(int argc, char** argv)
{
    int flor = 10;
    int egg = 2;

    eggd(flor, egg);

}