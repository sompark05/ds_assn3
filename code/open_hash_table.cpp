#include <iostream>
#include <fstream>
#include <string>
#include "open_hash_function.h"
#include "open_hash_table.h"

using namespace std;

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

OpenHashTable::OpenHashTable(int table_size, OpenHashFunction *hf) : table_size(table_size)
{
    this->hf = hf;
    this->collision = 0;
    this->longest = 0;
    table = new HashNode *[this->table_size];
    for (int i = 0; i < this->table_size; i++)
    {
        table[i] = NULL;
    }
    this->states = new OpenTableState[this->table_size];

    for (int i = 0; i < this->table_size; ++i)
    {
        this->states[i] = OPEN_EMPTY;
    }

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    /*  Write your codes if you need  */

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

OpenHashTable::~OpenHashTable()
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    /*  Write your codes if you need  */

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    delete[] table;
    delete[] this->states;
}

void OpenHashTable::print_result(ostream &out)
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    /*  Write your codes if you need  */

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    out << collision << " " << longest << endl;
}

void OpenHashTable::insert(int key)
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void OpenHashTable::delete_(int key)
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}
