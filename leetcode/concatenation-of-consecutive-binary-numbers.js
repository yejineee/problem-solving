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

console.log(concatenatedBinary(11));
