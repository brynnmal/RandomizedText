#include <iostream>
#include <cstdlib>
#include <ctime>
#include "makeSeuss.hpp"

using namespace std;

int main() {
    //srand(time(NULL));
    string inputFile = "DrSeuss (2023_12_02 17_19_19 UTC).txt";

    string outputFile1 = "Output_Hash1_Collision1.txt";
    string outputFile2 = "Output_Hash1_Collision2.txt";
    string outputFile3 = "Output_Hash2_Collision1.txt";
    string outputFile4 = "Output_Hash2_Collision2.txt";

    // makeSeuss makeSeuss1(inputFile, outputFile1, true, true);
    // makeSeuss makeSeuss2(inputFile, outputFile2, true, false);
    makeSeuss makeSeuss3(inputFile, outputFile3, false, true);
    makeSeuss makeSeuss4(inputFile, outputFile4, false, false);
    return 0;
    //map 8000 one hash one col then other hash then etc if all the col and hash work check rehash
}
