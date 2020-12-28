const N_GAME = 3;
const scoreRegex = /\d{1,2}/;
const bonusRegex = /[SDT]/;
const optionRegex = /[#*]/;

const getInfo = (string, regex) => string.match(regex);
const getScore = (string) => +getInfo(string, scoreRegex)[0];
const getBonus = (string) => getInfo(string, bonusRegex)[0];
const getOption = (string) => {
  const option = getInfo(string, optionRegex);
  return option ? option[0] : undefined;
};
const calcBonusScore = (score, bonus) => {
  const powMap = {
    S: 1,
    D: 2,
    T: 3,
  };
  return score ** powMap[bonus];
};
const solution = (dartResult) => {
  const gameScore = [];
  const gameInfo = dartResult.match(/(\d{1,2})([SDT])([*#])?/g);
  gameInfo.forEach((game, i) => {
    const score = getScore(game);
    const bonus = getBonus(game);
    const option = getOption(game);
    const bonusScore = calcBonusScore(score, bonus);
    if (option === "#") {
      gameScore.push(bonusScore * -1);
    } else if (option === "*") {
      if (i !== 0) {
        gameScore[i - 1] *= 2;
      }
      gameScore.push(bonusScore * 2);
    } else {
      gameScore.push(bonusScore);
    }
  });
  const result = gameScore.reduce((sum, score) => sum + score, 0);
  return result;
};

console.log(solution("1S*2T*3S"));
