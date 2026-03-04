#include "vectorej.hh"
#include <iostream>
int main() {
    Vector<int> v;
    for(int i = 0; i < 10; ++i) v.push_back(i);
    v.print();
    v.erase(3, 7); // remove elements 3,4,5,6
    v.print();
    return 0;
}
