class Stack {
  constructor() {
    this.s = [];
  }
  empty() {
    return this.s.length === 0;
  }
  top() {
    return this.s[this.s.length - 1];
  }
  push(item) {
    this.s.push(item);
  }
  pop() {
    const [top] = this.s.splice(this.s.length - 1, 1);
    return top;
  }
  values() {
    return [...this.s];
  }
}
function solution(progresses, speeds) {
  const count = new Stack();
  const days = new Stack();

  progresses.forEach((progress, i) => {
    const day = Math.ceil((100 - progress) / speeds[i]);
    if (days.empty() || days.top() < day) {
      days.push(day);
      count.push(1);
    } else {
      const top = count.pop();
      count.push(top + 1);
    }
  });
  return count.values();
}
