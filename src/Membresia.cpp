#include "Membresia.hpp"

#include <stdexcept>

Membresia::Membresia(const std::shared_ptr<Usuario>& usuario,
                     const std::shared_ptr<Grupo>& grupo,
                     Papel papel,
                     const std::string& dataEntrada)
    : usuario_(usuario), grupo_(grupo), papel_(papel), dataEntrada_(dataEntrada) {
    if (!usuario_) {
        throw std::invalid_argument("A membresia precisa de um usuario.");
    }
    if (!grupo_) {
        throw std::invalid_argument("A membresia precisa de um grupo.");
    }
}

std::shared_ptr<Usuario> Membresia::getUsuario() const { return usuario_; }

std::shared_ptr<Grupo> Membresia::getGrupo() const { return grupo_; }

Membresia::Papel Membresia::getPapel() const { return papel_; }

void Membresia::promoverAAdministrador() {
    // Se já é administrador, atribuir de novo não muda nada.
    papel_ = Papel::ADMINISTRADOR;
}

std::string Membresia::getDataEntrada() const { return dataEntrada_; }

bool Membresia::ehAdministrador() const { return papel_ == Papel::ADMINISTRADOR; }
