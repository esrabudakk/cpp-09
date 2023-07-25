// C++ program to illustrate std::istringstream
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::istringstream;
using std::string;

// Driver Code
int main()
{
    // Input string
    string a("1 20.00 0.3000 ");

    // Object class of istringstream
    istringstream my_stream(a);

    // Variable to store number n
    float n;

    // Stream a number till white space
    // is encountered
    while (my_stream)
    {
        my_stream >> n;
        cout << n << "\n";

    }

    // Print the number
}
