#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    char data;
    int frequency;
    Node *left;
    Node *right;
    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

Node *buildHuffmanTree(vector<char> data, vector<int> freq)
{
    priority_queue<Node *, vector<Node *>, CompareNodes> minHeap;
    for (size_t i = 0; i < data.size(); ++i)
    {
        minHeap.push(new Node(data[i], freq[i]));
    }
    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        Node *newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }
    return minHeap.top();
}
void printHuffmanCodes(Node *root, string code = "")
{
    if (!root)
        return;
    if (root->data != '$')
    {
        cout << root->data << ": " << code << endl;
    }
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}
int main()
{
    vector<char> data = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    Node *root = buildHuffmanTree(data, freq);
    cout << "Huffman Codes:\n";
    printHuffmanCodes(root);
    return 0;
}