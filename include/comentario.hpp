#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include <string>

struct Comentario {
private:
    std::string autor;
    std::string texto;
    std::string dataHora;

public:
    /// Cria um novo comentário com autor, texto e data/hora.
    Comentario(std::string autor, std::string texto, std::string dataHora);

    /// Retorna o nome do autor do comentário.
    std::string getAutor() const;

    /// Retorna o texto do comentário.
    std::string getTexto() const;

    /// Retorna a data/hora do comentário.
    std::string getDataHora() const;
};

#endif