#include "iostream"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val (x), left (nullptr), right (nullptr) {};
};

TreeNode* addNode(TreeNode* iter, int v)
{
    if(iter == nullptr) return new TreeNode(v);
    else if(v > iter->val) iter->right = addNode(iter->right, v);
    else iter->left = addNode(iter->left, v);
    return iter;
}

void printTree(TreeNode* root)
{
    if(root == nullptr) return;
    printTree(root->left);
    std::cout << root->val << ' ';
    printTree(root->right);
}

int height(TreeNode* iter)
{
    if(iter == nullptr) return 0;
    return 1 + std::max(height(iter->left), height(iter->right));
}

int main()
{
    std::cout << "Num of nodes: ";
    int n;
    std::cin >> n;   
    TreeNode* root(nullptr);
    while(n--){
        int a;
        std::cin >> a;
        root = addNode(root, a);
    }
}
