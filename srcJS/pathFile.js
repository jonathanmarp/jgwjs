"use strict";
exports.__esModule = true;
exports.pathFile = void 0;
// just exporting variable pathFile
var isWin = process.platform === "win32";
exports.pathFile = isWin == true ? "bin/JGW.exe" : "bin/JGW";
