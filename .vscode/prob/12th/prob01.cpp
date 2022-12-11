//테스트 데이터 통과
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 100
bool is_palindrome(char *word, int length, int stack);
int main() {
char word[BUFFER_SIZE];
scanf("%s", word);
int length = strlen(word);
int tmp = 0;
is_palindrome(word, length, tmp);
return 0;
}
bool is_palindrome(char* word, int length, int tmp) {
if (word[0 + tmp] != word[length - tmp - 1]) {
printf("No");
return false;
}
else if (tmp >length-tmp-1) {
printf("Yes");
return true;
}
else {
return is_palindrome(word, length, tmp + 1);
}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 100
int compare(char* str1, char* str2);
int main() {
char word1[BUFFER_SIZE];
char word2[BUFFER_SIZE];
scanf("%s", word1);
scanf("%s", word2);
int index;
compare(word1, word2);
if (compare(word1, word2) == 1) {
printf("%s\n", word2);
printf("%s", word1);
}
else {
printf("%s\n", word1);
printf("%s", word2);
}
return 0;
}
int compare(char* str1, char* str2) {
if (str1[0] < str2[0])
return -1;
else if (str1[0] > str2[0])
return 1;
else if(str1[0] == NULL && str2[0] = NULL) {
return 0;
}
else
return compare(str1 + 1, str2 + 1);
}