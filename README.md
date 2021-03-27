# jgwjs

> Same as jgw. This is a development version for javascript.

## !IMPORTANT
Don't Forget To Install Dependencis If You User Linux.
`$ apt install libsdl2-dev`

Don't run compileDev.sh or compile Dev.bat. Because the script already has a tool to automatically compile it.
Actually it is okay if you run it, but it would be good so that you don't have to be tired of compiling it, let alone the script

If you want to use it, you can download zip or use git.
if you want to use git this is the code for you to run in your terminal.
```bash
$ git clone https://github.com/jonathanmarp/jgwjs
```

If you don't want too many files you can delete the srcTS folder. the location is in `jgwjs/`.
Do not delete the rest because it will be used when the script runs.

do not change the name of the folder jgwjs.

## !MODE DEVELOPMENT

If you want to switch to development mode. The goal is if you play a voice pestle you can know where it went wrong.
This mode is on `jgwjs/jgwjs.js`

```javascript
"use strict";
exports.__esModule = true;
exports.RunNoteFile = exports.toneArray = exports.tone = void 0;
var checkFile = require("./srcJS/checking.js");
var pathFile = require("./srcJS/pathFile.js");
var readFile = require("./srcJS/readFile.js");
var startExec = require("./srcJS/startExec.js");
var jso = require("./jsostream/jsostream");
// change this is this is development mode
var development = false;
// check file its exist. If not exist this will be run compile script
jso.functions(":Check_File_Its_Exist:", function () {
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
});
// exporting function tone
jso.functions(":tone:", function (Freq, Duration) {
    jso.call(":Check_File_Its_Exist:");
    development == true ?
        console.log(startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration).toString())
        : startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration);
});
exports.tone = jso.importFunctions(":tone:");
// export function toneArray
jso.functions(":toneArray:", function (note) {
    jso.call(":Check_File_Its_Exist:");
    var cmd = "./" + pathFile.pathFile + " ";
    for (var i = 0; i < note.length; i++) {
        cmd += note[i][0] + " " + note[i][1] + " ";
    }
    development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
});
exports.toneArray = jso.importFunctions(":toneArray:");
// export function run note file
jso.functions(":RunNoteFile:", function (pathFiles) {
    jso.call(":Check_File_Its_Exist:");
    var code = readFile.readFile(pathFiles).split("\n").join("").split(" ").join("").split(",");
    var cmd = "./" + pathFile.pathFile + " ";
    for (var i = 0; i < code.length; i += 2) {
        cmd += code[i] + " " + code[i + 1] + " ";
    }
    development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
});
exports.RunNoteFile = jso.importFunctions(":RunNoteFile:");
```
Change The Variable Below To Be True:
```javascript
var development = false;
```

Into:
```javascript
var development = true;
```

## !USING

There are only three syntax functions here, namely:
- tone(Freq: double, Duration: float)
- toneArray(tone: Array<Array<number>>)
- RunNoteFile(pathFiles: string)

how to use it, namely. like the script below.
```javascript
const jgw = require("./jgwjs/jgwjs"); // where the jgwjs.js

// step 1
jgw.tone(440, 110); // for example frequency is 440 and duration 100 (cs (cent seconds)).

// step 2
jgw.toneArray([
  [440, 100], [550, 50]
]); // for example array 1 is frequency 440 and duration 100 (cs (cent seconds)). and array 2 is frequency 550 and duration 50 (cs (cent seconds))

// step 3
jgw.RunNoteFile("codeMusic"); // this parameter path or name of file
```

codeMusic:
```bash
440, 100,
550, 100,
440, 50
```

in this code for music run its not have parameter. first word is frequency and seconds word is duration.
