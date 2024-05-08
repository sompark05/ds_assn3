#include "sort.h"
#include <fstream>
#include <iostream>
#include <string>

sortAlg::sortAlg() {
  arr_size = 0;
  arr = new int[100]; // Each test case will be less than 100 values
}

using namespace std;

void sortAlg::printArray(ofstream &fout) {
  string answer;
  for (int i = 0; i < arr_size - 1; i++)
    answer += to_string(arr[i]) + " ";
  answer += to_string(arr[arr_size - 1]);
  fout << answer << endl;
}

void sortAlg::bubbleSort(ofstream &fout) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  bool swapped;
  for (int i = arr_size - 1; i > 0; i--) {
    swapped = false;
    for (int j = arr_size - 1; j > arr_size - i - 1; j--) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
    printArray(fout);
  }
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void sortAlg::merge(int left, int middle, int right) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  // create two arrays
  int left_array[middle - left + 1];
  int right_array[right - middle];

  // copy data of arr to left_array and right_array
  for (int i = 0; i < middle - left + 1; i++) {
    left_array[i] = arr[left + i];
  }
  for (int i = 0; i < right - middle; i++) {
    right_array[i] = arr[middle + 1 + i];
  }

  int index_for_l = 0;
  int index_for_r = 0;
  int index_for_a = left;

  // compare each element of left_array and right_array
  // and copy the larger element to arr
  while (index_for_l < middle - left + 1 && index_for_r < right - middle) {
    if (left_array[index_for_l] > right_array[index_for_r]) {
      arr[index_for_a] = left_array[index_for_l];
      index_for_l++;
    } else {
      arr[index_for_a] = right_array[index_for_r];
      index_for_r++;
    }

    index_for_a++;
  }

  // copy the remaining elements of left_array and right_array, if any
  for (; index_for_l < middle - left + 1; index_for_l++) {
    arr[index_for_a] = left_array[index_for_l];
    index_for_a++;
  }

  for (; index_for_r < right - middle; index_for_r++) {
    arr[index_for_a] = right_array[index_for_r];
    index_for_a++;
  }
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void sortAlg::mergeSort(ofstream &fout, int left, int right) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  for (int length = 1; length < arr_size; length *= 2) {

    // check if sorted
    for (int i = 0; i < arr_size; i++) {
      if (i == arr_size - 1) {
        return;
      }
      if (arr[i] < arr[i + 1]) {
        break;
      }
    }

    for (int index = 0; index < arr_size; index += 2 * length) {
      int left = index;
      int mid = min(index + length - 1, arr_size - 1);
      int end = min(index + 2 * length - 1, arr_size - 1);

      merge(left, mid, end);
    }

    printArray(fout);
  }
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}
