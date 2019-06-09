#include<iostream>
#include<list>
#include<climits>
#include<vector>
#include<bits/stdc++.h>


using namespace std;

class Node
{

  public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
       this->data = data;
       this->left = NULL;
       this->right = NULL;
    }
};

Node* construct(vector<int> &dlist){

    Node* root = NULL;
    vector<Node*>* nlist = new vector <Node*>();  // new list

    for(int i=0; i<dlist.size(); i++){

        if(dlist[i] == -1){
            nlist->pop_back();
        }
        else{
            Node* nn =  new Node(dlist[i]);  // newnode
            if(nlist->size() == 0){
                root = nn;
            }
            else{
                Node* lastn = nlist->back(); // back will give the content the content 
                if(lastn->left == NULL){
                    lastn->left = nn;
                }else{
                    lastn->right = nn;  
                }
            }
            nlist->push_back(nn);
        }
    }
    return root;

}

void display(Node* root){

    if(root->left != NULL && root->right != NULL){
        cout<<root->left->data<<"<-"<<root->data<<"->"<<root->right->data<<endl;
        display(root->left);
        display(root->right);
    }
    else if(root->left != NULL){
        cout<<root->left->data<<"<-"<<root->data<<"."<<endl;
        display(root->left);
    }
    else if(root->right != NULL){
        cout<<"."<<root->data<<"->"<<root->right->data<<endl;
        display(root->right);
    }
    else{
        cout<<"."<<root->data<<"."<<endl;
    }
    
}

// traverse the tre using the following 3 methods used for size

int size1(Node* root){   // reactive method
    if(root == NULL){
        return 0;
    }
    int ls = size1(root->left);
    int rs = size1(root->right);
    return ls +rs +1;

}


int size2(Node* root){   // pro active method
    int ls =0;
    int rs =0;
    if(root->left != NULL){
        ls = size2(root->left);
    }
    if(root->right != NULL){
        rs = size2(root->right);
    }
    return ls+rs+1;
}

int size3(Node* root){

    int ls = 0; 
    int rs = 0;

    if(root->left != NULL && root->right != NULL){
        ls = size3(root->left);
        rs = size3(root->left);
    }
    else if(root->left != NULL){
        ls = size3(root->left);
    }
    else if(root->right != NULL){
        rs = size3(root->right);
    }
    else
        return ls+rs+1;
    
   // return ls+rs+1;
}

int mymax1(Node* root){

   int rm1 = INT_MIN; 
   int rm2 = INT_MIN;
   int rm3 = INT_MIN;
    
    if(root->left){
       int cm = mymax1(root->left); //child max
       rm1 = max(rm1, cm);  // root max
    }
    
    if(root->right){
       int cm = mymax1(root->right); //child max
       rm2 = max(rm2, cm);  // root max
    }
   
   rm3 = max(rm1, rm2);
   rm3 = max(rm3, root->data);
   return rm3;

}
int sum(Node* root){   // reactive method
    if(root == NULL){
        return 0;
    }
    int ls = sum(root->left);
    int rs = sum(root->right);
    return (ls +rs + root->data);

}
int mymax(Node* root){   // reactive method
    if(root == NULL){
        return 0;
    }
    int lm = mymax(root->left);
    int rm = mymax(root->right);
    return max(root->data, max(lm, rm));

}

bool find(Node* root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        return true;
    }
    bool fil = find(root->left, data);  // found in left path
    if(fil == true){
        return true;
    }
    bool finr = find(root->right, data);  // find in right path
    if(finr == true){
        return true;
    }
    return false;
}

vector<int>* n2rp(Node* root, int data){    // node to root path
    
    vector<int>* ml = NULL;
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
         ml = new vector<int>();
         ml->push_back(root->data);
         return ml;
    }
    
    ml = n2rp(root->left, data); //node to left path
    if(ml != NULL){
        ml->push_back(root->data);
        return ml; 
    }
    ml = n2rp(root->right, data); //node to right path
    if(ml != NULL){
        ml->push_back(root->data);
        return ml; 
    }
    return ml;
}

void kdown(Node* root, int k){

 if(root == NULL){
     return ;
 }  
 if(k == 0 ){
     cout<<root->data;
     return;
 }
 kdown(root->left, k-1);
 kdown(root->right, k-1);
   
}

vector<Node*>* n2rp2(Node* root, int data){    // node to root path
    
    vector<Node*>* ml = NULL;
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
         ml = new vector<Node*>();
         ml->push_back(root);
         return ml;
    }
    
    ml = n2rp2(root->left, data); //node to left path
    if(ml != NULL){
        ml->push_back(root);
        return ml; 
    }
    ml = n2rp2(root->right, data); //node to right path
    if(ml != NULL){
        ml->push_back(root);
        return ml; 
    }
    return ml;
}

// k down for prohibitor
void kdown_far(Node* root,  Node* phbt, int k){

 if(root == NULL || root == phbt){
     return ;
 }  
 if(k == 0 ){
     cout<<root->data;
     return;
 }
 kdown_far(root->left, phbt,k-1);
 kdown_far(root->right, phbt, k-1);
   
}

void kfar(Node* root, int d, int k){  
// d -> is from which element  (kis se far)
//  and k -> is kitne far
   
   vector<Node*>* n2rp = n2rp2(root, d);

   for(int i= 0; i<= k && i<n2rp->size(); i++){
       kdown_far(n2rp->at(i), i == 0 ? NULL: n2rp->at(i-1), k-i);
   }

}

// TO - Duplicate 

vector<Node*>* toduplicate(Node* root){
    
    Node* dup = 
}

void removeleaves1(Node* root){  // this will not work only gonna remove the the address of the node from the stack
    if(root == NULL){
    return;
   }
    if(root->left == NULL && root->right == NULL){
    
    root= NULL;
    return;
    }
 removeleaves1(root->left);
 removeleaves1(root->right);

}


void removeleaves2(Node* root){  // this will not work for the tree who is having only one node with no childs 
    if(root == NULL){
       return;
    }
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
        delete root->left;
        root->left = NULL;
    }
    if(root->right != NULL && root->right->left == NULL && root->right->right == NULL){
        delete root->right;
        root->right = NULL;
    }
 removeleaves2(root->left);
 removeleaves2(root->right);

}


Node* removeleaves(Node* root){

if(root == NULL){
    return NULL;
}
if(root->left == NULL && root->right == NULL){
    delete root;
    root = NULL;
    return root;
}

root->left = removeleaves(root->left);
root->right = removeleaves(root->right);

return root;
}


void printRootToLeafInRange(Node* root, int low, int high, vector<int>& path, int sum){
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->data);
        sum = sum +root->data;

        if(sum >= low && sum<=high){
            for(int i=0; i<path.size() ;i++){
                cout<<path[i]<<endl;
            }
        }
        path.pop_back();
        return;
    }
    printRootToLeafInRange(root->left, low, high, path, sum);
}

void printsingle(Node* root){  // print single child
    if(root == NULL){
        cout<<"null root";
        return;
    }

     if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
        return;
    } 
    if(root->right== NULL && root->left ){
        cout<<root->left->data<<" ";
    }
    if(root->left== NULL && root->right ){
        cout<<root->right->data<<" ";
    }
    printsingle(root->left);
    printsingle(root->right);


}

void filler(Node* root, vector<int>& list){
    if(root == NULL){
        return;
    }
     
    sort(list.begin(), list.end()); 
    filler(root->left, list);
    list.push_back(root->data);
    filler(root->right, list);
}

void pairsum3(Node* root, int tar){
    vector<int> list;
    filler(root->list, list);  // it'll get the sorted list from filler --> as it s the bst it will be sorted phele se hi

    int li =0, ri =list.size() -1;

    while(li<ri){

        if(list[li]+list[ri] <tar){
            li++;
        }
        else if(list[li]+list[ri] >tar){
                ri --;
        }
        else{
            cout<<list[li] << list[ri];
            li++;
            ri--;
        }
    }
}


int main(int argc, char** argv){

vector <int> dlist{50,25,12,-1,37,30,-1,40,-1,-1,-1,75,62,60,-1,70,-1,-1,87,-1,-1,-1};
vector<int> list1 = {
        1,2,4,6,-1,7,-1,-1,5,8,10,13,17,-1,18,-1,-1,14,-1,-1,11,15,19,22,-1,23,-1,-1,20,-1,-1,16,21,-1,-1,-1,-1,9,12,-1,-1,-1,-1,3,-1,-1
    };
Node* root = construct(dlist);
Node* root1 = construct(list1);
display(root);
// cout<<"mymax o/p :"<<mymax(root)<<endl;
// cout<<"mymax1 o/p : "<< mymax1(root)<<endl;
// cout<<"Sum : "<<sum(root)<<endl;
// cout<<"size1 : "<<size1(root)<<endl;
// cout<<"size2 : "<<size2(root)<<endl;
// cout<<"size3 : "<<size3(root)<<endl;
// cout<<"find 87 : "<<find(root, 87)<<endl;
// cout<<"path from root to 30 : ";
// vector<int>* print = n2rp(root, 30);
//     for(auto i=print->begin(); i != print->end(); i++){
//         cout<< *i<<" ";
//     }
cout<<"*****************************************"<<endl;
// kfar(root, 37, 1);
// cout<<endl;  
// removeleaves(root);
// removeleaves1(root);
// removeleaves2(root);
// display(root);
printsingle(root);
cout<<endl;  
display(root);

pairsum3(root, 50);
}



