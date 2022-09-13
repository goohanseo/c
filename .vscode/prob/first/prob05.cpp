//테스트 데이터 통과
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int main(void){
    int n;
    printf("입력할 갯수 n을 입력하시오:\n");
    scanf("%d",&n);
    
    for(int i=0; i<n; i++)
        for(i=0; i<n; i++){
            int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);}
    sort(v.begin(),v.end()); //벡터 소트 정렬을 통해 순서대로 정렬
    v.erase(unique(v.begin(),v.end()),v.end()); //정렬 후 중복되는 벡터 삭제
    printf("%d: ",n);
    for (int i=0;i<v.size();i++)
    printf("%d ",v[i]);
    printf("\n");
    return 0;
}