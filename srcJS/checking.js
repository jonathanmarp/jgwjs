"use strict";
exports.__esModule = true;
exports.checkFile = void 0;
var fs = require("fs"); // Or `import fs from "fs";` with ESM
// export function checkFile parameter string
function checkFile(nameFile) {
    // make if else for fast
    switch (fs.existsSync(nameFile)) {
        // if return of fs is true its returning true
        case true:
            {
                return true;
            }
            break;
        // if not true it's returning false
        default:
            {
                return false;
            }
            break;
    }
}
exports.checkFile = checkFile;
