#include <stdio.h>


const int N = 16;
struct SkipListNode
{
        int key;
        int val;
        SkipListNode* forward[1];
};

SkipListNode* createSkipListNode(int n, int key, int val)
{
        SkipListNode* node = (SkipListNode*)malloc(sizeof(SkipListNode) + (n-1) * sizeof(SkipListNode));
        node->key = key;
        node->val = val;
        return node;

}

struct SkipList
{
        int level;
        SkipListNode* header;

        SkipList()
        {
                level = 0;
                header = createSkipListNode(N-1, 0, 0);
                for (int i = 0; i < N; ++i)
                {
                        header->forward[i] = NULL;
                }
        }
};

SkipListNode* find(SkipList* sk, int key)
{
        SkipListNode* node = sk->header;

        int i = sk->level-1;
        for (; i >= 0; i--)
        {
                while (node->forward[i] && node->forward[i]->key <= key)
                {
                        if (node->forward[i]->key == key) return node->forward[i];
                        node = node->foward[i];
                }
        }
        return NULL;
}

//XXX FIXME need modify
void insert(SkipList* sk, int key, int val)
{
        SkipListNode* node = find(sk, key);
        if (node !=NULL && node->val != val)
        {
                node->val = val;
                return;
        }
        int level = random() % (N+1);

        if (level > sk->level)
        {
                for (int i = sk->level; i < level; ++i)
                {
                }
                sk->level = level;
        }

        for (int i = 0; i < level-1; ++i)
        {
                node = sk->header;
                while (node->forward[i] && node->forward[i]->key < key)
                {
                        node = node->forward[i];
                }
                node->forward[i] = createSkipListNode(1, key, val);
        }
}
