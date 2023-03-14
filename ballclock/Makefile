CC=gcc
SUBDIRS=data_struct main obj
OBJS=sqstack.o linkqueue.o main.o
BIN_DIR=bin
BIN=app
OBJ_DIR=obj
INCLUDE_DIR=include
export CC SUBDIRS OBJS BIN OBJ_DIR INCLUDE_DIR BIN_DIR

all:CREATE_DIR $(SUBDIRS) 
CREATE_DIR:
	mkdir -p $(BIN_DIR) 
$(SUBDIRS):ECHO
	make -C $@
ECHO:
	@echo $(SUBDIRS)
	@echo begin compile
clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)/*.o
