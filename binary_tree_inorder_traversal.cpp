// In InOrder traversal, the tree is traversed in this way: left, root, right

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *buildTree(TreeNode *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new TreeNode(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left node: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right node: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void InOrderRecursive(TreeNode *root, vector<int> &ans)
{
    // Base Case
    // If we encounter a node pointing to NULL.
    if (root == NULL)
    {
        // We simply return to its parent.
        return;
    }

    // We first recursively visit the left child and go on till we find a leaf node.
    InOrderRecursive(root->left, ans);

    // Then we store that node value in ans vector called by reference
    ans.push_back(root->data);

    // Then we recursively visit the right child.
    InOrderRecursive(root->right, ans);
}

vector<int> InOrderIterative(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    // We first take an explicit stack data structure
    stack<TreeNode *> st;
    /*
    Stack is a Last-In-First-Out (LIFO) data structure, therefore when we encounter a node, 
    we simply push it to the stack and try to find nodes on its left. 
    When the current node points to NULL, it means that there is nothing left to traverse and we should move to the parent. 
    This parent is always placed at the top of the stack. If the stack is empty, 
    then we had already traversed the whole tree and should stop the execution.
    */

    while(true)
    {
        // In every iteration we check whether our current node is 
        // pointing to NULL or not.
        if(root != NULL)
        {
            // If it is not pointing to null, we simply push the current value 
            // to the stack and move the current node to its left child.
            st.push(root);
            root = root->left;
        }

        // If it is pointing to NULL, 
        else
        {
            // We first check whether the stack is empty or not. 
            // If the stack is empty, it means that we have traversed the tree 
            // and we break out of the loop.
            if(st.empty()) break;

            // If the stack is not empty, we pop the top value of the stack, 
            root = st.top();
            st.pop();

            // Store it to ans vector
            ans.push_back(root->data);

            // Move the current node to its right child.
            root = root->right;
        }
    }     
    return ans;
}

void Print1D(vector<int> toPrint)
{
    int n = toPrint.size();

    for (int i = 0; i < n; i++)
    {
        cout << toPrint[i] << " ";
    }
    cout << endl;
}

int main()
{
    TreeNode *root = NULL;

    // creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    vector<int> ans1;
    InOrderRecursive(root, ans1);
    Print1D(ans1);

    vector<int> ans2 = InOrderIterative(root);
    Print1D(ans2);
}
