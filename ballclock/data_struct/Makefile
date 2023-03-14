objects = sqstack.o linkqueue.o
all:$(objects)
$(objects): %.o: %.c
	$(CC) -c $< -o ../$(OBJ_DIR)/$@ -I ../$(INCLUDE_DIR)

