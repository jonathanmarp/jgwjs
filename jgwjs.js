"use strict";
exports.__esModule = true;
exports.RunNoteFile = exports.toneArray = exports.tone = void 0;
var checkFile = require("./srcJS/checking.js");
var pathFile = require("./srcJS/pathFile.js");
var readFile = require("./srcJS/readFile.js");
var startExec = require("./srcJS/startExec.js");
// change this is this is development mode
var development = false;
// check file its exist. If not exist this will be run compile script
function Check_File_Its_Exist() {
    var isWin = process.platform === "win32";
    switch (checkFile.checkFile(pathFile.pathFile)) {
        case false:
            {
                switch (isWin) {
                    case true:
                        {
                            startExec.startExec(pathFile.pathFile.split("/")[0] + "/" + "compileDev.bat");
                        }
                        break;
                    default:
                        {
                            startExec.startExec("bash " + pathFile.pathFile.split("/")[0] + "/" + "compileDev.sh");
                        }
                        break;
                }
            }
            break;
    }
}
// exporting function tone
function tone(Freq, Duration) {
    Check_File_Its_Exist();
    development == true ? 
        console.log(startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration).toString())
        : startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration);
}
exports.tone = tone;
// export function toneArray
function toneArray(note) {
    Check_File_Its_Exist();
    var cmd = "./" + pathFile.pathFile + " ";
    for (var i = 0; i < note.length; i++) {
        cmd += note[i][0] + " " + note[i][1] + " ";
    }
    development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
}
exports.toneArray = toneArray;
// export function run note file
function RunNoteFile(pathFiles) {
    Check_File_Its_Exist();
    var code = readFile.readFile(pathFiles).split("\n").join("").split(" ").join("").split(",");
    var cmd = "./" + pathFile.pathFile + " ";
    for (var i = 0; i < code.length; i += 2) {
        cmd += code[i] + " " + code[i + 1] + " ";
    }
    development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
}
exports.RunNoteFile = RunNoteFile;
