const fs = require("fs");

// this is synchronous operations

const text = fs.readFileSync("./test.txt", 'utf-8');

const textOut = "my name is parsa";

fs.writeFileSync("./another.txt", textOut, "utf-8");


