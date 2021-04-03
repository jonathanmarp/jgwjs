/*******************************************************\
 *              COPYRIGHT 2020 - 2025                  *
 *******************************************************
 *   Have privacy police this made by website          *
 *   https://jonathanmarpaung.rf.gd/                   *
 *   this for publish CODE                             *
 *((((((((((((((((((((((((((C))))))))))))))))))))))))))*
\*******************************************************/

declare let exports: any;

exports.print = function(x: any, ...y: Array<any>) {
    let Str = "";
    Str += x;
    for (let _0x01 = 0; _0x01 < y.length; _0x01++) {
        Str += y[_0x01];
    }
    console.log(Str);
}
