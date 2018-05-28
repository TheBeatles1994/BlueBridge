#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

string rst;
void preOrderTraverse(TreeNode *node)
{
    if(!node)
    {
        rst.append("#,");
        return;
    }
    else
    {
        rst.append(to_string(node->val) + ",");
    }

    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
    return;
}

char* Serialize(TreeNode *root) {
    preOrderTraverse(root);
    rst.pop_back();
    char *rstch = new char[rst.length()+1];
    strcpy(rstch, rst.c_str());
    return rstch;
}

void func(TreeNode* node, queue<string>& queStr)
{
    bool left = true;

    for(int i=0;i<2;i++)
    {
        string tempStr = queStr.front();
        queStr.pop();
        if(tempStr != "#")
        {
            TreeNode *newNode = new TreeNode(stoi(tempStr));
            if(left)
            {
                node->left = newNode;
                left = false;
            }
            else
            {
                node->right = newNode;
            }
            func(newNode, queStr);
        }
        else
        {
            left = false;
            continue;
        }
    }
}

TreeNode* constructTree(queue<string> queStr)
{
    if(queStr.empty() || queStr.front()=="#")
        return NULL;

    TreeNode* head = new TreeNode(stoi(queStr.front()));
    queStr.pop();

    func(head, queStr);

    return head;
}

TreeNode* Deserialize(char *str) {
    string mystr(str);
    size_t index=-1;
    queue<string> queStr;

    do{
        queStr.push(mystr.substr(index+1,mystr.find_first_of(",", index+1)-index-1));
        index = mystr.find_first_of(",", index+1);
    }while(index!=string::npos);

    return constructTree(queStr);
}

int main()
{
    char *ch = "8,6,#,#,10,#,#";

    char *rstch = Serialize(Deserialize(ch));

    printf("%s\n", rstch);

    return 0;
}
