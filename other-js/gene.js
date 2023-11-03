/**
generator返回generator object对象

next()方法，恢复执行直到最近的yield <value>

{value, done}
 */

function* generateSquence() {
  yield 1;
  yield 2;
  yield 3;
}

let generator = generateSquence();

for (let value of generator) {
  console.log(value);
}

let sequence = [0, ...generateSquence()];
console.log(sequence);

/**
可迭代对象 Ierator Object
[Symbol.iterator]() {
    return { next() }
}
 */
let range = {
  from: 1,
  to: 5,
  [Symbol.iterator]() {
    return {
      current: this.from,
      last: this.to,
      next() {
        if (this.current <= this.last) {
          return { done: false, value: this.current++ };
        } else {
          return { done: true };
        }
      },
    };
  },
};
console.log([...range]);

let range2 = {
  from: 1,
  to: 5,

  *[Symbol.iterator]() {
    for (let value = this.from; value <= this.to; value++) {
      yield value;
    }
  },
};
console.log([...range2]);

/**
 * generator函数可以永远产出yield值
 *
 * 组合generator
 *  generator组合是一个将一个generator流插入到另一个generator流的自然方式，不需要使用额外的内存来存储中间结果
 *
 * yield* 指令将执行委托给另一个generator
 */
function* generateSequence(start, end) {
  for (let i = start; i <= end; i++) yield i;
}
function* generatorPasswordCodes() {
  // 0..9
  yield* generateSequence(48, 57);

  // A..Z
  yield* generateSequence(65, 90);

  // a..z
  yield* generateSequence(97, 122);
}

let str = "";
for (let code of generatorPasswordCodes()) {
  str += String.fromCharCode(code);
}
console.log(str);

/**
 * 将外部值传入内部
 */
function* gen() {
  try {
    let ask1 = yield "2 + 2 = ?";
    console.log(ask1);
    let ask2 = yield "3 + 3 = ?";
    console.log(ask2);
  } catch (e) {
    console.error(e);
  }
}
let genObject = gen();
console.log(genObject.next().value);

// genObject.throw(new Error("The answer is not found in my database."))

console.log(genObject.next(4).value);
console.log(genObject.next(5).done);


/**
 * generator.throw()
 * 
 * generator.return(value)
 * 完成 generator的执行并返回给定的value
 */

/**
 * 伪随机数
 */

function* pseudoRando(seed) {
    let value = seed;
    while(true) {
        value = value * 16807 % 2147483647;
        yield value;
    }
}

let generatorP = pseudoRando(1);
console.log(generatorP.next().value);
console.log(generatorP.next().value);
console.log(generatorP.next().value);