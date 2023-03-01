#include<iostream>
#include<vector>
#include"output.h"
using namespace std;
vector<string> read_data();

int main(){

    ofstream outdata("Text_Data1.txt");
    vector<string> my_vector = read_data();
    string delimiter = "";
    string my_string = "";

    for (string element : my_vector) {
        my_string += element;
    }

    vector<int> element_lengths;
    for (string element : my_vector) {
        element_lengths.push_back(element.length());
    }

    vector<string> recreated_vector;
    int start_index = 0;
    for (int length : element_lengths) {
        string element = my_string.substr(start_index, length);
        recreated_vector.push_back(element);
        start_index += length;
    }

    for (string element : recreated_vector) {
        outdata << element << " ";
    }

    return 0;
}