FROM debian

RUN apt-get update

RUN apt-get install gcc g++ valgrind make man -y

CMD [ "bash" ]
