#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

파일 끝부분 깨끗하게 만들어주기 3-3
4-3 확인하기 

서술형
주소를 받아오는 포인터 p이기때문에 다음 주소를 받아오게 되면 이전의 *p에 저장된 값이 아닌 다음 *p가 받아온 값이 
출력된다

첫번째 노드의 주소 head라는 주소에 초기화
만약에 헤드를 지역변수로 두게 되면
함수를 만들때마다 헤드의 값을 어떠헥 업데이트 할것인가
메인에서 헤드의 값을 변경할때 문제
1.헤드의 주소를 넘겨줌
2.헤드의 값을 변경할 가능성이 있는 모든 함수는 그 일을 한다음
그 변경된 헤드의 값을 리턴해주고 내가 호출한 쪽에서 그 리턴한 값을
받아서 헤드의 값을 업데이트함

fscanf(!=EOF) 한번에 하나의 단어를 받아올 buf[]필요 파일의 끝
fgets

노드 출력
while (p != NULL) {
		printf("%s: %d\n", p->word, p->count);
		p = p->next; //다음 노드로 넘어가야함
		c++;
	}

&&가 ||보다 우선순위가 높음

bool 조건을 걸어서
false true 지정해주고
반복문 끝나고 조건 만족했을때
!false로 다음 명령 실행

c언어의 문자열 끝은 항상 NULL로 바꾸어주어야함

1. 파일읽기
2. 파일닫기


다음 개행문자를 인식하지 않을려면 !=EOF end of file

Strcpy 는 두개의 매개변수 필요
문자열 자체가 문자배열이어야 하는데 포인터변수일뿐임
strdup 새로운 문자열 복제해서 그 문자열을 포인터 주소에 넣어줌

\n로 아무것도 읽을 거 없이 넘어가는데 결국 print 하게 될 line은
좀전에 fgets로 읽은 line이라 한 번 더 복사함


타입변환 (변환할 타입)변수

객체를 모아서 생성해주기
polynomial *ptr-Poly