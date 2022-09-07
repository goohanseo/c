#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}
string word[100];
int main() {
	int N;
	cin >> N;
    printf("몇개의 영문 문자열을 받을것인지 입력하시오: 단, 각 문자열의 길이는 20이하이다.")
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	sort(word, word + N, cmp);
	for (int i = 0; i < N; i++) {
		if (word[i] == word[i - 1]) {
			continue;
		}
		cout << word[i] << "\n";
	}
	return 0;
}