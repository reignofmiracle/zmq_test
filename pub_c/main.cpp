#include <ctime>
#include <cstring>
#include <iostream>
#include <unistd.h>

#include "zmq.h"

int main() {
	auto context = zmq_ctx_new();
	auto pub = zmq_socket(context, ZMQ_PUB);
	zmq_bind(pub, "tcp://*:9999");

	char buf[128];
	while (true) {
		std::time_t now = std::time(nullptr);
		auto now_str = std::asctime(std::localtime(&now));
		std::clog << now_str << std::endl;
		sprintf(buf, "%s", now_str);
		zmq_send(pub, buf, strlen(buf), ZMQ_NOBLOCK);
		sleep(1);
	}

	zmq_close(pub);
	zmq_ctx_destroy(context);
}