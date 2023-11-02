function delay(ms) {
  return new Promise((resolve, reject) => {
    setTimeout(resolve, ms);
  });
}

function showCircle(x, y, radius) {
  let div = document.createElement("div");
  div.style.width = 0;
  div.style.height = 0;
  div.style.left = cx + "px";
  div.style.top = cy + "px";
  div.className = "circle";
  document.body.appendChild(div);
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      div.style.width = radius * 2 + "px";
      div.style.height = radius * 2 + "px";
      div.addEventListener("transitionend", function handler() {
        div.removeEventListener("transitionend", handler);
        resolve(div);
      });
    }, 0);
  });
}

let urls = [
  "https://api.github.com/users/iliakan",
  "https://api.github.com/users/remy",
  "https://api.github.com/users/jeresig",
];

let requests = urls.map((url) => fetch(url));

Promise.all(requests).then((responses) => {
  responses.forEach((response) => {
    console.log(response.url, response.status);
  });
});

Promise.allSettled(urls.map((url) => fetch(url))).then((results) => {
  results.forEach((result, num) => {
    if (result.status == "fulfilled") {
      alert(`${urls[num]}: ${result.value.status}`);
    }
    if (result.status == "rejected") {
      alert(`${urls[num]}: ${result.reason}`);
    }
  });
});

if (!Promise.allSettled) {
  const rejectHandler = (reason) => ({ status: "rejected", reason });

  const resolveHandler = (value) => ({ status: "fulfilled", value });

  Promise.allSettled = function (promises) {
    const convertedPromises = promises.map((p) =>
      Promise.resolve(p).then(resolveHandler, rejectHandler)
    );
    return Promise.all(convertedPromises);
  };
}

function loadScript(src, callback) {
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => callback(null, script);
  script.onerror = () => callback(new Error(`Script load error for ${src}`));
  document.head.append(script);
}

let loadScriptPromise = function (src) {
  return new Promise((resolve, reject) => {
    loadScript(src, (err, script) => {
      if (err) {
        reject(err);
      } else {
        resolve(script);
      }
    });
  });
};

// Promise工厂函数，接收一个需要promise化的函数f，并返回一个包装wrapper函数
function promisify(f, manyArgs = false) {
  return function (...args) {
    return new Promise((resolve, reject) => {
      function callback(err, ...results) {
        if (err) {
          reject(err);
        } else {
          resolve(manyArgs ? results : results[0]);
        }
      }

      args.push(callback);
      f.call(this, ...args);
    });
  };
}

// Usage
let loadScriptPromisify = promisify(loadScript);
loadScriptPromisify("https://api.github.com/users/iliakan").then((script) =>
  alert(script.src).catch((err) => alert(err))
);

/**
微任务队列，内部队列 PromiseJobs

只有JS引擎中没有其他任务在运行时，才开始执行任务队列中的任务

当一个promise准备就绪时，它的.then/.catch/.finalyy处理程序会被放入队列中

未处理的rejection
  - 如果一个 promise 的 error 未被在微任务队列的末尾进行处理，则会出现“未处理的 rejection”。
  - window.addEventListener('unhandledrejection', event => alert(event.reason));
 */

/**
async await是更舒服的方式使用promise的一种特殊语法

async总是返回promise对象
await让引擎等待直到promise完成settle并返回结果

现在Moduel顶层await
 */

(async () => {
  let response = await fetch(url);
  let user = await response.json();
  console.log(user);
})();

/**
await 接收thenable
 */

class Thenable {
  constructor(num) {
    this.num = num;
  }
  then(resolve, reject) {
    alert(resolve);
    setTimeout(() => resolve(this.num * 2), 1000);
  }
  async wait() {
    return await Promise.resolve(12);
  }
}

async function f() {
  let thenable = new Thenable(42);
  let result = await thenable;
  alert(result);
}

new Thenable(42).wait().then(alert);

async function loadJsonAsync(url) {
  let response = await fetch(url);
  if (response.status == 200) {
    let json = await response.json();
    return json;
  } else {
    throw new Error(await response.text());
  }
}

loadJsonAsync(url).catch(alert);
