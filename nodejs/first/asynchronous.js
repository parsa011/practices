const fs = require("fs");

// this is asyhchronous way
// this is means it wont block I/O
// will call the call back (arrow function) after reading file

fs.readFile("./another.txt", "utf-8", (err, data) => {
	if (err) {
		throw err;  
	}
	console.log(data);
});

console.log("this will be showed before reading fully");
