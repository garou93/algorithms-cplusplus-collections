//******-> haithem ben abdelaziz: haithem.ben.abdelaziz@gmail.com
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to print all the sub-sequences
// of a string
void printSubSeq(string sub, string ans)
{

	if (sub.length() == 0) {
		cout << "" << ans << " ";
		return;
	}

	// First character of sub
	char ch = sub[0];

	// Sub-string starting from second
	// character of sub
	string ros = sub.substr(1);

	// Excluding first character
	printSubSeq(ros, ans);

	// Including first character
	printSubSeq(ros, ans + ch);
}

// Driver code
int main()
{
	string str = "abc";
	printSubSeq(str, "");

	return 0;
}

// This code is contributed by divyesh072019
