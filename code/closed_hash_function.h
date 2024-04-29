#pragma once
#include <iostream>
#include <string>
using namespace std;

class ClosedHashFunction
{

public:
    ClosedHashFunction(int m) : index_size(m){};

    int closedhashing(int key, int attempt);
    int closedhashing1(int key);
    int closedhashing2(int attempt);
    /////////////////////////////////////////////////////////
    //////  TODO: Add public members if required ///////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
private:
    int key_size;
    int index_size;
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
