const EMPTY = ".";
const dir = [
  [0, 0],
  [1, 0],
  [0, 1],
  [1, 1],
];
const checkCrash = (r, c, crashBoard) => {
  dir.forEach(([dr, dc]) => (crashBoard[r + dr][c + dc] = true));
};

const countCrash = (checkBoard) => {
  const nCrash = checkBoard
    .flat()
    .reduce((count, check) => (check ? count + 1 : count), 0);
  return nCrash;
};

const fillEmptySpace = (board, checkBoard, m, n) => {
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (!checkBoard[r][c]) {
        continue;
      }
      for (let i = r; i > 0; i--) {
        board[i][c] = board[i - 1][c];
      }
      board[0][c] = EMPTY;
    }
  }
};
const getCheckBoard = (m, n) =>
  new Array(m).fill().map((_) => new Array(n).fill(false));

const isAllSame = (board, r, c) => {
  const block = board[r][c];
  return dir.every(([dr, dc]) => block === board[r + dr][c + dc]);
};
function solution(m, n, stringBoard) {
  const board = stringBoard.map((str) => Array.from(str));
  let totalCrash = 0;
  while (true) {
    const checkBoard = getCheckBoard(m, n);
    for (let r = 0; r < m - 1; r++) {
      for (let c = 0; c < n - 1; c++) {
        if (board[r][c] === EMPTY || !isAllSame(board, r, c)) {
          continue;
        }
        checkCrash(r, c, checkBoard);
      }
    }
    const count = countCrash(checkBoard);
    if (count === 0) {
      break;
    }
    totalCrash += count;
    fillEmptySpace(board, checkBoard, m, n);
  }

  return totalCrash;
}
