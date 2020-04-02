Given an array of 5 elements. (You can modify to n elements).

Convert this array to Height balanced Binary Search Tree (AVL Tree).

Input: 6 5 3 1 4
output : 1 3 4 5 6

                     4
                    / \
                   3   5
                  /     \
                 1        6
---------------------------------------------------------------------------------------------------------------------------------------------
1.Sort the array
2.Make the middle element as root node and 
root->left will be left of mid 
root->right will be right of mid
--------------------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include<bits/stdc++.h>

using namespace std;


struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode TreeNode;
void inorder(TreeNode *p)
{
    if(p ==  NULL)
     return;
     
    inorder(p->left);
    cout<<p->val;
    inorder(p->right);
}

TreeNode *create(vector <int> v ,int start ,int end)
{
    if(start > end)
    {
        return NULL;
    }
    
    int mid = start + (end - start) /2;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = v[mid];
    root->left = create(v,start ,mid-1);
    root->right = create(v,mid+1 , end);
    
    
    return root;
}
TreeNode *createAVL(vector <int> v)
{
    sort(v.begin(),v.end());
    
    return create(v,0,v.size()-1);
}

int main() {
	vector <int> v(5);
	
	for(int i=0;i<5;i++)
	  cin>>v[i];
	  
	 TreeNode *root = createAVL(v);
	 inorder(root);
	return 0;
}
