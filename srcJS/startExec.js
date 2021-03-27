"use strict";
exports.__esModule = true;
exports.startExec = void 0;
var execSync = require('child_process').execSync; // library for run shell in 
// exporting function startExec with parameter cmd (string)
function startExec(cmd) {
    return execSync(cmd);
}
exports.startExec = startExec;
