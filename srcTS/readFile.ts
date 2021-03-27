declare function require(name:string);
const fs: any = require('fs'); // library for file system management

// exporting function readFile with parameter pathFile (string) and encoding (string)
export function readFile(pathFile: string, encoding: string = 'utf-8') {
	return fs.readFileSync(pathFile, { encoding: encoding, flag: 'r' });
}