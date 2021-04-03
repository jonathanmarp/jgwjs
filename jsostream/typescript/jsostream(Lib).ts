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

const process = require('process');

exports.jsostream = function(callback: any) {
    try {
        callback(process.argv.length, process.argv);
    } catch (err) {
        console.log(err);
    }
}
