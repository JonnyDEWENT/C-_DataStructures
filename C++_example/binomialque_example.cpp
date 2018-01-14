#include <iostream>
#include "vector"
#include "math.h"
/*********************************************************************
 * @author Jon DeWent
 *
 ********************************************************************/
int main() {
    std::vector <int> x = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    // creating node struct for binomial que
    struct Node {
        int e;
        int count = 1;
        Node *lc = nullptr;
        Node *ns = nullptr;
    };
    std::vector<Node*> tree;
    for (auto y: x) {
        Node * temp = new Node;
        temp -> e = y;
        tree.push_back(temp);

    }
    std::cout << "This program demonstrates how binomial ques can be built with at most n -1 comparisons" << std::endl;
    std::cout << "the size is " << tree.size() << std::endl;
    int z = 0;
    int count = 0;
    int size = tree.size();
    for (int i = 0; i < tree.size() && count <= size * 2; i++) {

        if (tree[i + 1] != nullptr && tree[i]->count == tree[i+1]->count) {
            if (tree[i]->e < tree[i + 1]->e) {
                tree[i + 1]->ns = tree[i]->lc;
                tree[i]->lc = tree[i + 1];
                tree[i]->count++;
                tree.erase(tree.begin() + i + 1);
                z++;

            } else if (tree[i]->e > tree[i + 1]->e) {
                tree[i]->ns = tree[i + 1]->lc;
                tree[i + 1]->lc = tree[i];
                tree[i + 1]->count++;
                tree.erase(tree.begin() + i);
                z++;

            }
        }
            if (i == tree.size() -1) {
                i = -1;

            }

count++;



    }
    std::cout << "it took " << z << " comparisons" << std::endl;
    std::cout << "There are " << tree.size() << " roots." << std::endl;
    for (auto n : tree) {
//        std::cout << n->e << std::endl;
        if (n->lc != nullptr)
        std::cout << "leftchild of " << n->e << " is: " << n->lc->e << std::endl;

        std::cout << "The size is : " << pow(2, n->count - 1) << std::endl;
    }
//    std::cout << "the size is " << tree.size() << std::endl;

}