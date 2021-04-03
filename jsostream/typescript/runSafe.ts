/*******************************************************\
 *              COPYRIGHT 2020 - 2025                  *
 *******************************************************
 *   Have privacy police this made by website          *
 *   https://jonathanmarpaung.rf.gd/                   *
 *   this for publish CODE                             *
 *((((((((((((((((((((((((((C))))))))))))))))))))))))))*
\*******************************************************/

declare let exports: any;

exports.runSafe = function(functionsis: any) {
    try {
        functionsis();
    } catch(err) {
        return err;
    }
}
