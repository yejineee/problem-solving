var getSmallestString = function (n, k) {
  const aCharCode = "a".charCodeAt(0);
  const zNumeric = "z".charCodeAt(0) - aCharCode + 1;
  let smallestString = "";
  for (let i = n - 1; i >= 0; i--) {
    const numeric = k - i > zNumeric ? zNumeric : k - i;
    k -= numeric;
    smallestString =
      String.fromCharCode(aCharCode + numeric - 1) + smallestString;
  }
  return smallestString;
};
