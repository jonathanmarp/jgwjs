declare function require(name:string);
const fs: any = require("fs"); // Or `import fs from "fs";` with ESM

// export function checkFile parameter string
export function checkFile(nameFile: string)
{
	// make if else for fast
	switch(fs.existsSync(nameFile))
	{
		// if return of fs is true its returning true
		case true: {
			return true;
		}
		break;
		// if not true it's returning false
		default: {
			return false;
		}
		break;
	}
}