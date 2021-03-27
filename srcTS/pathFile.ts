declare let process: any;
// just exporting variable pathFile
let isWin: boolean = process.platform === "win32";
export let pathFile: string = isWin == true ? "bin/JGW.exe" : "bin/JGW";