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

Node* construct(vector<int> &dlist, int start, int end){

    if(start> end){
        return NULL;
    }
    int mid = (start+end)/2;

    Node* root = new Node (dlist[mid]);

    root->left = construct(dlist, start, mid-1);
    root->right = construct(dlist, mid+1, end);
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

int mymin(Node* root){
    if(root == NULL){
      return 0;
    }
    
    if(root->left != NULL){
        return mymin(root->left);
    }else{
        return root->data;
    }
  
}

int mymax(Node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

bool find(Node* root, int data){
   if( root == NULL ){
       return false;
   }
   else if(data > root->data ){
       return find(root->right, data);
   }
   else if(data < root->data){
       return find(root->left, data);
   }else{
       return true;
   }
}

void printInRange(Node* root, int lo, int hi){
    
    if(root == NULL){
        return;
    }
    if(lo > root->data){
        printInRange(root->left, lo, hi);
    }
    else if(hi < root->data){
        printInRange(root->right, lo, hi);
    }
    else{
        printInRange(root->left, lo, hi);
        cout<< root->data<<" ";
        printInRange(root->right, lo, hi);
    }
}

void replace(Node*root, int &sum){
    
    if(root == NULL){
        return;
    }
    replace(root->right, sum);

    int orv = root->data;
    root->data = sum;
    sum += orv;  

    replace(root->left, sum);

}

// void pairsum(Node* root, int tar, vector<int>& dlist){
//     if(root == NULL){
//         return;
//     }
    
//     int l =0; 
//     int r = dlist.size() -1;
//     bool chk = find(root, tar);
//     if(chk == true){
//         if(l<r){
            
//         }
//     }
// }

void pairsum2(Node* oroot, Node* root, int tar ){
    if(root== NULL){
        return ;
    }

    int comp = tar - root->data; // complement
    if(root->data <comp){
        if(find(oroot, comp) == true){
            cout<<root->data<<" "<<endl;
        }
    }
    pairsum2(oroot, root->left, tar);
    pairsum2(oroot, root->right, tar);
}

void filler(Node* root, vector<int>& list){
    if(root == NULL){
        return;
    }
    filler(root->left, list);
    list.push_back(root->data);
    filler(root->right, list);
}

void pairsum3(Node* root, int tar){
    
    if(root == NULL){
        return;
    }
    vector<int> list;
    filler(root, list);  // it'll get the sorted list from filler --> as it s the bst it will be sorted phele se hi

    int li =0;
    int ri =list.size()-1;

    while(li<=ri){

        if(list[li]+list[ri] <tar){
            li++;
        }
        else if(list[li]+list[ri] >tar){
                ri --;
        }
        else{
            cout<<list[li] <<" "<< list[ri]<<endl;
            li++;
            ri--;
        }
    }
}


Node* add(Node*root, int data){

    if(root == NULL){
        root = new Node(data);
        return root;
    }else if(root->data > data){
        root->left = add(root->left, data);
    }
    else if(root->data < data){
        root->right = add(root->right, data);
    }
   return root;
}

Node* remove(Node* root, int data){

    if(root == NULL){
       return NULL;
    }
    if(data > root->data){
        root->right = remove(root->right, data);
    }
    else if(data < root->data){
        root->left = remove(root->left, data);
    }
    else{
          if(root->left != NULL && root->right != NULL){
              int lmax = mymax(root->left);  // calculate the max from the LHS tree and make it the root
              root->data = lmax;
              root->left = remove(root->left, lmax);
          }
          else{
              Node* temp = root;
              root = root->left != NULL?root->left : root->right;
              delete temp;
          }
        //   else if(root->left != NULL){
        //       Node* temp = root;
        //       root= root->left;
        //       delete root;
        //   }
        //   else if(root->right != NULL){
        //       Node* temp = root;
        //       root = root->right;
        //       delete root;
        //   }else{
        //       Node* temp = root;
        //       root = NULL;
        //       delete temp;
        //   }
    }
    return root;
    // if(data == root->data && root->left && root->right == NULL){  // having one child on left side

    // }
    // if(data == root->data && root->right && root->left == NULL){  // having one child on right side

    // }
    // if(data == root->data && root->right && root->left)
}


int countBST(int n){
    if(n ==0 || n == 1){
        return 1;
    }
    int count = 0;
    for(int i =0; i<n; i++){
        count += countBST(i)+countBST(n-i-1);
    }
    return count;
}

int main(int argc, char** argv){
  
//   vector<int> dlist {12,25,37,50,62,75,87};
//   Node* root = construct(dlist, 0, 6);
// //   display(root);
//   cout<<endl;
//   printInRange(root, 25, 60);

//   int sum =0;
//   replace(root, sum);
//   display(root);
  
  vector<int>list {10,20,30,40,50,60,70,80,90};
  Node* rr=construct(list,0,8);
//   pairsum3(rr, 100 );
//   pairsum2(root, root, 50);
//    add(rr, 25);
//    display(rr);
//    cout<<"****************************************"<<endl;
//    remove(rr, 90);
//    display(rr);

   cout<<"count of BSTs : "<<countBST(3);
}