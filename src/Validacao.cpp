#include "Validacao.hpp"

#include <cctype>  // std::isdigit

namespace {

// Lê os dois dígitos que começam na posição i (ex.: "09" vira 9).
// Quem chama já conferiu que as duas posições são dígitos.
int doisDigitos(const std::string& texto, std::size_t i) {
    return (texto[i] - '0') * 10 + (texto[i + 1] - '0');
}

}  // namespace

namespace Validacao {

bool textoEmBranco(const std::string& texto) {
    return texto.find_first_not_of(" \t\r\n") == std::string::npos;
}

bool dataHoraValida(const std::string& dataHora) {
    // "AAAA-MM-DD HH:MM" tem sempre 16 caracteres.
    if (dataHora.size() != 16) {
        return false;
    }

    // Separadores nas posições fixas; o resto tem que ser dígito.
    for (std::size_t i = 0; i < dataHora.size(); ++i) {
        char c = dataHora[i];
        if (i == 4 || i == 7) {
            if (c != '-') return false;
        } else if (i == 10) {
            if (c != ' ') return false;
        } else if (i == 13) {
            if (c != ':') return false;
        } else if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }

    int mes = doisDigitos(dataHora, 5);
    int dia = doisDigitos(dataHora, 8);
    int hora = doisDigitos(dataHora, 11);
    int minuto = doisDigitos(dataHora, 14);

    if (mes < 1 || mes > 12) {
        return false;
    }
    // Fevereiro aceita 29 sempre: não conferimos se o ano é bissexto.
    const int diasNoMes[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dia < 1 || dia > diasNoMes[mes - 1]) {
        return false;
    }
    return hora <= 23 && minuto <= 59;
}

bool emailValido(const std::string& email) {
    if (email.find(' ') != std::string::npos) {
        return false;
    }

    // Um '@' só, e com algum texto antes dele.
    std::size_t arroba = email.find('@');
    if (arroba == std::string::npos || arroba == 0 ||
        email.find('@', arroba + 1) != std::string::npos) {
        return false;
    }

    // O domínio precisa de um ponto, que não pode vir colado no '@' nem no fim.
    std::size_t ponto = email.find('.', arroba + 1);
    return ponto != std::string::npos && ponto > arroba + 1 && ponto + 1 < email.size();
}

}  // namespace Validacao
