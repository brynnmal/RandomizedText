//
// Created by Brynn Maleryn on 11/5/24.
//

#include "hashNode.hpp"
#include "iostream"
#include <ctime>
using namespace std;


hashNode::hashNode(string s) {
  keyword = s;
  values = new string[100];
  valuesSize = 100;
  currSize = 0;
  srand(time(NULL));
}

  hashNode::hashNode(){
    keyword = "";
    values = new string[100];
    valuesSize = 100;
    currSize = 0;
    srand(time(NULL));
  }


  hashNode::hashNode(string s, string v) { //add key
    keyword = s;
    values = new string[100];
    values[0] = v;
    valuesSize = 100;
    currSize = 1;
  }

void hashNode::addValue(string v){
    if(currSize >= valuesSize) {
      dblArray();
    }
    values[currSize] = v;
    currSize++;
  }

void hashNode::dblArray() {
    valuesSize *= 2;
    string *tmp = new string[valuesSize];
    for(int i = 0; i < currSize; i++) {
      tmp[i] = values[i];
    }
    delete[] values;
    values = tmp;
  }

string hashNode::getRandValue() {
    return values[rand() % currSize];
  }