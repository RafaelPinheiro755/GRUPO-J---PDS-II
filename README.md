# Conecta — rede social por grupos

Projeto Final da disciplina **Programação e Desenvolvimento de Software II (PDS II)**
— UFMG, 2º semestre de 2026. **Grupo J**.

## Integrantes

| Nome | Matrícula | GitHub |
| --- | --- | --- |
| Lucas Ferreira Simões | 2026020102 | [@hislucas](https://github.com/hislucas) |
| Maryana Victoria da Costa Oliveira | 2022115389 | [@maryvco](https://github.com/maryvco) |
| Patrícia Fabio da Rocha | 2026430866 | [@patriciafabiodarocha](https://github.com/patriciafabiodarocha) |
| Rafael Araujo Camargo Pinheiro | 2022057729 | [@RafaelPinheiro755](https://github.com/RafaelPinheiro755) |
| Renzo Miranda Cruz | 2025020435 | [@RenzoMiranda1](https://github.com/RenzoMiranda1) |

## Tema

**Rede social por grupos.** Um sistema de terminal, em C++11, em que os
usuários se organizam em grupos (públicos ou privados) e publicam
micro-atualizações visíveis apenas para os membros de cada grupo, em vez de
um perfil aberto com um feed geral.

Funcionalidades previstas: criação e participação em grupos, publicação de
posts curtos, curtidas e comentários, feed pessoal consolidando os grupos do
usuário, gestão de membros (promoção/remoção por administradores), com os
dados guardados em arquivos de texto.

## Motivação

A escolha do tema veio da vontade de explorar, na prática, conceitos de
Programação Orientada a Objetos como associação entre classes,
encapsulamento e composição — presentes naturalmente na relação entre
usuários, grupos, posts e comentários — além de oferecer um domínio rico o
suficiente para justificar testes automatizados, tratamento de exceções e
persistência de dados em arquivo, como exigido pela disciplina.

## Estrutura do repositório

```
include/   cabeçalhos (.hpp) das classes
src/       implementações (.cpp)
tests/     testes de unidade
design/    user stories e cartões CRC
build/     saída da compilação (não versionada)
```

## Ambiente de desenvolvimento

O projeto usa apenas ferramentas livres e disponíveis nos três sistemas:

- compilador com suporte a **C++11** (g++ 6 ou mais novo)
- **GNU Make** para automatizar a compilação
- **doctest** para os testes de unidade
- **gcovr** para o relatório de cobertura
- **Doxygen** para a documentação

## Checkpoints

O andamento de cada checkpoint e o passo a passo do commit individual estão em
[`docs/checkpoints.md`](docs/checkpoints.md).
