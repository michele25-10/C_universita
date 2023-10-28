#include <stdio.h>

int main()
{
  // inizializzare le variabili necessarie
  int radiazione_ionizzante_diretta = 0;
  int radiazione_non_ionizzante_diretta = 0;
  int radiazione_non_ionizzante_indiretta = 0;
  int radiazione_ionizzante_indiretta = 0;
  double valore_campione;
  // Creare un ciclo infinito
  while (1)
  {
    printf("Valore campione (0 per terminare): ");
    scanf("%lf", &valore_campione);

    if (valore_campione == 0)
    {
      break;
    }
    
    if (valore_campione > 1)
    {
      radiazione_ionizzante_diretta += 1;
    }
    else if (valore_campione > 0)
    {
      radiazione_non_ionizzante_diretta += 1;
    }
    else if (valore_campione >= -1)
    {
      radiazione_non_ionizzante_indiretta += 1;
    }
    else if (valore_campione < -1)
    {
      radiazione_ionizzante_indiretta += 1;
    }
  }

  printf("\nCategorie di radiazione\n");
  printf("- Ionizzante diretta: %d\n", radiazione_ionizzante_diretta);
  printf("- Non ionizzante diretta: %d\n", radiazione_non_ionizzante_diretta);
  printf("- Non ionizzante indiretta: %d\n", radiazione_non_ionizzante_indiretta);
  printf("- Ionizzante indiretta: %d\n", radiazione_ionizzante_indiretta);

  return 0;
}
