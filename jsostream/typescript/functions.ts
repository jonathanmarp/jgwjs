/*******************************************************\
 *              COPYRIGHT 2020 - 2025                  *
 *******************************************************
 *   Have privacy police this made by website          *
 *   https://jonathanmarpaung.rf.gd/                   *
 *   this for publish CODE                             *
 *((((((((((((((((((((((((((C))))))))))))))))))))))))))*
\*******************************************************/

declare function require(name: string);
declare let exports: any;

let nameFunctions: Array<any> = [];
let allFunctions: Array<any> = [];

exports.functions = function(nameFuntion: any, callback: any) {
    nameFunctions.push(nameFuntion);
    allFunctions.push(callback);
}

exports.call = function(nameFuntion: any, ...param: Array<any>) {
    for (let _0x01 = 0; _0x01 < nameFunctions.length; _0x01++) {
        if (nameFunctions[_0x01] == nameFuntion) {
            return allFunctions[_0x01](param);
        }
    }
    throw new Error('Error Not Get Functions');
    return 0;
}

exports.importFunctions = function(nameFunction: any) {
    for (let _0x01 = 0; _0x01 < nameFunctions.length; _0x01++) {
        if (nameFunctions[_0x01] == nameFunction) {
            return allFunctions[_0x01];
        }
    }
    throw new Error('Error Not Get Functions');
    return 0;
}

exports.deleteFunctions = function(nameFill: any) {
    let target;
    for (let _0x01 = 0; _0x01 < nameFunctions.length; _0x01++) {
        if (nameFunctions[_0x01] == nameFill) {
            if (_0x01 == 0) {
                nameFunctions.shift();
                allFunctions.shift();
                return 0;
            } else {
                target = _0x01;
            }
            break;
        }
    }
    nameFunctions.splice(target, target);
    allFunctions.splice(target, target);
}
