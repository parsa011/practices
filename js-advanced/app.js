// 'bind'

class Product {
	constructor () {
		this.title = "book";
	}

	info () {
		console.log("Title 1 : " + this.title);
	}

	delayMethod() {
		setTimeout(function () {
			console.log("Title 2 : " + this.title);
		}.bind(this), 3000);
	}

}
const product = new Product();
product.info();
product.delayMethod();
