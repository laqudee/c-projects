{
  let user = {
    name: "John",
  };

  function wrap(target) {
    return new Proxy(target, {
      get(target, prop, receiver) {
        if (!Reflect.has(target, prop, receiver)) {
          throw new Error("No such property: " + prop);
        } else {
          return Reflect.get(target, prop, receiver);
        }
      },
    });
  }

  user = wrap(user);
  console.log(user.name);
  //   console.log(user.age);
}

{
  let array = [1, 2, 3];
  array = new Proxy(array, {
    get(target, index, receiver) {
      if (index < 0) {
        // index是个字符串，要转一下
        index = +index + target.length;
        return Reflect.get(target, index, receiver);
      } else {
        return Reflect.get(target, index, receiver);
      }
    },
  });

  console.log(array[-1]); // 3
  console.log(array[-2]); // 2
  console.log(array[0]); // 1
}

{
  // 可观察的Observable
  // 通过函数返回一个代理，使得对象可观察
  let handlers = Symbol("handlers");
  function makeObservable(target) {
    // 1. init handler 存储
    target[handlers] = [];

    target.observe = function (handler) {
      this[handlers].push(handler);
    };

    // 2. 创建一个proxy
    return new Proxy(target, {
      set(target, prop, value, receiver) {
        let success = Reflect.set(...arguments); // 将操作转发给对象
        if (success) {
          target[handlers].forEach((handler) => {
            handler(prop, value);
          });
        }
        return success;
      },
    });
  }

  let user = {};
  user = makeObservable(user);

  user.observe((key, value) => {
    console.log(`SET ${key} = ${value}`);
  });
  user.name = "John";
}

{
  // Proxy代理Map，并对其进行二次扩展
  let map = new Map();

  let proxy = new Proxy(map, {
    get(target, prop, receiver) {
      let value = Reflect.get(...arguments);
      if (typeof value == "function" && value.name == "get") {
        // 二次代理，修改Map.get的行为
        return new Proxy(value, {
          apply(func, thisArg, argArray) {
            // 如果特定键（abc）不存在，返回特定值（123）
            if (argArray.length == 1 && argArray[0] == "abc") {
              if (!target.has("abc")) return 123;
            }
            // 其他情况，原封不动返回即可
            // 注意使用原始对象target作为thisArg，否则仍然会出现插槽丢失问题
            return Reflect.apply(func, target, argArray);
          },
        });
      }
      // 其他函数也可以进行类似的操作
      return typeof value == "function" ? value.bind(target) : value;
    },
  });

  proxy.set("test", 1);
  console.log(proxy.get("test"));
  console.log(proxy.get("abc"));
  proxy.set("abc", 456); // 现在有abc这个键了
  console.log(proxy.get("abc")); // 456，预设的123不再生效了
}
