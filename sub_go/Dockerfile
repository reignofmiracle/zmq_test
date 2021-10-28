FROM golang

RUN mkdir -p /workspace
WORKDIR /workspace

# apt-get
RUN apt-get update
RUN apt-get install -y libzmq3-dev

# source code
COPY . .
RUN go build

CMD ./main
