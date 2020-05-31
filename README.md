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
