// This is global scope variable
var productTitle = "product name";

// global scope function
function info() {
	// yes, we have local scope for functions too
	function writeTitle() {
		console.log(productTitle);
	}

	// local scope variable , means we have access to this variable just in this function
	var price = 12;

	console.log(price);
}

info();

console.log(product);
