all:
	g++ thread_demo.cpp stat_context.cpp tls_util.cpp -o thread_demo -lpthread
clean:
	rm -r thread_demo
