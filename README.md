# CRUD Project
## This is 2020 OSS CRUD mini-project 

#### 이 CRUD project는 도서관 도서 관리 시스템이다. 도서 정보를 데이터로 가지고 있고 새로운 책의 정보를 추가하거나 업데이트, 삭제, 출력, 검색, 대출, 반납, 정렬 등의 메뉴들을 수행할 수 있다. 

### 1. To Make execute file 

make execute file : `make main`
 ```
 gcc -g -Wall -c books.c
 gcc -g -Wall -o main main.c books.o
 ```
make execute file with __debug__ : `make main_debug`
 ```
 gcc -g -Wall -DDEBUG -c books.c
 gcc -g -Wall -DDEBUG -o main main.c books.o
 ```

remove execute file : `make clean`
 ```
 rm *.o main
 ```
### 2. About main menu

  1. Add book : 새로운 도서정보 추가
  2. Search books by title : 책 제목으로 검색
  3. Search books by publish : 출판사이름으로 검색
  4. Search books by pages (under) : 책페이지 수로 검색(이하의 책들 모두 출력)
  5. Search books by author : 작가명으로 검색
  6. Search books by category : 카테고리로 검색
  7. Update book info : 책 정보 업데이트(수정)
  8. List of books : 전체 책 정보 리스트 출력
  9. Delete book : 책 정보 삭제
  10. Borrow book : 도서 대출
  11. Return book : 도서 반납
  12. Sort book list as publish year : 출판년도에 따라서 오름차순으로 정렬
  13. Load : 파일로부터 데이터 불러옴
  14. Save : 현재 데이터를 파일에 저장
  15. Book Number statistic : 총 도서수, 대출가능 도서수, 대출 불가능 도서수 출력
  
