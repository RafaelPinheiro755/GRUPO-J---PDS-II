#include "Post.hpp"

#include <algorithm>  // std::find
#include <stdexcept>

#include "Comentario.hpp"
#include "Grupo.hpp"
#include "Usuario.hpp"
#include "Validacao.hpp"

// Definição da constante estática (necessária em C++11; veja Comentario.cpp).
const std::size_t Post::TAMANHO_MAXIMO_TEXTO;

Post::Post(const std::shared_ptr<Usuario>& autor,
           const std::shared_ptr<Grupo>& grupo,
           const std::string& texto,
           const std::string& dataHora)
    : autor_(autor), grupo_(grupo), texto_(texto), dataHora_(dataHora) {
    if (!autor) {
        throw std::invalid_argument("O post precisa de um autor.");
    }
    if (!grupo) {
        throw std::invalid_argument("O post precisa de um grupo.");
    }
    if (Validacao::textoEmBranco(texto_)) {
        throw std::invalid_argument("O texto do post nao pode ficar vazio.");
    }
    if (texto_.size() > TAMANHO_MAXIMO_TEXTO) {
        throw std::invalid_argument("O post passa do tamanho maximo.");
    }
    // O Feed ordena os posts comparando esta data como texto, então ela
    // precisa estar sempre no formato "AAAA-MM-DD HH:MM".
    if (!Validacao::dataHoraValida(dataHora_)) {
        throw std::invalid_argument("A data/hora do post deve estar no formato AAAA-MM-DD HH:MM.");
    }
}

std::shared_ptr<Usuario> Post::getAutor() const { return autor_; }

// grupo_ é um weak_ptr: lock() devolve um shared_ptr se o grupo ainda existe
// (ou um ponteiro vazio se ele já foi destruído).
std::shared_ptr<Grupo> Post::getGrupo() const { return grupo_.lock(); }

std::string Post::getTexto() const { return texto_; }

std::string Post::getDataHora() const { return dataHora_; }

bool Post::curtir(const std::shared_ptr<Usuario>& usuario) {
    if (!usuario) {
        throw std::invalid_argument("Usuario invalido.");
    }
    if (foiCurtidoPor(usuario)) {
        return false;  // cada usuário só curte uma vez
    }
    curtidas_.push_back(usuario);
    return true;
}

bool Post::foiCurtidoPor(const std::shared_ptr<Usuario>& usuario) const {
    return std::find(curtidas_.begin(), curtidas_.end(), usuario) != curtidas_.end();
}

std::size_t Post::getQuantidadeCurtidas() const { return curtidas_.size(); }

void Post::adicionarComentario(const std::shared_ptr<Comentario>& comentario) {
    if (!comentario) {
        throw std::invalid_argument("Comentario invalido.");
    }
    // Os comentários nascem com data/hora automática, então adicionar na
    // ordem em que chegam já os deixa em ordem cronológica.
    comentarios_.push_back(comentario);
}

std::vector<std::shared_ptr<Comentario>> Post::getComentarios() const { return comentarios_; }
