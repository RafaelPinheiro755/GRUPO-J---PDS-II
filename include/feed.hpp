#ifndef FEED_HPP
#define FEED_HPP

#include <string>
#include <vector>

struct Feed {
private:
    std::string nomeUsuario;
    std::vector<std::string> posts; // textos dos posts já reunidos

public:
    /// Cria o feed de um usuário, identificado pelo nome.
    explicit Feed(std::string nomeUsuario);

    /// Adiciona um post (como texto) ao feed.
    void adicionarPost(std::string texto);

    /// Retorna a lista de posts do feed.
    std::vector<std::string> listarPosts() const;
};

#endif