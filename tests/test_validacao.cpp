#include "doctest.h"
#include "Validacao.hpp"

TEST_CASE("Validacao: texto vazio ou só com espaços está em branco") {
    CHECK(Validacao::textoEmBranco(""));
    CHECK(Validacao::textoEmBranco("   "));
    CHECK(Validacao::textoEmBranco(" \t\n"));
    CHECK_FALSE(Validacao::textoEmBranco("Eu vou"));
    CHECK_FALSE(Validacao::textoEmBranco("  a  "));
}

TEST_CASE("Validacao: aceita data/hora no formato AAAA-MM-DD HH:MM") {
    CHECK(Validacao::dataHoraValida("2026-10-01 09:00"));
    CHECK(Validacao::dataHoraValida("2026-12-31 23:59"));
    CHECK(Validacao::dataHoraValida("2026-02-29 00:00"));
}

TEST_CASE("Validacao: recusa data/hora fora do formato") {
    CHECK_FALSE(Validacao::dataHoraValida(""));
    CHECK_FALSE(Validacao::dataHoraValida("qualquer coisa"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-10-01"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-10-01 9:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026/10/01 09:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-10-01T09:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-1a-01 09:00"));
}

TEST_CASE("Validacao: recusa data/hora com valores impossíveis") {
    CHECK_FALSE(Validacao::dataHoraValida("2026-00-10 09:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-13-10 09:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-10-00 09:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-04-31 09:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-02-30 09:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-10-01 24:00"));
    CHECK_FALSE(Validacao::dataHoraValida("2026-10-01 09:60"));
}

TEST_CASE("Validacao: aceita e-mail no formato nome@dominio.algo") {
    CHECK(Validacao::emailValido("ana@email.com"));
    CHECK(Validacao::emailValido("ana.silva@ufmg.br"));
    CHECK(Validacao::emailValido("bruno@dcc.ufmg.br"));
}

TEST_CASE("Validacao: recusa e-mail fora do formato") {
    CHECK_FALSE(Validacao::emailValido(""));
    CHECK_FALSE(Validacao::emailValido("nao-e-email"));
    CHECK_FALSE(Validacao::emailValido("@email.com"));
    CHECK_FALSE(Validacao::emailValido("ana@"));
    CHECK_FALSE(Validacao::emailValido("ana@email"));
    CHECK_FALSE(Validacao::emailValido("ana@.com"));
    CHECK_FALSE(Validacao::emailValido("ana@email."));
    CHECK_FALSE(Validacao::emailValido("ana@@email.com"));
    CHECK_FALSE(Validacao::emailValido("ana @email.com"));
}
