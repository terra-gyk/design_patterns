/**
 * 依赖注入原则
 * 高层模块不应该依赖低层模块，它们都应该依赖于抽象。此外，抽象不应该依赖于细节，细节应该依赖于抽象。
 * 
 */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


// 抽象接口
class i_logger {
public:
    virtual void Log(const string& message) = 0;
};

// 具体实现
class console_logger : public i_logger {
public:
    void Log(const string& message) override {
        cout << message << endl;
    }
};

// 高层模块
class application {
private:
    i_logger* logger;

public:
    application(i_logger* logger) : logger(logger) {}

    void run() {
        // 应用程序运行逻辑
        logger->Log("application is running.");
    }
};

int main() {
    i_logger* logger = new console_logger();
    application app(logger);
    app.run();
    delete logger;
    return 0;
}
