gcc test.cpp -o test 生成可执行会报错

gcc -c test.cpp 只编译不链接
gcc test.o -o test -lstdc++ 联接C++的库
