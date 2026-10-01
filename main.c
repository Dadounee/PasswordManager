#include <stdio.h>
#include <stdlib.h>
#include "userInputs.h"

char    **getPass(void)
{
    static char    **passwords;
    
    if (!passwords)
    {
        passwords = malloc(2 * sizeof(char *));
        if (!passwords)
            fprintf(stderr, "Warning: Password malloc failed\n");
    }

    return (passwords);
}

int main(void)
{
    int    *userChoice;

    while(true)
    {    
        printf("==== Welcome to password manager ====\n\t[1.]See Passwords\n\t[2.]Add Password\n\t[3.]Remove Password\n\t[4.]Quit\n");
        userChoice = inputTreatment("%d");
        
        switch (*userChoice)
        {
            case 1:
                /* code */
                break;
            
            case 2:
                /* code */
                break;

            case 3:
                /* code */
                break;

            case 4:
                break;
        }
        if (*userChoice == 4)
            break ;
        system("cls");
    }
    return (0);
}
