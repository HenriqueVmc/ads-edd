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

--------------------------------------------------- pt 2 --------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#define BUFFERSIZE 4096

void processarLinha(char* linha, char** comandos);
void executarLinha(char** comandos);
void mudarDiretorio(char** comandos);
void listar();
void listarT();
void contarQ();
void criaDir(char* nome);
void removeDir(char* nome);
void copia(char* local, char* destino);
void totalarq();
void existe(char* nome);

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

        if(strcmp(comandos[0], "listar") == 0){ 
            if((comandos[1] != NULL) && (strcmp(comandos[1], "-t") == 0)){             
                listarT();            
            }else{

                listar();            
            }
            continue;
        }
        if(strcmp(comandos[0], "contarq") == 0){             
            contarQ();            
            continue;
        }
        if(strcmp(comandos[0], "criadir") == 0){             
            criaDir(comandos[1]);            
            continue;
        }
        if(strcmp(comandos[0], "removedir") == 0){             
            removeDir(comandos[1]);            
            continue;
        }
        if(strcmp(comandos[0], "copia") == 0){             
            copia(comandos[1], comandos[2]);            
            continue;
        }
        if(strcmp(comandos[0], "totalarq") == 0){             
            totalarq();            
            continue;
        }
        if(strcmp(comandos[0], "existe") == 0){             
            existe(comandos[1]);            
            continue;
        }
        // Mudar de diretório
        if(strcmp(comandos[0], "cd") == 0){
            mudarDiretorio(comandos);
        }else{
        // Executar Comandos em novo processo
            executarLinha(comandos);
            continue;
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

void executarLinha(char** comandos)
{    
    pid_t pid = fork();
    int status;

    if (pid == 0) {     
        execvp(comandos[0], comandos);  
        printf("\n %s: Nao eh um comando valido\n", comandos[0]);        
    }
    else {                
        wait(&status);        
    }
}

void mudarDiretorio(char** comandos)
{
    pid_t pid = fork();
    int status;

    if (pid == 0) {   
        if (comandos[1] == NULL) {
            chdir(getenv("HOME"));
        } else {
            if (chdir(comandos[1]) == -1) printf("\n %s: Nao eh um diretorio\n", comandos[1]);
        }
    }else{
        wait(&status);
    }
}

void listar()
{
    pid_t pid = fork();
    int status;

    if (pid == 0) { 
        char *cmd[]={"ls", NULL}; 
        execvp(cmd[0], cmd);     
        perror("Erro ao listar arquivos do dir.\n");        
        exit(1);  
    }
    else{  
        wait(&status);
    }
}

void listarT()
{
    pid_t pid = fork();
    int status;

    if (pid == 0) { 
        char *cmd[]={"du", "-ka"}; 
        execvp(cmd[0], cmd);     
        perror("Erro ao listar arquivos do dir.\n");   
        exit(1);     
    }
    else{  
        wait(&status);              
    }
}

void contarQ()
{
    pid_t pid = fork();
    int status;

    if (pid == 0) { 
            
        struct dirent * de;
        int qtdFiles = 0;
        
        DIR *dr = opendir(".");        

        while ((de = readdir(dr)) != NULL) {
            if (de->d_type == DT_REG) {
                qtdFiles++;
            }
        }
        closedir(dr);        
        printf("\n%i",qtdFiles);         
    }else{
        wait(&status);
    }
}

void criaDir(char* nome)
{
    pid_t pid = fork();
    int status;

    if (pid == 0) { 
        char *cmd[]={"mkdir", nome}; 
        execvp(cmd[0], cmd);     
        perror("Erro ao criar dir.\n");   
        exit(1);     
    }
    else{  
        wait(&status);              
    }
}

void removeDir(char* nome)
{
    pid_t pid = fork();
    int status;

    if (pid == 0) { 
        char *cmd[]={"rmdir", nome}; 
        execvp(cmd[0], cmd);     
        perror("Erro ao remover dir.\n");   
        exit(1);     
    }
    else{  
        wait(&status);              
    }
}

void copia(char* local, char* destino)
{
    
    pid_t pid = fork();
    int status;

    if (pid == 0) { 
        int input_fd, output_fd;    /* Input and output file descriptors */
        ssize_t ret_in, ret_out;    /* Number of bytes returned by read() and write() */
        char buffer[BUFFERSIZE];  

        input_fd = open(local, O_RDONLY);
    
        /* Create output file descriptor */
        output_fd = open(destino, O_WRONLY | O_CREAT, 0644);    
    
        /* Copy process */
        while((ret_in = read (input_fd, &buffer, BUFFERSIZE)) > 0){
            ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
            if(ret_out != ret_in){
                /* Write error */
                perror("Erro ao copiar arquivo");                
            }
        }
    }else{
        wait(&status);
    }

}

void totalarq()
{
    pid_t pid = fork();
    int status;

    if (pid == 0) { 
        char *cmd[]={"du", "-sh"}; 
        execvp(cmd[0], cmd);     
        perror("Erro ao verificar dir.\n");   
        exit(1);     
    }
    else{  
        wait(&status);              
    }
}

void existe(char* nome)
{
    
    struct dirent * de;
    char* existe = "NÃO";
    
    DIR *dr = opendir(".");        
         
    while((de = readdir(dr)) != NULL){
        if(strcmp(de->d_name, nome) == 0){
            existe = "SIM";   
            break;       
        }
    }
    printf("%s", existe);
    closedir(dr);            
}
