const MAX_LENGTH = 15;
const MIN_LENGTH = 3;

const convertToLowerStr = str => str.toLowerCase();
const deleteInvalidOne = str => str.replace(/[^a-z\d-_.]/g, '');
const deleteContinuousPeriod = str => str.replace(/\.{2,}/g, '.');
const deleteStartEndPeriod = str => str.replace(/^\.|\.$/g, '');
const putAIfEmpty = str => str.replace(/^$/, 'a');
const addToLast = (str, char) => str.padEnd(MIN_LENGTH, char);
const subStrToMaxLength = str => str.substring(0, MAX_LENGTH);

const isValidStrLength = str =>
  str.length >= MIN_LENGTH && str.length <= MAX_LENGTH;

function solution(new_id) {
  const step1Str = convertToLowerStr(new_id);
  const step2Str = deleteInvalidOne(step1Str);
  const step3Str = deleteContinuousPeriod(step2Str);
  const step4str = deleteStartEndPeriod(step3Str);
  if (isValidStrLength(step4str)) {
    return step4str;
  }
  const step5str = putAIfEmpty(step4str);
  if (step5str.length > MAX_LENGTH) {
    const maxLenStr = subStrToMaxLength(step5str);
    return deleteStartEndPeriod(maxLenStr);
  }
  return addToLast(step5str, step5str[step5str.length - 1]);
}
