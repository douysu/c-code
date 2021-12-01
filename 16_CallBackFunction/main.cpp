#include <iostream>
#include <functional>

class NativeWindow {
public:
    using KeyFunc = std::function<void(int)> ;

    // 设置回调函数
    void set_key_callback(KeyFunc func) {
        m_key_callback = func;
    }

    // 运行函数
    void run() {
        if (m_key_callback) {
            m_key_callback(42);
        }
    }
private:
    KeyFunc m_key_callback;
};

class MyWindow {
public:
    MyWindow() {
        m_window = new NativeWindow();

        // OK: capturing lambda to std::function
        m_window->set_key_callback([this](int key) {
            this->on_key(key);
            });
        
        // OK: works, but not as clear as capturing lambda
        m_window->set_key_callback(std::bind(&MyWindow::on_key, this, std::placeholders::_1));
    }
    ~MyWindow() {
        delete m_window;
    }
    void run() {
        m_window->run();
    }
    void on_key(int key) {
        std::cout << "key: " << key << "\n";
    }

private:
    NativeWindow* m_window;
};


int main() {
    MyWindow my_window;
    my_window.run();
    return 0;
}