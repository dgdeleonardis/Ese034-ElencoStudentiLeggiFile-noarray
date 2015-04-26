#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_STRLEN 30
#define MAX_FNAMELEN 25

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente s;
    FILE *puntaFile;
    char fileName[MAX_FNAMELEN+1];
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da cui legere : \n");
    scanf("%s", fileName);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    puntaFile = fopen(fileName, "rb");
    if(puntaFile == NULL) {
        printf("ERRORE: Impossibile aprire il file %s in lettura\n", fileName);
    }
    
    else {
        fread(&s, sizeof(studente), 1, puntaFile);
        while(!feof(puntaFile)) {
            printf("%s; %s; %d; %s\n", 
                    s.nome,
                    s.cognome,
                    s.eta,
                    s.classe);
        fread(&s, sizeof(studente), 1, puntaFile);
    }
    fclose(puntaFile);
    
    }
    return (EXIT_SUCCESS);
}