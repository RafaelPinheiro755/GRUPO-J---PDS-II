#ifndef POST_HPP
#define POST_HPP

#include <string>
#include <vector>
#include <memory>

class Usuario;     // forward declaration
class Grupo;       // forward declaration
class Comentario;  // forward declaration

/**
 * @class Post
 * @brief Representa uma atualização curta publicada em um grupo.
 *
 * Guarda o autor, o grupo, o texto e a data/hora da publicação, além das
 * curtidas e dos comentários recebidos.
 *
 * Colaboradores: Usuario, Grupo, Comentario
 */
class Post {
public:
    static const std::size_t TAMANHO_MAXIMO_TEXTO = 280;

private:
    std::shared_ptr<Usuario> autor_;
    std::weak_ptr<Grupo> grupo_; ///< weak_ptr: o Grupo já guarda os seus posts

    std::string texto_;
    std::string dataHora_;

    std::vector<std::shared_ptr<Usuario>> curtidas_;
    std::vector<std::shared_ptr<Comentario>> comentarios_;

public:
    /**
     * @brief Constrói um novo post.
     * @param autor Usuário que publicou o post.
     * @param grupo Grupo em que o post foi publicado.
     * @param texto Conteúdo do post (de 1 a 280 caracteres).
     * @param dataHora Data e hora de criação, no formato "AAAA-MM-DD HH:MM".
     * @throws std::invalid_argument se faltar autor ou grupo, se o texto
     *         estiver vazio ou passar de 280 caracteres, ou se a data/hora
     *         estiver fora do formato.
     */
    Post(const std::shared_ptr<Usuario>& autor,
         const std::shared_ptr<Grupo>& grupo,
         const std::string& texto,
         const std::string& dataHora);

    /// @brief Retorna o autor do post.
    std::shared_ptr<Usuario> getAutor() const;

    /// @brief Retorna o grupo em que o post foi publicado.
    std::shared_ptr<Grupo> getGrupo() const;

    /// @brief Retorna o texto do post.
    std::string getTexto() const;

    /// @brief Retorna a data/hora de criação do post.
    std::string getDataHora() const;

    /**
     * @brief Registra a curtida de um usuário no post.
     * @param usuario Usuário que curtiu.
     * @return true se a curtida foi registrada; false se o usuário já
     *         tinha curtido o post (cada usuário curte uma vez só).
     */
    bool curtir(const std::shared_ptr<Usuario>& usuario);

    /// @brief Verifica se o usuário já curtiu o post.
    bool foiCurtidoPor(const std::shared_ptr<Usuario>& usuario) const;

    /// @brief Retorna a quantidade de curtidas do post.
    std::size_t getQuantidadeCurtidas() const;

    /**
     * @brief Adiciona um comentário ao post.
     * @param comentario Comentário a adicionar (fica em ordem cronológica).
     */
    void adicionarComentario(const std::shared_ptr<Comentario>& comentario);

    /// @brief Retorna os comentários do post, em ordem cronológica.
    std::vector<std::shared_ptr<Comentario>> getComentarios() const;
};

#endif // POST_HPP
