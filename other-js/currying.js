/**
 * f(a,b,c) => f(a)(b)(c)
 * 只是对函数就行转换，部队函数进行调用
 */
{
  function curry(f) {
    return function (a) {
      return function (b) {
        return f(a, b);
      };
    };
  }

  // Usage
  function sum(a, b) {
    console.log(a + b);
    return a + b;
  }

  let curryingSum = curry(sum);
  curryingSum(1)(2);
}

/**
 * lodash库中的 _.curry(f)
 *
 * 部分应用函数partially applied function
 */

/**
 * 高级柯里化实现
 */
function curry(func) {
  return function curried(...args) {
    if (args.length >= func.length) {
      return func.apply(this, args);
    } else {
      return function (...args2) {
        return curried.apply(this, args.concat(args2));
      };
    }
  };
}

{
  function sum(a, b, c) {
    return a + b + c;
  }

  let curriedSum = curry(sum);

  console.log(curriedSum(1, 2, 3)); // 6，仍然可以被正常调用
  console.log(curriedSum(1)(2, 3)); // 6，对第一个参数的柯里化
  console.log(curriedSum(1)(2)(3)); // 6，全柯里化
}

{
  function User(name, birthday) {
    this.name = name;
    this.birthday = birthday;

    Object.defineProperty(this, "age", {
      get() {
        let now = new Date().getFullYear();
        return now - this.birthday.getFullYear();
      },
    });
  }

  let john = new User("John", new Date(1992, 1, 1));
  console.log(john.age);
  console.log(john.birthday);
}
