/**
 * 代理模式是一种结构型设计模式， 让你能够提供对象的替代品或其占位符。 代理控制着对于原对象的访问， 并允许在将请求提交给对象前后进行一些处理。
 * 代理模式更像是把原本的接口再次封装一遍，
 */

#include "proxy.h"

int main()
{
  std::shared_ptr<subject> subject_1 = std::make_shared<real_subject>();

  std::shared_ptr<subject> proxy_1 = std::make_shared<proxy>(subject_1);

  proxy_1->request();
  return 0;
} 