declare let process: any;
// just exporting variable pathFile
let isWin: boolean = process.platform === "win32";
export let pathFile: string = isWin == true ? "jgwjs/bin/JGW.exe" : "jgwsjs/bin/JGW";
