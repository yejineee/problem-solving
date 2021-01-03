const getAnswer = (numberOrder, t, m, p) => {
  const answerArray = new Array(t)
    .fill()
    .map((_, i) => numberOrder[m * i + (p - 1)]);
  return answerArray.join("");
};

const getNumberOrder = (n, t, m, p) => {
  let order = "";
  const maxIdx = m * (t - 1) + p - 1;
  for (let num = 0; order.length <= maxIdx; num++) {
    order += num.toString(n).toUpperCase();
  }
  return order;
};
function solution(n, t, m, p) {
  const numberOrder = getNumberOrder(n, t, m, p);
  const answer = getAnswer(numberOrder, t, m, p);
  return answer;
}
