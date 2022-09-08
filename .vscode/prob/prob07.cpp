#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a, string b) { //cmp함수를 통해 길이 순, 사전식 순으로 정렬
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}
string word[100];
int main() { //메인함수에서 문자들을 입력한 후 cmp함수를 통해서 정렬하여 다시 받아옴
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