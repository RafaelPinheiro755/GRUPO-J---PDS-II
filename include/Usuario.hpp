#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include <memory>

class Grupo;      // forward declaration (evita include circular)
class Membresia;  // forward declaration

/**
 * @class Usuario
 * @brief Representa um usuário da rede social.
 *
 * Armazena os dados de perfil e mantém a lista de grupos dos quais o
 * usuário participa, além dos convites pendentes recebidos.
 *
 * Colaboradores: Grupo, Membresia
 */
class Usuario {
private:
    std::string nome_;
    std::string email_;
    std::string foto_; ///< Caminho do arquivo de foto (opcional)

    std::vector<std::shared_ptr<Grupo>> grupos_;
    std::vector<std::string> convitesPendentes_; ///< Nomes dos grupos que convidaram o usuário

public:
    /**
     * @brief Constrói um novo usuário.
     * @param nome Nome do usuário (obrigatório).
     * @param email E-mail do usuário (obrigatório).
     * @param foto Caminho do arquivo de foto de perfil (opcional).
     */
    Usuario(const std::string& nome, const std::string& email, const std::string& foto = "");

    /// @brief Retorna o nome do usuário.
    std::string getNome() const;

    /// @brief Retorna o e-mail do usuário.
    std::string getEmail() const;

    /// @brief Retorna o caminho da foto de perfil.
    std::string getFoto() const;

    /**
     * @brief Adiciona o usuário à lista de membros de um grupo.
     * @param grupo Ponteiro compartilhado para o grupo a ser ingressado.
     */
    void entrarGrupo(const std::shared_ptr<Grupo>& grupo);

    /**
     * @brief Remove o usuário da lista de membros de um grupo.
     * @param grupo Ponteiro compartilhado para o grupo a ser deixado.
     */
    void sairGrupo(const std::shared_ptr<Grupo>& grupo);

    /// @brief Retorna a lista de grupos dos quais o usuário participa.
    std::vector<std::shared_ptr<Grupo>> getGrupos() const;

    /**
     * @brief Registra um convite pendente para um grupo.
     * @param nomeGrupo Nome do grupo que enviou o convite.
     */
    void receberConvite(const std::string& nomeGrupo);

    /// @brief Retorna a lista de convites pendentes.
    std::vector<std::string> getConvitesPendentes() const;
};

#endif // USUARIO_HPP
