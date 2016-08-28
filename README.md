# LocalThread_Demo
__thread example, C++


root@ubuntu:/home/nginx/cpp_thread/thread_demo# make clean; make 
rm -r thread_demo
g++ thread_demo.cpp stat_context.cpp tls_util.cpp -g -o thread_demo -lpthread
root@ubuntu:/home/nginx/cpp_thread/thread_demo# ./thread_demo
__thread: 0xb6200468
__thread: 0xb6200498
statistic total counter: 6000
