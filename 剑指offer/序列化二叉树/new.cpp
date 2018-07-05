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

TreeNode* constructTree(queue<string> queStr)
{
    if(queStr.front() == "#")
        return NULL;

    TreeNode *newnode = new TreeNode(stoi(queStr.front()));
    queStr.pop();

    newnode->left = constructTree(queStr);
    newnode->right = constructTree(queStr);

    return newnode;
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
    char *ch = "1,2,4,#,#,#,3,5,#,#,6,#,#";

    char *rstch = Serialize(Deserialize(ch));

    printf("%s\n", rstch);

    return 0;
}
