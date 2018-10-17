#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void processarLinha(char* linha, char** comandos);
int executarLinha(char** comandos);
int mudarDiretorio(char** comandos);

int main()
{
    char linha[100];
    char* comandos[10];  

    int tam = 0;

    printf("\n\t::: MINI $HELL LINUX :::\n");

    while(1) {
        // Pega o nome de usuário
        char* usuario = getenv("USER");
        // Pega o diretório atual
        char diretorio[100];
        getcwd(diretorio, sizeof(diretorio));   

        printf("\n[%s@shell %s]$ ", usuario, diretorio);
        fgets(linha, sizeof(linha), stdin);
        tam = strlen(linha);

        // Remove quebra de linha (\n)
        if(linha[tam - 1] == '\n') linha[tam - 1] = '\0';

        // Separa comandos da linha
        processarLinha(linha, comandos);
        
        if(strcmp(comandos[0], "exit") == 0) break;
        // Mudar de diretório
        if(strcmp(comandos[0], "cd") == 0){
            mudarDiretorio(comandos);
        }else{
        // Executar Comandos em novo processo
            if(executarLinha(comandos) == 0) break;
        }
    }

    return 0;
}

void processarLinha(char* linha, char** comandos)
{       
    for(int i = 0; i < 5; i++) {
        comandos[i] = strsep(&linha, " ");
        if(comandos[i] == NULL) break;
    }
}

int executarLinha(char** comandos)
{    
    pid_t pid = fork();

    if (pid == 0) {     
        execvp(comandos[0], comandos);  
        printf("\n %s: Nao eh um comando valido\n", comandos[0]);
        return 0;
    }
    else {        
        int status;
        waitpid(pid, &status, 0);
        return 1;
    }
}

int mudarDiretorio(char** comandos){
    if (comandos[1] == NULL) {
		chdir(getenv("HOME"));
	} else {
		if (chdir(comandos[1]) == -1) printf("\n %s: Nao eh um diretorio\n", comandos[1]);
	}
    return 1;
}