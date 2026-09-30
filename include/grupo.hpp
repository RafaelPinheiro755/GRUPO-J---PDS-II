#ifndef GRUPO_HPP
#define GRUPO_HPP

#include <string>
#include <vector>

struct Grupo {
private:
    std::string nome;
    std::string descricao;
    bool ehPublico; // true = público, false = privado

    std::vector<std::string> nomesDosMembros;
    std::vector<std::string> textosDosPosts;

public:
    /// Cria um novo grupo com nome, visibilidade e descrição.
    Grupo(std::string nome, bool ehPublico, std::string descricao);

    /// Retorna o nome do grupo.
    std::string getNome() const;

    /// Retorna a descrição do grupo.
    std::string getDescricao() const;

    /// Retorna true se o grupo for público.
    bool getEhPublico() const;

    /// Adiciona o nome de um novo membro ao grupo.
    void adicionarMembro(std::string nomeUsuario);

    /// Retorna a lista de nomes dos membros do grupo.
    std::vector<std::string> getMembros() const;

    /// Adiciona um post (como texto) à lista de posts do grupo.
    void adicionarPost(std::string texto);

    /// Retorna a lista de textos dos posts do grupo.
    std::vector<std::string> getPosts() const;
};

#endif