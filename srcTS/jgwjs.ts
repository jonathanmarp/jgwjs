declare function require(name:string);
declare let process: any;
const checkFile: any = require("./srcJS/checking.js");
const pathFile: any = require("./srcJS/pathFile.js");
const readFile: any = require("./srcJS/readFile.js");
const startExec: any = require("./srcJS/startExec.js");
const jso: any = require("./jsostream/jsostream");

// change this is this is development mode
let development: boolean = false;

// check file its exist. If not exist this will be run compile script
jso.functions(":Check_File_Its_Exist:", (): void => {
	let isWin: boolean = process.platform === "win32";
	switch(checkFile.checkFile(pathFile.pathFile)) {
		case false: {
			switch(isWin) {
				case true: {
					startExec.startExec(pathFile.pathFile.split("/")[0] + "/" + "compileDev.bat");
				}
				break;
				default: {
					startExec.startExec("bash " + pathFile.pathFile.split("/")[0] + "/" + "compileDev.sh");
				}
				break;
			}
		}
		break;
	}
});

// exporting function tone
jso.functions(":tone:", (Freq: number, Duration: number): void => {
	jso.call(":Check_File_Its_Exist:");

	development == true ? 
		console.log(startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration).toString())
		: startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration);
});

export let tone: Function = jso.importFunctions(":tone:");

// export function toneArray
jso.functions(":toneArray:", (note: Array<Array<number>>): void => {
	jso.call(":Check_File_Its_Exist:");

	let cmd: string = "./" + pathFile.pathFile + " ";
	for(let i: number  = 0; i < note.length; i++) {
		cmd += note[i][0] + " " + note[i][1] + " ";
	}

	development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
});

export let toneArray: Function = jso.importFunctions(":toneArray:");

// export function run note file
jso.functions(":RunNoteFile:", (pathFiles: string): void => {
	jso.call(":Check_File_Its_Exist:");
	let code: Array<string> = readFile.readFile(pathFiles).split("\n").join("").split(" ").join("").split(",");
	let cmd: string = "./" + pathFile.pathFile + " ";

	for(let i: number = 0; i < code.length; i += 2) {
		cmd += code[i] + " " + code[i + 1] + " ";
	}

	development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
});

export let RunNoteFile = jso.importFunctions(":RunNoteFile:");