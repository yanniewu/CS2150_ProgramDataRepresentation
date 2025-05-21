#!/bin/bash

#Yannie Wu
#averagetime.sh

echo "enter the exponent for counter.cpp:"
read exponent

#Check if input is quit
if [ exponent = "quit" ]
then
	exit
fi

#Compiling
clang++ counter.cpp timer.cpp
n=5
sum=0 

#Loop five times
for i in $(seq 1 $n)
do
	runtime=`./a.out $exponent | tail -1`
	sum=`expr $sum + $runtime`
	echo "Running iteration $i..."
	echo "time taken: $runtime ms"
done

#Calculating average time
avg=`expr $sum / $n`

echo "5 iterations took $sum ms"
echo "Average time was $avg ms"
