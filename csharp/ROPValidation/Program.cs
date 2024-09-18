using ROPValidation;

// this project is for testing ROP architecuture
// custom validation for a dummy class

var user = new User()
{
	Name = "parsa",
	LastName = "ma",
	Email = "parsa32569@gmail.com"
};

var validator = ActionResult.CreateValidator<User>(user);

var result = 
		validator
			.Validate(a => a.Name.Length >= 5, "Check user name length")
			.Validate(a => a.LastName.Length >= 5, "Check user Last name length");

if (!result.Succeeded)
{
	Console.WriteLine($"[FAILURE] : {result.Message}");
}
