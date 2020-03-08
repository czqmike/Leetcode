#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stack<string> S;
	
    int temp = 0;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') {
            S.push(line.substr(temp, i - temp));
            temp = i + 1;
        }
    }
    S.push(line.substr(temp));
	
	if (!S.empty()) {
		cout << S.top();
		S.pop();
	}
    while (!S.empty()) {
        string sout = S.top();
        S.pop();
        cout << ' ' << sout;
    }
    return 0;
}
