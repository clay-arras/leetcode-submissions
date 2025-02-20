// https://leetcode.com/problems/allow-one-function-call

/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    return function(...args){
        let val = fn(...args);
        fn = (args) => undefined;
        return val;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
