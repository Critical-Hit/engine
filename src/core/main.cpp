//
//  main.cpp
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc, const char * argv[])
{
    auto test = [] () { printf("Hello World\n"); };
    test();
    
    unordered_set<std::string> first ({"red","green","blue"});
    for(const string& x: first) cout << " " << x;
    cout << endl;
	getchar();

    return 0;
}

