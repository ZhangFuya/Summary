```makefile
ELF=main.out
CC=gcc	 #指定编译器
src=$(shell find -name  '*.c')
src2o=$(patsubst%.c,%.o,$src)	#这里也可以使用src2o=$(src:.c=.o)
$(ELF):$(src2o)
$(src2o):

.PHONT:clean
clean:
	rm -rf $(src2o)
```

