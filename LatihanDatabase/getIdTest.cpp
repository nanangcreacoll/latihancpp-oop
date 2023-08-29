#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{   
    string lastLine = "2;3;563476;kimia";
    stringstream s(lastLine);
    vector<int> vect;

    for (int i; s >> i;) {
        vect.push_back(i);    
        if (s.peek() == ';') break;
    }

    for (std::size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << std::endl;
    return 0;
}
