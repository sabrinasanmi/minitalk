# **Minitalk: Comunicação entre Cliente e Servidor com Sinais**

Este projeto implementa um protocolo de comunicação entre um cliente e um servidor utilizando sinais Unix (`SIGUSR1` e `SIGUSR2`) para enviar dados. O objetivo é praticar a manipulação de sinais e a comunicação entre processos no sistema operacional.

## **Objetivo**
O objetivo do projeto é permitir que um cliente envie uma mensagem para um servidor, que a recebe e a exibe na tela. A comunicação é feita bit a bit, com cada caractere da mensagem sendo enviado em sequência.

## **Arquivos**
O projeto consiste em dois arquivos principais:
- **client.c**: O código do cliente, que envia uma mensagem para o servidor.
- **server.c**: O código do servidor, que recebe a mensagem e a imprime.

## **Como Funciona**
1. **Servidor**: 
   - O servidor aguarda sinais do cliente.
   - Quando um sinal é recebido, o servidor interpreta o bit correspondente (1 para `SIGUSR1`, 0 para `SIGUSR2`).
   - Os bits são agrupados para formar um caractere.
   - O servidor imprime os caracteres na tela.

2. **Cliente**: 
   - O cliente recebe o PID do servidor e a mensagem a ser enviada como parâmetros.
   - O cliente envia os bits dos caracteres da mensagem um de cada vez, utilizando os sinais `SIGUSR1` (para 1) e `SIGUSR2` (para 0).
   - Após enviar toda a mensagem, o cliente envia um caractere nulo (`'\0'`) para indicar o fim da mensagem.

## **Como Compilar e Executar**

### **Compilação**
Para compilar o código, use o comando `gcc` para gerar os executáveis do cliente e do servidor:

```bash
gcc -o server server.c
gcc -o client client.c
```

### **Execução**
1. **Iniciar o servidor**:
   No terminal, execute o servidor, que irá mostrar seu PID (identificador do processo):

   ```bash
   ./server
   ```

   Exemplo de saída:
   ```
   PID do Servidor: 12345
   ```

2. **Iniciar o cliente**:
   Em outro terminal, execute o cliente, passando o PID do servidor e a mensagem que deseja enviar:

   ```bash
   ./client <PID do servidor> "Mensagem a ser enviada"
   ```

   Exemplo de execução:
   ```bash
   ./client 12345 "Olá, servidor!"
   ```

3. **O servidor irá imprimir a mensagem**: Após o cliente enviar os sinais, o servidor exibirá a mensagem na tela.

## **Explicação do Código**

### **Cliente (`client.c`)**:
- O cliente recebe o PID do servidor e a mensagem como parâmetros.
- Para cada caractere da mensagem, o cliente envia os bits um por vez usando os sinais `SIGUSR1` e `SIGUSR2`.
- O cliente envia um caractere nulo (`'\0'`) no final para indicar o fim da mensagem.

### **Servidor (`server.c`)**:
- O servidor aguarda os sinais do cliente.
- Ao receber um sinal, ele interpreta o bit (1 para `SIGUSR1`, 0 para `SIGUSR2`) e constrói o caractere.
- O servidor imprime o caractere assim que todos os 7 bits de um caractere são recebidos.

## **Possíveis Erros**
- **Erro ao enviar o sinal**: Se o PID do servidor não for válido ou o processo do servidor não estiver em execução, o cliente pode falhar ao enviar os sinais.
- **Erro de compilação**: Certifique-se de que o código foi compilado corretamente com o comando `gcc` acima.

## **Licença**
Este projeto é de uso educacional. Você pode usá-lo para estudar e aprender sobre a comunicação entre processos utilizando sinais no Unix.
