###기록용
* dfs의 메모리문제가 발생할 수 있다.
    * dfs는 구현이 편리하지만 재귀호출로 사용하면 계속해서 activation record가 쌓일 수 있다.
    * 이로인해 코딩테스트 시에는 메모리 문제가 발생할 수 있음을 유의하자.

* 백트래킹 알고리즘은 웬만하면..
    * void backtracking 이라는 함수가 있다손 치면
        * 함수 초입에 조건문을 다 때려박고 ( 완료조건 및 예외조건 다 )
        * 함수 내부에는 노드를 넣을 것인지 말 것인지만 짜자
        * 경험상 이게 제일 간단한 것 같다.

* dfs/bfs queue사용 시,
   * 방문할 노드를 미리 기록하기 때문에, 방문 시에 visited를 체크하게 되면, 중복 방문으로 인한 무한루프에 빠질 수 있다.
   * 따라서 방문할 노드에 대해선 어차피 방문할 것이므로(큐에 이미 올라감), visited를 미리 체크하자

* 순열
    * next_permutation은 순열
    * 조합을 찾을 땐 1, 1, 0, 0 등으로 1에 해당하는게 선택이라 생각하면 된다.
* backtracking
    * 14500_failed  코드 자주 보자. ( 테트로미노 )
        * 백트래킹으로 풀 수 있나? 시간 제한 고려하면 struct 미리 정의해서 미는게 나을 것 같다.
        * set 의 comparator 관련 내용 들어가있음.
        * n * m의 상수시간 해결이 훨씬 쉬운 이유.

* cpp comparator 관련 내용 나중에 정리해보자.
    * https://stackoverflow.com/questions/2620862/using-custom-stdset-comparator