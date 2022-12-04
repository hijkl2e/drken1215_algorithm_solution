# 12장 연습 문제 풀이

## 12.1 $N$개의 서로 다른 정수 $a_0,\ a_1,\ \ldots,\ a_{N-1}$이 주어졌을 때 각 $i$에 대해 $a_i$가 몇 번째로 작은 값인지 구하는 알고리즘을 설계하라.

[Link](12.1.cpp)

## 12.2 $N$개 가게가 있고 $i(=0,\ 1,\ \ldots,\ N-1)$번째 가게는 하나에 $A_i$원인 에너지 드링크를 최대 $B_i$개까지 판다고 하자. 모두 합쳐서 총 $M$개의 드링크를 사려고 할 때 최소 몇 원에 살 수 있는지 구하는 알고리즘을 설계하라. 다만 $\sum\nolimits_{i=0}^{N-1}B_i\ge M$이다.

[Link](12.2.cpp)

## 12.3 $N,\ K(N\ge K)$를 양의 정수라고 하자. 빈 집합 $S$가 있고 $N$개의 서로 다른 정수 $a_0,\ a_1,\ \dots,\ a_{N-1}$을 순서대로 삽입한다. 각 $i=K,\ K+1,\ \ldots,\ N$에 대해 $S$에 $i$개의 정수가 삽입된 단계를 생각할 때 $S$에 포함된 요소 중에 $K$번째로 작은 값을 출력하는 알고리즘을 설계하라. 다만, 전체 복잡도는 $O(N\log{N})$으로 만들어야 한다.

[Link](12.3.cpp)

## 12.4 계산량을 나타내는 함수 $T(N)$이 $T(N)=2T\left(\dfrac{N}{2}\right)+O(N^2)$를 만족할 때 $T(N)=O(N^2)$라는 걸 증명하라. 또한, $T(N)=2T\left(\dfrac{N}{2}\right)+O(N\log{N})$이라면 어떻게 되는가?

$$
\large
\eqalign{
T(N)&=2T\left(\frac{N}{2}\right)+O(N^2)\\
&\le2T\left(\frac{N}{2}\right)+dN^2\\
&\le2\left(2T\left(\frac{N}{2^2}\right)+\frac{d}{2^2}N^2\right)+dN^2\\
&\le\cdots\\
&\le cN+2\left(1-\left(\frac{1}{2}\right)^{\log{N}}\right)dN^2\\
&=O(N^2)\\
}
$$

$$
\large
\eqalign{
T(N)&=2T\left(\frac{N}{2}\right)+O(N\log{N})\\
&\le2T\left(\frac{N}{2}\right)+dN\log{N}\\
&\le2\left(2T\left(\frac{N}{2^2}\right)+\frac{d}{2}N(\log{N}-1)\right)+dN\log{N}\\
&\le\cdots\\
&\le cN+\frac{d}{2}N\log{N}+\frac{d}{2}N\log^2{N}\\
&=O(N\log^2{N})\\
}
$$

## 12.5 $N$개의 정수 $a_0,\ a_1,\ \ldots,\ a_{N-1}$이 주어졌을 때 $k$번째로 작은 정수를 $O(N)$으로 구하는 알고리즘을 설계하라.

$$
\large
\mathrm{PARTITION}(N)=O(N)
$$

$$
\large
\mathrm{PIVOT}(N)=\mathrm{SELECT}\left(\frac{N}{5}\right)+O(N)
$$

$$
\large
\eqalign{
\mathrm{SELECT}(N)&=\mathrm{PIVOT}(N)+\mathrm{PARTITION}(N)+\mathrm{SELECT}\left(\frac{7}{10}N\right)\\
&=\mathrm{SELECT}\left(\frac{7}{10}N\right)+\mathrm{SELECT}\left(\frac{N}{5}\right)+O(N)\\
}
$$

***

$$
\large
T(N)=O(N)
$$

### Proof

$$
\large
\eqalign{
T(N)&=T\left(\frac{7}{10}N\right)+T\left(\frac{N}{5}\right)+O(N)\\
&\le\frac{7}{10}cN+\frac{1}{5}cN+dN\\
&=\frac{9}{10}cN+dN\le cN\\
}
$$

[Link](12.5.cpp)

## 12.6 정수 $a,\ m(a\ge0,\ m\ge1)$이 주어졌을 때 $a^x\equiv x\pmod{m}$을 만족하는 양의 정수 $x$가 존재하는지 여부를 판정하고, 존재한다면 하나를 구하는 $O(\sqrt{m})$ 복잡도 알고리즘을 설계하라.

### Lemma

$$
\large
K\ge\phi(M)\ \wedge\ A^K\equiv K\pmod{\phi(M)}\implies A^{A^K}\equiv A^K\pmod{M}
$$

### Proof

$$
\large
A^K=c\ \phi(M)+K
$$

$$
\large
K=d\ \phi(M)+r\quad(0\le r<\phi(M))
$$

$$
\large
A^K=(c+d)\ \phi(M)+r
$$

$$
\large
\because\ d>0
$$

By [Corollary of Euler's theorem](https://github.com/hijkl2e/problem_solving/blob/main/algorithm/euler_theorem.md#corollary),

$$
\large
\eqalign{
A^K&=A^{d\ \phi(M)+r}\\
&\equiv A^{(c+d)\ \phi(M)+r}\pmod{M}\\
&=A^{A^K}
}
$$

$$
\large
\therefore\ K\ge\phi(M)\ \wedge\ A^K\equiv K\pmod{\phi(M)}\implies A^{A^K}\equiv A^K\pmod{M}
$$

[Link](12.6.cpp)
