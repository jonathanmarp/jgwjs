/*******************************************************\
 *              COPYRIGHT 2020 - 2025                  *
 *******************************************************
 *   Have privacy police this made by website          *
 *   https://jonathanmarpaung.rf.gd/                   *
 *   this for publish CODE                             *
 *((((((((((((((((((((((((((C))))))))))))))))))))))))))*
\*******************************************************/

declare let exports:any;

class enums {
    constructor(x) {
        this._0x01 = [];
        this._0x02 = [0];
        for (let _0x02 = 0; _0x02 < x.length; _0x02++) {
            this._0x01.push(x[_0x02]);
            this._0x02.push(_0x02 + 1);
        }
    }
    changeFirstNumber(_0x01: any) {
        for (let _0x03 = 0; _0x03 < this._0x01.length; _0x03++) {
            this._0x02[_0x03] = _0x03 + _0x01;
        }
    }
    getEnum(_0x01: any) {
        for (let _0x02 = 0; _0x02 < this._0x01.length; _0x02++) {
            if (this._0x01[_0x02] == _0x01) {
                return this._0x02[_0x02];
            }
        }
        return null;
    }
}

exports.enum = function(x) {
    return new enums(x);
}
