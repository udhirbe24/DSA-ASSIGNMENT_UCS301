#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
string inStr;
cout << "Enter stream (e.g., a a b c): ";
getline(cin, inStr);

vector<int> freq(256, 0);
queue<char> cQ;
string outStr = "";

for (char c : inStr) {
if (c == ' ') conƟnue;

freq[c]++;
if (freq[c] == 1) cQ.push(c);

while (!cQ.empty() && freq[cQ.front()] > 1) {
cQ.pop();
}

Dsa TUT 4

if (cQ.empty()) outStr += "-1 ";
else {
outStr += cQ.front();
outStr += " ";
}
}

cout << "Output: " << outStr << endl;

return 0;
}