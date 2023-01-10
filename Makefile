# Your program must compile with 'make'
# You must not change this file.

CC = gcc
FLAGS = -std=c99 -O0 -Wall -Werror -g -pedantic

default:
	$(CC) $(FLAGS) rgrep.c matcher.c -o rgrep

clean:
	rm -f rgrep
	rm -rf *.dSYM

check: clean default
	test "`echo "a\nb\nc" | ./rgrep 'a'`" = "a"
	test "`echo "a\n" | ./rgrep 'a'`" = "a"
	test "`echo "a" | ./rgrep '...'`" = ""
	test "`echo "abc" | ./rgrep '.b.'`" = "abc"
	test "`echo "h\naaaaah" | ./rgrep 'a+h'`" = "aaaaah"
	test "`echo "h\naaaaahhhhh" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "h\naaaaahhhhh\n" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "woot\nwot\nwat\n" | ./rgrep 'wo?t'`" = "wot"
	test "`echo "CCCCCCC\nC+\nC++" | ./rgrep '.\+\+'`" = "C++"
	test "`echo "GG" | ./rgrep 'G+'`" = "GG"
	test "`echo "USF_CS221.jpg" | ./rgrep 'U.F_CL?S2+1\.jpg'`" = "USF_CS221.jpg"
	test "`echo "beeebooa" | ./rgrep 'beeebooa'`" = "beeebooa"
	test "`echo "helloworld" | ./rgrep '.ell.world'`" = "helloworld"
	test "`echo "hellloworld" | ./rgrep 'hell+oworld'`" = "hellloworld"
	test "`echo "testing" | ./rgrep 'test+ing'`" = "testing"
	test "`echo "hhhellloworrld" | ./rgrep 'h+ell+owor+ld'`" = "hhhellloworrld"
	test "`echo "hellooo" | ./rgrep 'hello+'`" = "hellooo"
	test "`echo "helowrld" | ./rgrep 'hell?owo?rld'`" = "helowrld"
	test "`echo "helow" | ./rgrep 'hell?owo?'`" = "helow"
	test "`echo "ell" | ./rgrep 'h?ello?'`" = "ell"
	test "`echo "helloworld" | ./rgrep 'h.llo'`" = "helloworld"
	test "`echo "hell+o+world" | ./rgrep 'hell\+o\+world'`" = "hell+o+world"
	test "`echo "hello" | ./rgrep 'e.l'`" = "hello"
	@echo "Passed sanity check."

