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

// Make All Library
const jsostream = require("./lib/jsostream.js");
const print = require("./lib/print.js");
const file = require("./lib/file.js");
const fstream = require("./lib/fstream.js");
const functions = require("./lib/functions.js");
const random = require("./lib/random.js");
const sort = require("./lib/sort.js");
const toAny = require("./lib/toAny.js");
const variable = require("./lib/variable.js");
const enums = require("./lib/enum.js");
const runSafe = require("./lib/runSafe.js");

// Teleport Function From Library
exports.jsostream = jsostream.jsostream;
exports.print = print.print;
exports.readFile = file.readFile;
exports.appendFile = file.appendFile;
exports.openFile = file.openFile;
exports.writeFile = file.writeFile;
exports.fstream = fstream.fstream;
exports.functions = functions.functions;
exports.call = functions.call;
exports.importFunctions = functions.importFunctions;
exports.deleteFunctions = functions.deleteFunctions;
exports.randomNumber = random.randomNumber;
exports.randomString = random.randomString;
exports.sort = sort.sort;
exports.toChar = toAny.toChar;
exports.toArrText = toAny.toArrText;
exports.int = toAny.int;
exports.float = toAny.float;
exports.var = variable.var;
exports.vEquation = variable.vEquation;
exports.vGet = variable.vGet;
exports.vDelete = variable.vDelete;
exports.enum = enums.enum;
exports.runSafe = runSafe.runSafe;
