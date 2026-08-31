# Checkpoints do Projeto Final — Grupo J

Mapa do que cada checkpoint pede e onde isso está no repositório.

| CP | Entregável | Onde está |
| --- | --- | --- |
| C1 | Grupo formado e ambiente validado | Integrantes e ferramentas no `README.md` |
| C2 | Tema definido | Mini rede social — `README.md` |
| C3 | Commit de teste de cada integrante | Arquivos `<matrícula>.txt` na raiz |
| C4 | Estrutura de diretórios | `src/`, `include/`, `build/`, `tests/`, `design/` |
| C5 | User stories e cartões CRC | `design/` — 15/set |
| C6 | Contratos `.hpp`, Doxygen e README | `include/`, `Doxyfile` — 01/out |
| C7 | Testes de unidade e Makefile | `tests/`, `Makefile` — 13/out |
| C8 | Implementação dos `.cpp` | `src/` — 27/out |
| C9 | Programação defensiva e exceções | `src/` — 03/nov |
| C10 | Finalização e apresentação | `docs/` — 10 a 12/nov |

## O que cada integrante precisa fazer (C3 e participação)

O C3 é individual: **cada pessoa faz o próprio commit**, da própria máquina. A
nota individual depende disso — o professor mede, por autor, o número de commits,
as linhas alteradas e os dias distintos com atividade. Commit feito por outra
pessoa não conta para você.

Passo a passo, uma vez por integrante:

```bash
git clone <url-do-repositorio>
cd <pasta-do-repositorio>

# 1. Identidade igual à cadastrada no Moodle
git config user.name  "SEU NOME COMO ESTA NO MOODLE"
git config user.email "SEU EMAIL COMO ESTA NO MOODLE"

# 2. Arquivo do C3, com a sua matrícula no nome
#    Copie o conteúdo de qualquer <matrícula>.txt já existente na raiz.
git add <sua-matrícula>.txt
git commit -m "C3: commit de teste de <seu nome>"
git push
```

Depois disso, distribua as tarefas do dia a dia (uma classe, um conjunto de
testes, uma parte da documentação) e faça commits em dias diferentes. Evite
`squash merge` em pull requests: ele apaga a autoria individual dos commits.

Para conferir os próprios números a qualquer momento:

```bash
git log --no-merges --author="SEU EMAIL" --oneline | wc -l
git log --no-merges --author="SEU EMAIL" --pretty=tformat: --numstat \
  | awk '{ins+=$1; del+=$2} END {print ins+del}'
git log --no-merges --author="SEU EMAIL" --pretty=format:"%ad" --date=short \
  | sort -u | wc -l
```

## Sugestão de divisão por área

| Área | Arquivos | Responsável sugerido |
| --- | --- | --- |
| Perfis e amizades | `Usuario.*`, `test_usuario.cpp` | a combinar |
| Publicações e comentários | `Post*.*`, `Comentario.*`, `test_post.cpp` | a combinar |
| Regras da rede | `RedeSocial.*`, `test_redesocial.cpp` | a combinar |
| Persistência e validação | `Persistencia.*`, `Validacao.*`, testes | a combinar |
| Interface e documentação | `main.cpp`, `README.md`, `docs/` | a combinar |
