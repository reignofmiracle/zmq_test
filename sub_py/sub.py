import sys
import zmq

context = zmq.Context()
socket = context.socket(zmq.SUB)
socket.setsockopt_string(zmq.SUBSCRIBE, '')
socket.connect ("tcp://localhost:9999")

while True:
    print(socket.recv())