/**
 * @file color_printer.cpp
 * @brief 彩色打印工具类的实现
 */

#include "color_printer.h"
#include <cstdarg>
#include <cstdio>

/**
 * @brief 打印彩色字符串（const char*版本）
 *        专门处理字符串字面量
 *
 * @param color 颜色类型 (PrintColor枚举)
 * @param type 消息类型 ("INFO", "ERROR", "WARNING", "OK", "DEBUG")
 * @param message 要打印的消息内容（字符串字面量）
 */
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      const char* message) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 检查消息是否包含格式化占位符
    std::string msg_str(message);
    bool hasFormatSpecifier = (msg_str.find('%') != std::string::npos);

    if (!hasFormatSpecifier) {
        // 纯字符串，直接打印
        std::cout << color_code << "[" << type << "] " << msg_str << reset_code << std::endl;
    } else {
        // 包含格式化占位符，但没有提供参数，当作纯字符串处理
        std::cout << color_code << "[" << type << "] " << msg_str << reset_code << std::endl;
    }
}

/**
 * @brief 打印彩色字符串（std::string版本）
 *        处理std::string对象
 *
 * @param color 颜色类型 (PrintColor枚举)
 * @param type 消息类型 ("INFO", "ERROR", "WARNING", "OK", "DEBUG")
 * @param message 要打印的消息内容（std::string对象）
 */
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      const std::string& message) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 检查消息是否包含格式化占位符
    bool hasFormatSpecifier = (message.find('%') != std::string::npos);

    if (!hasFormatSpecifier) {
        // 纯字符串，直接打印
        std::cout << color_code << "[" << type << "] " << message << reset_code << std::endl;
    } else {
        // 包含格式化占位符，但没有提供参数，当作纯字符串处理
        std::cout << color_code << "[" << type << "] " << message << reset_code << std::endl;
    }
}

/**
 * @brief 打印彩色数字（bool版本）
 *        注意：bool类型放在前面，避免与字符串字面量冲突
 *
 * @param color 颜色类型 (PrintColor枚举)
 * @param type 消息类型
 * @param value 要打印的布尔值
 */
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      bool value) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 打印彩色消息，使用用户要求的格式
    std::cout << color_code << "[" << type << "] " << (value ? "true" : "false") << reset_code << std::endl;
}

/**
 * @brief 打印彩色数字（char版本）
 *
 * @param color 颜色类型 (PrintColor枚举)
 * @param type 消息类型
 * @param value 要打印的字符
 */
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      char value) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 打印彩色消息，使用用户要求的格式
    std::cout << color_code << "[" << type << "] " << value << reset_code << std::endl;
}

/**
 * @brief 打印彩色数字（int版本）
 *
 * @param color 颜色类型 (PrintColor枚举)
 * @param type 消息类型
 * @param value 要打印的整数值
 */
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      int value) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 打印彩色消息，使用用户要求的格式
    std::cout << color_code << "[" << type << "] " << value << reset_code << std::endl;
}

/**
 * @brief 打印彩色数字（float版本）
 *
 * @param color 颜色类型 (PrintColor枚举)
 * @param type 消息类型
 * @param value 要打印的浮点数值
 */
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      float value) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 打印彩色消息，使用用户要求的格式
    std::cout << color_code << "[" << type << "] " << value << reset_code << std::endl;
}

/**
 * @brief 打印彩色数字（double版本）
 *
 * @param color 颜色类型 (PrintColor枚举)
 * @param type 颜色类型
 * @param value 要打印的双精度浮点数值
 */
void ColorPrinter::PrintColoredMessage(PrintColor color,
                                      const std::string& type,
                                      double value) {
    std::string color_code = GetColorCode(color);
    const std::string reset_code = "\033[0m";

    // 打印彩色消息，使用用户要求的格式
    std::cout << color_code << "[" << type << "] " << value << reset_code << std::endl;
}

/**
 * @brief 获取颜色代码
 *
 * @param color 颜色枚举值
 * @return ANSI颜色代码
 */
std::string ColorPrinter::GetColorCode(PrintColor color) {
    switch (color) {
        case PrintColor::RED:
            return "\033[31m";  // 红色
        case PrintColor::GREEN:
            return "\033[32m";  // 绿色
        case PrintColor::YELLOW:
            return "\033[33m";  // 黄色
        case PrintColor::BLUE:
            return "\033[34m";  // 蓝色
        case PrintColor::MAGENTA:
            return "\033[35m";  // 品红
        case PrintColor::CYAN:
            return "\033[36m";  // 青色
        case PrintColor::WHITE:
            return "\033[37m";  // 白色
        default:
            return "\033[0m";   // 默认颜色（重置）
    }
}

/**
 * @brief 格式化字符串（基础情况）
 *
 * @param format 格式字符串
 * @return 格式化后的字符串
 */
std::string ColorPrinter::FormatString(const std::string& format) {
    return format;
}

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
void ColorPrinter::PrintSilentStatusIndicator(PrintColor color, bool isSilent, int& countRef) {
    // 当处于静默状态时打印累积的点号，最多打印100个点，达到100个后清空并重新开始循环
    if (isSilent) {
        countRef++;

        // 如果count超过100，清空并重置
        if (countRef > 100) {
            std::cout << "\r                      \r" << std::flush;  // 清空行（"[INFO] " + 100个"."）
            countRef = 1;  // 重置为1，开始新的循环
        }

        // 回到行首，重新打印完整的当前状态
        std::string color_code = GetColorCode(color);
        std::cout << "\r" << color_code << "[INFO] ";
        for (int i = 0; i < countRef; i++) {
            std::cout << ".";
        }
        std::cout << "\033[0m" << std::flush;
    }
}

/**
 * @brief 使用printf风格格式化字符串
 *        支持完整的printf格式说明符，包括精度设置
 *
 * @param format 格式字符串
 * @param ... 可变参数
 * @return 格式化后的字符串
 */
std::string ColorPrinter::FormatPrintf(const char* format, ...) {
    va_list args;

    // 第一次调用vsnprintf来确定需要的缓冲区大小
    va_start(args, format);
    int size = vsnprintf(nullptr, 0, format, args);
    va_end(args);

    if (size < 0) {
        return std::string(); // 格式化错误
    }

    // 分配足够大的缓冲区并格式化
    std::string result(size + 1, '\0');
    va_start(args, format);
    vsnprintf(&result[0], size + 1, format, args);
    va_end(args);

    // 移除末尾的null字符
    result.resize(size);
    return result;
}
