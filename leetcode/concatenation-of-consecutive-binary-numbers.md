---
tags: ps
---

# [LeetCode] Concatenation of Consecutive Binary Numbers

### 문제

[Concatenation of Consecutive Binary Numbers](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3618/)

### Fact

- 숫자가 이진수일 때, 이전 값에 현재 값을 붙이려면, 현재 이진수의 길이만큼 이전 값을 shift left하고, 현재 값과 이전값에 or 연산을 취하면 된다.
- 위의 비트 연산을 곱하기와 더하기로 바꾸면, 이전 값에 2의 (현재 이진수 값의 길이)제곱을 하고, 현재 값을 더하면 된다.
- 현재 이진수 값의 길이는 log k / log 2 + 1이다.

### 접근

- 1부터 n까지 다음을 반복한다.
  - 이전까지 붙여진 값이 sum이고 현재 숫자가 k일 때, 현재 수를 2진수로 바꾸어 이전 값에 붙인 값은 다음과 같다.
    > sum \* 2^(log k / log 2 + 1) + k
  - 위에서 구한 값에 10^9+7을 나눈 나머지를 k까지 덧붙인 이진수로 정한다.

### 복잡도

- 공간 복잡도 : O(1)
- 시간 복잡도 : O(N)

### 알게된 점

- 자바스크립트에서 10진수를 n진수로 표현할 때, `Number.prototype.toString(n)`으로 나타낼 수 있다. 자바스크립트에서 n진수를 10진수로 표현할 때, parseInt(x, n)으로 나타낼 수 있다. 위의 두 메서드로 문제를 풀었을 때, 시간초과가 발생하거나, 숫자가 자바스크립트가 표현할 수 있는 최댓값을 넘어서서, 음수로 표현되었다. 따라서 매 번 계산 때마다 결과를 10^9 + 7의 나머지로 저장을 하여 숫자가 너무 커지지 않도록 하였다. 또한, 메서드를 사용하여 값을 계산하지 않고, 곱하기와 더하기 연산으로 값을 계산하였다.
- 비트 연산을 할 때 꼭 10진수를 2진수로 바꾸지 않아도 된다. 다만, 비트 연산자를 사용하면 값이 이상해져서, 비트 연산 대신 곱하기와 더하기를 하였다. << 연산 한 번에 값이 2배가 되므로, << 를 해야할 때는 곱하기를 하였다.

### 코드

```javascript
var concatenatedBinary = function (n) {
  const DENOMINATOR = 10 ** 9 + 7;
  const result = new Array(n).fill().reduce((sum, _, i) => {
    const cur = i + 1;
    sum *= 2 ** (Math.floor(Math.log(cur) / Math.log(2)) + 1);
    sum += cur;
    return sum % DENOMINATOR;
  }, 0);
  return result;
};
```

### 소감

자바스크립트로 큰 수를 표현할 때, 주의해야 함을 알게 되었다. 자바스크립트에 BigInt가 있다고 하는데, 나중에 알아봐야겠다.(나중에한다고 하면 안할 것 같은데ㅠ)

leetcode로 처음 문제를 풀어봤는데, 문제가 상당히 간결하면서도 생각을 할 수 있게 해주어서 좋았다. 테스트케이스도 범위가 굉장히 커서 효율성을 고려하여 코드를 짜는데 큰 도움이 되었다. 시간 복잡도와 공간 복잡도에서 다른 사람들과 비교를 해주니, 더 나은 코드르 찾으려고 노력한 것 같다. 결론은 leetcode 최고!
