#include<iostream>
#include<vector>
struct TreeNode
{
    TreeNode(int val) :data(val), left(nullptr), right(nullptr) {}
    int data;
    TreeNode* left;
    TreeNode* right;

};

/*
here the time complexity is O👎
*/
bool haspath(TreeNode* root, int target) {
    if (root == nullptr)
        return false;
    else if (root->left == nullptr && root->right == nullptr)
        return (root->data == target);
    return haspath(root->left, target - root->data) || haspath(root->right, target - root->data);
}


int main(int argc, char const* argv[]) {
    TreeNode* a5 = new TreeNode(5);
    TreeNode* a4 = new TreeNode(4);
    TreeNode* a11 = new TreeNode(11);
    TreeNode* a7 = new TreeNode(7);
    TreeNode* a2 = new TreeNode(2);
    TreeNode* a8 = new TreeNode(8);
    TreeNode* a13 = new TreeNode(13);
    TreeNode* b4 = new TreeNode(4);
    TreeNode* a1 = new TreeNode(1);

    a11->left = a7;
    a11->right = a2;
    a4->left = a11;
    a13->right = a1;
    a8->left = a13;
    a8->right = b4;
    a5->left = a4;
    a5->right = a8;


    int target{ 26};

    std::cout << std::boolalpha << haspath(a5, target) << std::endl;
    return 0;
}