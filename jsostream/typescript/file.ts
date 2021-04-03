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

exports.readFile = function(nameFile: string, callback: any) {
    fs.readFile(nameFile, function(err: any, data: any) {
        callback(data, err);
    });
}

exports.appendFile = function(nameFile: string, contentFile: any, callback: any) {
    fs.appendFile(nameFile, contentFile, callback);
}

exports.openFile = function(nameFile: string, param: any, callback: any) {
    fs.open(nameFile, param, callback);
}

exports.writeFile = function(nameFile: string, contentFile: any, callback: any) {
    fs.writeFile(nameFile, contentFile, callback);
}
