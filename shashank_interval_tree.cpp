#include<bits/stdc++.h>
using namespace std;
struct interval_node{
    int lower_val;
    int higher_val;
};
struct node{
    struct interval_node *interval;
    int max_val;
    bool color;
    struct node *left, *right, *parent;
};
/*for creating a new node*/
struct node *createNewNode (struct interval_node *it){
    struct node *temp= new struct node;
    temp->interval= new struct interval_node;
    temp->interval->lower_val = it->lower_val;
    temp->interval->higher_val = it->higher_val;
    temp->max_val = it->higher_val;
    temp->color = 1; // 1 denotes red
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*insertion*/
struct node *BST_Insertion(struct node *root, struct node *inter){
    if (root == NULL)
       return inter;
    if (inter->interval->lower_val < root->interval->lower_val)
    {
        root->left  = BST_Insertion(root->left, inter);
        root->left->parent = root;
    }
    else if (inter->interval->lower_val > root->interval->lower_val)
    {
        root->right = BST_Insertion(root->right, inter);
        root->right->parent = root;
    }
    if (root->max_val < inter->interval->higher_val)
        root->max_val = inter->interval->higher_val;
    return root;
}

struct node *leftRotation(struct node *root, struct node *inter){
    struct node *inter_right = inter->right;
 
    inter->right = inter_right->left;
 
    if (inter->right != NULL)
        inter->right->parent = inter;
 
    inter_right->parent = inter->parent;
 
    if (inter->parent == NULL)
        root = inter_right;
 
    else if (inter == inter->parent->left)
        inter->parent->left = inter_right;
 
    else
        inter->parent->right = inter_right;
 
    inter_right->left = inter;
    inter->parent = inter_right;
    return root;
}

struct node *rightRotation(struct node *root, struct node *inter){
    struct node *inter_left = inter->left;
 
    inter->left = inter_left->right;
 
    if (inter->left != NULL)
        inter->left->parent = inter;
 
    inter_left->parent = inter->parent;
 
    if (inter->parent == NULL)
        root = inter_left;
 
    else if (inter == inter->parent->left)
        inter->parent->left = inter_left;
 
    else
        inter->parent->right = inter_left;
 
    inter_left->right = inter;
    inter->parent = inter_left;
    return root;
}
struct node * fixRBT(struct node *root, struct node *inter){
    struct node *parent_inter = NULL;
    struct node *grand_parent_inter = NULL;
 
    while ((inter != root) && (inter->color != 0) &&
           (inter->parent->color == 1))
    {
 
        parent_inter = inter->parent;
        grand_parent_inter = inter->parent->parent;
        if (parent_inter == grand_parent_inter->left)
        {
 
            struct node *uncle_inter = grand_parent_inter->right;
            if (uncle_inter != NULL && uncle_inter->color == 1)
            {
                grand_parent_inter->color = 1;
                parent_inter->color = 0;
                uncle_inter->color = 0;
                inter = grand_parent_inter;
            }
 
            else
            {
                if (inter == parent_inter->right)
                {
                    leftRotation(root, parent_inter);
                    inter = parent_inter;
                    parent_inter = inter->parent;
                }
                rightRotation(root, grand_parent_inter);
                swap(parent_inter->color, grand_parent_inter->color);
                inter = parent_inter;
            }
        }

        else
        {
            struct node *uncle_inter = grand_parent_inter->left;
            if ((uncle_inter != NULL) && (uncle_inter->color == 1))
            {
                grand_parent_inter->color =1;
                parent_inter->color = 0;
                uncle_inter->color = 0;
                inter = grand_parent_inter;
            }
            else
            {
                if (inter == parent_inter->left)
                {
                    rightRotation(root, parent_inter);
                    inter = parent_inter;
                    parent_inter = inter->parent;
                }

                leftRotation(root, grand_parent_inter);
                swap(parent_inter->color, grand_parent_inter->color);
                inter = parent_inter;
            }
        }
    }
 
    root->color = 0;
    return root;
}
struct node *Interval_Insertion (struct node *root, struct interval_node *i){
  struct node *temp= createNewNode(i); 
  root = BST_Insertion(root, temp);
  root=fixRBT(root,temp);
  return root;
}
bool doOVerlap(interval_node i1, interval_node i2)
{
    if (i1.lower_val <= i2.higher_val && i2.lower_val <= i1.higher_val)
        return true;
    return false;
}

interval_node *overlapSearch(struct node *root, interval_node i)
{
    if (root == NULL) return NULL;

    if (doOVerlap(*(root->interval), i))
        return root->interval;

    if (root->left != NULL && root->left->max_val >= i.lower_val)
        return overlapSearch(root->left, i);
 
    return overlapSearch(root->right, i);
}
int main()
{
    interval_node given_interval[] = {{15, 20}, {10, 30}, {17, 19},{5, 20}, {12, 15}, {30, 40} };
    int n = sizeof(given_interval)/sizeof(given_interval[0]);
    struct node *root = NULL;
    for (int i = 0; i < n; i++)
        root = Interval_Insertion(root, given_interval+i);
 
    interval_node k = {14,16};
 
    cout << "\nSearching for interval [" << k.lower_val << "," << k.higher_val << "]";
    interval_node *result = overlapSearch(root, k);
    if (result == NULL)
        cout << "\nNo Overlapping Interval found";
    else
        cout << "\nIt Overlaps with [" << result->lower_val << ", " << result->higher_val << "]"<<endl;
    return 0;
}
    


