#include <stdio.h>

const int BLACK= 0;
const int RED = 1;

struct rbtree_node
{
        int val;
        rbtree_node *parent;
        rbtree_node *left;
        rbtree_node *right;
        bool color;
        rbtree_node(int x)
        : val(x),parent(NULL), left(NULL), right(NULL),color(RED)
        {
        }
};

struct rbtree
{
        struct rbtree_node *root;
        rbtree() : root(NULL)
        {
        }
};

bool color_isred(rbtree_node* node)
{
        return node && node->color == RED;
}

bool color_isblack(rbtree_node* node)
{
        return !color_isred(node);
}

void right_rotate(rbtree_node** root, rbtree_node* node)
{
        rbtree_node *newnode = node->left;
}

void left_rotate(rbtree_node** root, rbtree_node* node)
{
}
void insert(rbtree* tree, int x)
{
        if (tree->root == NULL) // root node 
        {
                tree->root = new rbtree_node(x);
                tree->root->color = BLACK;
                return;
        }
        rbtree_node *node = tree->root;
        rbtree_node *parent;

        while (true)
        {
                if (node == NULL) break;
                parent = node;
                if (node->val == x) return;
                else if (node->val < x) node = node->right;
                else node = node->left;
        }
        rbtree_node *newnode = new rbtree_node(x);
        newnode->color = RED;
        if (x > parent->val) parent->right = newnode;
        else parent->left = newnode;

        newnode->parent = parent;
        node = newnode;

        rbtree_node *uncle;
        while (node != tree->root && color_isred(node->parent))
        {
                parent = node->parent;
                if (parent == parent->parent->left)
                {
                        uncle = parent->parent->right;
                        if (color_isred(uncle))
                        {
                                parent->color = BLACK;
                                uncle->color = BLACK;
                                parent->parent->color = RED;
                                node = parent->parent;
                        }
                        else
                        {
                                //XXX FIXME
                        }
                }
                else // parent == parent->parent->right
                {
                        uncle = parent->parent->left;
                        if (color_isred(uncle))
                        {
                                parent->color = BLACK;
                                uncle->color = BLACK;
                                parent->parent->color = RED;
                                node = parent->parent;
                        }
                        else
                      {
                                //XXX FIXME
                        }
                }
        }
        tree->root->color = BLACK;
}

rbtree_node* find(rbtree* tree, int x)
{
        rbtree_node *node = tree->root;

        while (true)
        {
                if (node == NULL) break;

                if (node->val == x)
                {
                        break;
                }
                else if (node->val > x)
                {
                        node = node->left;
                }
                else
                {
                        node = node->right;
                }
        }
        return node;
}

rbtree_node* find_min(rbtree* tree)
{
        rbtree_node *node = tree->root;
        if (node == NULL) return NULL;

        while (node->left != NULL)
        {
                node = node->left;
        }
        return node;
}

rbtree_node* find_max(rbtree* tree)
{
        rbtree_node *node = tree->root;
        if (node == NULL) return NULL;

        while (node->right != NULL)
        {
                node = node->right;
        }
        return node;
}
