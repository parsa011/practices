// promise
//
// is a js object , that can contains async processes , when a process is completed , it will run other process 

fetch("https://jsonplaceholder.typicode./todos/1")
	.then(function (response) {
		return response.json()
	})
	.catch(function (e) {
		console.log(e);
	})
	.then(function (data) {
		console.log(data);
	});
