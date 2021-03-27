# jgwjs

> Same as jgw. This is a development version for javascript.

## !IMPORTANT
Don't run compileDev.sh or compile Dev.bat. Because the script already has a tool to automatically compile it.
Actually it is okay if you run it, but it would be good so that you don't have to be tired of compiling it, let alone the script

If you want to use it, you can download zip or use git.
if you want to use git this is the code for you to run in your terminal.
```bash
$ git clone https://github.com/jonathanmarp/jgwjs
```

If you don't want too many files you can delete the srcTS folder. the location is in `jgwjs/`.
Do not delete the rest because it will be used when the script runs.

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
