#!/bin/bash

: 'Write a menu driven program to create Employee Record.
 The Record should contains: Employee Name, Employee Number, and Telephone Number.
 The script should be able to delete a record, search and display a specific employee details,
 sort the record and list the complete record.'

FILE=~/Desktop/Shell-Scripts/employee.txt
if test -f "$FILE"; then
    echo "$FILE already exists."
    echo
else
    touch $FILE
fi

while true; do
    echo "1. Create Employee Record"
    echo "2. Delete Employee Record"
    echo "3. Search Employee Record"
    echo "4. Display Employee Record"
    echo "5. Sort Employee Record"
    echo "6. List Employee Record"
    echo "7. Exit"
    read -p "Enter your choice (1-7): " choice
    echo
    echo

    case $choice in
    "1")
        read -p "Enter Employee Name: " ename
        read -p "Enter Employee Number: " eno
        read -p "Enter Employee Phone Number: " phone
        echo "$eno $ename $phone" >>$FILE
        echo "Employee Record Insert Sucessfully"
        ;;
    "2")
        read -p "Enter Employee Number: " eno
        ;;
    "3")
        read -p "Enter Employee Number: " eno
        ;;
    "4")
        read -p "Enter Employee Number: " eno
        ;;
    "5")
        read -p "Enter Employee Number: " eno
        ;;
    "6")
        cat $FILE
        echo
        echo
        ;;
    "7")
        exit
        ;;
    esac
done
