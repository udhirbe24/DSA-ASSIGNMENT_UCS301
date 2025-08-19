#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isVowel(char ch) {
ch = tolower(ch);
return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
int main() {
string s1 = "Hello";
string s2 = "World";
string concat = s1 + s2;
cout << "Concatenated: " << concat << endl;
string rev = s1;
reverse(rev.begin(), rev.end());
cout << "Reversed: " << rev << endl;
string str = "This is a test sentence";
string noVowels = "";
for (char c : str) {
if (!isVowel(c)) noVowels += c;
}
cout << "Without vowels: " << noVowels << endl;
vector<string> words = {"Banana", "Apple", "Mango", "Grapes"};
sort(words.begin(), words.end());
cout << "Sorted words: ";
for (auto &w : words) cout << w << " ";
cout << endl;
char ch = 'H';
char lower = tolower(ch);
cout << "Lowercase of " << ch << ": " << lower << endl;
return 0;
}