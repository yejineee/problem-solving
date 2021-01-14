const initDictionary = (dict) => {
  for (let i = "A".charCodeAt(0); i <= "Z".charCodeAt(0); i++) {
    dict.set(String.fromCharCode(i), dict.size + 1);
  }
};

const findLongestMsg = (msg, dict) => {
  let longestMsg = "";
  for (const alpha of msg) {
    if (!dict.has(longestMsg + alpha)) {
      break;
    }
    longestMsg += alpha;
  }
  return longestMsg;
};

const enrollNewWord = (word, dict) => {
  dict.set(word, dict.size + 1);
};

function solution(msg) {
  const answer = [];
  const dict = new Map();
  initDictionary(dict);
  while (!!msg.length) {
    const longestMsg = findLongestMsg(msg, dict);
    answer.push(dict.get(longestMsg));
    if (longestMsg.length < msg.length) {
      enrollNewWord(longestMsg + msg[longestMsg.length], dict);
    }
    msg = msg.slice(longestMsg.length);
  }
  return answer;
}
