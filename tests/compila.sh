exec cc -o $1 $1.c -I../include -I../libft/ ../src/*.c ../libft/libft.a -lm -g3 -fsanitize=address
