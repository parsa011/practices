const fs = require("fs");

const names = JSON.parse(fs.readFileSync("./names.json", "utf-8")).names;
const html = fs.readFileSync("./name.html", "utf-8");

module.exports = (name) => {
	let res = "<html><body>";
    names.forEach((n) => {
    	if (name !== undefined) {
        	if (n === name) {
        		res += html.replace("@Name", n);
        	}
    	} else {
    		res += html.replace("@Name", n);
    	}
	});
	res += "</body></html>";
	return res;
}
