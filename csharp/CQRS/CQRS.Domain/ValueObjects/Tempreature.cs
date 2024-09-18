﻿using CQRS.Domain.Exceptions;

namespace CQRS.Domain.ValueObjects;

public record Tempreature
{
    public double Value { get; }
    public Tempreature(double value)
    {
        if (value is < -100 or > 100)
        {
            throw new InvalidTemperatureException(value);
        }
    }

	public static implicit operator Tempreature(double value) 
        => new(value);

    public static implicit operator double(Tempreature tempreature)
        => tempreature.Value;
}
