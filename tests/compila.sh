exec cc -g3 -fsanitize=address -o $1.exe $1.c -I../include -I../libft/ ../src/*.c ../libft/libft.a -lm 
