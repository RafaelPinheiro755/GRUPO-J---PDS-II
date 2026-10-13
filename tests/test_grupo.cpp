#include "doctest.h"
#include "Grupo.hpp"
#include "Usuario.hpp"
#include "Membresia.hpp"
#include "Post.hpp"

#include <memory>
#include <stdexcept>
#include <string>

TEST_CASE("Grupo: guarda nome, descrição e tipo") {
    Grupo leitura("Leitura", Grupo::Tipo::PRIVADO, "Clube do livro");

    CHECK(leitura.getNome() == "Leitura");
    CHECK(leitura.getDescricao() == "Clube do livro");
    CHECK(leitura.getTipo() == Grupo::Tipo::PRIVADO);
}

TEST_CASE("Grupo: a descrição é opcional") {
    Grupo futebol("Futebol", Grupo::Tipo::PUBLICO);

    CHECK(futebol.getDescricao() == "");
    CHECK(futebol.getTipo() == Grupo::Tipo::PUBLICO);
}

TEST_CASE("Grupo: o nome é obrigatório") {
    CHECK_THROWS_AS(Grupo("", Grupo::Tipo::PUBLICO), std::invalid_argument);
}

TEST_CASE("Grupo: começa sem membros e sem posts") {
    Grupo futebol("Futebol", Grupo::Tipo::PUBLICO);

    CHECK(futebol.getMembros().empty());
    CHECK(futebol.getPosts().empty());
}

TEST_CASE("Grupo: adiciona membros") {
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");
    auto mAna = std::make_shared<Membresia>(ana, futebol, Membresia::Papel::ADMINISTRADOR, "2026-10-01");
    auto mBruno = std::make_shared<Membresia>(bruno, futebol, Membresia::Papel::MEMBRO, "2026-10-02");

    futebol->adicionarMembro(mAna);
    futebol->adicionarMembro(mBruno);

    REQUIRE(futebol->getMembros().size() == 2);
    CHECK(futebol->getMembros()[0] == mAna);
    CHECK(futebol->getMembros()[1] == mBruno);
}

TEST_CASE("Grupo: adiciona posts na ordem em que foram publicados") {
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto p1 = std::make_shared<Post>(ana, futebol, "Jogo sábado?", "2026-10-01 09:00");
    auto p2 = std::make_shared<Post>(ana, futebol, "Confirmado às 10h", "2026-10-01 12:00");

    futebol->adicionarPost(p1);
    futebol->adicionarPost(p2);

    REQUIRE(futebol->getPosts().size() == 2);
    CHECK(futebol->getPosts()[0] == p1);
    CHECK(futebol->getPosts()[1] == p2);
}

TEST_CASE("Grupo: o relatório traz o total de posts e o membro mais ativo") {
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");
    futebol->adicionarMembro(std::make_shared<Membresia>(ana, futebol, Membresia::Papel::ADMINISTRADOR, "2026-10-01"));
    futebol->adicionarMembro(std::make_shared<Membresia>(bruno, futebol, Membresia::Papel::MEMBRO, "2026-10-01"));
    futebol->adicionarPost(std::make_shared<Post>(ana, futebol, "Jogo sábado?", "2026-10-01 09:00"));
    futebol->adicionarPost(std::make_shared<Post>(ana, futebol, "Fechado então", "2026-10-01 10:00"));
    futebol->adicionarPost(std::make_shared<Post>(bruno, futebol, "Eu vou", "2026-10-01 11:00"));

    std::string relatorio = futebol->gerarRelatorioAtividade();

    // Ana publicou 2 dos 3 posts; Bruno só 1 (e foi o último a postar).
    CHECK(relatorio.find("3") != std::string::npos);
    CHECK(relatorio.find("Ana") != std::string::npos);
}
