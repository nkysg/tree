#include <stdio.h>

const int M = 5;
struct BtreeNode
{
        int keynum;
        int key[M-1];
        BtreeNode* childs[M];
};

int binarysearch_lower(int* a, int low, int high, int val)
{
        int best = -1;
        int mid = 0;
        while (low <= high)
        {
                mid = low + (high - low) / 2;
                if (a[mid] <= val)
                {
                        best = mid;
                        low = mid+1;
                }
                else
                {
                        high = mid-1;
                }
        }
        return best;
}

BtreeNode* find(BtreeNode* root, int val)
{
        BtreeNode* node = root;
        while (true)
        {
                int idx = binarysearch_lower(node->key, 0, node->keynum, val) + 1;
                if (node->key[idx] == val) return node;
                else
                {
                        node = node->childs[idx];
                        if (node)
                        {
                                i = 0;
                        }
                        else
                        {
                                return NULL;
                        }
                }
        }
        return NULL;
}

void insert(BtreeNode* root, int val)
{
}

void del(BtreeNode* root, int val)
{
}
