#include <stdio.h>

struct BSTree
{
        BSTree *left;
        BSTree *right;
        int val;
        BSTree(int x):left(NULL), right(NULL), val(x) {}
};


BSTree* find(BSTree* root, int x)
{
        while (true)
        {
                if (root == NULL) break;

                if (root->val == x) return root;
                else if (root->val > x) root = root->right;
                else root = root->left;
        }
        return root;
}

void find(BSTree* root, int x)
{
        BSTree* parent;
        while (true)
        {
                if (root == NULL) break;
                parent = root;
                if (root->val == x) return;
                else if (root->val > x) root = root->right;
                else    root = root->left;
        }
        if (parent)
        {
                BSTree* node = malloc(BSTree);
                node->val = x;
                if (x > parent->val) parent->right = node;
                else parent->left = node;
        }
}

BSTree* delete(BSTree* root, int x)
{
        BSTree* parent;
        while (true)
        {
                if (root == NULL) break;
                parent = root;
                if (root->val == x) break;
                else if (root->val > x) root = root->right;
                else root = root->left;
        }
        if (root == NULL) return NULL;
        else if (root->left == NULL && root->right == NULL)
        {
                if (parent->val > x) parent->left = NULL;
                else parent->right = NULL;
                return root;
        }
        else
        {
                BSTree** node = parent->val >  x ? &(parent->left) : &(parent->right);
                if (root->right)
                {
                        *node = root->right;
                }
                else
                {
                        *node = root->left;
                }
        }
        return root;
}
