#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Função que lida com o recebimento dos sinais (bits)
void handle_signal(int sig) {
    static char c = 0;  // Armazena o caractere sendo formado
    static int bit = 0; // Contador dos bits recebidos

    // Verifica qual sinal foi recebido e forma o caractere
    if (sig == SIGUSR1) {
        c |= (1 << bit);  // Define o bit correspondente como 1
    }

    bit++;  // Passa para o próximo bit

    // Quando todos os 7 bits forem recebidos, imprime o caractere
    if (bit == 7) {
        if (c == '\0')  // Se o caractere for nulo, significa que a mensagem acabou
            write(1, "\n", 1);  // Imprime a nova linha
        else
            write(1, &c, 1);  // Imprime o caractere

        c = 0;  // Reseta o caractere
        bit = 0;  // Reseta o contador de bits
    }
}

int main() {
    struct sigaction sa;

    // Exibe o PID do servidor para que o cliente possa usá-lo
    printf("PID do Servidor: %d\n", getpid());

    // Configura o manipulador de sinais para SIGUSR1 e SIGUSR2
    sa.sa_handler = &handle_signal;
    sa.sa_flags = SA_RESTART;

    // Configura o tratamento de sinais SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Erro ao configurar SIGUSR1");
        exit(1);
    }

    // Configura o tratamento de sinais SIGUSR2
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("Erro ao configurar SIGUSR2");
        exit(1);
    }

    // Fica aguardando os sinais (processo "vivo" para receber sinais)
    while (1)
        pause();

    return 0;
}
