/************************************************************************************************************************************/
/*                                                                                                                                  */
/*       Library Record System                                                                                                      */
/*       ---------------------                                                                                                      */
/*       Author: Conner McCabe                                                                                                      */
/*                                                                                                                                  */
/*       This library record system is used to dynamically allow users to create their own database of records containing           */
/*       3 different forms of identification of a book, the title, author and ISBN of the book. The user will also be able          */
/*       to search and display any record at will using either the books isbn number or the books title. The user will also         */
/*       be able to display every record stored in the library of books. The records are displayed in 3 neat columns for ease       */
/*       of use.                                                                                                                    */
/*                                                                                                                                  */
/************************************************************************************************************************************/

/* These are the various includes which are required for this system as they hold the functions which are required to follow out certain methods. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is the structure I have created to hold all of the data being stored within the database */
struct bookType
{
    char isbn[15];
    char title[30];
    char author[30];
    
};
/* This function is used to swallow unwanted data stored in the buffer so that it is not passed onto the next line */
void eatExtraInput()
{
    int c;
    while ((c = getchar()) != '\n');
}
/***********************************************************************************************************************************************/
/*                                                                                                                                             */
/*                       displayAllRecords Function                                                                                            */
/*                       --------------------------                                                                                            */
/*                                                                                                                                             */
/*                       This function is used to display all records of books stored in the binary file.                                      */
/*                                                                                                                                             */
/*                                                                                                                                             */
/***********************************************************************************************************************************************/
void displayAllRecords()
{
    struct bookType book;
    int i = 0;
    FILE *BookFile = fopen("BookFile.bin", "rb+");
    rewind(BookFile);
    printf("\n*********************************************************************************************************");
    printf("\n*                      Title                       |             Author             |        ISBN       *");
    printf("\n*--------------------------------------------------*--------------------------------*-------------------*");
    while(fread(&book, sizeof(struct bookType), 1, BookFile))
    {
        /* This if statement is used to check to see if the title of each record contains the newline character and if so, it then removes it*/
        if (book.title[strlen(book.title) - 1] == '\n')
        {
            book.title[strlen(book.title) - 1] = '\0';
        }
        /* Display the record's title */
        printf("\n* %s", book.title);
        
        /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
        if(strlen(book.title) < 50)
        {
            
            while((i+strlen(book.title)) < 49)
            {
                i++;
                printf(" ");
            }
            i = 0;
        }
        
        /**************************************/
        /* This if statement is used to check to see if the author of each record contains the newline character and if so, it then removes it*/
        if (book.author[strlen(book.author) - 1] == '\n')
        {
            book.author[strlen(book.author) - 1] = '\0';
        }
        
        /* Display the record's author */
        printf("| %s", book.author);
        
        /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
        if(strlen(book.author) < 30)
        {
            
            while((i+strlen(book.author)) < 31)
            {
                i++;
                printf(" ");
            }
            i = 0;
        }
        
        /**************************************/
        
        /* This if statement is used to check to see if the isbn of each record contains the newline character and if so, it then removes it */
        if (book.isbn[strlen(book.isbn) - 1] == '\n')
        {
            book.isbn[strlen(book.isbn) - 1] = '\0';
        }
        
        /* Display the record's isbn */
        printf("| %s ", book.isbn);
        
        /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
        if(strlen(book.isbn) < 30)
        {
            
            while((i+strlen(book.isbn)) < 17)
            {
                i++;
                printf(" ");
            }
            i = 0;
            
        }
        printf("*");
        printf("\n*--------------------------------------------------*--------------------------------*-------------------*");
    }
    /* This line is used to close the file that the BookFile pointer is pointing to. */
    fclose(BookFile);
    printf("\n\n");
    /* This line asks the user to press any key to continue. */
    system("PAUSE");
    
}
/***********************************************************************************************************************************************/
/*                                                                                                                                             */
/*                       searchByTitle Function                                                                                                */
/*                       ----------------------                                                                                               */
/*                                                                                                                                             */
/*                       This function is used to search the bin file for a book on record by the name of                                      */
/*                       the Author.                                                                                                           */
/*                                                                                                                                             */
/*                                                                                                                                             */
/***********************************************************************************************************************************************/
void searchByTitle()
{
    struct bookType book;
    int i = 0;
    char name[30];
    printf("Enter a book Title to search: ");
    /* This is used to retrieve the Title to search by from the user */
    fgets(name, 30, stdin);
    FILE *BookFile = fopen("BookFile.bin", "rb+");
    rewind(BookFile);
    int counter = 1;
    printf("\n*********************************************************************************************************");
    printf("\n*                      Title                       |             Author             |        ISBN       *");
    printf("\n*--------------------------------------------------*--------------------------------*-------------------*");
    while(fread(&book, sizeof(struct bookType), 1, BookFile))
    {
        if(strcmp(book.title, name) == 0)
        {
            
            counter = strcmp(book.title, name);
            
            /* This if statement is used to check to see if the title of each record contains the newline character and if so, it then removes it*/
            if (book.title[strlen(book.title) - 1] == '\n')
            {
                book.title[strlen(book.title) - 1] = '\0';
            }
            
            /* Display the record's title */
            printf("\n* %s", book.title);
            
            /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
            if(strlen(book.title) < 50)
            {
                while((i+strlen(book.title)) < 49)
                {
                    i++;
                    printf(" ");
                }
                i = 0;
            }
            
            /**************************************/
            /* This if statement is used to check to see if the title of each record contains the newline character and if so, it then removes it*/
            if (book.author[strlen(book.author) - 1] == '\n')
            {
                book.author[strlen(book.author) - 1] = '\0';
            }
            
            /* Display the record's author */
            printf("| %s", book.author);
            
            /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
            if(strlen(book.author) < 30)
            {
                
                while((i+strlen(book.author)) < 31)
                {
                    i++;
                    printf(" ");
                }
                i = 0;
            }
            
            /**************************************/
            /* This if statement is used to check to see if the title of each record contains the newline character and if so, it then removes it*/
            if (book.isbn[strlen(book.isbn) - 1] == '\n')
            {
                book.isbn[strlen(book.isbn) - 1] = '\0';
            }
            
            /* Display the record's isbn */
            printf("| %s ", book.isbn);
            
            /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
            if(strlen(book.isbn) < 30)
            {
                
                while((i+strlen(book.isbn)) < 17)
                {
                    i++;
                    printf(" ");
                }
                i = 0;
                
            }
            printf("*");
            printf("\n*--------------------------------------------------*--------------------------------*-------------------*");
        }
    }
    /* This line is used to close the file that the BookFile pointer is pointing to. */
    fclose(BookFile);
    if(counter == 1)
    {
        printf("\n* No books were found, sorry.                                                                           *");
        printf("\n*-------------------------------------------------------------------------------------------------------*");
    }
    /* This line is used to close the file that the BookFile pointer is pointing to. */
    fclose(BookFile);
    
    printf("\n\n");
    /* This line asks the user to press any key to continue. */
    system("PAUSE");
    
}

/***********************************************************************************************************************************************/
/*                                                                                                                                             */
/*                       searchByISBN Function                                                                                                 */
/*                       ---------------------                                                                                                 */
/*                                                                                                                                             */
/*                       This function is used to search the bin file for a book on record by the name of                                      */
/*                       the Author.                                                                                                           */
/*                                                                                                                                             */
/*                                                                                                                                             */
/***********************************************************************************************************************************************/
void searchByISBN()
{
    struct bookType book;
    int i = 0;
    char name[15];
    printf("Enter a book ISBN to search: ");
    fgets(name, 15, stdin);
    if(name[strlen(name)-1] != '\n')
    {
        eatExtraInput();
    }
    FILE *BookFile = fopen("BookFile.bin", "rb+");
    rewind(BookFile);
    int counter = 1;
    printf("\n*********************************************************************************************************");
    printf("\n*                      Title                       |             Author             |        ISBN       *");
    printf("\n*--------------------------------------------------*--------------------------------*-------------------*");
    while(fread(&book, sizeof(struct bookType), 1, BookFile))
    {
        if(strcmp(book.isbn, name) == 0)
        {
            counter = strcmp(book.isbn, name);
            
            /* This if statement is used to check to see if the title of each record contains the newline character and if so, it then removes it*/
            if (book.title[strlen(book.title) - 1] == '\n')
            {
                book.title[strlen(book.title) - 1] = '\0';
            }
            
            /* Display the record's title */
            printf("\n* %s", book.title);
            
            /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
            if(strlen(book.title) < 50)
            {
                
                while((i+strlen(book.title)) < 49)
                {
                    i++;
                    printf(" ");
                }
                i = 0;
            }
            
            /**************************************/
            
            /* This if statement is used to check to see if the title of each record contains the newline character and if so, it then removes it*/
            if (book.author[strlen(book.author) - 1] == '\n')
            {
                book.author[strlen(book.author) - 1] = '\0';
            }
            
            /* Display the record's author */
            printf("| %s", book.author);
            
            /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
            if(strlen(book.author) < 30)
            {
                
                while((i+strlen(book.author)) < 31)
                {
                    i++;
                    printf(" ");
                }
                i = 0;
            }
            
            /**************************************/
            
            /* This if statement is used to check to see if the title of each record contains the newline character and if so, it then removes it*/
            if (book.isbn[strlen(book.isbn) - 1] == '\n')
            {
                book.isbn[strlen(book.isbn) - 1] = '\0';
            }
            
            /* Display the record's isbn */
            printf("| %s ", book.isbn);
            
            /*This if statement is used to dynamically change the width of the column according to the size of the string by printing the space character for however many characters the column has to match. */
            if(strlen(book.isbn) < 30)
            {
                
                while((i+strlen(book.isbn)) < 17)
                {
                    i++;
                    printf(" ");
                }
                i = 0;
                
            }
            printf("*");
            printf("\n*--------------------------------------------------*--------------------------------*-------------------*");
        }
    }
    fclose(BookFile);
    if(counter == 1)
    {
        printf("\n* No books were found, sorry.                                                                           *");
        printf("\n*-------------------------------------------------------------------------------------------------------*");
    }
    /* This line is used to close the file that the BookFile pointer is pointing to. */
    fclose(BookFile);
    
    printf("\n\n");
    /* This line asks the user to press any key to continue. */
    system("PAUSE");
}

/***********************************************************************************************************************************************/
/*                                                                                                                                             */
/*                       searchMethod Function                                                                                                 */
/*                       ---------------------                                                                                                 */
/*                                                                                                                                             */
/*                       This function is used to determine which part of the book they wish to search by, whether it be                       */
/*                       the Author's name, the title of the book or the ISBN number.                                                          */
/*                                                                                                                                             */
/*                                                                                                                                             */
/***********************************************************************************************************************************************/
void searchMethod()
{
    char choice[2];
    int intChoice;
    /* This loop is used to make sure that the user cannot enter bad data */
    do
    {
        printf("         This is the search section of the software        \n");
        printf("-----------------------------------------------------------\n");
        printf("* Please make a selection from one of the options below:  *\n");
        printf("-----------------------------------------------------------\n");
        printf("*                                                         *\n");
        printf("*               1. Search by book title                   *\n");
        printf("*                                                         *\n");
        printf("*               2. Search by ISBN                         *\n");
        printf("*                                                         *\n");
        printf("*               3. Exit to main menu                      *\n");
        printf("*                                                         *\n");
        printf("*                                                         *\n");
        printf("-----------------------------------------------------------\n");
        printf("\nPlease enter a number from 1 - 3 to select an option from the search type menu: ");
        /* This resets the choice for each loop back */
        if(choice[0] != 0)
        {
            choice[0] = 0;
        }
        /* This statement reads in the user's choice */
        fgets(choice, 2, stdin);
        
        /* This if statement is used to determine whether the user has entered more than the character limit and if so it gets rid of the excess data */
        if(choice[strlen(choice)-1] != '\n')
        {
            eatExtraInput();
        }
        intChoice = atoi(&choice[0]);
        
        /* This switch statement is used to call the appropriate function based on the user's input */
        switch(intChoice)
        {
            case 1:
                searchByTitle();
                break;
            case 2:
                searchByISBN();
                break;
            case 3:
                return 0;
                break;
            default :
                printf("*Please enter a valid condition! \n");
                break;
        }
        
    }while(intChoice != 1 || intChoice != 2 || intChoice != 3 );
    mainMenu();
}

/***********************************************************************************************************************************************/
/*                                                                                                                                             */
/*                       addBook Function                                                                                                      */
/*                       ----------------                                                                                                      */
/*                                                                                                                                             */
/*                       This function is used to add new books to the bin file, the user must know the book's                                 */
/*                       Title, Author and ISBN number in order to add a book successfully.                                                    */
/*                                                                                                                                             */
/*                                                                                                                                             */
/***********************************************************************************************************************************************/
void addBook()
{
    struct bookType book;
    char isbn[15];
    int writeAnotherCounter;
    FILE *BookFile;
    /* This if statement is used to check to see if the binary file already exists, if so it then sets up the pointer, and if not it creates the file and writes a dummy record. */
    if(fopen("BookFile.bin", "rb"))
    {
        BookFile = fopen("BookFile.bin", "ab+");
        printf("\nBinary library exists, continue...\n");
    }
    else
    {
        BookFile = fopen("BookFile.bin", "ab+");
        strcpy(book.isbn, "             ");
        strcpy(book.title, " ");
        strcpy(book.author, " ");
        fwrite(&book, sizeof(book), 1, BookFile);
    }
    int i = 0;
    printf("Welcome to the add book section of this software.\n");
    
    printf("\nPlease enter the book's ISBN number: ");
    /* This line gets the ISBN number from the user */
    fgets(isbn, 15, stdin);
    
    /* This if statement is used to swallow excess data from the buffer if the user enters too many characters */
    if(isbn[strlen(isbn)-1] != '\n')
    {
        eatExtraInput();
    }
    /* This if statment makes sure that the ISBN is the right length and if so it proceeds with the write to the file, if not it outputs an error message */
    if(strlen(isbn) == 14)
    {
        rewind(BookFile);
        /* This loop is used to read in each of the records held in the file */
        while(fread(&book, sizeof(struct bookType), 1, BookFile))
        {
            if(strcmp(book.isbn, isbn) == 0)
            {
                printf("*There is already a record with that isbn.");
                return 0;
            }
            else
            {
                strcpy(book.isbn, isbn);
            }
        }
        fclose(BookFile);
        BookFile = fopen("BookFile.bin", "ab+");
        printf("\nPlease enter the name of the book: ");
        /* This line is used to get the title of the book from the user */
        fgets(book.title, 30, stdin);
        if(book.title[strlen(book.title)-1] != '\n')
        {
            eatExtraInput();
        }
        
        printf("\nPlease enter the name of the book's author: ");
        /* This line is used to get the author of the book from the user */
        fgets(book.author, 30, stdin);
        if(book.author[strlen(book.author)-1] != '\n')
        {
            eatExtraInput();
        }
        /* This if statement is used to make sure that the binary file is properly opened and if not it outputs an error, and if it's successful it continues with the write */
        if(!BookFile)
        {
            printf("Error opening BinFile.bin");
        }
        else
        {
            /* This if statement is used to tell if the data was successfully written to the binary file and if so it outputs a success message and if not it outputs an error message */
            if(fwrite(&book, sizeof(struct bookType), 1, BookFile))
            {
                printf("\nThis is the isbn number: %s", book.isbn);
                printf("\nThis is the name of the book: %s", book.title);
                printf("\nThis is the author's name: %s", book.author);
                printf("\nRecord added successfully!");
                fclose(BookFile);
            }
            else
            {
                printf("There was an error creating your new record, please alert an administrator...");
            }
        }
    }
    else
    {
        printf("\n*Please enter an isbn with 13 characters.\n");
    }
    fclose(BookFile);
    printf("\n\n");
    /* This line asks the user to press any key to continue. */
    system("PAUSE");
    mainMenu();
}
/***********************************************************************************************************************************************/
/*                                                                                                                                             */
/*                       mainMenu Function                                                                                                         */
/*                       -----------------                                                                                                     */
/*                                                                                                                                             */
/*                       This function is used to determine what the user wants to do, whether they want to                                    */
/*                       search for a book, add one or just exit the program, this is where it is decided.                                     */
/*                                                                                                                                             */
/*                                                                                                                                             */
/***********************************************************************************************************************************************/
void mainMenu()
{
    char choice[2];
    int intChoice;
    /* This loop is used to make sure that the user cannot enter bad data */
    do
    {
        printf("\n\nWelcome to the library system developed by Conner McCabe.  \n");
        printf("-----------------------------------------------------------\n");
        printf("* Please make a selection from one of the options below:  *\n");
        printf("-----------------------------------------------------------\n");
        printf("*                                                         *\n");
        printf("*               1. Search for a Book                      *\n");
        printf("*                                                         *\n");
        printf("*               2. View all records on file               *\n");
        printf("*                                                         *\n");
        printf("*               3. Add a Book to the Library              *\n");
        printf("*                                                         *\n");
        printf("*               4. Exit the Program                       *\n");
        printf("*                                                         *\n");
        printf("*                                                         *\n");
        printf("-----------------------------------------------------------\n");
        printf("\nPlease enter a number from 1 - 3 to select an option from the main menu: ");
        /* This resets the choice for each loop back */
        if(choice[0] != 0)
        {
            choice[0] = 0;
        }
        /* This statement reads in the user's choice */
        fgets(choice, 2, stdin);
        
        /* This if statement is used to determine whether the user has entered more than the character limit and if so it gets rid of the excess data */
        if(choice[strlen(choice)-1] != '\n')
        {
            eatExtraInput();
        }
        intChoice = atoi(&choice[0]);
        
        /* This switch statement is used to call each function based on the user's input */
        switch(intChoice)
        {
            case 1:
                searchMethod();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                addBook();
                break;
            case 4:
                exit(0);
                break;
            default :
                printf("*Please enter a valid condition! \n");
                break;
        }
        
    }while(intChoice != 1 || intChoice != 2 || intChoice != 3 );
}
/***********************************************************************************************************************************************/
/*                                                                                                                                             */
/*                       main Function                                                                                                         */
/*                       -------------                                                                                                         */
/*                                                                                                                                             */
/*                       This function is used to call the mainMenu function                                                                   */
/*                                                                                                                                             */
/*                                                                                                                                             */
/***********************************************************************************************************************************************/
int main(int argc, char *argv[])
{
    
    /* This calls the mainMenu function and starts the programs main role */
    mainMenu();
    system("pause");
    return 0;
    
}
