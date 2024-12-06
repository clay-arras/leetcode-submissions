// https://leetcode.com/problems/memoize

/**
 * @param {Function} fn
 */
function memoize(fn) {
    
    let myArr = [...Array(11)];
    let myGrid = [...Array(11)].map(e => Array(11));
    return function(...args) {
        if (args.length == 1) {
            if (typeof myArr[args[0]] === 'undefined') {
                myArr[args[0]] = fn(...args);
            } 
            return myArr[args[0]];
        } else if (args.length == 2) {
            if (typeof myGrid[args[0]][args[1]] === 'undefined') {
                myGrid[args[0]][args[1]] = fn(...args);
            } 
            return myGrid[args[0]][args[1]];
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */