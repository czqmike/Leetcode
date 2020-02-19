#include <iostream> 
#include <fstream>
using namespace std;

int main() {
    ofstream outf("out.txt");
    ifstream inf("in.txt");

    if (!inf) {
        cerr << "infile error!";
        return -1;
    }
    if (!outf) {
        cerr << "outfile error!";
        return -2;
    }

    string word;
    while (inf >> word) {
        outf << word << ' ';
    }
    return 0;
}