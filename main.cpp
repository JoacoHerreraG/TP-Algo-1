// Version del 5/11/2018

#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    cout << "Implementando TPI!!" << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}