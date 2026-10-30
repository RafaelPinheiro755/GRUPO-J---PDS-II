#ifndef VALIDACAO_HPP
#define VALIDACAO_HPP

#include <string>

/**
 * @file Validacao.hpp
 * @brief Funções de apoio para validar os dados que entram no sistema.
 *
 * As classes usam estas funções nos construtores e lançam
 * std::invalid_argument quando o dado não passa.
 */
namespace Validacao {

/**
 * @brief Verifica se o texto está vazio ou só tem espaços.
 * @param texto Texto a verificar.
 * @return true se não houver nenhum caractere além de espaços.
 */
bool textoEmBranco(const std::string& texto);

/**
 * @brief Verifica se a data/hora está no formato "AAAA-MM-DD HH:MM".
 * @param dataHora Texto a verificar.
 * @return true se o formato estiver certo e mês, dia, hora e minuto
 *         forem valores possíveis.
 */
bool dataHoraValida(const std::string& dataHora);

/**
 * @brief Verifica se o e-mail tem o formato nome@dominio.algo.
 * @param email E-mail a verificar.
 * @return true se houver um único '@', com texto antes dele e um ponto
 *         no domínio, e nenhum espaço.
 */
bool emailValido(const std::string& email);

}  // namespace Validacao

#endif // VALIDACAO_HPP
