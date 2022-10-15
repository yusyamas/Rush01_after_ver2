echo "##########norminette##########"
for f in $(find . -name 'rush-01*.c');
do
    echo "-----------------------------------"
    echo "norminette $f"
    norminette -R CheckForbiddenSourceHeader $f
done
echo "##########分割コンパイル##########"
gcc -c -Wall -Wextra -Werror $(find . -name 'rush-01*.c')
gcc -Wall -Wextra -Werror rush-01_0.o rush-01_1.o rush-01_2.o \
rush-01_3.o rush-01_4.o rush-01_5.o 
