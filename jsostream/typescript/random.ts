/*******************************************************\
 *              COPYRIGHT 2020 - 2025                  *
 *******************************************************
 *   Have privacy police this made by website          *
 *   https://jonathanmarpaung.rf.gd/                   *
 *   this for publish CODE                             *
 *((((((((((((((((((((((((((C))))))))))))))))))))))))))*
\*******************************************************/

declare let exports: any;

exports.randomNumber = () => Math.random();
exports.randomString = function(_0x02 = 0) {
    let str: any = "qwertyuiopasdfghjklzxcvbnm";
    let result = "";
    str = str.split("");
    if (_0x02 == 0) {
        _0x02 = str.length;
    }
    for (let _0x01 = 0; _0x01 < _0x02; _0x01++) {
        result += str[Math.floor(Math.random() * str.length)];
    }
    return result;
}
