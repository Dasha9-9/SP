FROM ubuntu
MAINTAINER zlodeeva d
<<<<<<< dee7cbfae416dcc4a7b7d791cf132a449233b982
RUN apt-get update && apt-get install -y gcc
WORKDIR /sp
COPY /laba3
=======
<<<<<<< dee7cbfae416dcc4a7b7d791cf132a449233b982
RUN apt-get update && apt-get install -y gcc
WORKDIR /sp
COPY /laba3
=======
RUN apt-get update && apt-get install -y g++
WORKDIR /sp
COPY /lab5
>>>>>>> lab56
>>>>>>> lab56

