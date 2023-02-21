let input = Number(require("fs").readFileSync("/dev/stdin").toString());

if (input === 0) input = 1;

res = Array.apply(null, Array(input))
  .map((_, index) => index + 1)
  .reduce((acc, cur) => {
    return acc * cur;
  });

console.log(res);
