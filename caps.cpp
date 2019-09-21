#include<bits/stdc++.h>
using namespace std;

int reccaps(vector<vector<int>> &caphaveper, vector<bool> &caps, int cp, int tp)
{
  
    if(cp == tp)
    {
        return 1;
    
    }
        int myres  =0;

    for(int i=0; i< caphaveper[cp].size(); i++){

      if(caps[caphaveper[cp][i]] == false )
      {
          caps[caphaveper[cp][i]] = true;
          int res = reccaps(caphaveper, caps, cp+1, tp);
          myres = myres+res;
          caps[caphaveper[cp][i]] = false;

      }
    }
    return myres;
}

int countpartyBMDDP(int cp, int tp, int captaken, vector<vector<int>>&pmap, vector<vector<int>> &strg)
{
    if(cp == tp)
    {
        return 1;
    }
    if(strg[cp][captaken] != 0)
    {
        return strg[cp][captaken];
    }
    int myres = 0;

    for(int i=0; i<pmap[cp].size(); i++)
    {
        int cap = pmap[cp][i];
        if((captaken & (1<<cp)) == 0)
        {
            int res = countpartyBMDDP(cp+1, tp, (captaken | (1<<cap)), pmap, strg);
            myres += res; 
        }
        strg[cp][captaken] = myres;
    }
    return myres;
}

int reccapsBM(vector<vector<int>> &caphaveper, int captaken, int cp, int tp)
{
    
    if(cp == tp)
    {
        return 1;
    
    }
        int myres  =0;

    for(int i=0; i< caphaveper[cp].size(); i++){
        int cap = caphaveper[cp][i];

        if((captaken & (1<<cap)) == 0 )
        {
          captaken = captaken^(1<<cap);
          int res = reccapsBM(caphaveper, captaken, cp+1, tp);
          myres = myres+res;
          captaken = captaken^(1<<cap);

        }

    //   myres = count;
    }
    return myres;
}



//when we have large number of caps and caps are at level + persons aare at options for each cap present at a perticular level
int capatlevel(vector<vector<int>> &caphaveper, vector<bool> &person, int cc, int tc)
{
  
  // cc = current cap 
  // tc = total cap

    if(cc == tc)  
    {
        for(int i =0; i<)
        return 0;
    }
        int myres  = 0;
      capatlevel(caphaveper, person, cc+1, tc);


     for(int i=0; i< caphaveper[cc].size(); i++){

       if(person[caphaveper[cc][i]] == false )
      {
          person[caphaveper[cc][i]] = true;
          int res = capatlevel(caphaveper, person, cc+1, tc);
          myres = myres+res;
          person[caphaveper[cc][i]] = false;

      }
    }
    return myres;
}

int main(int argc, char** argv)
{
    int persons = 3;
    int caps = 20;
    int caplevel = 100;

    vector<bool>capsv(caps, false);
    vector<bool>personv(caps, false);


    vector<vector<int>> caphaveper{ // 
     {5,7,19},
     {2,7},
     {19,5}
    };

    vector<vector<int>> strg(persons, vector<int>(1<<caps, 0));

    //cout<<reccaps(caphaveper, capsv, 0, persons);
    // cout<<reccapsBM(caphaveper,0,0,persons)<<endl;
    // cout<<countpartyBMDDP(0, persons, 0, caphaveper, strg);
    cout<<capatlevel(caphaveper, personv, 0, caplevel);
  
}