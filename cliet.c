#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Função para enviar um caractere para o servidor, bit a bit
void send_char(pid_t server_pid, char c) {
    int bit;
    
    // Loop para enviar os 7 bits do caractere
    for (bit = 0; bit < 7; bit++) {
        // Envia SIGUSR1 para 1 e SIGUSR2 para 0
        if (c & (1 << bit))
            kill(server_pid, SIGUSR1);  // Envia 1
        else
            kill(server_pid, SIGUSR2);  // Envia 0
        
        usleep(100);  // Atraso para garantir que o servidor receba o sinal
    }
}

int main(int argc, char **argv) {
    pid_t server_pid;
    int i;

    // Verifica se os argumentos foram passados corretamente
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <PID do servidor> <mensagem>\n", argv[0]);
        exit(1);  // Encerra o programa em caso de erro
    }

    // Converte o PID do servidor de string para inteiro
    server_pid = (pid_t)atoi(argv[1]);

    // Verifica se o PID do servidor é válido
    if (kill(server_pid, 0) == -1) {
        perror("Erro: PID do servidor inválido");
        exit(1);
    }

    // Verifica se a mensagem não está vazia
    if (argv[2][0] == '\0') {
        fprintf(stderr, "Erro: Mensagem vazia\n");
        exit(1);
    }

    // Envia cada caractere da mensagem para o servidor
    for (i = 0; argv[2][i] != '\0'; i++) {
        send_char(server_pid, argv[2][i]);
    }

    // Envia caractere nulo para indicar o fim da mensagem
    send_char(server_pid, '\0');  

    return 0;
}
