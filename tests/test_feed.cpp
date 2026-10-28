#include "doctest.h"
#include "Feed.hpp"
#include "Usuario.hpp"
#include "Grupo.hpp"
#include "Post.hpp"

#include <memory>

// As datas seguem o formato "AAAA-MM-DD HH:MM", que ordena certo como texto.

TEST_CASE("Feed: usuário sem grupos tem o feed vazio") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");

    Feed feed(ana);

    CHECK(feed.listarPosts().empty());
}

TEST_CASE("Feed: junta os posts dos grupos do usuário, do mais recente para o mais antigo") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    auto leitura = std::make_shared<Grupo>("Leitura", Grupo::Tipo::PRIVADO);
    auto cinema = std::make_shared<Grupo>("Cinema", Grupo::Tipo::PUBLICO);

    auto p1 = std::make_shared<Post>(bruno, futebol, "Jogo sábado?", "2026-10-01 09:00");
    auto p2 = std::make_shared<Post>(bruno, leitura, "Capítulo 3 hoje", "2026-10-03 18:30");
    auto p3 = std::make_shared<Post>(ana, futebol, "Eu vou", "2026-10-02 12:00");
    auto p4 = std::make_shared<Post>(bruno, cinema, "Sessão às 20h", "2026-10-04 20:00");
    futebol->adicionarPost(p1);
    leitura->adicionarPost(p2);
    futebol->adicionarPost(p3);
    cinema->adicionarPost(p4);

    ana->entrarGrupo(futebol);
    ana->entrarGrupo(leitura);
    Feed feed(ana);

    auto posts = feed.listarPosts();

    REQUIRE(posts.size() == 3);
    CHECK(posts[0] == p2);
    CHECK(posts[1] == p3);
    CHECK(posts[2] == p1);
}

TEST_CASE("Feed: cada post indica de qual grupo veio") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    auto leitura = std::make_shared<Grupo>("Leitura", Grupo::Tipo::PRIVADO);
    futebol->adicionarPost(std::make_shared<Post>(ana, futebol, "Jogo sábado?", "2026-10-01 09:00"));
    leitura->adicionarPost(std::make_shared<Post>(ana, leitura, "Capítulo 3 hoje", "2026-10-03 18:30"));
    ana->entrarGrupo(futebol);
    ana->entrarGrupo(leitura);

    auto posts = Feed(ana).listarPosts();

    REQUIRE(posts.size() == 2);
    REQUIRE(posts[0]->getGrupo() != nullptr);
    REQUIRE(posts[1]->getGrupo() != nullptr);
    CHECK(posts[0]->getGrupo()->getNome() == "Leitura");
    CHECK(posts[1]->getGrupo()->getNome() == "Futebol");
}

TEST_CASE("Feed: filtra os posts de um grupo específico") {
    auto ana = std::make_shared<Usuario>("Ana", "ana@email.com");
    auto futebol = std::make_shared<Grupo>("Futebol", Grupo::Tipo::PUBLICO);
    auto leitura = std::make_shared<Grupo>("Leitura", Grupo::Tipo::PRIVADO);
    auto p1 = std::make_shared<Post>(ana, futebol, "Jogo sábado?", "2026-10-01 09:00");
    auto p2 = std::make_shared<Post>(ana, leitura, "Capítulo 3 hoje", "2026-10-03 18:30");
    auto p3 = std::make_shared<Post>(ana, futebol, "Eu vou", "2026-10-02 12:00");
    futebol->adicionarPost(p1);
    leitura->adicionarPost(p2);
    futebol->adicionarPost(p3);
    ana->entrarGrupo(futebol);
    ana->entrarGrupo(leitura);

    auto posts = Feed(ana).listarPostsPorGrupo(futebol);

    REQUIRE(posts.size() == 2);
    CHECK(posts[0] == p3);
    CHECK(posts[1] == p1);
}
