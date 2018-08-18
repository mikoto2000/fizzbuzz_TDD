# 下記ディレクトリ構成でプロジェクトを作る
#
# ```
# fizzbuzz_TDD/
#   +- include/ : ヘッダファイル
#   +- src/     : ソースコード
#   +- test/    : テストコード
# ```
SRCS = ./src/fizzbuzz.c ./src/main.c
TEST_SRCS = ./test/test_fizzbuzz.cpp
CFLAGS = -I ./include
LIBS =
TARGET = fizzbuzz
OBJS = $(subst .c,.o,$(SRCS))

ifeq ($(OS),Windows_NT)
TARGET := $(TARGET).exe
endif

TEST_OBJS = $(OBJS:.o=.gcovo) $(subst .cpp,.gcovo,$(TEST_SRCS))
TEST_CFLAGS = $(CFLAGS)
TEST_LIBS = $(LIBS) -lgtest -lgtest_main -lgcov
TEST_TARGET = test_$(TARGET)

.SUFFIXES: .c .cpp .o .gcovo

all : test $(TARGET)
test : $(TEST_TARGET)
	./$(TEST_TARGET)

$(TARGET) : $(OBJS)
	gcc $(OBJS) $(LIBS) -o $@

$(TEST_TARGET) : $(TEST_OBJS:.o=.gcovo)
	g++ $(filter-out ./src/main.gcovo, $(TEST_OBJS)) $(TEST_LIBS) -o $@

.c.o :
	gcc -c $(CFLAGS) -I. $< -o $@

.c.gcovo :
	gcc --coverage -c $(CFLAGS) -I. $< -o $@

.cpp.gcovo :
	g++ --coverage -c $(TEST_CFLAGS) -I. $< -o $@

clean :
	rm -f **/*.o *.gcov **/*.cda **/*.gcno **/*.gcovo $(TARGET) $(TEST_TARGET)

