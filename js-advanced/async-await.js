// async / await 
//
// These are just a simple syntax to work with promises, these are not a new way , just a simple syntax

async function sendRequest() {
	try {
		const response = await fetch("https://jsonplaceholder.typicode.com/todos/1");
		const data = await response.json();
		console.log(data);
	} catch (err) {
		console.log(err);
	}
}

sendRequest();
