namespace ROPValidation;

public class ActionResult
{
    public bool Succeeded { get; set; }
    public string Message { get; set; } = default!;

    public static ActionResult<T> CreateValidator<T>(T param)
        => new(param);

    public static ActionResult<T> Failure<T>(string message)
        => new(message);

    public static ActionResult<T> Success<T>(T data)
        => new(data);
}

public class ActionResult<T> : ActionResult
{
    public T Data { get; set; }
    
    public ActionResult(string message)
    {
        Message = message;
        Succeeded = false;
        Data = default!;
    }

    public ActionResult(T data)
    {
        Data = data;
        Succeeded = true;
    }
}

public static class ActionResultExtension
{ 
    public static ActionResult<T> Validate<T>(
        this ActionResult<T> actionResult,
        Func<T, bool> predict,
        string message
	)
    {
        if (!actionResult.Succeeded)
        {
            return actionResult;
        }

        var predictResult = predict(actionResult.Data);
        if (!predictResult)
        {
            return ActionResult.Failure<T>(message);
        }

        return actionResult;
    }
}
