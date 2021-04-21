#! /bin/sh

  clang++ -Wall -Wextra -Werror -g -I ../containers/iterators -I ../containers -I . ft_vector_test.cpp -o user_bin_for_leaks && valgrind --leak-check=full --track-origins=yes ./user_bin_for_leaks
