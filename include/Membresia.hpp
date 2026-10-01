#ifndef MEMBRESIA_HPP
#define MEMBRESIA_HPP

#include <string>
#include <memory>

class Usuario;
class Grupo;

/**
 * @class Membresia
 * @brief Representa o vínculo entre um usuário e um grupo, incluindo
 *        o papel (membro ou administrador) e a data de entrada.
 *
 * Colaboradores: Usuario, Grupo
 */
class Membresia {
public:
    /// @brief Papel do usuário dentro do grupo.
    enum class Papel { MEMBRO, ADMINISTRADOR };

private:
    std::shared_ptr<Usuario> usuario_;
    std::shared_ptr<Grupo> grupo_;
    Papel papel_;
    std::string dataEntrada_;

public:
    /**
     * @brief Constrói uma nova membresia.
     * @param usuario Usuário associado ao grupo.
     * @param grupo Grupo ao qual o usuário está associado.
     * @param papel Papel inicial do usuário no grupo.
     * @param dataEntrada Data de entrada no grupo.
     */
    Membresia(const std::shared_ptr<Usuario>& usuario,
              const std::shared_ptr<Grupo>& grupo,
              Papel papel,
              const std::string& dataEntrada);

    /// @brief Retorna o usuário desta membresia.
    std::shared_ptr<Usuario> getUsuario() const;

    /// @brief Retorna o grupo desta membresia.
    std::shared_ptr<Grupo> getGrupo() const;

    /// @brief Retorna o papel atual do usuário no grupo.
    Papel getPapel() const;

    /**
     * @brief Promove o usuário a administrador do grupo.
     */
    void promoverAAdministrador();

    /// @brief Retorna a data de entrada do usuário no grupo.
    std::string getDataEntrada() const;

    /// @brief Verifica se o usuário tem permissão de administrador.
    bool ehAdministrador() const;
};

#endif // MEMBRESIA_HPP
