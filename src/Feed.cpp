#include "Feed.hpp"

#include <algorithm>  // std::find, std::stable_sort
#include <stdexcept>

#include "Grupo.hpp"
#include "Post.hpp"
#include "Usuario.hpp"

namespace {

// Critério de ordenação: a data/hora no formato "AAAA-MM-DD HH:MM" pode ser
// comparada como texto, porque o ano vem primeiro, depois mês, dia, hora...
bool maisRecentePrimeiro(const std::shared_ptr<Post>& a, const std::shared_ptr<Post>& b) {
    return a->getDataHora() > b->getDataHora();
}

}  // namespace

Feed::Feed(const std::shared_ptr<Usuario>& usuario) : usuario_(usuario) {
    if (!usuario_) {
        throw std::invalid_argument("O feed precisa de um usuario.");
    }
}

std::vector<std::shared_ptr<Post>> Feed::listarPosts() const {
    std::vector<std::shared_ptr<Post>> todos;

    // Junta os posts de todos os grupos do usuário.
    for (const auto& grupo : usuario_->getGrupos()) {
        std::vector<std::shared_ptr<Post>> doGrupo = grupo->getPosts();
        todos.insert(todos.end(), doGrupo.begin(), doGrupo.end());
    }

    // stable_sort mantém a ordem original entre posts com a mesma data/hora.
    std::stable_sort(todos.begin(), todos.end(), maisRecentePrimeiro);
    return todos;
}

std::vector<std::shared_ptr<Post>> Feed::listarPostsPorGrupo(
    const std::shared_ptr<Grupo>& grupo) const {
    std::vector<std::shared_ptr<Post>> posts;

    // Só devolve posts de grupos dos quais o usuário realmente participa.
    const std::vector<std::shared_ptr<Grupo>> grupos = usuario_->getGrupos();
    if (!grupo || std::find(grupos.begin(), grupos.end(), grupo) == grupos.end()) {
        return posts;  // vazio
    }

    posts = grupo->getPosts();
    std::stable_sort(posts.begin(), posts.end(), maisRecentePrimeiro);
    return posts;
}
