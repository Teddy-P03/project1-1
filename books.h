#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 30

typedef struct books_info {
	char title[40]; // 도서명
	char author[30]; // 작가명
	char publisher[30]; // 출판사
	int year; //출판 년도
	char category[30]; // 도서 카테고리
	int borrow; // 대출가능여부 (0: 대출중, 1: 대출가능)
	int pages; // 책페이지 수
} Books;

//라이브러리 함수 원형 정의
int book_count(); // 현재 저장된 도서의 수 가져오기
int book_available(); // 추가할 공간이 있는지
int book_first_available();
void update(Books* p, char *a, char* b, int n, char* c, int d); // 도서 정보 업뎃
void Add(char* a, char* b, char *c, int d, char* e, int f); //새로운 도서 추가
char* book_to_string(Books* p);
Books* searchby_title(char* n);  // 도서제목이 일치하는 도서 포인터 찾기
int searchby_publish(Books* a[], char* n); // 출판사 이름이 일치하는 도서 개수를 리턴
int searchby_pages(Books* a[], int n);  // 페이지 수로 도서 개수 리턴
int searchby_author(Books* a[], char* n);  // 작가이름 일치하는 도서개수 리턴
char* get_title(Books* p); // 책 제목
char* get_author(Books* p); // 책 작가
char* get_publish(Books* p); // 책 출판사
int get_year(Books* p); // 책 출판년도
char* get_category(Books* p); // 책 카테고리
int get_pages(Books* p); // 책 페이지
int get_borrow(Books* p); // 대출가능여부
void book_get_all(Books* a[]);
void book_init();
char* book_string_save(Books* p);

