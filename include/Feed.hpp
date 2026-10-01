#ifndef FEED_HPP
#define FEED_HPP

#include <string>
#include <vector>
#include <memory>

class Usuario;
class Grupo;
class Post;

/**
 * @class Feed
 * @brief Consolida os posts de todos os grupos de um usuário.
 *
 * Colaboradores: Usuario, Grupo, Post
 */
class Feed {
public:
    /**
     * @brief Constrói o feed consolidado de um usuário.
     * @param usuario Usuário para o qual o feed será montado.
     */
    explicit Feed(const std::shared_ptr<Usuario>& usuario);

    /**
     * @brief Retorna todos os posts dos grupos do usuário, ordenados
     *        do mais recente para o mais antigo.
     * @return Lista de posts ordenada por data/hora.
     */
    std::vector<std::shared_ptr<Post>> listarPosts() const;

    /**
     * @brief Retorna os posts de um grupo específico do usuário.
     * @param grupo Grupo pelo qual filtrar os posts.
     * @return Lista de posts daquele grupo, ordenada por data/hora.
     */
    std::vector<std::shared_ptr<Post>> listarPostsPorGrupo(const std::shared_ptr<Grupo>& grupo) const;

private:
    std::shared_ptr<Usuario> usuario_;
};

#endif // FEED_HPP
