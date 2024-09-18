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
class ILogger {
public:
    virtual void Log(const string& message) = 0;
};

// 具体实现
class ConsoleLogger : public ILogger {
public:
    void Log(const string& message) override {
        cout << message << endl;
    }
};

// 高层模块
class Application {
private:
    ILogger* logger;

public:
    Application(ILogger* logger) : logger(logger) {}

    void Run() {
        // 应用程序运行逻辑
        logger->Log("Application is running.");
    }
};

int main() {
    ILogger* logger = new ConsoleLogger();
    Application app(logger);
    app.Run();
    delete logger;
    return 0;
}
