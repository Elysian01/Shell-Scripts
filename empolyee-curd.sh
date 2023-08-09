#!/bin/bash

: 'Write a menu driven program to create Employee Record.
 The Record should contains: Employee Name, Employee Number, and Telephone Number.
 The script should be able to delete a record, search and display a specific employee details,
 sort the record and list the complete record.'

# FILE=~/Desktop/Shell-Scripts/employee.txt
FILE=employee.txt
if test -f "$FILE"; then
    # echo "$FILE already exists."
    echo
else
    touch $FILE
fi

function display_menu() {
    echo
    echo "1. Create Employee Record"
    echo "2. Delete Employee Record"
    echo "3. Search Employee Record"
    echo "4. Sort Employee Record"
    echo "5. List Employee Record"
    echo "6. Exit"
}

function create_record() {
    read -p "Enter Employee Name: " ename
    read -p "Enter Employee Number: " eno
    read -p "Enter Employee Phone Number: " phone
    # grep -q stands for quiet, it will execute quietly and will not show any o/p or error.
    if grep -q "^.*:$eno:.*$" $FILE; then
        echo "Employee Number $eno already exists. Cannot create duplicate records."
    else
        # Append the new record to the file
        echo "$ename:$eno:$phone" >>$FILE
        echo "Employee Record created successfully!"
        echo
    fi
}

function delete_record() {
    read -p "Enter the Employee Number to delete: " eno
    # grep -v prints out all the pattern, that donot match the pattern
    grep -v "^.*:$eno:.*$" $FILE >temp.txt
    mv temp.txt $FILE
    echo "Employee Record deleted successfully!"
    echo
}

function search_record() {
    read -p "Enter the Employee Number to search: " eno
    grep "^.*:$eno:.*$" $FILE
}

function sort_records() {
    sort -t ':' -k 2 $FILE >temp.txt
    # sort -t, t stands for delimiter, -k chooses column and sort on basis of that
    mv temp.txt $FILE
    echo "Record Sorted Successfully!!!"
}

function list_records() {
    cat $FILE
    # sed 's/:/ /g' $FILE
    # more $FILE
    echo
}

while true; do
    display_menu
    read -p "Enter your choice (1-6): " choice
    echo

    case $choice in
    1)
        create_record
        ;;
    2)
        delete_record
        ;;
    3)
        search_record
        ;;
    4)
        sort_records
        ;;
    5)
        list_records
        ;;
    6)
        echo "Exiting..."
        exit 0
        ;;
    *)
        echo "Invalid choice. Please enter a valid option (1-6)."
        ;;
    esac
done
