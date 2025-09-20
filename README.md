# color-printer

一款C++实现的彩色控制台打印库，提供多功能彩色输出功能，使用CMake构建。

## 功能特性

- 🎨 **多彩输出**: 支持7种颜色（红、绿、黄、蓝、品红、青、白）
- 📝 **多种消息类型**: 支持INFO、ERROR、WARNING、OK、DEBUG等消息类型
- 🔢 **多类型支持**: 支持字符串、数字（int、float、double）、布尔值、字符等数据类型
- 🎯 **格式化输出**: 支持printf风格的格式化字符串
- 🔄 **状态指示器**: 提供静默状态指示器功能
- 📚 **易于使用**: 静态方法调用，无需实例化

## 构建要求

- C++20 标准
- CMake 3.22+
- 支持ANSI颜色代码的终端

## 构建步骤

```bash
# 克隆项目
git clone <repository-url>
cd color-printer

# 创建构建目录
mkdir build
cd build

# 生成构建文件
cmake ..

# 编译
make

# 安装（可选）
sudo make install
```

## 使用方法

### 1. 包含头文件

```cpp
#include "color_printer.h"
```

### 2. 基本使用

#### 打印彩色消息

```cpp
// 打印不同类型的消息
ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "INFO", "程序启动成功");
ColorPrinter::PrintColoredMessage(PrintColor::RED, "ERROR", "文件打开失败");
ColorPrinter::PrintColoredMessage(PrintColor::YELLOW, "WARNING", "配置参数缺失");
ColorPrinter::PrintColoredMessage(PrintColor::BLUE, "OK", "任务完成");
ColorPrinter::PrintColoredMessage(PrintColor::CYAN, "DEBUG", "变量值: ");
```

#### 打印不同数据类型

```cpp
// 字符串
ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "INFO", "Hello World");

// 数字类型
ColorPrinter::PrintColoredMessage(PrintColor::BLUE, "INFO", 42);           // int
ColorPrinter::PrintColoredMessage(PrintColor::BLUE, "INFO", 3.14159f);     // float
ColorPrinter::PrintColoredMessage(PrintColor::BLUE, "INFO", 3.1415926535); // double

// 布尔值
ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "INFO", true);   // 输出: [INFO] true
ColorPrinter::PrintColoredMessage(PrintColor::RED, "INFO", false);    // 输出: [INFO] false

// 字符
ColorPrinter::PrintColoredMessage(PrintColor::YELLOW, "INFO", 'A');
```

#### 格式化输出

```cpp
// 格式化字符串（类似printf）
ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "INFO", "用户ID: %d, 姓名: %s", 12345, "张三");
ColorPrinter::PrintColoredMessage(PrintColor::BLUE, "INFO", "PI值: %.2f", 3.14159);
ColorPrinter::PrintColoredMessage(PrintColor::YELLOW, "INFO", "进度: %d%%", 85);
```

### 3. 高级功能

#### 静默状态指示器

```cpp
#include <chrono>
#include <thread>

// 使用示例：在循环中显示进度
int counter = 0;
bool isProcessing = true;

while (isProcessing) {
    // 执行某些操作...
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // 显示绿色进度点
    ColorPrinter::PrintSilentStatusIndicator(PrintColor::GREEN, true, counter);

    // 模拟完成条件
    static int count = 0;
    if (++count > 50) {
        isProcessing = false;
    }
}

// 完成时打印成功消息
ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "OK", "处理完成");
```

#### 多个独立指示器

```cpp
// 可以同时使用多个独立的指示器
int counter1 = 0;
int counter2 = 0;

// 绿色指示器用于正常任务
ColorPrinter::PrintSilentStatusIndicator(PrintColor::GREEN, taskRunning, counter1);

// 红色指示器用于错误状态
ColorPrinter::PrintSilentStatusIndicator(PrintColor::RED, errorCondition, counter2);
```

### 4. 颜色和消息类型

#### 支持的颜色

- `PrintColor::RED` - 红色
- `PrintColor::GREEN` - 绿色
- `PrintColor::YELLOW` - 黄色
- `PrintColor::BLUE` - 蓝色
- `PrintColor::MAGENTA` - 品红
- `PrintColor::CYAN` - 青色
- `PrintColor::WHITE` - 白色

#### 建议的消息类型

- `"INFO"` - 一般信息
- `"ERROR"` - 错误信息
- `"WARNING"` - 警告信息
- `"OK"` - 成功信息
- `"DEBUG"` - 调试信息

### 5. 在项目中集成

#### 方法一：直接使用源文件

将 `include/color_printer.h` 和 `src/color_printer.cpp` 复制到您的项目中：

```text
your_project/
├── include/
│   └── color_printer.h
├── src/
│   ├── color_printer.cpp
│   └── main.cpp
└── CMakeLists.txt
```

在您的 `CMakeLists.txt` 中添加：

```cmake
add_executable(your_app
    src/main.cpp
    src/color_printer.cpp
)

target_include_directories(your_app PRIVATE include)
```

#### 方法二：使用构建的库

```cmake
# 查找库
find_library(COLOR_PRINTER_LIB color_printer)

# 或者指定库路径
# set(COLOR_PRINTER_LIB "/path/to/libcolor_printer.so")

add_executable(your_app src/main.cpp)

target_link_libraries(your_app ${COLOR_PRINTER_LIB})
target_include_directories(your_app PRIVATE "/path/to/include")
```

#### 方法三：系统安装后使用

如果您已经将库安装到系统目录，可以使用以下方式：

```cmake
# 使用CMake的find_package（需要额外的配置文件）
find_package(color_printer REQUIRED)
target_link_libraries(your_app color_printer)

# 或者直接链接系统库
target_link_libraries(your_app color_printer)
target_include_directories(your_app PRIVATE "/usr/local/include")
```

### 6. 安装说明

#### 构建和安装

```bash
# 构建库
mkdir build
cd build
cmake ..
make

# 安装到系统目录（需要管理员权限）
sudo make install
```

#### 安装内容

安装后将在以下位置创建文件：

- `/usr/local/lib/libcolor_printer.so` - 动态库文件
- `/usr/local/include/color_printer.h` - 头文件
- `/usr/local/lib/cmake/color_printer/` - CMake配置文件（用于find_package）

#### 卸载说明

如果需要卸载已安装的库，可以使用以下命令：

```bash
# 卸载库文件和头文件（需要管理员权限）
sudo rm -f /usr/local/lib/libcolor_printer.so
sudo rm -rf /usr/local/include/color_printer.h
sudo rm -rf /usr/local/lib/cmake/color_printer/

# 更新动态链接器缓存
sudo ldconfig

# 验证卸载是否成功
ls /usr/local/lib/libcolor_printer.so /usr/local/include/color_printer.h 2>/dev/null && echo "卸载失败，文件仍存在" || echo "库已成功卸载"
```

**注意**：如果您使用包管理器安装的库，请使用相应的包管理器命令卸载（如 `sudo apt remove color-printer` 或 `sudo yum remove color-printer`）。

### 7. 示例程序

```cpp
#include "color_printer.h"
#include <thread>
#include <chrono>

int main() {
    // 欢迎信息
    ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "INFO", "=== 彩色打印库演示 ===");

    // 基本消息类型演示
    ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "OK", "程序启动成功");
    ColorPrinter::PrintColoredMessage(PrintColor::BLUE, "INFO", "当前版本: %s", "1.0.0");
    ColorPrinter::PrintColoredMessage(PrintColor::YELLOW, "WARNING", "配置文件未找到，使用默认配置");

    // 数据类型演示
    int userCount = 150;
    double accuracy = 98.75;
    bool isConnected = true;

    ColorPrinter::PrintColoredMessage(PrintColor::CYAN, "INFO", "用户数量: %d", userCount);
    ColorPrinter::PrintColoredMessage(PrintColor::CYAN, "INFO", "准确率: %.2f%%", accuracy);
    ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "INFO", isConnected);

    // 模拟处理过程
    ColorPrinter::PrintColoredMessage(PrintColor::BLUE, "INFO", "开始处理数据...");
    int counter = 0;
    for (int i = 0; i < 20; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        ColorPrinter::PrintSilentStatusIndicator(PrintColor::GREEN, true, counter);
    }

    ColorPrinter::PrintColoredMessage(PrintColor::GREEN, "OK", "数据处理完成");

    // 错误演示
    ColorPrinter::PrintColoredMessage(PrintColor::RED, "ERROR", "网络连接失败，重试次数: %d", 3);

    return 0;
}
```

## 注意事项

1. **终端支持**: 该库使用ANSI转义序列，需要支持ANSI颜色的终端
2. **线程安全**: 库的静态方法是线程安全的，可以在多线程环境中使用
3. **性能**: 彩色输出相比普通输出有轻微性能开销
4. **计数器管理**: `PrintSilentStatusIndicator` 的计数器参数需要由调用者管理

## 许可证

请查看 LICENSE 文件了解许可证信息。
