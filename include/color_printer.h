/**
 * @file color_printer.h
 * @brief 彩色打印工具类
 *        提供彩色控制台输出的功能，支持多种数据类型和格式化输出
 */

#ifndef COLOR_PRINTER_H
#define COLOR_PRINTER_H

#include <string>
#include <sstream>
#include <iostream>

/**
 * @enum PrintColor
 * @brief 打印颜色枚举类
 */
enum class PrintColor {
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

/**
 * @class ColorPrinter
 * @brief 彩色打印工具类
 *        提供彩色控制台输出的静态方法
 */
class ColorPrinter {
public:

    /**
     * @brief 打印彩色字符串（const char*版本）
     *        专门处理字符串字面量
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型 ("INFO", "ERROR", "WARNING", "OK", "DEBUG")
     * @param message 要打印的消息内容（字符串字面量）
     */
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   const char* message);

    /**
     * @brief 打印彩色字符串（std::string版本）
     *        处理std::string对象
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型 ("INFO", "ERROR", "WARNING", "OK", "DEBUG")
     * @param message 要打印的消息内容（std::string对象）
     */
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   const std::string& message);

    /**
     * @brief 打印彩色数字（bool版本）
     *        注意：bool类型放在前面，避免与字符串字面量冲突
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型
     * @param value 要打印的布尔值
     */
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   bool value);

    /**
     * @brief 打印彩色数字（char版本）
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型
     * @param value 要打印的字符
     */
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   char value);

    /**
     * @brief 打印彩色数字（int版本）
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型
     * @param value 要打印的整数值
     */
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   int value);

    /**
     * @brief 打印彩色数字（float版本）
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型
     * @param value 要打印的浮点数值
     */
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   float value);

    /**
     * @brief 打印彩色数字（double版本）
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型
     * @param value 要打印的双精度浮点数值
     */
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   double value);


    /**
     * @brief 打印彩色格式化字符串（至少一个参数）
     *        支持格式化输出，类似printf("%d", value) 或 printf("%.3f %s", 3.14159, "test")
     *
     * @param color 颜色类型 (PrintColor枚举)
     * @param type 消息类型 ("INFO", "ERROR", "WARNING", "OK", "DEBUG")
     * @param format 格式字符串
     * @param first 第一个格式化参数
     * @param args 其余格式化参数
     */
    template <typename T, typename... Args>
    static void PrintColoredMessage(PrintColor color,
                                   const std::string& type,
                                   const char* format,
                                   T first,
                                   Args... args);

    /**
     * @brief 打印静默状态指示器
     *        打印累积的点号来指示静默状态
     *        最多打印100个点，达到100个后清空并重新开始循环
     *
     * @param color 打印颜色 (PrintColor枚举)
     * @param isSilent 是否处于静默状态（当为true时打印点号）
     * @param countRef 引用计数器，用于维护每个调用者的独立计数状态
     *
     * @note 使用示例：
     *       // 绿色点号
     *       int counter = 0;
     *       ColorPrinter::PrintSilentStatusIndicator(PrintColor::GREEN, condition, counter);
     *
     *       // 红色点号
     *       int counter2 = 0;
     *       ColorPrinter::PrintSilentStatusIndicator(PrintColor::RED, errorCondition, counter2);
     *
     *       在类中：
     *       int myCounter = 0;
     *       ColorPrinter::PrintSilentStatusIndicator(PrintColor::YELLOW, isSilent, myCounter);
     *
     *       这允许在多个地方独立使用，每个地方维护自己的计数器状态
     */
    static void PrintSilentStatusIndicator(PrintColor color, bool isSilent, int& countRef);

private:

    static std::string GetColorCode(PrintColor color);


    static std::string FormatString(const std::string& format);

    /**
     * @brief 使用printf风格格式化字符串
     *        支持完整的printf格式说明符，包括精度设置
     */
    static std::string FormatPrintf(const char* format, ...);


    template <typename T, typename... Args>
    static std::string FormatString(const std::string& format, T first, Args... args);
};

// 模板函数实现
template <typename T, typename... Args>
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      const char* format,
                                      T first,
                                      Args... args) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 使用printf风格格式化消息，支持精度设置
    std::string message_str = FormatPrintf(format, first, args...);

    // 打印彩色消息，使用用户要求的格式
    std::cout << color_code << "[" << type << "] " << message_str << reset_code << std::endl;
}

template <typename T, typename... Args>
std::string ColorPrinter::FormatString(const std::string& format, T first, Args... args) {
    std::string result = format;
    size_t pos = result.find('%');

    if (pos != std::string::npos) {
        // 查找完整的格式说明符（包括精度等）
        size_t end_pos = pos + 1;
        bool found_specifier = false;

        // 跳过格式说明符的各个部分：%[flags][width][.precision][length]type
        while (end_pos < result.length()) {
            char c = result[end_pos];
            if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
                c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' ||
                c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'p' || c == 'n') {
                found_specifier = true;
                end_pos++; // 包括类型字符
                break;
            } else if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0' ||
                      (c >= '0' && c <= '9') || c == '.') {
                // 继续查找，跳过标志、宽度、精度等
                end_pos++;
            } else {
                // 无效字符，停止查找
                break;
            }
        }

        if (found_specifier) {
            // 使用stringstream进行格式化
            std::stringstream ss;
            ss << first;
            std::string replacement = ss.str();

            // 替换整个格式说明符
            result.replace(pos, end_pos - pos, replacement);
        } else {
            // 如果没有找到有效的格式说明符，直接替换%
            std::stringstream ss;
            ss << first;
            std::string replacement = ss.str();
            result.replace(pos, 1, replacement);
        }
    }

    return FormatString(result, args...);
}

#endif // COLOR_PRINTER_H
