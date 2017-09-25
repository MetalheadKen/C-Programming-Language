#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH  32
#define SPECIES 10000

typedef struct _Species {
    char name[LENGTH];
    int  count;
} Species;

void CountSpecies(Species *, char *, int *);
int Compare(const void *, const void *);

int main(int argc, char *argv[])
{
    int times;
    char string[LENGTH];

    fflush(stdin);
    while (~scanf("%d%*c", &times)) {
        while (times--) {
            int position = 0;
            float allSpeciesCount = 0.0;
            Species species[SPECIES];

            getchar();
            memset(&species, 0, sizeof(species));
            
            while (fgets(string, LENGTH, stdin) != NULL && strcmp(string, "\n")) {
                /* Removed the Newline characters */
                string[strlen(string) - 1] = '\0';

                CountSpecies(species, string, &position);
                allSpeciesCount++;
                
                qsort(species, SPECIES, sizeof(species[0]), Compare);
            }

            for (int i = 0; i < SPECIES; i++) {
                if (species[i].count)
                    printf("%s %.4f\n", species[i].name, species[i].count * 100.0 / allSpeciesCount);
            }

            printf("\n");
        }
    }

    return 0;
}

void CountSpecies(Species *species, char *string, int *position)
{
    Species *find = (Species *) bsearch(string, species, SPECIES, sizeof(species[0]), Compare);

    if (find == NULL) {
        strcpy(species[*position].name, string);
        species[*position].count = 1;
        ++*position;
    } else
        (*find).count++;
}

int Compare(const void *species1, const void *species2)
{
    Species *speciesA = (Species *) species1;
    Species *speciesB = (Species *) species2;

    return strcmp(speciesA->name, speciesB->name);
}
