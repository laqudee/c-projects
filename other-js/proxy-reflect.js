/**
 * proxy包装另一个对象并拦截/写和其他操作
 *
 * 没有任何handler，proxy就是target的透明包装器wrapper
 *
 * 内部方法。描述了最底层的工作方式
 *  - [[GET]]
 *  - [[SET]]
 *  - [[HasProperty]]
 *  - [[Delete]]
 *  - [[Call]]
 *  - [[Construct]]
 *  - [[GetPrototypeOf]]
 *  - [[IsExtensible]]
 *  - [[DefineOwnProperty]]
 *  - [[GetOwnProperty]]
 *  - [[OwnPropertyKeys]]
 *
 * 不变量
 *  - 内部方法和捕捉器必须满足的条件
 *
 * get(target, property, receiver)
 *  - receiver就是本次读取属性所在的this对象，通常是proxy对象本身
 */
{
  let numbers = [0, 1, 2];
  numbers = new Proxy(numbers, {
    get(target, prop) {
      if (prop in target) {
        return target[prop];
      } else {
        return 0;
      }
    },
    set(target, prop, val) {
      if (typeof val === "number") {
        target[prop] = val;
        return true;
      } else {
        return false;
      }
    },
  });

  console.log(numbers[1]);
  console.log(numbers[123]);

  numbers.push(4);
  numbers.push(1);
  console.log(numbers, numbers.length);
}

/**
 * 代理应该在所有地方都完全替代target对象，target对象被代理后，任何人都不应该再引用目标对象
 *
 * 数组的push，内部使用[[Set]]操作
 *
 * for..in,Object.keys和大多数循环对象属性的方法都使用内部方法[[OwnPropertyKeys]]由OwnKeys拦截器来获取属性列表
 *
 * Object.getOwnPropertyNames(obj)返回非symbol键
 * Object.getOwnPropertySymbols(obj)返回symbol键
 * Object.keys/values() 返回带有 enumerable 标志的非 symbol 键/值
 * for..in 循环遍历所有带有 enumerable 标志的非 symbol 键，以及原型对象的键
 */
{
  let user = {
    name: "libai",
    age: 34,
    _password: "*****",
    checkPassword(value) {
      return value === this._password;
    },
  };
  user = new Proxy(user, {
    get(target, prop) {
      if (prop.startsWith("_")) {
        throw Error("Access denied!");
      }
      let value = target[prop];
      if (typeof value === "function") {
        return value.bind(target);
      }
      return value;
    },
    set(target, prop, val) {
      if (prop.startsWith("_")) {
        throw Error("Access denied!");
      }
      target[prop] = val;
      return true;
    },
    ownKeys(target) {
      return Object.keys(target).filter((key) => !key.startsWith("_"));
    },
    deleteProperty(target, prop) {
      if (prop.startsWith("_")) {
        throw Error("Access denied!");
      }
      delete target[prop];
      return true;
    },
  });

  for (let key in user) {
    console.log(key);
  }
  console.log(Object.keys(user));
  //   console.log(Object.values(user));
  //   console.log(Object.entries(user));
  //   try {
  //     console.log(user._password);
  //   } catch (e) {
  //     console.error(e);
  //   }

  //   try {
  //     user._password = "123456";
  //   } catch (e) {
  //     console.error(e);
  //   }

  //   try {
  //     delete user._password;
  //   } catch (e) {
  //     console.error(e);
  //   }

  console.log(user.checkPassword("123456"));
}

{
  let user = {};
  user = new Proxy(user, {
    ownKeys(target) {
      return ["a", "b", "c"];
    },
    getOwnPropertyDescriptor(target, prop) {
      return {
        enumerable: true,
        configurable: true,
        value: target[prop],
        writable: true,
      };
    },
  });

  console.log(Object.keys(user));
}
/**
 * has捕捉器
 *
 * in 操作符
 */

{
  let range = {
    start: 1,
    end: 10,
  };
  range = new Proxy(range, {
    has(target, prop) {
      return prop >= target.start && prop <= target.end;
    },
  });

  console.log(5 in range);
  console.log(50 in range);
}

{
  function delay(f, ms) {
    // return function () {
    //   setTimeout(() => f.apply(this, arguments), ms);
    // };
    return new Proxy(f, {
      apply(target, thisArg, args) {
        setTimeout(() => target.apply(thisArg, args), ms);
      },
    });
  }

  function f(a, b) {
    console.log(a + b);
  }

  let f1000 = delay(f, 1000);
  console.log(f1000.length);
  f1000(1, 2);
}
