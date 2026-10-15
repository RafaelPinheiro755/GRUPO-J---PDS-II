#include "doctest.h"
#include "Usuario.hpp"
#include "Grupo.hpp"

#include <memory>
#include <stdexcept>

TEST_CASE("Usuario: guarda nome, e-mail e foto") {
    Usuario ana("Ana", "ana@email.com", "fotos/ana.png");

    CHECK(ana.getNome() == "Ana");
    CHECK(ana.getEmail() == "ana@email.com");
    CHECK(ana.getFoto() == "fotos/ana.png");
}

TEST_CASE("Usuario: a foto de perfil é opcional") {
    Usuario bruno("Bruno", "bruno@email.com");

    CHECK(bruno.getFoto() == "");
}

TEST_CASE("Usuario: nome e e-mail são obrigatórios") {
    CHECK_THROWS_AS(Usuario("", "ana@email.com"), std::invalid_argument);
    CHECK_THROWS_AS(Usuario("Ana", ""), std::invalid_argument);
}

TEST_CASE("Usuario: começa sem grupos e sem convites") {
    Usuario ana("Ana", "ana@email.com");

    CHECK(ana.getGrupos().empty());
    CHECK(ana.getConvitesPendentes().empty());
}

TEST_CASE("Usuario: entra e sai de grupos") {
    Usuario ana("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    auto leitura = std::make_shared<Grupo>("Leitura", Grupo::Tipo::PRIVADO);

    ana.entrarGrupo(futebol);
    ana.entrarGrupo(leitura);
    REQUIRE(ana.getGrupos().size() == 2);
    CHECK(ana.getGrupos()[0] == futebol);
    CHECK(ana.getGrupos()[1] == leitura);

    ana.sairGrupo(futebol);
    REQUIRE(ana.getGrupos().size() == 1);
    CHECK(ana.getGrupos()[0] == leitura);
}

TEST_CASE("Usuario: registra os convites recebidos") {
    Usuario ana("Ana", "ana@email.com");

    ana.receberConvite("Leitura");
    ana.receberConvite("Cinema");

    REQUIRE(ana.getConvitesPendentes().size() == 2);
    CHECK(ana.getConvitesPendentes()[0] == "Leitura");
    CHECK(ana.getConvitesPendentes()[1] == "Cinema");
}
