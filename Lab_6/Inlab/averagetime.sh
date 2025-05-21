#!/bin/bash

#Yannie Wu
#averagetime.sh

read dictionary #saves dictionary txt file to vairable
read grid #saves grid txt file to variable

#Grabbing runtime for five trials
run1=`./a.out $dictionary $grid | tail -1`
run2=`./a.out $dictionary $grid | tail -1`
run3=`./a.out $dictionary $grid | tail -1`
run4=`./a.out $dictionary $grid | tail -1`
run5=`./a.out $dictionary $grid | tail -1`

#Calculating average runtime
sum=`expr $run1 + $run2`
sum=`expr $sum + $run3`
sum=`expr $sum + $run4`
sum=`expr $sum + $run5`

avg=`expr $sum / 5`

echo "$avg"

