#include <iostream>

// 懒汉式 -- 调用时构造
class singleton_lazy {

private:
  singleton_lazy();

public:
  // 删除拷贝构造 赋值构造
  singleton_lazy(singleton const&) = delete;
  singleton_lazy& operator=(singleton const&) = delete;

  // 单例模式实现的关键
  static singleton_lazy* getSingleton(); 
  static singleton_lazy* single_instance;
}

singleton_lazy* singleton_lazy::single_instance = nullptr;

singleton_lazy* singleton_lazy::getSingleton() {
  // 为保证懒汉式的线程安全,可简单粗暴的这么写，建议此处用原子量，开销会小一些
  // std::lock_guard lk(mutex);
  if (single_instance == nullptr) {
    single_instance = new singleton_lazy();
  }

  return single_instance;
};

// 饿汉式 -- 初始化时构造
class singleton_hunger {

private:
  singleton_hunger();

public:
  // 删除拷贝构造 赋值构造
  singleton_hunger(singleton const&) = delete;
  singleton_hunger& operator=(singleton const&) = delete;

  // 单例模式实现的关键
  static singleton_hunger* getSingleton(); 
  static singleton_hunger* single_instance;
}

singleton_hunger* singleton_hunger::single_instance = new singleton_hunger;

singleton_hunger* singleton_hunger::getSingleton() {
  return single_instance;
}


// 扩充：单态模式
class single {
private:
  static int id;
public:
  int get_id() const { return id; };
  void set_id(int val) { id = val; };
}
int single::id = 0;
