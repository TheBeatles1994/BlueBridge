#include <iostream>
#include <vector>

using namespace std;
/* 二叉排序树 */
struct BiTree
{
    int val;
    struct BiTree *left;
    struct BiTree *right;
    BiTree(int val):val(val),left(NULL),right(NULL){}
};
typedef struct BiTree BTree;
typedef struct BiTree *pBTree;

pBTree head = NULL;
/* 创建二叉搜索树 */
void createBiTree(pBTree &head)
{
    int in;
    pBTree copyhead;        //保存头结点
    while(true)
    {
        cin>>in;
        if(in <= 0)
            break;

        if(head == NULL)    //第一次头结点为空
        {
            head = new BTree(in);
            copyhead = head;
        }
        else
        {
            pBTree temp = copyhead; //当前节点
            pBTree pre;             //当前节点前一节点
            while(temp)
            {
                pre = temp;
                if(in < temp->val)
                {
                    temp = temp->left;
                }
                else
                    temp = temp->right;
            }
            if(pre->val > in)
                pre->left = new BTree(in);
            else
                pre->right = new BTree(in);
        }
    }
}
/* 中序遍历 */
void inOrderTraverse(pBTree tree)
{
    if(tree == NULL)
        return;
    inOrderTraverse(tree->left);
    cout << tree->val<<" ";
    inOrderTraverse(tree->right);
}
/* 查找是否存在某一节点 */
pBTree isExist(pBTree tree, int val)
{
    while(tree)
    {
        if(val<tree->val)
            tree = tree->left;
        else if(val > tree->val)
            tree = tree->right;
        else
            return tree;
    }
    return NULL;
}
//3 7 4 6 9 8 1 5 2 -1
/* 删除某一节点 */
void deleteNode(pBTree &tree, int val)
{
    pBTree copyhead = tree;
    pBTree pre = NULL;
    bool isLeft = true;

    while(tree)
    {
        if(tree->val == val)
        {
            if(tree->left == NULL)  //无左节点
            {
                if(pre == NULL)     //为根节点
                {
                    if(tree->right) //右节点非空
                    {
                        pre = tree;
                        tree = tree->right;
                        delete pre; //删除该节点
                    }
                    else            //独立的一个根节点
                    {
                        delete tree;
                        tree = NULL;
                    }
                    return;
                }
                else if(!tree->right)           //为叶子结点
                {
                    if(isLeft)
                    {
                        pre->left = NULL;
                        delete tree;
                    }
                    else
                    {
                        pre->right = NULL;
                        delete tree;
                    }
                    tree = copyhead;
                    return;
                }
                else if(tree->right)            //有右节点，即为中间节点
                {
                    if(isLeft)
                    {
                        pre->left = tree->right;
                        delete tree;
                        tree = copyhead;
                    }
                    else
                    {
                        pre->right = tree->right;
                        delete tree;
                        tree = copyhead;
                    }

                    return;
                }
            }
            else if(tree->right == NULL)
            {
                if(pre == NULL)     //为根节点
                {
                    if(tree->left) //右节点非空
                    {
                        pre = tree;
                        tree = tree->left;
                        delete pre; //删除该节点
                    }
                    else            //独立的一个根节点
                    {
                        delete tree;
                        tree = NULL;
                    }
                    return;
                }
                else if(tree->left)            //有左节点，即为中间节点
                {
                    if(isLeft)
                    {
                        pre->left = tree->left;
                        delete tree;
                        tree = copyhead;
                    }
                    else
                    {
                        pre->right = tree->left;
                        delete tree;
                        tree = copyhead;
                    }

                    return;
                }
            }
            else    //最麻烦情况：左右节点都有！！！
            {
                //不想写了，自己的方法太麻烦！！！
            }
        }
        else if(tree->val > val)
        {
            pre = tree;
            isLeft = true;
            tree = tree->left;
        }
        else
        {
            pre = tree;
            isLeft = false;
            tree = tree->right;
        }
    }

    return;
}

int main()
{
    createBiTree(head);

    int in;
    while(cin>>in)
    {
        deleteNode(head, in);
        inOrderTraverse(head);
        cout<<endl;
    }

    return 0;
}
