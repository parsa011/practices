function matchOne(pattern, text)
{
    if (!text)
        return false;
    if (!pattern || pattern === ".")
        return true;
    return pattern === text;
}

// for example : pattern = "a.c" , text = "abc"
// it will work line :
//      matchOne('a', 'a') && matchOne('.', 'b') && matchOne('c', 'c') && match("", "")
// they are true && true && true && true , so result is true 
function match(pattern, text)
{
    if (pattern === "")
        return true;
    if (pattern === "$" && text === "") 
        return true;
    else {
        return matchOne(pattern[0], text[0]) && match(pattern.slice(1), text.slice(1));
    }
}