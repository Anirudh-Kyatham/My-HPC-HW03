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
int solution(TreeNode* root) {
    if (root == nullptr)
        return 0;
    else
        return std::max(solution(root->left), solution(root->right)) + 1;

}


int main(int argc, char const* argv[]) {
    TreeNode* a15 = new TreeNode(15);
    TreeNode* a7 = new TreeNode(7);
    TreeNode* a20 = new TreeNode(20);
    TreeNode* a9 = new TreeNode(9);
    TreeNode* a3 = new TreeNode(3);
    a7->left = new TreeNode(10);
    a20->left = a15;
    a20->right = a7;
    a3->left = a9;
    a3->right = a20;

    std::cout << "max depth of binary tree is " << solution(a3) << std::endl;
    return 0;
}