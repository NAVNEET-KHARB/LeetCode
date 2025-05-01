/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let val = init;
    let ansObj = {
        increment : () => {
            val += 1;
            return val;
        },
        decrement : () => {
            val -= 1;
            return val;
        },
        reset : () => {
            val = init;
            return val;
        }
    }
    return ansObj;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */