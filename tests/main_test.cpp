/**
 * @file main_test.cpp
 * @brief Ponto de entrada dos testes de unidade (doctest).
 *
 * Este arquivo só gera o main() do doctest. Os testes ficam nos arquivos
 * test_<classe>.cpp desta pasta e entram sozinhos na compilação pelo Makefile.
 */

// O MinGW.org antigo (g++ 6.3 do Windows) não tem std::mutex nem gmtime_s,
// que o doctest usa. Nesse compilador desligamos as duas coisas; nos demais
// (Linux, macOS, MinGW-w64) nada muda.
#if defined(__MINGW32__) && !defined(__MINGW64_VERSION_MAJOR)
#include <ctime>
#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_COLORS_NONE
static inline int gmtime_s(std::tm* resultado, const std::time_t* tempo) {
    std::tm* utc = std::gmtime(tempo);
    if (utc == nullptr) return 1;
    *resultado = *utc;
    return 0;
}
#endif

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
