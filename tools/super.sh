#!/bin/zsh

d=0
e=0
f=0
g=0
h=0
way=$(echo ${0%/super.sh})
echo $way
for (( i=1; i<=$@; i++ ))
do
	echo "---------------ROUND $i----------------"
	$way/generator --big-superposition > $way/tests/megatest
	b=$(/bin/cat $way/tests/megatest | grep -m 1 "number" | cut -d ' ' -f8)
	$way/../lem_in --file tools/tests/megatest > $way/result
	a=$(cat $way/result | grep L | wc | tr -s ' ' | cut -d ' ' -f2)
	$way/generator --big > $way/tests/megatest
	c=$(echo "$b - $a" | bc)
	echo "moi = $a | map = $b | diff = $c"
	d=$(echo "$d + $c" | bc)
	if [ $c -gt -3 ]
	then
		echo "\033[32m SUPO OK \033[0m"
	else
		echo "\033[31m diff = $c\033[0m"
	fi
	b=$(cat $way/tests/megatest | grep -m 1 "number" | cut -d ' ' -f8)
	$way/../lem_in --file tools/tests/megatest > $way/result
	a=$(cat $way/result | grep L | wc | tr -s ' ' | cut -d ' ' -f2)
	$way/generator --flow-thousand > $way/tests/megatest
	c=$(echo "$b - $a" | bc)
	echo "moi = $a | map = $b | diff = $c"
	e=$(echo "$e + $c" | bc)
	if [ $c -gt -3 ]
	then
		echo "\033[32m BIG OK !\033[0m"
	else
		echo "\033[31m diff = $c\033[0m"
	fi
	b=$(cat $way/tests/megatest | grep -m 1 "number" | cut -d ' ' -f8)
	$way/../lem_in --file tools/tests/megatest > $way/result
	a=$(cat $way/result | grep L | wc | tr -s ' ' | cut -d ' ' -f2)
	$way/generator --flow-ten > $way/tests/megatest
	c=$(echo "$b - $a" | bc)
	echo "moi = $a | map = $b | diff = $c"
	f=$(echo "$f + $c" | bc)
	if [ $c -gt -3 ]
	then
		echo "\033[32m THOUSAND OK !\033[0m"
	else
		echo "\033[31m diff = $c\033[0m"
	fi
	b=$(cat $way/tests/megatest | grep -m 1 "number" | cut -d ' ' -f8)
	$way/../lem_in --file tools/tests/megatest > $way/result
	a=$(cat $way/result | grep L | wc | tr -s ' ' | cut -d ' ' -f2)
	$way/generator --flow-one > $way/tests/megatest
	c=$(echo "$b - $a" | bc)
	echo "moi = $a | map = $b | diff = $c"
	g=$(echo "$g + $c" | bc)
	if [ $c -gt -3 ]
	then
		echo "\033[32m TEN OK !\033[0m"
	else
		echo "\033[31m diff = $c\033[0m"
	fi
	b=$(cat $way/tests/megatest | grep -m 1 "number" | cut -d ' ' -f8)
	$way/../lem_in --file tools/tests/megatest > $way/result
	a=$(cat $way/result | grep L | wc | tr -s ' ' | cut -d ' ' -f2)
	c=$(echo "$b - $a" | bc)
	echo "moi = $a | map = $b | diff = $c"
	h=$(echo "$h + $c" | bc)
	if [ $c -gt -3 ]
	then
		echo "\033[32m ONE OK !\033[0m"
	else
		echo "\033[31m diff = $c\033[0m"
	fi
	echo -n "\033[0m"
done
echo "$d $e $f $g $h"
