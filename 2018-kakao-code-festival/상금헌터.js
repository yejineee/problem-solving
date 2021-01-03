const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .slice(1);

const firstAwardTable = [
  { acc: 1, award: 500 * 10 ** 4 },
  { acc: 3, award: 300 * 10 ** 4 },
  { acc: 6, award: 200 * 10 ** 4 },
  { acc: 10, award: 50 * 10 ** 4 },
  { acc: 15, award: 30 * 10 ** 4 },
  { acc: 21, award: 10 * 10 ** 4 },
];

const secondAwardTable = [
  { acc: 1, award: 512 * 10 ** 4 },
  { acc: 3, award: 256 * 10 ** 4 },
  { acc: 7, award: 128 * 10 ** 4 },
  { acc: 15, award: 64 * 10 ** 4 },
  { acc: 31, award: 32 * 10 ** 4 },
];

const getTotalPeople = (arr) => arr[arr.length - 1].acc;

const calcMoney = (grade, awardTable) => {
  if (grade === 0 || grade > getTotalPeople(awardTable)) {
    return 0;
  }
  for (const { acc, award } of awardTable) {
    if (acc < grade) {
      continue;
    }
    return award;
  }
  return 0;
};

const solution = () => {
  input.forEach((testcase) => {
    const [firstGrade, secondGrade] = testcase.split(" ").map((str) => +str);
    const result =
      calcMoney(firstGrade, firstAwardTable) +
      calcMoney(secondGrade, secondAwardTable);
    console.log(result);
  });
};

solution();
