const isCorrect = (str) => str[0] === "(";
const splitUV = (str) => {
  let i = 0;
  let open = 0;
  do {
    open += str[i++] === "(" ? 1 : -1;
  } while (open !== 0);
  return [str.substring(0, i), str.substring(i)];
};

const reverseBracket = (str) => {
  return Array.from(str)
    .map((bracket) => (bracket === "(" ? ")" : "("))
    .join("");
};
const incorrectStrHandler = (u, v) => {
  return `(${solution(v)})${reverseBracket(u.substring(1, u.length - 1))}`;
};

function solution(p) {
  if (p.length === 0) {
    return p;
  }
  const [u, v] = splitUV(p);
  if (isCorrect(u)) {
    return u + solution(v);
  }
  return incorrectStrHandler(u, v);
}

module.exports = {
  isCorrect,
  splitUV,
  reverseBracket,
  incorrectStrHandler,
  solution,
};
