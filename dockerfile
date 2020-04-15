FROM ubuntu
MAINTAINER zlodeeva d
RUN apt-get update && apt-get install -y gcc
WORKDIR /sp
COPY /laba3

