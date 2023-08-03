#!/bin/bash

read -p "Enter your Age: " age

if [ $age -lt 30 ]
then
   echo "Your age is less than 30"
elif [ $age -eq 30 ]
then
   echo "Your age is 30"
else
   echo "Your age is greater than 30"
fi
