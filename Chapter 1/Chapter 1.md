# 1장 연습 문제 풀이

## 1.1 나이 맞히기 게임에서 A 씨의 나이가 20살 이상 36살 미만인 각각의 경우에 대해 이진 탐색으로 나이를 맞힐 때까지의 흐름을 구하라.

[Link](1.1.cpp)

## 1.2 나이 맞히기 게임에서 A 씨의 나이 후보가 0세 이상 100세 미만으로 100개 있다고 하자. 예/아니오로 답할 수 있는 질문을 반복해서 나이를 맞힌다고 할 때 확실하게 맞힐 수 있는 질문 횟수는 여섯 번인가? 아니면 일곱 번인가?

최악의 경우 나이 후보의 개수는 다음과 같이 감소한다.

100 -> 50 -> 25 -> 13 -> 7 -> 4 -> 2 -> 1

따라서 정답은 일곱 번이다.

[Link](1.2.cpp)

## 1.3 그림 1-3 왼쪽 퍼즐의 답을 구하라.

&nbsp;&nbsp;&nbsp;2 7

× 3 5

1 3 5

8 1

9 4 5

[Link](1.3.cpp)

## 1.4 그림 1-3 오른쪽 퍼즐의 답을 구하라.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6 6 6 6 6 6

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;×&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 7 1 1

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6 6 6 6 6 6

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6 6 6 6 6 6

&nbsp;&nbsp;&nbsp;4 6 6 6 6 6 2

&nbsp;&nbsp;&nbsp;6 6 6 6 6 6

1 1 4 0 6 6 5 5 2 6

[Link](1.4.cpp)

## 1.5 그림 1-6의 미로에서 오른쪽 아래 그림처럼 이동 횟수를 알고 있는 상태일 때 실제로 S 칸에서 G 칸 사이의 최단 경로를 복원하는 방법을 논하라.

G 칸에서 시작한다. 현재 칸과 인접한 칸 중 현재 칸에 적힌 수보다 1만큼 작은 수가 적힌 칸으로 이동한다. 이를 S 칸에 도달할 때까지 반복한다.

이 경로를 거꾸로 뒤집으면 S 칸에서 G 칸 사이의 최단 경로를 복원할 수 있다.

[Link](1.5.cpp)

## 1.6 좋아하는 알고리즘을 하나 정해서 현실 사회에 실제로 사용되는 응용 사례를 조사해 보라.

[Link](https://youtu.be/WPdWvnAAurg)