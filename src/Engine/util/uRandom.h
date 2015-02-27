#ifndef URANDOM_H
#define URANDOM_H
#include <cstdlib>
#include <ctime>

class uRandom
{
public:

    /*Função que retorna se deu certo uma tentativa
     * relacionada a uma porcentagem.
     * ex: tente algo que tenha 15% de chance de dar certo:
     * bool resultado = byChance(15.0f);
     */
    static bool byChance(float percent);

    //Iniciar a semente aleatória
    static void initRandomSeed();

    /*Pegar um número aleatório
    * de 0 a num.
    */
    static int getInt(int num);
};

#endif // URANDOM_H
