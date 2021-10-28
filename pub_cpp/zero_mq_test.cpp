#include "pch.h"

#include <ctime>
#include <Windows.h>

#include "zmq.h"

TEST(ZeroMQTest, _pub_sub) {
	auto context = zmq_ctx_new();
	auto pub = zmq_socket(context, ZMQ_PUB);
	zmq_bind(pub, "tcp://*:9999");

	char buf[128];
	while (true) {
		std::time_t now = std::time(nullptr);
		auto now_str = std::asctime(std::localtime(&now));
		std::clog << now_str << std::endl;
		sprintf_s(buf, 128, "%s", now_str);
		zmq_send(pub, buf, strlen(buf), ZMQ_NOBLOCK);
		Sleep(1000);
	}

	zmq_close(pub);
	zmq_ctx_destroy(context);
}