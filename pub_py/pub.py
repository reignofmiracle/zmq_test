import datetime
import time

import zmq

context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:9999")

while True:
    now = datetime.datetime.now().isoformat()
    print(now)
    socket.send(now.encode())
    time.sleep(1)