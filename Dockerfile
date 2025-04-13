FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++

COPY . /app
WORKDIR /app

RUN g++ -o sorter main.cpp

CMD ["./sorter", "0", "tests/input1.txt"]
