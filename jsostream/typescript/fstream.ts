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

const fs = require('fs');

class Fstream {
    constructor(_0x01: any) {
        this.nameFile = _0x01;
    }
    writeFile(contentFile: any, callback: any) {
        fs.writeFile(this.nameFile, contentFile, callback);
    }
    openFile(param: any, callback: any) {
        fs.open(this.nameFile, param, callback);
    }
    appendFile(contentFile: any, callback: any) {
        fs.appendFile(this.nameFile, contentFile, callback);
    }
}

exports.fstream = (nameFile) => new Fstream(nameFile);
