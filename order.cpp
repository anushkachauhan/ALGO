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

int search(int data, vector<int>& in){
    int i=0;
    for( i=0; i<in.size(); i++){
        if(in[i] == data){
            return i;
        }
    }
    return i;
}

Node* construct1(vector<int>& pre, vector<int>& in, int Sindex, int endidx){
    Node* root = NULL;
   

    if(Sindex > endidx){
        return NULL;
    }

    int rootdata = pre[Sindex];
    int idx = search(rootdata, in);// this  will return us root --> give us the index where the root lie in inorder
    
    
    
        endidx = idx -1;
        root->left = construct1(pre, in, Sindex+1, endidx );
        
   
    
        Sindex = idx+1;
        endidx = in.size();
        root->right = construct1(pre, in, Sindex, endidx );
        
    
    
   return root;
    
}

Node* construct2(vector<int>& post, vector<int>& in, int plo, int phi, int ilo, int ihi){
     if(plo > phi || ilo > ihi){
        return NULL;   
    }

    Node* root = new Node(post[phi]);
    int lhs =0;

    while(in[ilo+lhs] != post[phi]){
        lhs++;
    }

    root->left = construct2(post, in, plo, plo+lhs-1, ilo , ilo+lhs-1 );
    root->right = construct2(post, in, plo+lhs, phi-1, ilo+lhs+1, ihi);

    return root;
}

Node* construct1_sir(vector<int>& pre, vector<int>& in, int plo, int phi, int ilo, int ihi){  
     if(plo > phi || ilo > ihi){
        return NULL;   
    }

    Node* root = new Node(pre[plo]);
    int lhs =0;
    while(in[ilo+lhs] != pre[plo]){
        lhs++;
    }

    root->left = construct1_sir(pre, in, plo+1, plo+lhs, ilo , ilo+lhs-1 );
    root->right = construct1_sir(pre, in, plo+lhs+1, phi, ilo+lhs+1, ihi);

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

Node* data_parent(vector<int>& da, vector<int>& parent){
     
     Node* root =NULL;
     vector<Node*> narr(1000,NULL);

     for(int i =0; i< da.size(); i++){
       narr[da[i]] = new Node(da[i]);
    }

    for(int i=0; i<da.size(); i++){
          int data = da[i];
          int pdata= parent[i];

          Node* node = narr[data];
              Node* par = narr[pdata];


          if(pdata == -1){
               root = node;
            }
          else{
              if(par->left == NULL){
                  par->left =  node;
              }
              else{
                  par->right =  node;
              }
            }
    // return root;
    }
    
    return root;
  
}

Node* construct4(vector<int>&pre, vector<int>&post, int plo, int phi, int polo, int pohi){
 
 Node* root = new Node(pre[plo]);
 if(plo == phi){
        return root;   
    }

    int lhs =0;
    while(pre[plo+1] != post[polo+lhs]){
        lhs++;
    }

    root->left = construct4(pre, post, plo+1, plo+lhs+1, polo,polo+lhs  );
    root->right = construct4(pre, post, plo+lhs+2 , phi, polo+lhs+1, pohi-1);

    return root;

}

int height(Node* node){
    if(node == NULL){
        return 0;
    }

    return 1+ max(height(node->left), height(node->right));
}

int diameter(Node* node){

    if(node == NULL){
        return 0; 
    }

    int lheight = height(node->left);
    int rheight = height(node->right);

    int ldia = diameter(node->left);
    int rdia = diameter(node->right);

    return max(1+ lheight+ rheight, max(ldia, rdia));
}

class diapair{

    public:
      int ht =0;
      int dia = 0;
};

diapair* diameter2(Node* root){
    if(root == NULL){
        diapair* bp = new diapair();
        bp->ht = 0;
        bp->dia = 0;
        return bp;
    }

    diapair* lp = diameter2(root->left);
    diapair* rp = diameter2(root->right);

    diapair* mp = new diapair();

    mp->ht = max(lp->ht, rp->ht);
    mp->dia = max(lp->ht + rp->ht+1, max(lp->ht, rp->ht)); 

    return mp;
}

class balanced{
    public:
      int ht = 0;
      bool isbal = true;
};

bool isbalanced(Node * root){
      if(root == NULL){
          return 0;
      }
    
    int left = height(root->left);
    int right = height(root->right);

    int gap = abs(left - right);

    if(gap<=1){
        return true;
    }else{
        return false;
    }
}

balanced* isbalanced2(Node* root){
    if( root == NULL){
        balanced* bp = new balanced();
        bp->ht = 0;
        bp->isbal = true;
        return bp;
    }

    balanced* lp = isbalanced2(root->left);
    balanced* rp = isbalanced2(root->right);

    balanced* my = new balanced();
    int gap = lp->ht - rp->ht;
    my->ht = max(lp->ht , rp->ht )+1;
    my->isbal = lp->isbal && rp->isbal && gap>=-1 && gap<= 1;
    return my;
}

class BSTpair{
     public:
        int min = INT_MAX;
        int max = INT_MIN;
        bool isBST;
};

BSTpair* isBST(Node* root){
    if(root == NULL){
         BSTpair* bp = new BSTpair();
         bp->isBST = true;
         bp->max = INT_MIN;
         bp->min = INT_MAX;
         return bp; 
      }

    BSTpair* lp = isBST(root->left);
    BSTpair* rp = isBST(root->right);
    
   BSTpair* mp = new BSTpair();
   mp->min = min(root->data, min(lp->min, rp->min));
   mp->max = max(root->data, max(lp->max, rp->max));
   mp->isBST = lp->isBST &&
               rp->isBST &&
               root->data >lp->max &&
               root->data <rp->min;

    return mp;           

}

class LBSTpair{    /////// largest BST 
     public:
        int min = INT_MAX;
        int max = INT_MIN;
        bool isBST;
        int lbstroot;
        int lbstsize;
};

LBSTpair* isLBST(Node* root){
    if(root == NULL){
         LBSTpair* bp = new LBSTpair();
         bp->isBST = true;
         bp->max = INT_MIN;
         bp->min = INT_MAX;
         bp->lbstroot =-1;
         bp->lbstsize = 0;
         return bp; 
      }

    LBSTpair* lp = isLBST(root->left);
    LBSTpair* rp = isLBST(root->right);
    
   LBSTpair* mp = new LBSTpair();
   mp->min = min(root->data, min(lp->min, rp->min));
   mp->max = max(root->data, max(lp->max, rp->max));
   mp->isBST = lp->isBST &&
               rp->isBST &&
               root->data >lp->max &&
               root->data <rp->min;

    if(mp->isBST == true){
        mp->lbstroot = root->data;
        mp->lbstsize = lp->lbstsize +rp->lbstsize+1;
    }           
    else{
        if(lp->lbstsize>rp->lbstsize){
            mp->lbstroot = lp->lbstroot;
            mp->lbstsize = lp->lbstsize;
        }
        else{
            mp->lbstroot = rp->lbstroot;
            mp->lbstsize = rp->lbstsize;
        }
    }

    return mp;           

}

int main(int argc, char** argv){
    vector <int> dlist{50,25,12,-1,37,30,-1,40,-1,-1,-1,75,62,60,-1,70,-1,-1,87,-1,-1,-1};
    // vector<int> in {12,25,37,40,50,62,75,87};
    // vector<int> post { 12,40,37,25,62,87,75,50};
    // vector<int> pre{50,25,12,37,40,75,62,87};
    
    // Node* root =construct1(pre, in, 0, 7);
    // display(root);

    // Node* root1 =construct1_sir(pre, in, 0, 7, 0, 7);
    // Node* root2 = construct2(post, in, 0, 7, 0,7);

    // //display(root1);
    // cout<<"************************"<<endl;
    // display(root2);

    // vector<int> dataArr{ 12, 25, 50, 75, 37, 87, 40, 80};
    // vector<int> parent{ 25, 50, -1, 50, 25, 75, 37, 87};

    // Node* root3 =data_parent(dataArr, parent);
    // display(root3);

    vector<int> pre{ 1,2,4,8,9,5,3,6,7};
    vector<int> post{ 8,9,4,5,2,6,7,3,1};
    Node* root4 = construct(dlist);
    // display(root4);

    // cout<<height(root4)<<endl;

    // cout<<diameter(root4);

    balanced* Bal = isbalanced2(root4);
    cout<<Bal->isbal<<endl;

    vector<int> prebst{50,25,12,37,30,40,75,62,60,70,87,90};
    vector<int> inbst{12,25,30,37,40,50,60,62,70,75,87,90};

    Node* rootpre = construct1_sir(prebst, inbst,0,11,0,11);

    BSTpair* pair1 = isBST(rootpre);
    cout<<"check if it is BST or not : "<<pair1->isBST<<endl;

    LBSTpair* p2 = isLBST(rootpre);
    cout<<p2->lbstsize<<" "<<p2->lbstroot<<" "<<endl;
}
