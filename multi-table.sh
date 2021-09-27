#!/bin/sh
if [ $1 -ge 10 ] || [ $2 -ge 10 ] || [ $1 -le 0 ] || [ $2 -le 0 ]
then
    echo "Error: try with numbers in 1 ~ 9"
    exit 1
fi

for i in $(seq 1 $1)
do
    for j in $(seq 1 $2)
    do
        mul=`expr $i \* $j`
        printf "$i*$j=$mul "
    done
    echo ""
done

exit 0