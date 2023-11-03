import fetch from 'node-fetch'
/**
 * 异步迭代与generator
 *
 * 网络分段chunk-by-chunk
 */
let range = {
  from: 1,
  to: 5,
  [Symbol.asyncIterator]() {
    return {
      current: this.from,
      last: this.to,
      async next() {
        await new Promise((resolve) => setTimeout(resolve, 1000));
        if (this.current <= this.last) {
          return { done: false, value: this.current++ };
        } else {
          return { done: true };
        }
      },
    };
  },
};

// (async () => {
//   for await (let value of range) {
//     console.log(value);
//   }
// })();

/**
 * 提供Iterator的对象与方法：Symbol.iterator; Symbol.asyncIterator;
 * next()返回的值是：anyType； Promise
 * 循环使用：for..of; for await..of
 */

/**
 * 异步generator
 */
async function* generateSquence(start, end) {
  for (let i = start; i <= end; i++) {
    await new Promise((resolve) => setTimeout(resolve, 1000));
    yield i;
  }
}

// (async () => {
//   for await (let value of generateSquence(1, 5)) {
//     console.log(value);
//   }
// })();

/**
 * 异步可迭代对象
 */
let asyncRange = {
  from: 1,
  to: 5,
  async *[Symbol.asyncIterator]() {
    for (let value = this.from; value <= this.to; value++) {
      await new Promise((resolve) => setTimeout(resolve, 1000));
      yield value;
    }
  },
};

(async () => {
  for await (let value of asyncRange) {
    console.log(value);
  }
})();

/**
 * 实践
 */
async function* fetchCommits(repo) {
  let url = `https://api.github.com/repos/${repo}/commits`;
  while (url) {
    const response = await fetch(url, {
      headers: { "User-Agent": "Mozilla/5.0" },
    });
    const body = await response.json();
    let nextPage = response.headers.get("Link").match(/<(.*?)>; rel="next"/);
    nextPage = nextPage?.[1];

    url = nextPage;

    for (let commit of body) {
      yield commit;
    }
  }
}

(async () => {
  for await (let commit of fetchCommits("zigcc/awesome-zig")) {
    console.log(commit);
  }
})();
