// 二叉树（链式存储）
// 函数接口：
// TreeNode* createTree();           // 先序创建二叉树，0表示空结点
// void preorder(TreeNode *root);    // 先序遍历（根左右）
// void inorder(TreeNode *root);     // 中序遍历（左根右）
// void postorder(TreeNode *root);   // 后序遍历（左右根）
// int getDepth(TreeNode *root);     // 获取树的深度
// int getNodeCount(TreeNode *root); // 获取结点总数
// void destroyTree(TreeNode *root); // 销毁二叉树
#include <stdio.h>
#include <stdlib.h>

//记得判空哦

typedef struct TreeNode {
    int data;                       // 结点数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;

TreeNode* createTree() {
    int val;
    scanf("%d", &val);
    if (val == 0) return NULL; // 0表示空结点
    
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = val;
    node->left = createTree();  // 递归创建左子树
    node->right = createTree(); // 递归创建右子树
    return node;
}

void preorder(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(TreeNode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// 获取树的深度
int getDepth(TreeNode *root) {
    if (root == NULL) return 0;
    int leftDepth = getDepth(root->left);//递归
    int rightDepth = getDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//深度 = max(左子树深度, 右子树深度) + 1
}
//获取结点总数
int getNodeCount(TreeNode *root) {
    if (root == NULL) return 0;
    int leftCount = getNodeCount(root->left);
    int rightCount = getNodeCount(root->right);
    return leftCount + rightCount + 1;
}
// 销毁二叉树
void destroyTree(TreeNode *root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}
// 测试主函数
int main() {
    TreeNode *root = createTree();
    printf("先序遍历: ");
    preorder(root);
    printf("\n中序遍历: ");
    inorder(root);
    printf("\n后序遍历: ");
    postorder(root);
    printf("\n树的深度: %d\n", getDepth(root));
    printf("结点总数: %d\n", getNodeCount(root));
    destroyTree(root);
    return 0;
}