const makePriority = (candidate, priority, list) => {
  if (candidate.length === 0) {
    list.push(priority);
    return;
  }
  for (let i = 0; i < candidate.length; i++) {
    const newCandidate = candidate.slice(0, i) + candidate.slice(i + 1);
    const newPriority = priority + candidate[i];
    makePriority(newCandidate, newPriority, list);
  }
};

const getPriorityList = (expression) => {
  const priorityList = [];
  const candidate = [...new Set(expression.match(/[^\d]/g))];
  makePriority(candidate, "", priorityList);
  return priorityList;
};

const evalExpression = (priority, expression) => {
  for (const op of priority) {
    while (expression.indexOf(op) !== -1) {
      const opIdx = expression.indexOf(op);
      const evaluatedExp = `${eval(
        expression.slice(opIdx - 1, opIdx + 2).join("")
      )}`;
      expression = [
        ...expression.slice(0, opIdx - 1),
        evaluatedExp,
        ...expression.slice(opIdx + 2),
      ];
    }
  }
  return Math.abs(+expression[0]);
};
function solution(expression) {
  const expList = expression.match(/\d+|[+\-*]/g);
  const priorityList = getPriorityList(expression);
  const answer = priorityList.reduce((maxResult, priority) => {
    const result = evalExpression(priority, expList);
    return Math.max(maxResult, result);
  }, 0);
  return answer;
}

solution("100-200*300-500+20");
