#include<bits/stdc++.h>

using namespace std;


//when we have large number of caps and caps are at level + persons aare at options for each cap present at a perticular level
int capatlevel(vector<vector<int>> &cpmap, vector<bool> &takenperson, int cc)
{
  
  // cc = current cap 
  // tc = total cap

    if(cc == cpmap.size())  // means current caps are = to total number of caps
    {
        for(int i =0; i<takenperson.size(); i++)
        {
            if(takenperson[i] == false)
            {  
                 return 0;
            }
        }
        return 1;
    }
        int myres  = 0;
        myres += capatlevel(cpmap, takenperson, cc+1);


     for(int i=0; i< cpmap[cc].size(); i++){
       
       if(takenperson[cpmap[cc][i]] == false )
      {
          takenperson[cpmap[cc][i]] = true;
          int res = capatlevel(cpmap, takenperson, cc+1);
          myres = myres+res;
          takenperson[cpmap[cc][i]] = false;

      }
    }
    return myres;
}

int capatlevelBM(vector<vector<int>> &cpmap, int cc,int pbm, int tp)
{
  
  // cc = current cap 
  // tc = total cap
  // pbm - person bitmask

    if(cc == cpmap.size())  // means current caps are = to total number of caps
    {
        if(pbm == ((1<<tp) -1))
        {  
           return 1;
        }
        
        return 0;
    }
        int myres  = 0;
        myres += capatlevelBM(cpmap, cc+1, pbm, tp);


     for(int i=0; i< cpmap[cc].size(); i++){
         int person = cpmap[cc][i];
       
       if( (pbm &(1<<person)) ==0 )
      {
          int res = capatlevelBM(cpmap, cc+1, pbm|(1<<person) , tp);
          myres = myres+res;
      }
    }
    return myres;
}

int capatlevelBMDP(vector<vector<int>> &cpmap, int cc, vector<vector<int>> &strg, int pbm, int tp)
{
        if(cc == cpmap.size())  // means current caps are = to total number of caps
    {
        if(pbm == ((1<<tp) -1))
        {  
           return 1;
        }
        
        return 0;
    }
        int myres  = 0;
        myres += capatlevelBMDP(cpmap, cc+1, strg, pbm, tp);
        if(strg[cc][pbm] != 0 )
        {
            return strg[cc][pbm];
        }


     for(int i=0; i< cpmap[cc].size(); i++){
         int person = cpmap[cc][i];
       
       if((pbm &(1<<person)) == 0 )
      {
          int res = capatlevelBMDP(cpmap, cc+1, strg, pbm|(1<<person), tp);
          myres = myres+res;
      }
    }
    strg[cc][pbm] = myres;
    return myres;
}


//tabulation
int captab(vector<vector<int>> &cpmap, int tp)
{
    vector<vector<int>> strg(cpmap.size() -1, vector<int> (1<<tp , 0));

    for(int i = strg.size() -1; i>=0; i--)
    {
        for(int j = strg[i].size() - 1; j>=0; j--)
        {
            // last cell
            if(i == strg.size() -1 && j == strg.size() -1)
            {
                strg[i][j] = 1;
            }
            else if(i == strg.size() -1)
            {
                strg.size() = 0;
            }
            else if(j == strg.size() -1)
            {
                strg[i][j] = 1;
            }
            else
            {
                strg[i][j] = strg[i+1][j];

                for(int p =0; o<cpmap[i].size(); p++)
                {
                    int person = cpmap[i][p];
                    if((j & (1<<person)) == 0)
                    {
                        strg[i][j] += strg[i+1][j | (1<<person)];
                    }
                }
            }
            
        }
    }
    return strg[0][0];
}

int main(int argc, char** argv)
{
    int caps = 4;
    int persons = 3;

    vector<vector<int>> pcmap{
        {1,3},
        {1,2,3},
        {0,2}
    };

    vector<vector<int>> cpmap(caps);

    for(int p = 0; p < pcmap.size(); p++)
    {
        for(int ci =0; ci< pcmap[p].size(); ci++)
        {
            int cap = pcmap[p][ci];
            cpmap[cap].push_back(p);
        }
    }

    for(int p = 0; p < cpmap.size(); p++)
    {
        for(int ci =0; ci< cpmap[p].size(); ci++)
        {
            cout<<cpmap[p][ci]<<" ";
        }
        cout<<endl;
    
    }

    vector<vector<int>> strg (caps, vector<int>(1<<persons, 0));

    cout<<cpmap[0].size()<<endl;
    vector<bool> takenperson(persons, false);
    cout<<endl;
    cout<<"count : "<<capatlevel(cpmap, takenperson, 0)<<" "<< endl;
    cout<<capatlevelBM(cpmap, 0, 0, persons)<<endl;
    cout<<capatlevelBMDP(cpmap, 0, strg, 0, persons);
}