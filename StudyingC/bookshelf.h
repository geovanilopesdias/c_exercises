#include <stdio.h>
#include <string.h>
#include <regex.h>

typedef struct book{
  char title[101], author[51], publisher[51];
  int edition_year, pages;
} Book;

Book newBook(){
  Book b;
  printf ("Title (up to 100 letters): ");
  fgets(b.title, sizeof(b.title), stdin);
  b.title[strcspn(b.title, "\n")] = '\0';
  //scanf("%s", &b.title); getchar();
  
  printf("Author (up to 50 letters): ");
  fgets(b.author, sizeof(b.author), stdin);
  b.author[strcspn(b.author, "\n")] = '\0';
  
  //scanf("%s", &b.author); getchar();
  printf("Publisher: ");
  fgets(b.publisher, sizeof(b.publisher), stdin);
  b.publisher[strcspn(b.publisher, "\n")] = '\0';
  //scanf("%s", &b.publisher); getchar();
  
  printf("Year of the printed edition: ");
  scanf("%i", &b.edition_year); getchar();
  printf("How many pages: ");
  scanf("%i", &b.pages); getchar();
  
  return b;
}


void showBook(Book b){
  printf("%s, by %s. Published by %s in %d; %d p.\n", b.title, b.author, b.publisher, b.edition_year, b.pages);
}


void showLibraryBookshelf(Book *bs, int bsLimit){
  printf("***\n\tExhibiting the library's bookshelf:\n");
  for(int i = 0; i < bsLimit; i++) showBook(bs[i]);
}


void fillBookshelf(Book *bs, int bsLength, int *lastIndex){
  if (*lastIndex == bsLength-1) printf("\n***\nSorry: the bookshelf is full!\n");
  else{
    int i; char answer = 'N';
    for(i = *lastIndex; i < bsLength; i++){
      printf("\n***\nBook registration:\n");
      bs[i] = newBook();
      if (i != bsLength-1) printf("***\nDo you want to register one more? (Type n or N to stop, any other to continue): ");
      else printf("WARNING: the bookshelf is full!");
      answer = getchar();
      if (answer == 'n' || answer == 'N') break;
    }
    *lastIndex = --i;
  }
  
}


/*
* Returns 1 if the pattern match or 0 instead.
* From pubs.opengroup.org/onlinepubs/009695399/functions/regcomp.html*/
int match(const char *string, char *pattern){
  int status;
  regex_t re;
  if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
    return(0);
  }
  status = regexec(&re, string, (size_t) 0, NULL, 0);
  regfree(&re);
  if (status != 0) {
    return(0);
  }
  return(1);
}


void findBooks(Book *bs, int bsSize, const char *searchType){
  int bookFound, noBookFound = 1;
  char userSearch[101];
  printf("Type the book's %s: ", searchType);
  fgets(userSearch, sizeof(userSearch), stdin);
  userSearch[strcspn(userSearch, "\n")] = '\0'; 

  printf("*****\nResult when searching by '%s':\n", userSearch);
  for (int i = 0; i < bsSize; i++){
    if(strcmp(searchType, "title") == 0) bookFound = match(bs[i].title, userSearch);
    else bookFound = match(bs[i].author, userSearch);
    
    if(bookFound){
      noBookFound = 0;
      showBook(bs[i]);
    }
  }  
  if(noBookFound) {
    printf("***\n\tSorry, no books were found when searching for '%s'.\n", userSearch);
  }
  
}


void findBooksByYear(Book *bs, int bsSize){
  int search = 0;
  do {
    printf("Type the book year of edition: ");
    scanf("%d", &search); getchar();
    if (search < 1900 || search > 2023) {
      printf("Invalid year value inserted. Try again!\n");
    }
  } while(search < 1900 || search > 2023);

  for (int i = 0; i < bsSize; i++){
    if(bs[i].edition_year == search) {
      printf("%s, by %s. Published by %s; %d p.\n", bs[i].title, bs[i].author, bs[i].publisher, bs[i].pages);
    }
  }
}


void showLibraryMenu(){
  printf("=====\n\n\tChoose one of the options below:\n-----\n");
  printf("0: Exhibit bookshelf\n");
  printf("1: Register a book\n");
  printf("2: Search book by title\n");
  printf("3: Find books of an author\n");
  printf("4: Search book by year of edition\n");
  printf("5: Exit\n-----\n");
}

void mainLibraryLoop(int bsSize){
  int userOption = -1, lastIndex = 0;
  Book bookshelf[bsSize];
  do {
    showLibraryMenu();
    do {
      printf("Your option (0 up to 5): ");
      scanf("%d", &userOption); getchar();
      if(userOption < 0 || userOption > 5) printf("Invalid option. Try again!\n");
    } while (userOption < 0 || userOption > 5);
    
    if(userOption == 0){
      if(lastIndex != 0) showLibraryBookshelf(bookshelf, lastIndex+1);
      else printf("***\n\tThe bookshelf is empty: there's no book to show.\n");
    }
      
    else if (userOption == 1){
      fillBookshelf(&bookshelf, bsSize, &lastIndex);
    }
      
    else if (userOption == 2){
      findBooks(bookshelf, bsSize, "title");
    }
      
    else if (userOption == 3){
      findBooks(bookshelf, bsSize, "author");
    }
      
    else if (userOption == 4){ // Option 4:
      findBooksByYear(bookshelf, bsSize);
    }
      
    else { // Option 5:
      printf("Exiting the program...");
    }
    
  } while (userOption != 5);
}