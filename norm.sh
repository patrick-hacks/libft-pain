#!/bin/bash

LIBFT="./libft"

printf "\033[0;33m"
echo 'wrongly used "" / <>:'
printf "\033[1;31m"
grep -r '<libft.h>' $LIBFT
grep -r '\"stdlib.h\"' $LIBFT
grep -r '\"unistd.h\"' $LIBFT
grep -r '\"string.h\"' $LIBFT
grep -r '\"stdio\"' $LIBFT
printf "\033[0;33m"
echo "files with non static functions:"
(cd ./libft && make > /dev/null)
printf "\033[0;31m"
nm -o $LIBFT/libft.a | grep " T " | cut -d ':' -f 2 | uniq -c | grep -v '^ *1 ' | cat
printf "\033[0m"
(cd ./libft && make fclean > /dev/null)
