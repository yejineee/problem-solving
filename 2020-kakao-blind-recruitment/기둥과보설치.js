const PILLAR = 0;
const BO = 1;
const REMOVE = 0;
const INSTALL = 1;

const getInitialWall = (n) => {
  const wall = new Array(n + 1)
    .fill()
    .map((_) =>
      new Array(n + 1).fill().map((_) => ({ pillar: false, bo: false }))
    );
  return wall;
};

const isValidPillar = (wall, x, y) => {
  const isOnFloor = y === 0;
  const isOnBo = wall[y][x].bo || (x - 1 >= 0 && wall[y][x - 1].bo);
  const isOnPillar = y - 1 >= 0 && wall[y - 1][x].pillar;
  return isOnFloor || isOnBo || isOnPillar;
};

const isValidBo = (n) => (wall, x, y) => {
  const checkOneSideOnPillar =
    y - 1 >= 0 &&
    (wall[y - 1][x].pillar || (x + 1 <= n && wall[y - 1][x + 1].pillar));
  const checkBothOnBo =
    x - 1 >= 0 && wall[y][x - 1].bo && x + 1 < n && wall[y][x + 1].bo;
  return checkOneSideOnPillar || checkBothOnBo;
};

const toggleStatusOfWall = (wall, x, y, type) => {
  wall[y][x][type] = !wall[y][x][type];
};

const checkNoEffect = (validFunc, testWall, locList, n, type) => {
  const passAllValidFunc = locList
    .filter((loc) => loc.x >= 0 && loc.y <= n && testWall[loc.y][loc.x][type])
    .every((loc) => validFunc(testWall, loc.x, loc.y));
  return passAllValidFunc;
};

const removeBoIfPossible = (wall, x, y, n) => {
  const boLoc = [
    { x: x - 1, y },
    { x: x + 1, y },
  ];
  const pillarLoc = [
    { x, y },
    { x: x + 1, y },
  ];
  toggleStatusOfWall(wall, x, y, "bo");

  const noEffectOnBo = checkNoEffect(isValidBo(n), wall, boLoc, n, "bo");
  const noEffectOnPillar = checkNoEffect(
    isValidPillar,
    wall,
    pillarLoc,
    n,
    "pillar"
  );
  if (noEffectOnBo && noEffectOnPillar) {
    return;
  }
  toggleStatusOfWall(wall, x, y, "bo");
};

const removePillarIfPossible = (wall, x, y, n) => {
  const boLoc = [
    { x, y: y + 1 },
    { x: x - 1, y: y + 1 },
  ];
  const pillarLoc = [{ x, y: y + 1 }];
  toggleStatusOfWall(wall, x, y, "pillar");

  const noEffectOnBo = checkNoEffect(isValidBo(n), wall, boLoc, n, "bo");
  const noEffectOnPillar = checkNoEffect(
    isValidPillar,
    wall,
    pillarLoc,
    n,
    "pillar"
  );

  if (noEffectOnBo && noEffectOnPillar) {
    return;
  }
  toggleStatusOfWall(wall, x, y, "pillar");
};
const installIfPossible = (validFunc, wall, x, y, type) => {
  if (!validFunc(wall, x, y)) {
    return;
  }
  wall[y][x][type] = true;
};

const getFinalFrame = (wall, n) => {
  const finalFrame = [];
  for (let x = 0; x <= n; x++) {
    for (let y = 0; y <= n; y++) {
      if (wall[y][x].pillar) {
        finalFrame.push([x, y, PILLAR]);
      }
      if (wall[y][x].bo) {
        finalFrame.push([x, y, BO]);
      }
    }
  }
  return finalFrame;
};

function solution(n, build_frame) {
  let wall = getInitialWall(n);

  for (const [x, y, type, action] of build_frame) {
    if (type === PILLAR) {
      if (action === INSTALL) {
        installIfPossible(isValidPillar, wall, x, y, "pillar");
      } else {
        removePillarIfPossible(wall, x, y, n);
      }
    } else {
      // BO
      if (action === INSTALL) {
        installIfPossible(isValidBo(n), wall, x, y, "bo");
      } else {
        removeBoIfPossible(wall, x, y, n);
      }
    }
  }
  const finalFrame = getFinalFrame(wall, n);
  return finalFrame;
}
