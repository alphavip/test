#include <iostream>
#include <stack>
#include <queue>
#include <stdio.h>

const static uint32_t path[8][8] = {
    {0,1,0,1,0,1,0},
    {1,0,0,0,1,1,1},
    {1,0,0,0,1,1,1},
    {1,0,0,0,1,1,1},
    {1,0,0,0,1,1,1},
    {1,0,0,0,1,1,1},
    {1,0,0,0,1,1,1}
};

//先把二叉树得遍历写一遍吧
struct Node
{
    uint32_t value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};
//            1
//        /      \
//       2         3
//     /   \      /  \
//    4    5      6   7
//   / \  / \    / \  / \
//  8  9  10 11 12 13 14 15 
//deep first search 1 2 4 8 9 5 10 11 3 6 12 13 7 14 15
//bread first search 123456


void DFSVisitor(Node* troot)
{
    if(troot == nullptr)
        return;
    std::stack<Node*> nvisitlist;
    nvisitlist.push(troot);
    while (!nvisitlist.empty())
    {
        //访问节点
        Node* tmp = nvisitlist.top();
        nvisitlist.pop();
        std::cout << tmp->value << std::endl;
        if(tmp->right != nullptr)
            nvisitlist.push(tmp->right);
        if(tmp->left != nullptr)
            nvisitlist.push(tmp->left);
    }    
}


void BFSVisitor(Node* troot)
{
    if(troot == nullptr)
        return;
    std::queue<Node*> nvisitlist;
    nvisitlist.push(troot);
    while (!nvisitlist.empty())
    {
        Node* tmp = nvisitlist.front();
        std::cout << tmp->value << std::endl;
        nvisitlist.pop();
        if(tmp->left != nullptr)
            nvisitlist.push(tmp->left);
        if(tmp->right != nullptr)
            nvisitlist.push(tmp->right);
    }
}


int main()
{
    Node* troot = new Node();
    troot->value = 1;
    std::queue<Node*> quequelist;
    quequelist.push(troot);

    while (!quequelist.empty())
    {
        Node* tmp = quequelist.front();
        quequelist.pop();
        tmp->left = new Node();
        tmp->left->value = tmp->value * 2;
        tmp->right = new Node();
        tmp->right->value = tmp->value * 2 + 1;
        if((1 << 2) > tmp->value)
        {
            quequelist.push(tmp->left);
            quequelist.push(tmp->right);
        }
    }


    DFSVisitor(troot);
    BFSVisitor(troot);
}