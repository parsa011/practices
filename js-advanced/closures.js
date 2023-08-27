// closures

function createUser() {
	const user = "parsa";
	return function() {
		console.log(user);
	};
}

const create = createUser();
create();
