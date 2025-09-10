exec cc -g3 -fsanitize=address -o $1.exe $1.c \
	-I../src/include -I../libft/ $(find ../src -name '*.c') \
	../libft/libft.a -lm 
