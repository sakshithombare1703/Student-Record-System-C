#include<stdio.h>
int studentCount = 0;
//structure to store student information
struct student {
    int roll_no;
    char name[50];
    float marks;
};
struct student students[20];

void display_menu(){
    printf("=======================\n  Student Record System\n=====================\n1.Add Student \n 2.Display student \n 3.search student \n 4. Update data \n 5.Delete Student \n 6.Exit \n");  
}
//function to add student
void add_student(){
    
    printf("Enter roll no:\n");
    scanf("%d",&students[studentCount].roll_no);
    printf("Enter name:\n");
    scanf("%s",students[studentCount].name);
    printf("Enter marks:\n");
    scanf("%f",& students[studentCount].marks);
    
    studentCount++;

}
// function to display student data 
void display_student(){
    if(studentCount == 0){
        printf("No record found.\n");
    }
    else{ 
        int i;
        for (int i = 0; i<studentCount; i++){
            printf("----Student Details----\n");
            printf("Roll_No:%d\n",students[i].roll_no);
            printf("Name:%s\n",students[i].name);
            printf("Marks:%f\n",students[i].marks);
    }
    
}

}
// function to search the student
void search_student(){
    int search_roll;
    int found = 0;
    printf("Enter roll_no:");
    scanf("%d",&search_roll);
    for (int i = 0; i < studentCount; i++)
    {
        if(students[i].roll_no == search_roll){
            printf("----Student Details----\n");
            printf("Roll_No:%d\n",students[i].roll_no);
            printf("Name:%s\n",students[i].name);
            printf("Marks:%f\n",students[i].marks);
            found = 1;
        }
    }
    if(found == 0){
        printf("Result not found\n");
    }
    
}
// function to update student data
void update_data(){
    int update_roll;
    int found = 0;
    printf("Enter Roll number to update:");
    scanf("%d",&update_roll);
    for (int  i = 0; i < studentCount; i++)
    {
        if(students[i].roll_no == update_roll){
            printf("----Update Data----\n");
            printf("Enter roll number:\n");
            scanf("%d",&students[i].roll_no);
            printf("Enter name:\n");
            scanf("%s",students[i].name);
            printf("Enter marks:\n");
            scanf("%f",&students[i].marks);
            found = 1;
            break;

        }    
    }
    if(found==1){
        printf("Record updated successfully\n");
    }
    else{
        printf("No data found\n");
    }
    
}
// function to delete student data
void delete_data(){
    int delete_roll;
    int found = 0;
    printf("Enter roll_no to delete: ");
    scanf("%d",&delete_roll);
    for(int i = 0; i < studentCount; i++){
        if(students[i].roll_no == delete_roll){ 
            for(int j = i; j<studentCount-1; j++){
                students[j] = students[j+1];
            }
                found = 1;
                studentCount--;
                break;
             
            
        }
    }
    if(found==1){
        printf("Data deleted successfully\n");
    }
    else{
        printf("Data isnt available to delete\n");
    }

}
void exit_program(){
    printf("Exited from system.\n");
}

int main(){
    int choice;
    
    do
    {   display_menu();
        printf("Enter a choice: \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            display_student();
            break;
        case 3:
            search_student();
            break;
        case 4:
            update_data();
            break;
        case 5:
            delete_data();
            break;
        case 6:
            exit_program();
            break;
        
        default:
            printf("Invalid choice. \n");
            break;
        }
    } while (choice != 6);

return 0;
}
