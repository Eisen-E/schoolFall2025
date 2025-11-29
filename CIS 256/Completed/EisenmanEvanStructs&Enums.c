//Evan Eisenman 11/16/25
//CIS 265 12555
//C Structs & Enumerations Assignment
//This program prompts a user with a menu to select from 3 diffrent actions to preform

//directives to inclued the stdio and string standard c libraries 
#include <stdio.h>
#include <string.h>

//Macro to define file path
#define FILE_PATH "studentdatabase.txt"
//Macros to control string lengths
#define FIRST_NAME_LEN 15
#define LAST_NAME_LEN 20
#define MAJOR_LEN 20
//macro for max ammount of students in the array
#define MAX_STUDENTS 100
//macro for user prompt
#define PROMPT "Press (D) to display all students records information\nPress (S) to search and display a student information by student ID\nPress (C) to provide a count of students per campus\nPress (Q) to quit\n"
//struct for a students name has the first and last name field
struct student_name
{
    char first[FIRST_NAME_LEN+1];
    char last[LAST_NAME_LEN+1];
};
//Stuct for a student that has a field for their id name(struct) and major and campus
struct student
{
    int id;
    struct student_name name;
    char major[MAJOR_LEN+1];
    int campus;
};
//enum for the campus east =0 west=1 downtown =2
enum campus
{
    EAST,WEST,DOWNTOWN
};

//loads the formated csv and stores the students info in a an array passed to it through a pointer and returns the ammount of entries
int load_file(struct student *studentArray)
{
    FILE *fp; //declarations of our filepath pointer for the text file stream
    //declartion for vars that will store the information of current line in the file stream and one to count the ammount of entries
    int id,index=0,campusInt;
    char firstName[FIRST_NAME_LEN],lastName[LAST_NAME_LEN],major[MAJOR_LEN],campus[20];
    
    //opens the file stream in read only mode and checks if it oppend properaly if it did not it this func returns -1
    fp = fopen(FILE_PATH,"r");
    if (fp == NULL)
    {
        return -1;
    }
    //loops through and pulls the infromation from each line using the fscanf to search through the formatted line
    while((fscanf(fp,"%d,%s %[A-Za-z],%[A-Za-z ],%[A-Za-z ]",&id,firstName,lastName,major,campus))!=EOF && index < MAX_STUDENTS)
    {
        //uses the enum to convert the campus name into an intfor the id
        if (strcmp(campus,"East Campus")==0)
        {
            campusInt = EAST;
        }
        else if(strcmp(campus,"West Campus")==0)
        {
            campusInt = WEST;
        }
        else
        {
            campusInt = DOWNTOWN;
        }
        //stores the id and campus id into the fields of the struct at current index
        studentArray[index] = (struct student) {.id = id,.campus=campusInt};
        //coppies the strings for fname lname and major into the correct fields at the current index
        strcpy(studentArray[index].name.first,firstName);
        strcpy(studentArray[index].name.last,lastName);
        strcpy(studentArray[index].major,major);
        index++;
    }
    //returns the ammount of entries
    return index;
}
//loops through the array using the 2nd argument passed as a stopping point
void display_all_student(struct student *studentArray,int ammountOfStudents)
{
    int studentsDisplayed=0;//var used to loop through the array
    char campus[20];//string to store the current campus after it is converted back to a string
    //loops through for every student in the array
    while(studentsDisplayed < ammountOfStudents)
    {
        switch (studentArray[studentsDisplayed].campus)
        {
        case 0:
            strcpy(campus,"East Campus");
            break;
        case 1:
            strcpy(campus,"West Campus");
            break;
        case 2:
            strcpy(campus,"Downtown Campus");
            break;
        }
        //displays the info of the student at the current index
        printf("ID:%d First Name:%s Last Name:%s Major:%s Campus: %s\n",studentArray[studentsDisplayed].id,studentArray[studentsDisplayed].name.first,studentArray[studentsDisplayed].name.last,studentArray[studentsDisplayed].major,campus);
        studentsDisplayed++;
    }
}
//searches through the array for an id of a student and displays their entry if they are not found tells the user they cannot be found
void display_id_record(struct student *studentArray,int ammountOfStudents,int id)
{
    int recordsSearched=0,recordNotLocated = 1;//records searched var will hold how many records are searched and not located will flag if all entrys have been processed without finding the desired id
    while(recordsSearched < ammountOfStudents)
    {
        if (studentArray[recordsSearched].id==id)//if id is found we display the info at the current index
        {
            printf("ID:%d First Name:%s Last Name:%s Major:%s Campus: %d\n",studentArray[recordsSearched].id,studentArray[recordsSearched].name.first,studentArray[recordsSearched].name.last,studentArray[recordsSearched].major,studentArray[recordsSearched].campus);
            recordNotLocated = 0;//changes record not found flag to 0 so we can tell the function to not print the not found statement
        }
        recordsSearched++;
    }
    if(recordNotLocated){printf("Could not locate student with ID:%d\n",id);}//tells the user if no record has been found
}
//loops through the array and uses the campus int to incremnt a counter that tracks the population at each campus
void display_students_per_campus(struct student *studentArray,int ammountOfStudents)
{
    //vars used to count have many records seached and count of students at each campus
    int recordsSearched=0,eastCount=0,westCount=0,downCount=0;
    while(recordsSearched < ammountOfStudents)
    {
        //switch statement uses ENUM to control which var gets intcrmented based of the campus at the current index
        switch (studentArray[recordsSearched].campus)
        {
        case EAST:
            eastCount++;
            break;
        case WEST:
            westCount++;
            break;
        case DOWNTOWN:
            downCount++;
            break;
        }
        recordsSearched++;
    }
    printf("East Campus: %d students\nWest Campus: %d students\nDowntown Campus: %d students\n",eastCount,westCount,downCount);//prints counts
}
int main(void)
{
    struct student studentArray[MAX_STUDENTS];//array that will hold all student structs
    int currentStudentsInt,idSearch;//currents students is the total ammount of students there are records for idsearch will hold int for the desired id ot search for
    char userChoice;//holds char of the current user selection
    
    currentStudentsInt = load_file(studentArray);//calls load_file to convert CSV into array and returns amount of entries
    printf(PROMPT);//prints a prompt
    scanf(" %c",&userChoice);//gets userchoice
    while (userChoice !='q'&& userChoice !='Q' )//exits loop if user enters q
    {
        //if else stament to control user selection
        if(userChoice =='d'|| userChoice =='D')
        {
            display_all_student(studentArray,currentStudentsInt);
        }
        else if (userChoice =='s'|| userChoice =='S')
        {
            printf("Please enter and ID to search: ");
            scanf(" %d",&idSearch);
            display_id_record(studentArray,currentStudentsInt,idSearch);
        }
        else if (userChoice =='c'|| userChoice =='C')
        {
            display_students_per_campus(studentArray,currentStudentsInt);
        }
        else{printf("Incorrect selection please retry");}
        printf(PROMPT);
        scanf(" %c",&userChoice);
    }

    return 0;
}