#include "Comentario.hpp"

#include <stdexcept>

// Em C++11, uma constante estática declarada dentro da classe precisa também
// de uma definição fora dela (sem o valor, que já está no .hpp). Sem isso,
// usar a constante de certas formas dá erro de "undefined reference".
const std::size_t Comentario::TAMANHO_MAXIMO_TEXTO;

Comentario::Comentario(const std::shared_ptr<Usuario>& autor,
                       const std::string& texto,
                       const std::string& dataHora)
    : autor_(autor), texto_(texto), dataHora_(dataHora) {
    if (!autor_) {
        throw std::invalid_argument("O comentario precisa de um autor.");
    }
    // Atenção: size() conta bytes, não letras. Com acentos em UTF-8 (ã, é...),
    // cada letra pode ocupar 2 bytes. Para o checkpoint, isso é suficiente.
    if (texto_.size() > TAMANHO_MAXIMO_TEXTO) {
        throw std::invalid_argument("O comentario passa do tamanho maximo.");
    }
}

std::shared_ptr<Usuario> Comentario::getAutor() const { return autor_; }

std::string Comentario::getTexto() const { return texto_; }

std::string Comentario::getDataHora() const { return dataHora_; }
