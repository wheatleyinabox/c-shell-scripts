#!/bin/sh
NUMS="1 2 3 4 5 6 7"
for NUM in $NUMS
do
  var='expr $NUM & 2'
  if [ $var -eq 0 ]
  then
    echo $NUM
  fi
done