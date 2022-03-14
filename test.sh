#!/bin/sh

try() {
	if [ $(./anal.elf "$1") -eq $2 ]; then
		echo "\033[1;32mSuccess\033[0m"
	else
		echo "\033[1;31mFail\033[0m"
	fi
}

try "((42))" 42
try "((1+3+5))" 9
try "((2*3*5))" 30
try "((2+3*5))" 17
try "1+3*5" 16
try "(1+3)*5" 20
try "2*3+5" 11
try "2*(3+5)" 16
try "2*(3*4+5+(6+7)+(3*4)*1+2)" 88

