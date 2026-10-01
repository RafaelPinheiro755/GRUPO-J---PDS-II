#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include <string>
#include <memory>

class Usuario;
class Post;

/**
 * @class Comentario
 * @brief Representa um comentário feito por um usuário em um post.
 *
 * Colaboradores: Usuario, Post
 */
class Comentario {
public:
    static const std::size_t TAMANHO_MAXIMO_TEXTO = 280;

private:
    std::shared_ptr<Usuario> autor_;
    std::string texto_;
    std::string dataHora_;

public:
    /**
     * @brief Constrói um novo comentário.
     * @param autor Usuário que fez o comentário.
     * @param texto Conteúdo do comentário (até 280 caracteres).
     * @param dataHora Data e hora de criação, gerada automaticamente.
     */
    Comentario(const std::shared_ptr<Usuario>& autor,
               const std::string& texto,
               const std::string& dataHora);

    /// @brief Retorna o autor do comentário.
    std::shared_ptr<Usuario> getAutor() const;

    /// @brief Retorna o texto do comentário.
    std::string getTexto() const;

    /// @brief Retorna a data/hora do comentário.
    std::string getDataHora() const;
};

#endif // COMENTARIO_HPP
