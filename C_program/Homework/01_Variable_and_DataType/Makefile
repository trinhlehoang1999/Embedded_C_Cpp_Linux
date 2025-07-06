# Tên file đầu ra
TARGET = SWPS_exe

# Các thư mục
SRC_DIR = src
OBJ_DIR = bin
INC_DIR = include

# Danh sách file nguồn và object
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compiler và flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I$(INC_DIR)

# Mục mặc định
all: $(TARGET)

# Tạo file thực thi
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# Biên dịch từng file .c thành .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Dọn sạch
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean