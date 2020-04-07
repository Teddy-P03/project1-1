#include "books.h"

Books* book[MAX_BOOKS];

int _count = 0;

int book_count(){
	return _count;
}

int book_available(){
	int i;
	for (i=0;i<MAX_BOOKS;i++){
		if (book[i]==NULL) return 1;
	}
	return 0;
}

int book_first_available(){
	int i;
   	for(i=0; i<MAX_BOOKS; i++){
        	if(book[i]==NULL) return i;
   	 }
   	 return -1;
}

void Add(char* a, char* b, char* c, int d, char* e, int f){
	int index = book_first_available();
	book[index] = (Books*)malloc(sizeof(Books));
	Books* p = book[index];

	strcpy(p->title, a);
	strcpy(p->author, b);
	strcpy(p->publisher, c);
	p->year = d;
	strcpy(p->category, e);
	p->pages = f;
	p->borrow = 1;
	_count++; 
#if DEBUG
	printf("[DEBUG] Add Book : %s\n", p->title);
#endif 
}

char* book_to_string(Books* p){
	static char str[100];
	if (p->borrow==0) {
		sprintf(str, "[%s] | %s | %s (%d) | %s | %d | 대출불가능\n", p->title, p->author, p->publisher, p->year, p->category, p->pages);
	}
	else if (p->borrow==1) {
		sprintf(str, "[%s] | %s | %s(%d) | %s | %d | 대출가능\n", p->title, p->author, p->publisher, p->year, p->category, p->pages);
	}
#if DEBUG 
	printf("[DEBUG] sort book's info: %s\n", p->title);
#endif
	return str;
}

Books* searchby_title(char* n){
	int i;
	for (i=0;i<_count;i++) {
		if (book[i]!=NULL && strncmp(book[i]->title, n, 3)==0) return book[i];
#if DEBUG
		printf("[DEBUG] search book by title: %s\n", book[i]->title);
#endif
	}
	return NULL;
}

int searchby_publish(Books* a[], char* n){
	int i, c=0;
	for(i=0;i<_count;i++){
		if (book[i]!=NULL && (strncmp(book[i]->publisher, n,3))==0){
			a[c] = book[i];
			c++;
		}
	}
	return c;
}

int searchby_pages(Books* a[], int n){
	int i, c=0;
	for (i=0;i<_count;i++){
		if (book[i]!=NULL && (book[i]->pages <= n)) {
			a[c] = book[i];
			c++;
		}
	}
	return c;
}


int searchby_author(Books* a[], char* n){
	int i, c=0;
	for (i=0;i<_count;i++){
		if (book[i]!=NULL && strcmp(book[i]->author, n)==0) {
			a[c] = book[i];
			c++;
		}
	}	
	return c;
}

char* get_title(Books* p) {
#if DEBUG
	printf("[DEBUG] Get title: %s\n", p->title);
#endif
	return p->title;
}

char* get_author(Books* p) {
#if DEBUG
	printf("[DEBUG] Get author: %s\n", p->author);
#endif
	return p->author;
}

char* get_publish(Books* p){
#if DEBUG
	printf("[DEBUG] Get publisher: %s\n", p->publisher);
#endif
	return p->publisher;
}

int get_year(Books* p) {
#if DEBUG
	printf("[DEBUG] Get publish year: %d\n", p->year);
#endif
	return p->year;
}

char* get_category(Books* p){
#if DEBUG
	printf("[DEBUG] Get category: %s\n", p->category);
#endif
	return p->category;
}

int get_pages(Books* p) {
#if DEBUG
	printf("[DEBUG] Get pages: %d\n", p->pages);
#endif
	return p->pages;
}

int get_borrow(Books* p){
	if (p->borrow == 0) return 0;
	else return 1;
}

void book_init(){
	int i;
	for (i=0;i<MAX_BOOKS;i++){
		if (book[i]!=NULL){
			free(book[i]);
		}
		book[i] = NULL;
	}
	_count=0;
#if DEBUG
	printf("[DEBUG] Delete all books\n");
#endif

}

char* book_string_save(Books* p){
	static char str[200];
#if DEBUG
	printf("[DEBUG] Will save book's info string to file: %s\n", p->title);
#endif
	sprintf(str, "%s %s %d %s %d %s", p->author, p->publisher, p->year, p->category, p->pages, p->title);
	return str;
}

void book_get_all(Books* a[]){
	int i, c=0;
	for (i=0;i<MAX_BOOKS;i++){
		if (book[i]!=NULL){
			a[c]=book[i];
			c++;
		}
	}	
#if DEBUG
	printf("[DEBUG] Get All Books\n");
#endif
}


