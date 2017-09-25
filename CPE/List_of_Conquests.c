#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 75
#define TIMES  200

typedef struct _Country {
    int  times;
    int  counter[TIMES];
    char name[TIMES][LENGTH];
} Country;

void CountCountry(Country *, const char *, int);
void SortCountry(Country *);

int main(int argc, char *argv[])
{
    int  inputTimes;
    char string[LENGTH];
    
    fflush(stdin);
    while (~scanf("%d", &inputTimes)) {
        Country country = {.times = inputTimes};
        
        /* Get a Country's string and then flush the output buffer */
        for (int i = 0; i < inputTimes; i++) {
            scanf("%s %*[^\n]%*c", string);
            CountCountry(&country, string, i);
        }

        SortCountry(&country);

        for (int i = 0; i < inputTimes; i++)
            if (country.name[i][0] != '\0')
                printf("%s %d\n", country.name[i], country.counter[i] + 1);
    }

    return 0;
}

void CountCountry(Country *country, const char *string, int position)
{
    int i = 0;
    while (i < country->times && strcmp(country->name[i], string))
        i++;

    if (i >= country->times)
        strcpy(country->name[position], string);
    else
        country->counter[i]++;
}

void SortCountry(Country *country)
{
    for (int i = 0; i < country->times - 1; i++) {
        for (int j = 0; j < country->times - 1 - i; j++) {
            if (strcmp(country->name[j], country->name[j + 1]) > 0) {
                /* Swap the name of country and the times of country */
                char ptrTemp[TIMES];
                strcpy(ptrTemp, country->name[j + 1]);
                strcpy(country->name[j + 1], country->name[j]);
                strcpy(country->name[j], ptrTemp);

                int temp = country->counter[j + 1];
                country->counter[j + 1] = country->counter[j];
                country->counter[j] = temp;
            }
        }
    }
}
