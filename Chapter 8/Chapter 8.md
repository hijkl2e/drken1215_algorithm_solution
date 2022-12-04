# 8장 연습 문제 풀이

## 8.1 코드 8-6의 연결 리스트에서 각 노드에 저장한 값을 순서대로 출력하는 함수 `printList`(26~32번째 줄) 처리의 복잡도를 평가하라.

`for` 문은 정확히 $\large N$번 반복한다. 따라서 시간 복잡도는 $\large O(N)$이다.

## 8.2 크기가 $N$인 연결 리스트에서 `get(i)`가 `head`에서 시작해 $i$번째인 요소를 취득하는 함수라고 하자. 이때 다음 코드의 복잡도를 구하라.

```c++
for (int i = 0; i < N; ++i) {
    cout << get(i) << endl;
}
```

$\large i$번째 요소를 취득하기 위해서는 다음 노드로의 이동 연산을 $\large(i+1)$번 수행해야 한다.

$$
\large
\sum_{k=0}^{N-1}(k+1)=\sum_{k=1}^Nk=\frac{N(N+1)}{2}
$$

따라서 시간 복잡도는 $\large O(N^2)$이다.

## 8.3 연결 리스트의 크기를 $O(1)$로 취득 가능한 방법을 서술하라.

크기를 나타내는 멤버 변수를 선언하고 삽입 및 삭제 연산마다 적절히 증가 또는 감소시켜 준다.

## 8.4 단방향 연결 리스트에서 특정 노드 $v$를 삭제하는 방법을 서술하라. 단, $O(N)$ 복잡도를 허용한다.

더미 노드에서 시작한다. 현재 노드의 다음 노드가 $\large v$ 노드라면 현재 노드의 다음 노드를 현재 노드의 다음 노드의 다음 노드로 변경한다.

그렇지 않다면 현재 노드를 다음 노드로 변경하고 탐색을 계속한다.

## 8.5 $N$개의 서로 다른 정수 $a_0,\ a_1,\ \ldots,\ a_{N-1}$과 $M$개의 서로 다른 정수 $b_0,\ b_1,\ \ldots,\ b_{M-1}$이 주어졌다고 하자. $a$와 $b$에서 공통으로 등장하는 정수의 개수를 평균적으로 $O(N + M)$ 복잡도로 구하는 알고리즘을 설계하라.

[Link](8.5.cpp)

## 8.6 $N$개의 정수 $a_0,\ a_1,\ \ldots,\ a_{N-1}$과 $M$개의 정수 $b_0,\ b_1,\ \ldots,\ b_{M-1}$이 주어졌다고 하자. $a_i=b_j$가 되는 인덱스 $i,\ j$ 조합의 개수를 평균적으로 $O(N + M)$ 복잡도로 구하는 알고리즘을 설계하라.

[Link](8.6.cpp)

## 8.7 $N$개의 정수 $a_0,\ a_1,\ \ldots,\ a_{N-1}$과 $M$개의 정수 $b_0,\ b_1,\ \ldots,\ b_{M-1}$이 주어졌다고 하자. 두 정수열에서 각각 하나씩 골라 더한 합이 $K$가 될 수 있는지 여부를 평균적으로 $O(N)$ 복잡도로 판정하는 알고리즘을 설계하라. 참고로 6.6절에서는 비슷한 문제를 이진 탐색 트리를 기반으로 $O(N\log{N})$ 복잡도로 푸는 알고리즘을 제시했다.

[Link](8.7.cpp)