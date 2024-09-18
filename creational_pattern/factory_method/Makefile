# 定义编译器
CXX := g++
# 定义编译选项
CXXFLAGS := -Wall -std=c++20

# 定义目标
TARGET := program

# 查找源文件
SRCS := $(wildcard *.cpp)
# 从源文件中提取对象文件
OBJS := $(SRCS:.cpp=.o)

# 默认目标
all: $(TARGET)

# 编译目标
$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译规则
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理目标
clean:
	rm -f $(OBJS) $(TARGET)

# .PHONY定义伪目标
.PHONY: all clean
