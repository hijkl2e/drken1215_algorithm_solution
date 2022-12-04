# 4장 연습 문제 풀이

## 4.1 트리보나치 수열은 다음과 같이 정의된 수열이다. (하단 수식 참고) 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, ...로 이어질 때 트리보나치 수열의 제N항 값을 구하는 재귀 함수를 설계하라.

* $\large T_0=0$
* $\large T_1=0$
* $\large T_2=1$
* $\large T_N=T_{N-1}+T_{N-2}+T_{N-3}\quad(N=3,\ 4,\ \cdots)$

[Link](4.1.cpp)

## 4.2 연습 문제 4.1에서 설계한 재귀 함수에 대해 메모이제이션을 사용해서 효율을 개선하라. 그리고 메모이제이션 실시 후의 복잡도를 평가하라.

[Link](4.2.cpp)

메모이제이션을 사용하면 $\large N$번째 항을 구할 때까지 실시하는 덧셈 횟수는 최대 $\large2N-4$회이다.

따라서 시간 복잡도는 $\large O(N)$이 된다.

## 4.3 피보나치 수열의 일반항이 $F_N=\dfrac{1}{\sqrt{5}}\left(\left(\dfrac{1+\sqrt{5}}{2}\right)^N-\left(\dfrac{1-\sqrt{5}}{2}\right)^N\right)$인 것을 증명하라.

### Proposition

$$
\large
F_N=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^N-\left(\frac{1-\sqrt{5}}{2}\right)^N\right)
$$

### Proof

#### Base case

$$
\large
\eqalign{
F_0&=0=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^0-\left(\frac{1-\sqrt{5}}{2}\right)^0\right)\\
F_1&=1=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^1-\left(\frac{1-\sqrt{5}}{2}\right)^1\right)\\
}
$$

#### Induction step


$$
\large
\eqalign{
F_N&=F_{N-1}+F_{N-2}\\
&=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^{N-1}-\left(\frac{1-\sqrt{5}}{2}\right)^{N-1}\right)
+\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^{N-2}-\left(\frac{1-\sqrt{5}}{2}\right)^{N-2}\right)\\
&=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^{N-2}\times\left(\frac{1+\sqrt{5}}{2}+1\right)
+\left(\frac{1-\sqrt{5}}{2}\right)^{N-2}\times\left(\frac{1-\sqrt{5}}{2}+1\right)\right)\\
&=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^{N-2}\times\left(\frac{1+\sqrt{5}}{2}\right)^2
+\left(\frac{1-\sqrt{5}}{2}\right)^{N-2}\times\left(\frac{1-\sqrt{5}}{2}\right)^2\right)\\
&=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^N-\left(\frac{1-\sqrt{5}}{2}\right)^N\right)\\
}
$$

#### Conclusion

$$
\large
F_N=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^N-\left(\frac{1-\sqrt{5}}{2}\right)^N\right)
$$

## 4.4 코드 4-5의 알고리즘 복잡도가 $O\left(\left(\dfrac{1+\sqrt{5}}{2}\right)^N\right)$인 것을 증명하라.

$$
\large
\eqalign{
T(0)&=T(1)=1\\
T(N)&=T(N-1)+T(N-2)+1\qquad\text{for }N\ge2\\
}
$$

***

### Proposition

$$
\large
T(N)=2F_{N+1}-1
$$

### Proof

#### Base case

$$
\large
\eqalign{
T(0)=1=2F_1-1\\
T(1)=1=2F_2-1\\
}
$$

#### Induction step


$$
\large
\eqalign{
T(N)&=T(N-1)+T(N-2)+1\\
&=(2F_N-1)+(2F_{N-1}-1)+1\\
&=2(F_N+F_{N-1})-1\\
&=2F_{N+1}-1\\
}
$$

#### Conclusion

$$
\large
T(N)=2F_{N+1}-1
$$

***

$$
\large
\eqalign{
T(N)&=2F_{N+1}-1\\
&=\frac{2}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^{N+1}-\left(\frac{1-\sqrt{5}}{2}\right)^{N+1}\right)-1\\
}
$$

$$
\large
\left(\frac{1-\sqrt{5}}{2}\right)^N=(-0.61803\ldots)^N=O(1)
$$

$$
\large
\therefore\ T(N)=O\left(\left(\frac{1+\sqrt{5}}{2}\right)^N\right)
$$

## 4.5 10진수 표기로 각 자리 수가 7, 5, 3 중 하나이고 7, 5, 3이 모두 한 번은 등장하는 정수를 '753수'라고 부르기로 하자. 양의 정수 $K$가 주어졌을 때 $K$ 이하의 753수가 몇 개 존재하는지 구하는 알고리즘을 설계하라. 단, $K$의 자릿수를 $d$라고 할 때 $O(3^d)$ 복잡도가 허용 범위다.

[Link](4.5.cpp)

## 4.6 부분합 문제에서 재귀 함수를 사용한 복잡도 $O(2^N)$의 코드 4-9에 대해 메모이제이션을 사용하여 $O(NW)$ 복잡도로 개선하라.

[Link](4.6.cpp)