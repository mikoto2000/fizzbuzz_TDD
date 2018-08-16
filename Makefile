# 下記ディレクトリ構成でプロジェクトを作る
#
# ```
# fizzbuzz_TDD/
#   +- include/ : ヘッダファイル
#   +- src/     : ソースコード
#   +- test/    : テストコード
# ```
SRCS = TODO
TEST_SRCS = ./test/test_fizzbuzz.cpp
CFLAGS =
LIBS =
TARGET = fizzbuzz
OBJS = $(subst .c,.o,$(SRCS))

ifeq ($(OS),Windows_NT)
TARGET := $(TARGET).exe
endif

TEST_OBJS = $(subst .cpp,.o,$(TEST_SRCS))
TEST_CFLAGS = $(CFLAGS)
TEST_LIBS = $(LIBS) -lgtest -lgtest_main
TEST_TARGET = test_$(TARGET)

.SUFFIXES: .c .cpp .o

all : test $(TARGET)
test : $(TEST_TARGET)

$(TARGET) : $(OBJS)
	g++ $(OBJS) $(LIBS) -o $@

$(TEST_TARGET) : $(TEST_OBJS)
	g++ $(TEST_OBJS) $(TEST_LIBS) -o $@

.c.o :
	g++ -c $(CFLAGS) -I. $< -o $@

.cpp.o :
	g++ -c $(TEST_CFLAGS) -I. $< -o $@

clean :
	rm -f **/*.o $(TARGET) $(TEST_TARGET)

