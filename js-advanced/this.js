// 'this' keyword
//
// context in js , will be controlled by js engine (can be browser or node)
// environment in js , are datas or variables that can be related to a specific contex 
//
// this always points to an object

//console.log(this);
//
//function info() {
//	console.log(this);
//}

this.title = "book";

const _this = this;

function info() {
	console.log('Title : ' + _this.title);
}

info();

const product = {
	productInfo : info
}

product.productInfo();
