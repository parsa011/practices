// callback
// this is a feature of js, that can be used for async functions

function info(title, price, cb) {
	const result = title + ' ' + price;

	cb(result);
}


info('book', 123, function (p) {
	console.log(p);
});
