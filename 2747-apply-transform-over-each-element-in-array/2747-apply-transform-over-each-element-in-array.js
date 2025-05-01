/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    arr.forEach((ele,ind) => {
        arr[ind] = fn(ele,ind);
    })
    return arr;
};