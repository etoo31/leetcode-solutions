/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length < t.length)
    {
        let temp = s;
        s = t;
        t = temp;
    }
    let smap  = {};
    let tmap = {};
    for (let c of s){
        if (!smap[c])smap[c] = 0;
        smap[c]++
    }
    for (let c of t){
        if (!tmap[c])tmap[c] = 0;
        tmap[c]++
    }
    for (let c of s){
        if (smap[c] !== tmap[c])
            return false;
    }
    return true;
            
        
};