// promise
//
// is a js object , that can contains async processes , when a process is completed , it will run other process 

const myPromise = new Promise(function (resolve, reject) {
	// 3 important state for promises
	// pending - resolve - reject
	setTimeout(function () {
		// when we care calling it , we are marking our promises as resolved
		resolve('It Worked.');
	}, 3000);
});


myPromise.then(function (response) {
	console.log(response);
});
