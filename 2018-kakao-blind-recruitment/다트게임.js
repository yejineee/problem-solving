const NOT_FOUND = -1;
const NOT_DETERMINED = -1;
const getScore = (startIdx, input) => {
  const bonus = ["S", "D", "T"];
  const bonusIdx = new Array(bonus.length).fill().reduce((result, _, i) => {
    const idx = input.indexOf(bonus[i], startIdx);
    if (idx !== NOT_FOUND) {
      if (result === NOT_DETERMINED) {
        return idx;
      }
      return Math.min(result, idx);
    }
    return result;
  }, NOT_DETERMINED);
  return [+input.substring(startIdx, bonusIdx), bonusIdx];
};

const calcBonusScore = (score, bonus) => {
  const bonusCalcMap = {
    S: (score) => score,
    D: (score) => score ** 2,
    T: (score) => score ** 3,
  };
  return bonusCalcMap[bonus](score);
};

function solution(dartResult) {
  const gameScore = [];
  let i = 0;
  while (i < dartResult.length) {
    const [score, bonusIdx] = getScore(i, dartResult);
    const bonusScore = calcBonusScore(score, dartResult[bonusIdx]);
    const optIdx = bonusIdx + 1;
    if (dartResult[optIdx] === "*") {
      if (gameScore.length !== 0) {
        gameScore[gameScore.length - 1] *= 2;
      }
      gameScore.push(bonusScore * 2);
      i = optIdx + 1;
    } else if (dartResult[optIdx] === "#") {
      gameScore.push(bonusScore * -1);
      i = optIdx + 1;
    } else {
      gameScore.push(bonusScore);
      i = bonusIdx + 1;
    }
  }

  const answer = gameScore.reduce((sum, score) => sum + score, 0);
  return answer;
}

module.exports = { solution, calcBonusScore, getScore };
