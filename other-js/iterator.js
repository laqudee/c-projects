/**
 * iterable object
 * 对数组的泛化，任何对象都可以被定制用在for..of循环中
 *
 * Symbol.iterator可以创建可迭代对象
 *
 * for.of 循环，会调用[Symbol.iterator](){}方法，该方法返回一个包含next函数的对象
 *
 * 迭代器对象核心功能：关注点分离
 *  - 对象本身没有next()方法
 *  - 通过调用[Symbol.iterator]()创建的迭代器对象有next()方法
 *
 * 迭代器对象与其进行迭代的对象是分开的
 */
let range = {
  from: 1,
  to: 5,

  [Symbol.iterator]() {
    this.current = this.from;
    return this;
  },

  next() {
    if (this.current <= this.to) {
      return { value: this.current++, done: false };
    } else {
      return { value: undefined, done: true };
    }
  },
};

for (let value of range) {
  console.log(value);
}

/**
 * 代理对
 */
let str = "hello";
let iterator = str[Symbol.iterator]();
while (true) {
  let result = iterator.next();
  if (result.done) break;
  console.log(result.value);
}

/**
 * iterable 与 array-like
 *   - 可迭代对象实现了Symbol.iterator方法的对象
 *  - array-like对象是具有索引和length属性的对象
 *
 * 字符串既是可迭代的实现了Symbol.iterator方法；又具有索引和length属性
 *
 * Array.from()可以接受一个可迭代或类数组的值返回一个【真正】的数组
 */
let arraylike = {
  0: "hello",
  1: "world",
  length: 2,
};
let arr = Array.from(arraylike);
arr.push("libei");
console.log(arr);


let rangArray = Array.from(range, (num) => {
    if (isNaN(num)) {
        return 0
    } else {
        return num * num
    }
});
console.log(rangArray);
rangArray.push("Hell");
console.log(rangArray);

function slice(str, start, end) {
    return Array.from(str).slice(start, end).join('')
}

let str2 = '𝒳😂𩷶';
console.log(slice(str2, 1,3));

/**
 * 可以应用for..of的对象都被称为可迭代的
 * 可迭代对象必须实现了Symbol.iterator方法
 *  - obj[Symbol.iterator]()的结果被称为Iterator迭代器
 *  - Iterator必须包含next()方法，返回一个{value:any, done:boolean}对象
 *  - Symbol.iterator方法会被for..of自动调用，用户也可以手动调用
 * 
 * 内建的可迭代对象，数组和字符串，都实现了Symbol.iterator
 * 字符串迭代器能够识别代理对surrogate pairs
 * 
 * Array.from(obj[, mapFn, thisArg])
 */