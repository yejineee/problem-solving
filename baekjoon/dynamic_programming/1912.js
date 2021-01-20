const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const solution = () => {
  const num = input[1].split(" ").map((v) => +v);
  const maxNum = new Array(num.length);
  num.forEach((value, i) => {
    if (i === 0) {
      maxNum[i] = value;
      return;
    }
    maxNum[i] = Math.max(maxNum[i - 1] + value, value);
  });
  console.log(Math.max(...maxNum));
};
solution();
