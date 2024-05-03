using FluentValidation;
using Uni.Application.Professors.Commands.CreateProfessor;

namespace Uni.Application.Professors.Dtos.Validators;

public class CreateProfessorCommandValidator : AbstractValidator<CreateProfessorCommand>
{
    public CreateProfessorCommandValidator()
    {
        RuleFor(a => a.Name)
            .NotEmpty()
            .Length(3, 50)
            .WithMessage("نام را به درستی وارد نمایید");
    }
}