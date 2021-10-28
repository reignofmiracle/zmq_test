package main

import (
	"fmt"

	zmq "github.com/pebbe/zmq4"
)

func main() {
	subscriber, _ := zmq.NewSocket(zmq.SUB)
	defer subscriber.Close()
	subscriber.SetSubscribe("")

	subscriber.Connect("tcp://localhost:9999")

	for {
		address, _ := subscriber.Recv(0)
		fmt.Println(address)
	}
}
