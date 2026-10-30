#include "Usuario.hpp"

#include <algorithm>  // std::find, std::remove
#include <stdexcept>  // std::invalid_argument

#include "Validacao.hpp"

// Aqui não precisamos de #include "Grupo.hpp": só guardamos ponteiros para
// Grupo, nunca chamamos métodos dele. Se um dia chamarmos, inclui-se aqui.

Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& foto)
    : nome_(nome), email_(email), foto_(foto) {
    // Regra da User Story 1: nome e e-mail são obrigatórios.
    if (Validacao::textoEmBranco(nome_)) {
        throw std::invalid_argument("O nome do usuario e obrigatorio.");
    }
    if (email_.empty()) {
        throw std::invalid_argument("O e-mail do usuario e obrigatorio.");
    }
    if (!Validacao::emailValido(email_)) {
        throw std::invalid_argument("O e-mail do usuario e invalido.");
    }
}

std::string Usuario::getNome() const { return nome_; }

std::string Usuario::getEmail() const { return email_; }

std::string Usuario::getFoto() const { return foto_; }

void Usuario::entrarGrupo(const std::shared_ptr<Grupo>& grupo) {
    if (!grupo) {
        throw std::invalid_argument("Grupo invalido.");
    }
    // Só adiciona se o usuário ainda não estiver nesse grupo.
    if (std::find(grupos_.begin(), grupos_.end(), grupo) == grupos_.end()) {
        grupos_.push_back(grupo);
    }
}

void Usuario::sairGrupo(const std::shared_ptr<Grupo>& grupo) {
    // Idioma "erase-remove": remove() move os elementos iguais para o fim e
    // erase() apaga essa sobra. Se o grupo não estiver na lista, nada muda.
    grupos_.erase(std::remove(grupos_.begin(), grupos_.end(), grupo), grupos_.end());
}

std::vector<std::shared_ptr<Grupo>> Usuario::getGrupos() const { return grupos_; }

void Usuario::receberConvite(const std::string& nomeGrupo) {
    if (nomeGrupo.empty()) {
        throw std::invalid_argument("O nome do grupo do convite e obrigatorio.");
    }
    if (std::find(convitesPendentes_.begin(), convitesPendentes_.end(), nomeGrupo) ==
        convitesPendentes_.end()) {
        convitesPendentes_.push_back(nomeGrupo);
    }
}

std::vector<std::string> Usuario::getConvitesPendentes() const { return convitesPendentes_; }
