"use strict";
exports.__esModule = true;
exports.readFile = void 0;
var fs = require('fs'); // library for file system management
// exporting function readFile with parameter pathFile (string) and encoding (string)
function readFile(pathFile, encoding) {
    if (encoding === void 0) { encoding = 'utf-8'; }
    return fs.readFileSync(pathFile, { encoding: encoding, flag: 'r' });
}
exports.readFile = readFile;
