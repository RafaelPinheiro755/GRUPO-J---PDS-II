# Conecta — mini rede social

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

**Mini rede social.** Um sistema de terminal, em C++11, que modela as interações
entre usuários e organiza os conteúdos publicados em uma timeline.

Funcionalidades previstas: gestão de perfis, publicações de tipos diferentes
(texto, vídeo e imagem), listagem em timeline, curtidas e comentários, lista de
amigos e relatórios da rede, com os dados guardados em arquivos de texto.

## Motivação

Uma rede social parece simples de fora, mas concentra um problema clássico de
modelagem: conteúdos de naturezas diferentes precisam conviver na mesma lista,
ser exibidos lado a lado e receber as mesmas interações, sem que o restante do
sistema precise perguntar de que tipo é cada um. É um domínio conhecido por todo
mundo do grupo, o que deixa a discussão de requisitos mais rápida, e ao mesmo
tempo exercita de forma natural os conceitos centrais da disciplina: herança e
polimorfismo na hierarquia de publicações, encapsulamento nas regras que não
podem ser burladas de fora, e tratamento de exceções na leitura dos arquivos.

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
