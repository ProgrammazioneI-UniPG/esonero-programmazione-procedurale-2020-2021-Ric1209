// Riccardo Romani  Matricola: 313162


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int lunghezza(char stringa[]){
  int i = 0;
  while(stringa[i]!=EOF){
    i++;
  }
  return i;
}

int main()
{
  int c;
  int i;
  int scelta;
  char testo[128];
  char chiave[128];
  char output1[128]; //testo criptato
  char output2[128]; //testo decriptato
  char output_1[128]; //testo criptato senza caratteri speciali
  int l_t; //lunghezza testo
  int l_c; //lunghezza chiave
  int l_out; //lunghezza output1

  printf("Inserisci un testo da cifrare di massimo 128 caratteri, se ne inserisci uno piu lungo, i caratteri in eccesso verranno scartati:\n");
  fgets(testo, 128, stdin);


  l_t = strlen(testo);
  l_c = strlen(chiave);
  printf("La lunghezza del testo è:  %d\n", l_t);


  printf("Il testo inserito è:'%s'\n", testo);

  printf("\n\nAzioni possibili:\n-->[0] per uscire\n-->[1] per inserire una chiave\n-->[2] per generarla casualmente\n");
  scanf("%d", &scelta);

  while ((c = getchar()) != '\n' &&c != EOF);

    switch (scelta){
    case 0:
    printf("Ciao!\n");
    break;

    case 1:

    printf("Inserisci una chiave di lunghezza maggiore o uguale al testo: \n");
    fgets(chiave, 128, stdin);
    l_t = strlen(testo);
    l_c = strlen(chiave);

      while(l_c < l_t){
        printf("Chiave troppo corta, reinseriscila:\n");
        fgets(chiave, 128, stdin);

      }

         for (i=0; i<=l_t; i++){
         output1[i] = testo[i] ^ chiave[i];
    }
    for(i=0; i<32; i++){
      output_1[i] = output1[i] + 32;
    }

    printf("Il testo cifrato è: '%s'\n", output_1);
    printf("La chiave inserita è: '%s'\n", chiave);

    for (i=0; i<=l_t; i++){
      output2[i] = output1[i] ^ chiave[i];
    }

    printf("Il testo decriptato e: '%s'\n", output2);


    printf("Ciao!\n");
    break;

    case 2:
    srand (time(NULL));
    for(i=0; i<=l_t; i++){
      chiave[i] = (char) (rand() % 128);
    }
    chiave[128]='\0';
    printf("chiave: %s\n", chiave);
    for (i=0; i<=l_t; i++){
      output1[i] = testo[i] ^ chiave[i];
    }
    for(i=0; i<32; i++){
      output_1[i] = output1[i] + 32;
    }

    printf("Il testo criptato con chiave casuale è: '%s'\n", output_1);
    l_out = strlen(output1);
    for(i=0; i<=l_out; i++){
      output2[i] = output1[i] ^ chiave[i];
    }
    printf("Il testo decriptato è: '%s'\n", output2);
      break;


    default:
    while (scelta<0 || scelta>2){
    printf("Puoi digitare solo [0],[1],[2]!!\n");
    scanf("%d", &scelta);
  }
    break;
  }


return 0;
}
