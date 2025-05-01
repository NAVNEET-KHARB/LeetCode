/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    let obj = {
        toBe : function(val1) {
            if (val === val1) return true;
            throw new Error("Not Equal");
        },
        notToBe : function(val1) {
            if (val !== val1) return true;
            throw new Error("Equal");
        }
    }
    return obj;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */