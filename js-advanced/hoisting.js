// hoisting in javascript
//
// but this will not work with variables 

info();

console.log(price);

let price  = 12;

function info() {
	console.log("book");
}
