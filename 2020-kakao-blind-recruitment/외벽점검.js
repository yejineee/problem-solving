const findNextLoc = (cur, next, n) => (cur + next) % n;

const permutation = (arr, k, list, result) => {
  if (list.length === k) {
    result.push(list);
    return;
  }
  for (let i = 0; i < arr.length; i++) {
    const nextArr = [...arr.slice(0, i), ...arr.slice(i + 1)];
    permutation(nextArr, k, [...list, arr[i]], result);
  }
  return result;
};
const countWeak = (unFoundWeak, distance, n) => {
  let count = 0;
  const start = unFoundWeak[0];
  for (let next = 0; next <= distance; next++) {
    const nextLoc = findNextLoc(start, next, n);
    if (nextLoc !== unFoundWeak[0]) {
      continue;
    }
    count += 1;
    unFoundWeak.shift();
  }
  return count;
};

function solution(n, weak, dist) {
  const totalWeak = weak.length;
  for (let k = 1; k <= dist.length; k++) {
    const combiList = permutation(dist, k, [], []);
    const findAll = combiList.some((list) => {
      for (let startIdx = 0; startIdx < weak.length; startIdx++) {
        const unFoundWeak = [
          ...weak.slice(startIdx),
          ...weak.slice(0, startIdx),
        ];
        const foundCount = list.reduce((sum, distance) => {
          const count = countWeak(unFoundWeak, distance, n);
          return sum + count;
        }, 0);
        if (foundCount === totalWeak) {
          return true;
        }
      }
      return false;
    });
    if (findAll) {
      return k;
    }
  }
  return -1;
}
