using FluentValidation;

namespace Uni.Application.Professors.Commands.EditProfessor;

public class EditProfessorCommandValidator : AbstractValidator<EditProfessorCommand>
{
    public EditProfessorCommandValidator()
    {
        RuleFor(a => a.Email)
            .EmailAddress()
            .WithMessage("ایمیل را به درستی وارد نمایید");

        RuleFor(a => a.Name)
            .NotEmpty()
            .WithMessage("نا را وارد نمایید");

        RuleFor(a => a.LastName)
            .NotEmpty()
            .WithMessage("نام خانوادگی را وارد نمایید");
    }
}