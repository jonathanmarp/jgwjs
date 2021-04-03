/*******************************************************\
 *              COPYRIGHT 2020 - 2025                  *
 *******************************************************
 *   Have privacy police this made by website          *
 *   https://jonathanmarpaung.rf.gd/                   *
 *   this for publish CODE                             *
 *((((((((((((((((((((((((((C))))))))))))))))))))))))))*
\*******************************************************/

declare let exports: any;

exports.sort = function(_0x01: Array<number>) {
    let _0x02 = _0x01.length;
    for (let _0x03 = 0; _0x03 < _0x02; _0x03++) {
        for (let _0x04 = 0; _0x04 < _0x02; _0x04++) {
            if (_0x01[_0x04] > _0x01[_0x04 + 0x01]) {
                let _0x05 = _0x01[_0x04];
                _0x01[_0x04] = _0x01[_0x04 + 0x01];
                _0x01[_0x04 + 0x01] = _0x05;
            }
        }
    }
    return _0x01;
}
