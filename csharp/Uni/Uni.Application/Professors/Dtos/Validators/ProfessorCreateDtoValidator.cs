using FluentValidation;

namespace Uni.Application.Professors.Dtos.Validators;

public class ProfessorCreateDtoValidator : AbstractValidator<ProfessorCreateDto>
{
    public ProfessorCreateDtoValidator()
    {
        RuleFor(a => a.Name)
            .NotEmpty()
            .Length(3, 50)
            .WithMessage("نام را به درستی وارد نمایید");
    }
}