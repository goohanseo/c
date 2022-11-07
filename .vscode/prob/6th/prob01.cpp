//데이터 테스트 통과
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 10000

struct NODE{
    char *data;
    int count;
    struct NODE *next;
};
typedef struct NODE Node;
Node *head = NULL;
Node *headdesc = NULL;

void add_first(char *item);
void add_after(Node*prev,char*item);
void add_to_ordered_list(char* item);
void printNode();
void sub_list();
void remove_after(Node* prev);
void descend_list(Node*node);
void printdescNode();
void add_first_node(Node* node);
void add_after_node(Node* prev, Node* node);

int main(void){
    char buffer[BUFFER_SIZE];
    FILE * file = fopen("harry.txt","r"); //파일 읽어오기
    char buf[BUFFER_SIZE]; //단어의 길이 정의
    while(fscanf(file, "%s", buf) != EOF){
        add_to_ordered_list(strdup(buf));
    }
    fclose(file);
    printf("1번 문제 출력");
    printNode();
    printf("2번 문제 출력");
    sub_list();
    printNode();
    printf("3번 문제 출력");
    while(head != NULL){
        descend_list(head);
    }
    printdescNode();
}



void add_first(char* item){
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->count = 1;
    tmp->next = head;
    head = tmp;
}

void add_after(Node* prev, char* item){
    if (prev == NULL){
        return;
    }
    Node* tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->count = 1;
    tmp->next = prev->next;
    prev->next = tmp;
}

void add_to_ordered_list(char *item){
    Node *now = head;
    Node *prev = NULL;
    while (now !=NULL && strcmp(now->data,item)<=0){
        if (strcmp(now->data, item)==0){
            now->count++;
            return;
        }
        prev=now;
        now = now->next;
    }
    if (prev == NULL){
        add_first(item);
    }
    else{
        add_after(prev, item);
    }
}

void printNode(){
    int sum = 0;
    for (Node* now = head; now != NULL; now = now->next){
        printf("%s: %d\n", now-> data, now->count);
        sum++;
    }
    printf("%d\n", sum);
}

// void remove_first(){
//     head = head->next;
// }

void sub_list(){
    Node*prev = NULL;
    Node*now = head;
    while(now != NULL){
        if(now->count <= 10){
            remove_after(prev);
            now = now->next;
        }
        else{
            prev = now;
            now = now->next;
        }
    }
}

void remove_after(Node *prev){
    Node *tmp = prev->next;
    if(tmp == NULL){
        return ;
    }
    else {
        prev->next = tmp->next;
    }
}

void descend_list(Node*node){
    Node*nowdesc = headdesc;
    Node*prevdesc = NULL;
    while (nowdesc != NULL && (nowdesc->count >= node->count)){
        if (nowdesc->count == node->count){
            if(strcmp(nowdesc->data, node->data)<0){
                prevdesc = nowdesc;
                nowdesc = nowdesc->next;
            }
        }
        else{
            prevdesc = nowdesc;
                nowdesc = nowdesc->next;
        }
    }
    if (prevdesc == NULL){
        add_first_node(node);
    }
    else{
        add_after_node(prevdesc,node);
    }
}

void printdescNode(){
    int sum = 0;
    for (Node *node = headdesc; node != NULL; node = node->next){
        printf("%s: %d\n", node->data, node->count);
		sum++;
    }
    printf("%d\n",sum);
}

void add_first_node(Node* node) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp = head;
	head = head->next;
	tmp->next = headdesc;
	headdesc = tmp;
}

//prev 다음에 노드 추가
void add_after_node(Node* prev, Node* node) {
	if (prev == NULL) {
		return;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp = head;
	head = head->next;
	tmp->next = prev->next;
	prev->next = tmp;
}