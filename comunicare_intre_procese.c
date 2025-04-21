#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

#define LIMITA_TIMP 10 
#define MESAJ "La"
#define STOP "STOP"

// Variabile globale pentru stocarea statisticii caracterelor
int nr_total = 0;  
int nr_mari = 0;   
int nr_mici = 0;  

// Pipe-uri pentru comunicarea între procese
int pipe1[2]; 
int pipe2[2];  

/* 
 * handler - Funcție care gestionează semnalul SIGUSR1
 * 
 * Această funcție este apelată atunci când procesul fiu primește semnalul SIGUSR1,
 * actualizând statistica și trimițând-o înapoi procesului părinte.
 */
void handler(int sig) {
    char stats[100];
    snprintf(stats, sizeof(stats), "Total caractere: %d\nMari: %d\nMici: %d\n", nr_total, nr_mari, nr_mici);
    write(pipe2[1], stats, strlen(stats) + 1); 
}

/* 
 * citire_din_pipe - Funcție care citește caractere din pipe și actualizează statisticile
 * 
 * Această funcție este apelată de procesul fiu. Ea citește datele transmise de procesul părinte
 * prin pipe1, analizează caracterele și actualizează numărul total de caractere, precum și
 * numărul de caractere mari și mici.
 */
void citire_din_pipe() {
    char buffer[10];  
    while (1) {
        int nr = read(pipe1[0], buffer, sizeof(buffer) - 1);
        if (nr > 0) {
            buffer[nr] = '\0';  
            if (strcmp(buffer, STOP) == 0) {
                break; 
            }
            
            printf("Mesajul primit de fiu: %s\n", buffer);  
            
            for (int i = 0; i < nr; i++) {
                if (isupper(buffer[i])) {
                    nr_mari++;  
                } else if (islower(buffer[i])) {
                    nr_mici++;  
                }
            }
          
            nr_total += nr;
        } else {
            break;  
        }
    }
}

/* 
 * main - Funcția principală care controlează logica programului
 * 
 * În această funcție se creează pipe-urile pentru comunicare, se face fork pentru a crea un proces fiu,
 * și se gestionează interacțiunile între procese. Părintele trimite date, iar fiul le procesează și trimite
 * înapoi statistica. După 10 secunde, părintele închide procesul fiu și afișează statisticile.
 */
int main() {
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Eroare la crearea pipe-urilor\n");  
        exit(EXIT_FAILURE); 
    }

    pid_t pid = fork();  

    if (pid < 0) {
        perror("Eroare la fork\n");  
        exit(EXIT_FAILURE);  
    }

    if (pid == 0) {  
        signal(SIGUSR1, handler); 
        citire_din_pipe();  
        exit(EXIT_SUCCESS);  
    } else { 
        char stats[100];
        for (int timp_trecut = 0; timp_trecut < LIMITA_TIMP; timp_trecut++) {
            printf("Mesajul trimis de parinte: %s\n", MESAJ);  
            write(pipe1[1], MESAJ, strlen(MESAJ));  
            sleep(1);  
            kill(pid, SIGUSR1); 
            
            read(pipe2[0], stats, sizeof(stats));
            printf("Statistica de la fiu:\n%s", stats);
        }

        write(pipe1[1], STOP, strlen(STOP));
        wait(NULL); 
    }

    return 0;  
}
