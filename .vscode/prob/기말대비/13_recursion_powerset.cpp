맨 처음 recursion 밖에서 호출할때는 (0,data); 로 호ㅜㄹ
powerset(p,s) 
if s is an empty set
let t be the first element of s;
powerset(p, s-{t}); t 포함x
powerset(PU{t},s-{t}); t포함 어쨋든 p와 s를 합치긴 함