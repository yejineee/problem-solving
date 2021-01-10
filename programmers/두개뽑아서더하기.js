function solution(numbers) {
  const answer = new Set();
  for (let i = 0; i < numbers.length - 1; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      answer.add(numbers[i] + numbers[j]);
    }
  }

  return [...answer].sort((a, b) => a - b);
}
