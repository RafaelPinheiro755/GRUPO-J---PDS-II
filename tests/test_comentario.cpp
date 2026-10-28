#include "doctest.h"
#include "Comentario.hpp"
#include "Usuario.hpp"

#include <memory>
#include <stdexcept>
#include <string>

TEST_CASE("Comentario: guarda autor, texto e data/hora") {
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");

    Comentario c(bruno, "Eu vou", "2026-10-01 09:05");

    CHECK(c.getAutor() == bruno);
    CHECK(c.getTexto() == "Eu vou");
    CHECK(c.getDataHora() == "2026-10-01 09:05");
}

TEST_CASE("Comentario: aceita texto com exatamente 280 caracteres") {
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");
    std::string texto(280, 'a');

    Comentario c(bruno, texto, "2026-10-01 09:05");

    CHECK(c.getTexto().size() == 280);
}

TEST_CASE("Comentario: recusa texto com mais de 280 caracteres") {
    auto bruno = std::make_shared<Usuario>("Bruno", "bruno@email.com");

    CHECK_THROWS_AS(Comentario(bruno, std::string(281, 'a'), "2026-10-01 09:05"),
                    std::invalid_argument);
}
