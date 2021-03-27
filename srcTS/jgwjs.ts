declare function require(name:string);
declare let process: any;
const checkFile: any = require("./srcJS/checking.js");
const pathFile: any = require("./srcJS/pathFile.js");
const readFile: any = require("./srcJS/readFile.js");
const startExec: any = require("./srcJS/startExec.js");

// change this is this is development mode
let development: boolean = false;

// check file its exist. If not exist this will be run compile script
function Check_File_Its_Exist(): void {
	let isWin: boolean = process.platform === "win32";
	switch(checkFile.checkFile(pathFile.pathFile)) {
		case false: {
			switch(isWin) {
				case true: {
					startExec.startExec("compileDev.bat");
				}
				break;
				default: {
					startExec.startExec("bash compileDev.sh");
				}
				break;
			}
		}
		break;
	}
}

// exporting function tone
export function tone(Freq: number, Duration: number): void {
	Check_File_Its_Exist();

	development == true ? 
		console.log(startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration).toString())
		: startExec.startExec("./" + pathFile.pathFile + " " + Freq + " " + Duration);
}

// export function toneArray
export function toneArray(note: Array<Array<number>>) {
	Check_File_Its_Exist();

	let cmd: string = "./" + pathFile.pathFile + " ";
	for(let i: number  = 0; i < note.length; i++) {
		cmd += note[i][0] + " " + note[i][1] + " ";
	}

	development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
}

// export function run note file
export function RunNoteFile(pathFiles: string) {
	Check_File_Its_Exist();
	let code: Array<string> = readFile.readFile(pathFiles).split("\n").join("").split(" ").join("").split(",");
	let cmd: string = "./" + pathFile.pathFile + " ";

	for(let i: number = 0; i < code.length; i += 2) {
		cmd += code[i] + " " + code[i + 1] + " ";
	}

	development == true ? console.log(startExec.startExec(cmd).toString()) : startExec.startExec(cmd);
}