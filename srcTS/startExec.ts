declare function require(name:string);
const execSync: any = require('child_process').execSync; // library for run shell in 

// exporting function startExec with parameter cmd (string)
export function startExec(cmd: string) {
	return execSync(cmd);
}