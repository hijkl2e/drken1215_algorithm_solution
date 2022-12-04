# 2장 연습 문제 풀이

## 2.1 다음 계산 시간(입력 크기는 $N$)을 란다우 빅오 표기법으로 나타내라.

$$
\large
\eqalign{
T_1(N)&=1000N\\
T_2(N)&=5N^2+10N+7\\
T_3(N)&=4N^2+3N\sqrt{N}\\
T_4(N)&=N\sqrt{N}+5N\log{N}\\
T_5(N)&=2^N+N^{2019}\\
}
$$

***

$$
\large
\eqalign{
T_1(N)&=O(N)\\
T_2(N)&=O(N^2)\\
T_3(N)&=O(N^2)\\
T_4(N)&=O(N\sqrt{N})\\
T_5(N)&=O(2^N)\\
}
$$

## 2.2 다음 프로그램의 복잡도를 구하고 란다우 빅오 표기법으로 표현하라. 이 프로그램은 $N$개 중에서 세 개를 고르는 방법을 모두 나열하는 프로그램이다.

```c++
for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
        for (int k = j + 1; k < N; ++k) {
            
        }
    }
}
```

$$
\large
T(N)=\binom{N}{3}=\frac{N(N-1)(N-2)}{6}=O(N^3)
$$

## 2.3 다음 프로그램의 복잡도를 구하고 란다우 빅오 표기법으로 표현하라. 이 함수는 양의 정수 $N$이 소인수인지 판정한다.

```c++
bool is_prime(int N) {
    if (N <= 1) return false;
    for (int p = 2; p * p <= N; ++p) {
        if (N % p == 0) return false;
    }
    return true;
}
```

$$
\large
T(N)=\left\lfloor\sqrt{N}\right\rfloor=O(\sqrt{N})
$$

## 2.4 나이 맞히기 게임에서 A 씨 나이가 $0$세 이상 $2^k$세 미만일 때 이진 탐색법으로 $k$회에 맞힐 수 있는지 확인하라.

### Proposition

$$
\large
T(2^k)=k
$$

### Proof

#### Base case

$$
\large
T(1)=0
$$

#### Induction step

$$
\large
T(2^{k+1})=T(2^k)+1=k+1
$$

#### Conclusion

$$
\large
T(2^k)=k
$$

## 2.5 나이 맞히기 게임에서 A 씨 나이가 $0$세 이상 $N$세 미만일 때 이진 탐색법으로 $O(\log{N})$회에 맞힐 수 있다는 것을 증명하라.

### Proposition 1

$$
\large
T(N)=T\left(\left\lceil\frac{N}{2}\right\rceil\right)+1\qquad\text{for }N\ge2
$$

### Proof

#### Base case

$$
\large
T(2)=1=T(1)+1
$$

#### Induction step

$$
\large
\eqalign{
T(2N)&=T(N)+1\\
&=T\left(\left\lceil\frac{2N}{2}\right\rceil\right)+1\\
}
$$

$$
\large
\eqalign{
T(2N-1)&=T(N)+1\\
&=T\left(\left\lceil\frac{2N-1}{2}\right\rceil\right)+1\\
}
$$

#### Conclusion

$$
\large
T(N)=T\left(\left\lceil\frac{N}{2}\right\rceil\right)+1\qquad\text{for }N\ge2
$$

***

### Proposition 2

$$
\large
T(N)=\lceil\log{N}\rceil\qquad\text{for }N\ge2
$$

### Proof

#### Base case

$$
\large
T(2)=1=\lceil\log{2}\rceil
$$

#### Induction step

$$
\large
\eqalign{
T(2N)&=T(N)+1\\
&=\lceil\log{N}\rceil+1\\
&=\lceil\log{2N}\rceil\\
}
$$

$$
\large
\eqalign{
T(2N-1)&=T(N)+1\\
&=\lceil\log{N}\rceil+1\\
&=\lceil\log{2N}\rceil\\
&=\lceil\log{(2N-1)}\rceil\\
}
$$

#### Conclusion

$$
\large
T(N)=\lceil\log{N}\rceil\qquad\text{for }N\ge2
$$

***

### Therefore

$$
\large
T(N)=\lceil\log{N}\rceil=O(\log{N})
$$

## 2.6 $1+\dfrac{1}{2}+\cdots+\dfrac{1}{N}=O(\log{N})$이 성립하는 것을 증명하라.

### Solution 1 (hijkl2e)

$$
\large
\eqalign{
T(N)&=1+\frac{1}{2}+\cdots+\frac{1}{N}\\
&\le1+\left(\frac{1}{2}+\frac{1}{2}\right)+\left(\frac{1}{4}+\frac{1}{4}+\frac{1}{4}+\frac{1}{4}\right)+\cdots\\
&\le\lfloor\log{N}\rfloor+1=O(\log{N})\\
}
$$

***

### Solution 2 (drken1215)

$$
\large
\eqalign{
T(N)&=1+\frac{1}{2}+\cdots+\frac{1}{N}\\
&=\sum_{k=1}^N\frac{1}{k}\\
&\le1+\int_1^N\frac{1}{x}\ dx\\
&=1+\log{N}\\
&=O(\log{N})\\
}
$$

