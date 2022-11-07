#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
struct node {
	char* word;
	int count;
	struct node* next;
};
 
typedef struct node Node; //rename
Node* head = NULL;
 
int main() {
	char buf[30];
	FILE* fp = fopen("harry.txt", "r");
	while (fscanf(fp,"%s",buf)!= EOF){
		Node* p = head, *q=NULL;
		while (p != NULL && strcmp(p->word, buf) < 0) {  //노드의 끝까지 가거나 같거나 더 큰거 만났을때
			//compare p -> word and buf 
			q = p;
			p = p->next; //대소 비교를 하면서 p와 q의 자리를 찾아가는중
		}
		if (p != NULL && strcmp(p->word, buf)==0) //두개가 같다면 p가 word를 가르키고 있음
			p->count++; //p의 next가 나보다 큰 값이니 p가 나랑 같거나 나보다 작거나
		else {
			Node* t = (Node*)malloc(sizeof(Node));
			t->word = strdup(buf);//버퍼의 주소를 복사하면 안 되고 복제해야됨
			t->count = 1;
			t->next = NULL;
			if (q == NULL) {
				t->next = head; //새로만들어질 노드가 지금의 헤드를 가르키고 새로 만들어질 노드에 head 설정
				head = t; //새로운 노드 추가 + 젤 앞으로 들어갈 때
			}
			else {
				t->next = q->next; //맨마지막일 경우 p는 NULL q는 마지막 노드
				q->next = t; //p가 NULL q가 마지막
			}
		}
	}
	fclose(fp);
	printf("Anser1:\n");
	Node* p = head;
	int c = 0;
	while (p!=NULL){
	printf("%s: %d\n",p->word, p->count);
	p= p->next;
}
	printf("%d\n", c);
 
	//problem 6-2
 
	p = head; //p 재정의 하면 안 됨.
	Node* q = NULL;
	while (p != NULL) {
		if (p->count <= 10) {
			//remove node p, removeafter(q)
			if (q == NULL) { //삭제해야될 노드가 첫번째
				head = head->next; //head = p
				p = p->next; //무한반복시키지 않기 위해 p도 한칸 전진
				//삭제된게 첫번째 노드면 q는 여전히 null
			}
			else {
				q->next = p->next; //이렇게만 하면 삭제된 p를 가르키고있음
				p = p->next; //다음 노드를 가르켜줘야됨
			}
		}
		else {
			q = p;
			p = p->next;
		}
		//p=p->next; 가능
	}
 
	printf("Anser2:\n");
	p = head;
	c = 0;
	while (p != NULL) {
		printf("%s: %d\n", p->word, p->count);
		p = p->next;
		c++;
	}
	printf("%d\n", c);
 
	//problem 6-3

    Node *head2 = NULL; //새로운 노드의 헤드노드 임시적으로 만듬
    while (head != NULL){ //원래 연결리스트에서 노드 하나씩 떼옴
        Node *p = head; //헤드가 가르키는 첫번째 노드를 떼옴 //삭제된 노드를 *p로 가지고 왔음 
        head = head->next; //헤드를 한칸앞으로 전진시켜서 다음 노드 지정
        p -> next = NULL; //떼어진 첫번째 노드 다음 노드 지정 x

        Node *s = head2, *t=NULL; //p와 q t는 s의 한칸 전
        while (s!=NULL && (s->count > p->count || //삽입하려는 카운트보다 작거나
        (s->count == p->count &&
        strcmp(s->word, p->word) < 0))){
            t =s;
            s = s->next; //t,s 위치 정해놓고 다음 p값 대입하기
        }
        if (t == NULL){ //p가 젤 처음일때
            p->next = head2; //add first
            head2 = p;
        }
        else{
            p->next = t -> next; //p->next = s
            t->next = p; //addafter
        }
    }
 printf("Anser3:\n");
	head = head2; //노드의 head를 head2임 잘 생각해야됨
    p = head;
	c = 0;
	while (p != NULL) {
		printf("%s: %d\n", p->word, p->count);
		p = p->next;
		c++;
	}

	printf("%d\n", c);
	return 0;
}