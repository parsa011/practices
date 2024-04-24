const http = require("http");
const url = require("url");
const fs = require("fs");
const getNamesHtml = require("./getNamesHtml");

const indexPage = fs.readFileSync(`${__dirname}/index.html`, "utf-8");

const server = http.createServer((req, res) => {
	const path = req.url;

	res.writeHead(200, {
		"Content-type": "text/html"
	});

	const { query, pathname } = url.parse(path, true);
	console.log(pathname);

	if (pathname === "/") {
		res.end(indexPage);
	} else if (pathname === "/names") {
		res.end(getNamesHtml(query.name));
	} else {
		res.end("<h1>Page Not Found</h1>");
	}
});

server.listen(8000, "127.0.0.1", () => {
	console.log("Server Started");
});
