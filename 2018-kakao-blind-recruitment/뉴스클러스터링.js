const isAlpha = (x) => "a" <= x.toLowerCase() && "z" >= x.toLowerCase();
const getMultiSet = (str) => {
  const strArr = Array.from(str).map((s) => s.toLowerCase());
  const multiSet = strArr.reduce((multi, cur, i) => {
    if (i >= strArr.length - 1) {
      return multi;
    }
    const next = strArr[i + 1];
    if (!isAlpha(cur) || !isAlpha(next)) {
      return multi;
    }
    multi.push(cur + next);
    return multi;
  }, []);
  return multiSet;
};

const getResult = (num) => Math.floor(num * 65536);

const getIntersection = (arr1, arr2) => {
  const set1 = new Set(arr1);
  const intersection = arr2.reduce((interSet, element) => {
    if (set1.has(element)) {
      interSet.add(element);
    }
    return interSet;
  }, new Set());
  return [...intersection];
};

const countElement = (arr, value) => arr.filter((x) => x === value).length;

const countSetNotIntersection = (arr, intersection) => {
  const interSet = new Set(intersection);
  const filtered = arr.filter((elem) => !interSet.has(elem));
  return filtered.length;
};

function solution(str1, str2) {
  const multiSet1 = getMultiSet(str1);
  const multiSet2 = getMultiSet(str2);
  if (multiSet1.length === 0 && multiSet2.length === 0) {
    return getResult(1);
  }
  const intersectionArr = getIntersection(multiSet1, multiSet2);
  const baseUnion =
    countSetNotIntersection(multiSet1, intersectionArr) +
    countSetNotIntersection(multiSet2, intersectionArr);
  const { nIntersection, nUnion } = intersectionArr.reduce(
    (count, element) => {
      const countElemIn1 = countElement(multiSet1, element);
      const countElemIn2 = countElement(multiSet2, element);
      count.nIntersection += Math.min(countElemIn1, countElemIn2);
      count.nUnion += Math.max(countElemIn1, countElemIn2);
      return count;
    },
    { nIntersection: 0, nUnion: baseUnion }
  );
  return getResult(nIntersection / nUnion);
}
