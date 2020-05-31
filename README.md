# СУСИ
**Информационна система за обслужване на студенти.**

Програмата работи с команди от конзолата. Започва без начални специалности, студенти и курсове. Такива могат да се добавят ръчно или като се отвори файлът **start.susi** с команда **open**. Без да се отвори файл не може да се използва.

Във файлът се съдържа следната информация:
| Специалност  | 
| ------------- |
| ComputerScience  | 
| SoftwareEngineering  | 

| Студент  |  Специалност  | Група | Факултетен номер |
| ----- | ----- |----- | ----- |
| Petko  |  ComputerScience  | 7 | 1 |
| Pavel  |  SoftwareEngineering  | 2 | 2 |
| Ivan  |  ComputerScience  | 7 | 3 |
| Krisi  |  SoftwareEngineering  | 1 | 4 |

| Учебна дисциплина  |  Специалност  | Задължителна | Нужен курс |
| ----- | ----- |----- | ----- |
| Program1  |  ComputerScience  | true | 1 |
| Program2  |  ComputerScience  | true | 2 |
| Program3  |  ComputerScience  | true | 3 |
| Program4  |  ComputerScience  | true | 4 |
| FreeP  |  ComputerScience  | false | 1 |
| ProgramX  |  SoftwareEngineering  | true | 1 |
| Program1  |  SoftwareEngineering  | true | 1 |

**Отваряне на файл**
```
>open start.susi //open <location/name>
Successfully opened start.susi
```
**Записване на студент**
```
>enroll 5 ComputerScience 3 Hristina //enroll <fn><program><group><name>
Successfully enrolled Hristina
```
Така успешно беше записана Христина в специалност Компютърни науки, група 3, факултетен номер 5.

**Записване на изпити и преминаване към следваща година**
```
>enrollin 5 Program1 //enrollin <fn><course>
Student Hristina is now enrolled in Program1.

>advance 5 //advance <fn>
Successfully advanced Hristina

>enrollin 5 Program3 
This course is not for the intended year.
```
**Пример за протокол**
```
>enrollin 1 Program1 //enrollin <fn><course>
Student Petko is now enrolled in Program1.

>enrollin 2 Program1
Student Pavel is now enrolled in Program1.

>enrollin 3 Program1
Student Ivan is now enrolled in Program1.

>enrollin 4 Program1
Student Krisi is now enrolled in Program1.

>addgrade 3 Program1 5 //addgrade <fn><course><grade>
Successfully added grade!

>addgrade 1 Program1 4
Successfully added grade!

>addgrade 4 Program1 6
Successfully added grade!

>addgrade 2 Program1 3
Successfully added grade!

>protocol Program1
For program: ComputerScience
1, 3
For program: SoftwareEngineering
2, 4
```
**Пример за академична справка**
```
>addcourse ComputerScience T1 true 1 //addcourse <program><course><isMandatory><year>
Successfully added course T1 for program.

>addcourse ComputerScience T2 true 1
Successfully added course T2 for program.

>addcourse ComputerScience T3 true 1
Successfully added course T3 for program.

>addcourse ComputerScience T4 true 1
Successfully added course T4 for program.

>enrollin 1 Program1 //enrollin <fn><course>
Student Petko is now enrolled in Program1.

>enrollin 1 T1
Student Petko is now enrolled in T1.

>enrollin 1 T2
Student Petko is now enrolled in T2.

>enrollin 1 T3
Student Petko is now enrolled in T3.

>enrollin 1 T4
Student Petko is now enrolled in T4.

>addgrade 1 Program1 2.3 //addgrade <fn><course><grade>
Successfully added grade!

>addgrade 1 T1 3
Successfully added grade!

>addgrade 1 T2 4
Successfully added grade!

>addgrade 1 T3 6
Successfully added grade!

>report 1 //report <fn>
Successful courses:
T1, grade: 3
T2, grade: 4
T3, grade: 6

Unsuccessful courses:
Program1, grade: 2.3
T4, grade: 2

Student overall grade: 3.46
```
## Команди
| Име  | Описание |
| ------------- | ------------- |
| open \<file\>  | opens \<file\> |
| close  | closes currently opened file |
| save | saves the currently open file |
| saveas \<file\> | saves the currently open file in \<file\> |
| help | prints this information |
| exit | exists the program |
| enroll \<fn\>\<program\>\<group\>\<name\> | enrolls student with name \<name\> in first year in program \<program\> in group \<group\> and with faculty number \<fn\> |
| advance \<fn\> | takes the student to the next year |
| change \<fn\>\<option\>\<value\> | \<option\> can be either 'program', 'group' or 'year'. Transfers student with faculty number \<fn\> in a new program, group or year specified with \<value\> |
| graduate \<fn\> | marks the student with faculty number \<fn\> as graduated |
| interrupt \<fn\> | marks the student with faculty number \<fn\> as interrupted. Interrupted students can't take exams, enrol in courses or change program, group or year |
| resume \<fn\> | restores student rights to the student with faculty number \<fn\> |
| print \<fn\> | prints out a reference for the student with faculty number \<fn\> |
| printall \<program\>\<year\> | prints out a reference for all students in program <program> and year \<year\> |
| enrollin \<fn\>\<course\> | enrolls the student with faculty number \<fn\> in course \<course\> |
| addgrade \<fn\>\<course\>\<grade\> | Adds a grade \<grade\> in course \<course\> for student with faculty number \<fn\>. You can only add a grade if a student is enrolled in that course. |
| protocol \<course\> | Prints out all the faculty numbers of students enrolled for course \<course\>. There is a different protocol for each program. |
| report \<fn\> | Prints out academic reference for grades of student with faculty number \<fn\> |
| addprogram \<program\> | Adds a program \<program\> in the system |
| addcourse \<program\>\<course\>\<mandatory\>\<year\> | Adds a course \<course\> for program \<program\> which can be either mandatory or not \<mandatory\> (true/false) for year \<year\> |
  
