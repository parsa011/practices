using CAC;

#pragma warning disable  CS8600 // Converting null literal or possible null value to non-nullable type.
#pragma warning disable CS0219 // Variable is assigned but its value is never used

#region Invariant
IInvariant<Animal> invariantAnimal1 = (IInvariant<Animal>)null; // ok
// IInvariant<Animal> invariantAnimal2 = (IInvariant<Mammal>)null; // compilation error
// IInvariant<Animal> invariantAnimal3 = (IInvariant<Dog>)null; // compilation error

// IInvariant<Mammal> invariantMammal1 = (IInvariant<Animal>)null; // compilation error
IInvariant<Mammal> invariantMammal2 = (IInvariant<Mammal>)null; // ok
// IInvariant<Mammal> invariantMammal3 = (IInvariant<Dog>)null; // compilation error

//IInvariant<Dog> invariantDog1 = (IInvariant<Animal>)null; // compilation error
//IInvariant<Dog> invariantDog2 = (IInvariant<Mammal>)null; // compilation error
IInvariant<Dog> invariantDog3 = (IInvariant<Dog>)null; // ok
#endregion

#region Covariant
ICovariant<Animal> covariantAnimal1 = (ICovariant<Animal>)null; // ok
ICovariant<Animal> covariantAnimal2 = (ICovariant<Mammal>)null; // ok!!!
ICovariant<Animal> covariantAnimal3 = (ICovariant<Dog>)null; // ok!!!

// ICovariant<Mammal> covariantMammal1 = (ICovariant<Animal>)null; // compilation error
ICovariant<Mammal> covariantMammal2 = (ICovariant<Mammal>)null; // ok
ICovariant<Mammal> covariantMammal3 = (ICovariant<Dog>)null; // ok!!!

// ICovariant<Dog> covariantDog1 = (ICovariant<Animal>)null; // compilation error
// ICovariant<Dog> covariantDog2 = (ICovariant<Mammal>)null; // compilation error
ICovariant<Dog> covariantDog3 = (ICovariant<Dog>)null; // ok
#endregion

#region Contravariance
IContravariant<Animal> contravariantAnimal1 = (IContravariant<Animal>)null; // ok
// IContravariant<Animal> contravariantAnimal2 = (IContravariant<Mammal>)null; // compilation error
// IContravariant<Animal> contravariantAnimal3 = (IContravariant<Dog>)null; // compilation error

IContravariant<Mammal> contravariantMammal1 = (IContravariant<Animal>)null; // ok!!!
IContravariant<Mammal> contravariantMammal2 = (IContravariant<Mammal>)null; // ok
// IContravariant<Mammal> contravariantMammal3 = (IContravariant<Dog>)null; // compilation error

IContravariant<Dog> contravariantDog1 = (IContravariant<Animal>)null; // ok!!!
IContravariant<Dog> contravariantDog2 = (IContravariant<Mammal>)null; // ok!!!
IContravariant<Dog> contravariantDog3 = (IContravariant<Dog>)null; // ok
#endregion