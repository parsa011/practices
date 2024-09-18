namespace CAC;

// code belongs to : https://stackoverflow.com/a/53134957/8725592

public interface IInvariant<T>
{
     T Get(); // ok, an invariant type can be both put into and returned
    void Set(T t); // ok, an invariant type can be both put into and returned
}

public interface IContravariant<in T>
{
    //T Get(); // compilation error, cannot return a contravariant type
    void Set(T t); // ok, a contravariant type can only be **put into** our class (hence "in")
}

public interface ICovariant<out T>
{
    T Get(); // ok, a covariant type can only be **returned** from our class (hence "out")
    //void Set(T t); // compilation error, cannot put a covariant type into our class
}