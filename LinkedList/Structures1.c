#include <stdio.h>
#include <string.h>



//Declaration of structure
struct s{
    int num;
    char name[15];
};

//Another way of declaration with initilisation
struct structure_to_store_data{
    int roll_no;
    char *name;
    int age;
    float grade;
}s3 ;

struct structure3{
    int x, y, z;
};

/*

Limitations of Structures:
    1.Cannot Declare functions inside structures
    2.Cannot have constructors
    3.No static members
    4.No data hiding
    5.Cannot use arithmetic operations of structure itself but can do operations on elements of structures

*/

int main(){
    struct s s1;
    //Values are added after initilisation
    s1.num = 123;
    strcpy(s1.name, "Mukund");
    printf("Structure 1 Details");
    printf("\n%d %s\n", s1.num, s1.name);

    //values are added during initilisation
    struct s s2 = {456, "DEF"};
    printf("Structure 2 Details");
    printf("\n%d %s\n", s2.num, s2.name);

    //s3 is initiliased during declaration of structure itself and values are added now
    s3.roll_no = 1;
    s3.name = "ABC";
    s3.age = 18;
    s3.grade = 8.7;
    printf("Structure 3 Details");
    printf("\n%d %s %d %f\n", s3.roll_no, s3.name, s3.age, s3.grade);


    //Array of structures
    struct structure3 s4[5];
    s4[0].x = 2;
    s4[0].y = 5;
    s4[0].z = 1;
    printf("Structure 4 Details");
    printf("\n%d %d %d\n", s4[0].x, s4[0].y, s4[0].z);

    //Designated Initilisation
    //Order is not necessary if we initilise values with variable names
    struct structure3 s5 = {.z = 2, .x = 8, .y = 19};
    printf("Structure 5 Details");
    printf("\n%d %d %d\n", s5.x, s5.y, s5.z);

    return 0;
}