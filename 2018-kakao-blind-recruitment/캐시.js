const HIT = 1;
const MISS = 5;

const isInCache = (cityList, target) =>
  cityList.some((city) => city === target);

const removeFromCache = (cityList, target) =>
  cityList.filter((city) => city !== target);

function solution(cacheSize, cities) {
  if (cacheSize === 0) {
    return cities.length * MISS;
  }
  const lowCities = cities.map((city) => city.toLowerCase());
  let cache = [];
  const totalTime = lowCities.reduce((time, city) => {
    if (isInCache(cache, city)) {
      cache = [...removeFromCache(cache, city), city];
      return time + HIT;
    }
    if (cache.length >= cacheSize) {
      cache.shift();
    }
    cache.push(city);
    return time + MISS;
  }, 0);
  return totalTime;
}
