#include <cstdlib>
#include <thread>
#include "iostream"
using namespace std;

//
// Created by Jinx on 24-12-14.
//
int main() {
    char *a = (char *) malloc(static_cast<size_t>(1 << 30));
    cout << "0"<<(int) *(a+((1<<30)-4))<<endl;
    this_thread::sleep_for(std::chrono::seconds(30));
    delete a;
}