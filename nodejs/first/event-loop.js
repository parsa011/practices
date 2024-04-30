// remember this is not standard js function
// this is built-in functoin in nodejs
// that helps us to do modules int js :)) 
const fs = require("fs");


fs.readFile("./server.js", (err, data) => {
	console.log("I/O finished");
	
	setTimeout(() => {
		console.log("timeout 1 ");
	}, 0);

	setTimeout(() => {
		console.log("Timeout 2 is finished");
	}, 2000);

	setImmediate(() => {
		console.log("I think timer is done");
	});

});

console.log("Top Level Code");
