//
//  main.cpp
//

#include <iostream>
#include <string>
#include <unordered_set>
#include "sample.h"

using namespace std;

int main(int argc, const char * argv[])
{
    auto hello = [] () { printf("Hello World\n"); };
    hello();

    printf("5? %d.", five());
    
    unordered_set<std::string> first ({"red","green","blue"});
    for(const string& x: first) cout << " " << x;
    cout << endl;
	getchar();

    return 0;
}

