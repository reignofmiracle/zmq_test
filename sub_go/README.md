# Build
docker build -t zmq_test .

# Run
docker run --network host --rm -d --name zmq_test zmq_test 

# logging
docker logs -f zmq_test

# Stop
docker stop zmq_test

# Removal
docker rm zmq_test
