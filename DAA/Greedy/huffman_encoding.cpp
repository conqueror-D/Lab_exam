// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e.
// character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes
// in preorder traversal of the tree.
// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken
// on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken
// on the left of the subtree and other one to the right.

// S = "abcdef"
// f[] = {5, 9, 12, 13, 16, 45}
// Output:
// 0 100 101 1100 1101 111
// HuffmanCodes will be:
// f : 0
// c : 100
// d : 101
// a : 1100
// b : 1101
// e : 111
// Hence printing them in the PreOrder of Binary
// Tree.

#include <bits/stdc++.h>
using namespace std;

class Treenode
{
public:
    int value;
    Treenode *left, *right;
    Treenode(int _value)
    {
        value = _value;
        left = nullptr;
        right = nullptr;
    }
};

struct compare
{
    bool operator()(const Treenode *left, Treenode *right) const
    {
        return left->value > right->value;
    }
};

void preorder(Treenode *root, vector<string> &encoded, string curr)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        encoded.push_back(curr);
        return;
    }
    preorder(root->left, encoded, curr + '0');
    preorder(root->right, encoded, curr + '1');
}

vector<string> Huffman_encode(string &s, vector<int> &freq)
{
    priority_queue<Treenode *, vector<Treenode *>, compare> pq;
    for (int i = 0; i < freq.size(); i++)
    {
        Treenode *temp = new Treenode(freq[i]);
        pq.push(temp);
    }

    while (pq.size() != 1)
    {
        Treenode *left = pq.top();
        pq.pop();
        Treenode *right = pq.top();
        pq.pop();

        Treenode *parent = new Treenode(left->value + right->value);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    vector<string> encodedValues;
    preorder(pq.top(), encodedValues, "");
    return encodedValues;
}
int main()
{
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    vector<string> ans = Huffman_encode(s, freq);
    for (string n : ans)
    {
        cout << n << endl;
    }
    return 0;
}