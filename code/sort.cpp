#include "sort.h"
#include <fstream>
#include <iostream>
#include <string>

sortAlg::sortAlg()
{
    arr_size = 0;
    arr = new int[100]; // Each test case will be less than 100 values
}

using namespace std;

void sortAlg::printArray(ofstream &fout)
{
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);
    fout << answer << endl;
}

void sortAlg::bubbleSort(ofstream &fout)
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void sortAlg::merge(int left, int middle, int right, bool &changed)
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void sortAlg::mergeSort(ofstream &fout, int left, int right)
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}
