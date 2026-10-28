#include "Grupo.hpp"

#include <map>
#include <sstream>
#include <stdexcept>

#include "Membresia.hpp"
#include "Post.hpp"
#include "Usuario.hpp"

Grupo::Grupo(const std::string& nome, Tipo tipo, const std::string& descricao)
    : nome_(nome), descricao_(descricao), tipo_(tipo) {
    // Regra da User Story 2: o nome do grupo é obrigatório.
    if (nome_.empty()) {
        throw std::invalid_argument("O nome do grupo e obrigatorio.");
    }
}

std::string Grupo::getNome() const { return nome_; }

std::string Grupo::getDescricao() const { return descricao_; }

Grupo::Tipo Grupo::getTipo() const { return tipo_; }

void Grupo::adicionarMembro(const std::shared_ptr<Membresia>& membresia) {
    if (!membresia) {
        throw std::invalid_argument("Membresia invalida.");
    }
    membros_.push_back(membresia);
}

std::vector<std::shared_ptr<Membresia>> Grupo::getMembros() const { return membros_; }

void Grupo::adicionarPost(const std::shared_ptr<Post>& post) {
    if (!post) {
        throw std::invalid_argument("Post invalido.");
    }
    posts_.push_back(post);
}

std::vector<std::shared_ptr<Post>> Grupo::getPosts() const { return posts_; }

std::string Grupo::gerarRelatorioAtividade() const {
    // 1) Conta quantos posts cada autor publicou. A chave do mapa é o
    //    endereço do Usuario, para dois usuários com o mesmo nome não se misturarem.
    std::map<const Usuario*, int> contagem;
    for (const auto& post : posts_) {
        ++contagem[post->getAutor().get()];
    }

    // 2) Acha o autor com mais posts. Em caso de empate, vence quem
    //    publicou primeiro (por isso percorremos os posts em ordem).
    std::shared_ptr<Usuario> maisAtivo;
    int maiorQuantidade = 0;
    for (const auto& post : posts_) {
        std::shared_ptr<Usuario> autor = post->getAutor();
        int quantidade = contagem[autor.get()];
        if (quantidade > maiorQuantidade) {
            maiorQuantidade = quantidade;
            maisAtivo = autor;
        }
    }

    // 3) Monta o texto do relatório.
    std::ostringstream relatorio;
    relatorio << "Relatorio de atividade do grupo \"" << nome_ << "\"\n";
    relatorio << "Total de membros: " << membros_.size() << "\n";
    relatorio << "Total de posts: " << posts_.size() << "\n";
    if (maisAtivo) {
        relatorio << "Membro mais ativo: " << maisAtivo->getNome() << " ("
                  << maiorQuantidade << " posts)\n";
    } else {
        relatorio << "Membro mais ativo: nenhum (o grupo ainda nao tem posts)\n";
    }
    return relatorio.str();
}
