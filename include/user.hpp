#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>

struct Usuario {
private:
    std::string nome;
    std::string email;
    std::string foto; // caminho do arquivo, pode ficar vazio

    // por enquanto guardamos só o NOME dos grupos, não o objeto Grupo de verdade
    std::vector<std::string> nomesDosGrupos;
    std::vector<std::string> convitesPendentes;

public:
    /// Cria um novo usuário com nome e e-mail.
    Usuario(std::string nome, std::string email);

    /// Retorna o nome do usuário.
    std::string getNome() const;

    /// Retorna o e-mail do usuário.
    std::string getEmail() const;

    /// Adiciona o nome de um grupo à lista de grupos do usuário.
    void entrarGrupo(std::string nomeGrupo);

    /// Remove o nome de um grupo da lista de grupos do usuário.
    void sairGrupo(std::string nomeGrupo);

    /// Retorna a lista de nomes dos grupos do usuário.
    std::vector<std::string> getGrupos() const;

    /// Registra um convite pendente vindo de um grupo.
    void receberConvite(std::string nomeGrupo);

    /// Retorna a lista de convites pendentes.
    std::vector<std::string> getConvites() const;
};

#endif