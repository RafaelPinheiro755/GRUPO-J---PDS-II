#ifndef POST_HPP
#define POST_HPP

#include <string>
#include <vector>

struct Post {
private:
    std::string autor;  // nome de quem postou
    std::string grupo;  // nome do grupo onde foi postado
    std::string texto;
    std::string dataHora;

    std::vector<std::string> quemCurtiu;
    std::vector<std::string> comentarios; // por enquanto, só o texto do comentário

public:
    /// Cria um novo post com autor, grupo, texto e data/hora.
    Post(std::string autor, std::string grupo, std::string texto, std::string dataHora);

    /// Retorna o nome do autor do post.
    std::string getAutor() const;

    /// Retorna o nome do grupo onde o post foi publicado.
    std::string getGrupo() const;

    /// Retorna o texto do post.
    std::string getTexto() const;

    /// Retorna a data/hora de criação do post.
    std::string getDataHora() const;

    /// Registra a curtida de um usuário no post.
    void curtir(std::string nomeUsuario);

    /// Retorna a quantidade de curtidas do post.
    int getQuantidadeCurtidas() const;

    /// Adiciona um comentário (como texto) ao post.
    void adicionarComentario(std::string texto);

    /// Retorna a lista de comentários do post.
    std::vector<std::string> getComentarios() const;
};

#endif