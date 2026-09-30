#ifndef MEMBRESIA_HPP
#define MEMBRESIA_HPP

#include <string>

struct Membresia {
private:
    std::string nomeUsuario;
    std::string nomeGrupo;
    bool ehAdmin; // true = administrador, false = membro comum
    std::string dataEntrada;

public:
    /// Cria uma nova membresia entre um usuário e um grupo.
    Membresia(std::string nomeUsuario, std::string nomeGrupo, std::string dataEntrada);

    /// Retorna o nome do usuário desta membresia.
    std::string getUsuario() const;

    /// Retorna o nome do grupo desta membresia.
    std::string getGrupo() const;

    /// Retorna a data de entrada no grupo.
    std::string getDataEntrada() const;

    /// Promove o usuário a administrador do grupo.
    void promoverAAdministrador();

    /// Retorna true se o usuário for administrador do grupo.
    bool ehAdministrador() const;
};

#endif