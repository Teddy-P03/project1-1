# include "books.h"

// 함수원형
void add_book();
void search_title();
void search_publish();
void search_pages();
void search_author();
void update_book();
void list_book();
void delete_book();
void borrow_book();
void return_book();
void sort_year();
void load_file();
void save_file();
void statistic_book();
void search_category();

int main(){
	int menu;
	while(1){
		printf("\n<Select the menu>\n");
		printf("1. Add book\n2. Search books by title\n");
		printf("3. Search books by publish\n4. Search books by pages (under)\n");
		printf("5. Search books by author\n6. Search books by category\n7. Update book info\n");
		printf("8. List of books\n9. Delete book\n");
		printf("10. Borrow book\n11. return book\n12. Sort book list as publish year\n");
		printf("13. Load\n14. Save\n15. Book Number statistic\n0. Quit\n");
		printf("Enter a number: ");
		scanf("%d", &menu);
		getchar();
		printf("\n");
		switch(menu) {
			case 1:
				add_book();
				break;
			case 2:
				search_title();
				break;
			case 3:
				search_publish();
				break;
			case 4:
				search_pages();
				break;
			case 5:
				search_author();
				break;
			case 6:
				search_category();
				break;	
			case 7:
				update_book();
				break;
			case 8:
				list_book();
				break;
			case 9:
				delete_book();
				break;
			case 10:
				borrow_book();
				break;
			case 11:
				return_book();
				break;
			case 12:
				sort_year();
				break;
			case 13: 
				load_file();
				break;
			case 14:
				save_file();
				break;
			case 15: 
				statistic_book();
				break;
			case 0:
			default: 
				return 0; 
				
		}
	
	}
	return 0;
}

void add_book() {
	if (!book_available()){
		printf("There is no space for new books!!\n");
		return;	
	}
	char title[40], author[30], publisher[30], category[30];
	int year, pages;
	printf("Enter a new book's info.\n");
	printf("Title > ");  // 제목
	scanf("%[^\n]s", title);
	getchar();
	if (searchby_title(title)) {
		printf("That book already exist!\n");
		return;
	}
	printf("Author > "); //작가
	scanf("%[^\n]s", author);
	getchar();
	printf("Publisher > ");  // 출판사
	scanf("%[^\n]s", publisher);
	getchar();
	printf("Publish year > ");  // 출판년도
	scanf("%d", &year);
	printf("Category > ");  // 카테고리
	scanf("%s", category);
	printf("Page > ");  // 책 쪽수
	scanf("%d", &pages);
	Add(title, author, publisher, year, category, pages);
	printf("\n");

}

void search_title(){
	char title[40];
	printf("Enter a book title you want to search > ");
	scanf("%[^\n]s", title);
	getchar();	
	Books* p = searchby_title(title);
	if (p) {
		printf("Book's info\n");
		printf("Title: %s\n", get_title(p));
		printf("Author: %s\n", get_author(p));
		printf("Publisher: %s\n", get_publish(p));
		printf("Publish year: %d\n", get_year(p));
		printf("Category: %s\n", get_category(p));
		printf("Page: %d\n", get_pages(p));
		if (get_borrow(p)==0) printf("Borrow: 대출불가능\n");
		else if (get_borrow(p)==1) printf("Borrow: 대출가능\n");
	}
	else {
		printf("No such book!\n");
	}
	//printf("%s\n", book_to_string(p));
	
}
void search_category(){
	char category[30];
	printf("Enter a category you want to search > ");
	scanf("%s", category);
	Books* book[MAX_BOOKS];
	int size = searchby_category(book, category);
	printf("There are %d books.\n", size);
	for (int i=0;i<size;i++) {
		Books* p = book[i];
		printf("%d. %s\n", i+1, book_to_string(p));
	}
	printf("\n");

}
void search_publish(){
	char publ[30];
	printf("Enter a publisher you want to search > ");
	scanf("%[^\n]s", publ);
	getchar();
	
	Books* book[MAX_BOOKS];
	int size =searchby_publish(book, publ);
	printf("There are %d books.\n", size);
	for (int i=0;i<size;i++){
		Books* p = book[i];
		printf("%d. %s\n", i+1, book_to_string(p));
	}
	printf("\n");

}

void search_pages(){ 
	int num;
	printf("Enter page you want to search (under) > ");
	scanf("%d", &num);
	Books* book[MAX_BOOKS];
	int size = searchby_pages(book, num);
	for (int i=0;i<size;i++){
		Books *p = book[i];
		printf("%d. %s\n", i+1, book_to_string(p));
	}
	printf("\n");
}

void search_author(){
	char name[30];
	printf("Enter a author you want to search > ");
	scanf("%[^\n]s", name);
	getchar();
	Books* book[MAX_BOOKS];
	int size = searchby_author(book, name);
	printf("There are %d books.\n", size);
	for (int i=0;i<size;i++) {
		Books* p = book[i];
		printf("%d. %s\n", i+1, book_to_string(p));
	}	
	printf("\n");

}

void update_book(){
	char title[30], author[30], publisher[30], category[30];
	int year, pages;
	printf("Enter a title > ");
	scanf("%[^\n]s", title);	
	getchar();
	Books* p = searchby_title(title);
	if(p) {
		printf("Enter update info.\n");
		printf("Author > "); //작가
		scanf("%[^\n]s", author);
		getchar();
		printf("Publisher > ");  // 출판사
		scanf("%[^\n]s", publisher);
		getchar();
		printf("Publish year > ");  // 출판년도
		scanf("%d", &year);
		printf("Category > ");  // 카테고리
		scanf("%s", category);
		printf("Page > ");  // 책 쪽수
		scanf("%d", &pages);
		update(p, author, publisher, year, category, pages);
		printf("\n");
	}
	else {
		printf("No such book..!\n");
	}
}

void list_book(){
	printf("All Book's info.\n");
	int size = book_count();
	Books* book[MAX_BOOKS];
	book_get_all(book);
	for (int i=0;i<size;i++){
		Books* p = book[i];
		printf("%d. %s\n", i+1, book_to_string(p));
	}

}

void delete_book(){
	char title[30];
	printf("Enter a name > ");
	scanf("%[^\n]s", title);
	Books* p = searchby_title(title);
	if(p) {
        	delete(p);
        	printf("The book's info is deleted!\n");
    	}
  	else {
        	printf("No such book!\n");
    	}	

}

void borrow_book(){
	char title[30];
	printf("Enter title you want to borrow> ");
	scanf("%[^\n]s", title);
	Books* p = searchby_title(title);
	if (p) {
		if (rb(p)==1){
			borrow(p);
		}	
		else if (rb(p)==0){
			printf("You can't borrow book. Someone is borrowing..\n");
			return;
		}
		else {
			printf("No such book!\n");	
			return;
		}
		printf("You borrowed book: %s", title);
		printf("\n");
	}
	else {
		printf("No such book!\n");
	}
}

void return_book(){
	char title[30];
	printf("Enter title you want to return> ");
	scanf("%[^\n]s", title);
	Books* p = searchby_title(title);
	if (!p) {
		printf("No such book!\n");
		return;
	}
	if (rb(p)==0){
		returns(p);
	}	
	else if (rb(p)==1){
		printf("This book already returned.\n");
		return;
	}
	else {
		printf("No such book!\n");	
		return;
	}
	printf("You returned book: %s", title);
	printf("\n");
}

void sort_year(){
	printf("Sort book's info list as publish year!\n");
	Books* book[MAX_BOOKS];
	book_get_all(book);
	sort(book);
	printf("\n");	
	printf("(If you want to save, go to menu [14. Save] )\n");
} 

void load_file(){
	printf("All data will be deleted and new books's info will be reloaded.\n");
	printf("1.yes 0.No > ");
	int yn;
	scanf("%d", &yn);
	if (yn==0) return;
	book_init();
	
	FILE* f = fopen("books.txt", "r");
	char title[40], author[30], publisher[30], category[30];
	int year, page;
	while(!feof(f)) {
		if (!book_available()) {
 			printf("There is no space for new book\n");
			break;
		}
		int n = fscanf(f, "%s %s %d %s %d %[^\n]s", author, publisher, &year, category, &page, title); 
		if (n<6) break;
		Add(title, author, publisher, year, category, page); 
	}
	printf("%d books are read from file!\n", book_count());
	fclose(f);

}

void save_file(){
	FILE* f = fopen("books.txt","w");
	printf("All books saved.\n");
	int size = book_count();
	Books* book[MAX_BOOKS];
	book_get_all(book);
	for (int i=0;i<size;i++) {
		Books* p = book[i];
		fprintf(f, "%s\n", book_string_save(p));
	}
	fclose(f);
}

void statistic_book(){
	printf("This is book's info statistic report\n");
	int available=0, not=0; 
	int size = book_count();
	Books* book[MAX_BOOKS];
	book_get_all(book);
	for (int i=0;i<size;i++) {
		Books* p = book[i];
		if (get_borrow(p)==1) available++;
		else  not++; 
	}
	printf("Total books: %d\n", book_count());
	printf("Number of borrow available books: %d\n", available);
	printf("Number of borrow not available books: %d\n\n", not);

}



