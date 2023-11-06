{
  let user = {
    _name: "Guest",
    get name() {  // 指定的getter ，则被调用时receiver则为被调用时的this值
      return this._name;
    },
  };

  let userProxy = new Proxy(user, {
    get(target, prop, receiver) {
      console.log(receiver); // 这里会调栈溢出
      //   return target[prop]; // 读取admin.name时，由于admin对象自身没有name属性，搜索将转到其原型，原型是userProxy。target[prop]指向user，所以this指向出了问题
      return Reflect.get(target, prop, receiver);
    },
  });

  let admin = {
    __proto__: userProxy,
    _name: "Admin",
  };

  console.log(admin.name);
}

/**
 * receiver，保证将正确的this传递给getter
 * Reflect调用的名称与捕捉器的命名完全相同
 */

/**
 * Proxy的局限性：
 *  - 内建对象：内部插槽internal slot， Map/ Set/ Date/ Promise
 *  - 类似于属性，仅限内部使用，仅用于规范目的
 *  - 例如 Map的数据，存放在MapData内部插槽中
 *  - 不能通过GET、SET内建方法访问，Proxy无法拦截
 */
{
  let map = new Map();
  let proxy = new Proxy(map, {
    get(target, prop, receiver) {
      let value = Reflect.get(...arguments);
      console.log("get-value: ", value);
      return typeof value === "function" ? value.bind(target) : value;
    },
  });

  proxy.set("test", 1);
  console.log(proxy.get("test"));
}

/**
 * 内建 Array没有使用内部插槽
 */

/**
 * 私有字段
 * #name属性
 * 通过内部插槽实现，JS在访问它们时，不使用[[Get]]/[[Set]]
 *
 * proxy,通过bind方法解决
 */
{
  class User {
    #name = "Libai";

    getName() {
      return this.#name;
    }
  }

  let user = new User();
  user = new Proxy(user, {
    get(target, prop, receiver) {
      let value = Reflect.get(...arguments);
      return typeof value == "function" ? value.bind(target) : value;
    },
  });

  console.log(user.getName());
}

/**
 * proxy != target
 *
 * Proxy无法拦截严格相等性检查
 */

/**
 * 可撤销Proxy，一个可撤销的代理是可以被禁用的代理
 *
 * 对revoke()的调用会从代理中删除对目标对象的所有内部引用
 */
{
  let object = {
    data: "Valuable data",
  };
  let { proxy, revoke } = Proxy.revocable(object, {});

  console.log(proxy.data);
  // 禁用
  revoke();
  // 代理失效
  console.log(proxy.data);
}

{
  let revokes = new WeakMap();

  let object = {
    data: "Valuable data",
  };
  let { proxy, revoke } = Proxy.revocable(object, {});

  revokes.set(proxy, revoke);

  console.log(proxy.data);

  revoke = revokes.get(proxy);
  revoke();

  console.log(proxy.data);
}
