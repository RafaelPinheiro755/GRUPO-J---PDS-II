#ifndef GRUPO_HPP
#define GRUPO_HPP

#include <string>
#include <vector>
#include <memory>

class Usuario;    // forward declaration
class Post;       // forward declaration
class Membresia;  // forward declaration

/**
 * @class Grupo
 * @brief Representa um grupo da rede social (público ou privado).
 *
 * Mantém a lista de membros e de posts publicados no grupo, além de
 * permitir a geração de um relatório simples de atividade.
 *
 * Colaboradores: Usuario, Post, Membresia
 */
class Grupo {
public:
    /// @brief Tipo de visibilidade do grupo.
    enum class Tipo { PUBLICO, PRIVADO };

private:
    std::string nome_;
    std::string descricao_;
    Tipo tipo_;

    std::vector<std::shared_ptr<Membresia>> membros_;
    std::vector<std::shared_ptr<Post>> posts_;

public:
    /**
     * @brief Constrói um novo grupo.
     * @param nome Nome do grupo (obrigatório).
     * @param tipo Visibilidade do grupo (PUBLICO ou PRIVADO).
     * @param descricao Descrição do grupo (opcional).
     */
    Grupo(const std::string& nome, Tipo tipo, const std::string& descricao = "");

    /// @brief Retorna o nome do grupo.
    std::string getNome() const;

    /// @brief Retorna a descrição do grupo.
    std::string getDescricao() const;

    /// @brief Retorna o tipo (público/privado) do grupo.
    Tipo getTipo() const;

    /**
     * @brief Adiciona um novo membro ao grupo.
     * @param membresia Registro de membresia (usuário + papel) a adicionar.
     */
    void adicionarMembro(const std::shared_ptr<Membresia>& membresia);

    /// @brief Retorna a lista de membros do grupo.
    std::vector<std::shared_ptr<Membresia>> getMembros() const;

    /**
     * @brief Adiciona um post à lista de posts do grupo.
     * @param post Ponteiro compartilhado para o post publicado.
     */
    void adicionarPost(const std::shared_ptr<Post>& post);

    /// @brief Retorna a lista de posts do grupo.
    std::vector<std::shared_ptr<Post>> getPosts() const;

    /**
     * @brief Gera um relatório simples de atividade do grupo.
     * @return String formatada com total de posts, total de membros e
     *         o membro mais ativo (a definir critério na implementação).
     */
    std::string gerarRelatorioAtividade() const;
};

#endif // GRUPO_HPP
