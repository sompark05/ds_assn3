#pragma once
#include "bst.h"

using namespace std;

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void insert(char letter);
    void remove(char letter);

    void printInOrder(ofstream &fout);
    void printPreOrder(ofstream &fout);
    void printFrequency(ofstream &fout);

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};