#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("..................Welcome to Swiggy Services...............\n\n");
    printf("Login Type\n");
    printf("Enter Your choice {1. Admin, 2.Professor, 3.Student} : ");
    int login_type, id;
    char pswd[20];
    scanf("%d", &login_type);
    printf("Enter Login ID: ");
    scanf("%d", &id);
    printf("Password: ");
    scanf("%s", &pswd);

    // login the user
    int successful_login = 0;

    if (successful_login)
    {
        int choice;
        if (login_type == 1)
        {
            while (1)
            {
                printf("..........Welcome to Admin Menu.........\n");
                printf("1. Add Student\n");
                printf("2. View Student Details\n");
                printf("3. Add faculty\n");
                printf("4. View Faculty Details\n");
                printf("5. Activate Student\n");
                printf("6. Block Student\n");
                printf("7. Modify Student Detail\n");
                printf("8. Modify Faculty Detail\n");
                printf("9. Logout and Exit\n");
                printf("Enter Your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 9:
                    exit(0);
                default:
                    printf("Invalid Choice, Try Again...");
                }
            }
        }
        else if (login_type == 2)
        {
            while (1)
            {
                printf("..........Welcome to Professor Menu.........\n");
                printf("1. View Offering Courses\n");
                printf("2. Add New Course\n");
                printf("3. Remove Course from Academia\n");
                printf("4. Update Course Details\n");
                printf("5. Change Password\n");
                printf("6. Logout and Exit\n");
                printf("Enter Your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 6:
                    exit(0);
                default:
                    printf("Invalid Choice, Try Again...");
                }
            }
        }
        else
        {
            while (1)
            {
                printf("..........Welcome to Student Menu.........\n");
                printf("1. View All Courses\n");
                printf("2. Enroll in a New Course\n");
                printf("3. Drop Course\n");
                printf("4. View Enrolled Course Details\n");
                printf("5. Change Password\n");
                printf("6. Logout and Exit\n");
                printf("Enter Your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 6:
                    exit(0);
                default:
                    printf("Invalid Choice, Try Again...");
                }
            }
        }
    }
    return 0;
}