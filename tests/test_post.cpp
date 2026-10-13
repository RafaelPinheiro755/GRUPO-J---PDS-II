#include "doctest.h"
#include "Post.hpp"
#include "Usuario.hpp"
#include "Grupo.hpp"
#include "Comentario.hpp"

#include <memory>
#include <stdexcept>
#include <string>

TEST_CASE("Post: guarda autor, grupo, texto e data/hora") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);

    Post post(ana, futebol, "Jogo sábado?", "2026-10-01 09:00");

    CHECK(post.getAutor() == ana);
    CHECK(post.getGrupo() == futebol);
    CHECK(post.getTexto() == "Jogo sábado?");
    CHECK(post.getDataHora() == "2026-10-01 09:00");
}

TEST_CASE("Post: o texto tem no máximo 280 caracteres") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);

    CHECK_NOTHROW(Post(ana, futebol, std::string(280, 'a'), "2026-10-01 09:00"));
    CHECK_THROWS_AS(Post(ana, futebol, std::string(281, 'a'), "2026-10-01 09:00"),
                    std::invalid_argument);
}

TEST_CASE("Post: começa sem curtidas e sem comentários") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);

    Post post(ana, futebol, "Jogo sábado?", "2026-10-01 09:00");

    CHECK(post.getQuantidadeCurtidas() == 0);
    CHECK(post.getComentarios().empty());
}

TEST_CASE("Post: cada usuário só curte o mesmo post uma vez") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");
    auto carla = std::make_shared<Usuario>("Carla", "carla@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    Post post(ana, futebol, "Jogo sábado?", "2026-10-01 09:00");

    CHECK(post.curtir(bruno));
    CHECK(post.getQuantidadeCurtidas() == 1);
    CHECK(post.foiCurtidoPor(bruno));

    CHECK_FALSE(post.curtir(bruno));
    CHECK(post.getQuantidadeCurtidas() == 1);

    CHECK(post.curtir(ana));
    CHECK(post.getQuantidadeCurtidas() == 2);
    CHECK_FALSE(post.foiCurtidoPor(carla));
}

TEST_CASE("Post: os comentários ficam em ordem cronológica") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    Post post(ana, futebol, "Jogo sábado?", "2026-10-01 09:00");
    auto c1 = std::make_shared<Comentario>(bruno, "Eu vou", "2026-10-01 09:05");
    auto c2 = std::make_shared<Comentario>(ana, "Fechado", "2026-10-01 09:10");

    post.adicionarComentario(c1);
    post.adicionarComentario(c2);

    REQUIRE(post.getComentarios().size() == 2);
    CHECK(post.getComentarios()[0] == c1);
    CHECK(post.getComentarios()[1] == c2);
}
