using AutoMapper;
using Uni.Application.Professors.Commands.CreateProfessor;
using Uni.Application.Professors.Commands.EditProfessor;
using Uni.Domain.Entities;

namespace Uni.Application.Professors.Dtos;

public class ProfessorsProfile : Profile
{
    public ProfessorsProfile()
    {
        CreateMap<Professor, ProfessorDto>()
            .ForMember(a => a.City, opt => opt.MapFrom(b => b.Address.City))
            .ForMember(a => a.Street, opt => opt.MapFrom(b => b.Address.Street));

        CreateMap<CreateProfessorCommand, Professor>()
            .ForMember(a => a.Address, opt => opt.MapFrom(
                src => new Address() {
                    City = src.City,
                    Street = src.Street
                }
            )).ReverseMap();

        CreateMap<EditProfessorCommand, Professor>()
            .ForMember(a => a.Address, opt => opt.MapFrom(
                src => new Address() {
                    City = src.City,
                    Street = src.Street
                }
            )).ReverseMap();
    }
}