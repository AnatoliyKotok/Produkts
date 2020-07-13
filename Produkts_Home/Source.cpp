#include "Produkts.h"
#include<iostream>
using namespace std;
int main() {
    string fname = "prod.dat";
    Produkts pr("Apple", 23.5, 12);
    BinaryP b;
    b.write(pr, fname);
    b.read(fname).print();
}