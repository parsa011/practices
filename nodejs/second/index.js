const http = require("http");
const url = require("url");
const slugify = require("slugify");

const server = http.createServer((req, res) => {
    res.end("Working");
});

server.listen(8000);
