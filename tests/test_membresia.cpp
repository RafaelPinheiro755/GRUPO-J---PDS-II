#include "doctest.h"
#include "Membresia.hpp"
#include "Usuario.hpp"
#include "Grupo.hpp"

#include <memory>

TEST_CASE("Membresia: liga o usuário ao grupo com a data de entrada") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);

    Membresia m(ana, futebol, Membresia::Papel::MEMBRO, "2026-10-01");

    CHECK(m.getUsuario() == ana);
    CHECK(m.getGrupo() == futebol);
    CHECK(m.getDataEntrada() == "2026-10-01");
}

TEST_CASE("Membresia: membro comum não é administrador") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);

    Membresia m(ana, futebol, Membresia::Papel::MEMBRO, "2026-10-01");

    CHECK(m.getPapel() == Membresia::Papel::MEMBRO);
    CHECK_FALSE(m.ehAdministrador());
}

TEST_CASE("Membresia: quem cria o grupo já entra como administrador") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);

    Membresia m(ana, futebol, Membresia::Papel::ADMINISTRADOR, "2026-10-01");

    CHECK(m.getPapel() == Membresia::Papel::ADMINISTRADOR);
    CHECK(m.ehAdministrador());
}

TEST_CASE("Membresia: promover torna o membro administrador") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    Membresia m(ana, futebol, Membresia::Papel::MEMBRO, "2026-10-01");

    m.promoverAAdministrador();

    CHECK(m.getPapel() == Membresia::Papel::ADMINISTRADOR);
    CHECK(m.ehAdministrador());
}

TEST_CASE("Membresia: promover quem já é administrador não muda nada") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    Membresia m(ana, futebol, Membresia::Papel::ADMINISTRADOR, "2026-10-01");

    m.promoverAAdministrador();

    CHECK(m.getPapel() == Membresia::Papel::ADMINISTRADOR);
    CHECK(m.getDataEntrada() == "2026-10-01");
}
