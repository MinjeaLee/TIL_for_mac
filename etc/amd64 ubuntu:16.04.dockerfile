FROM --platform=linux/amd64 ubuntu:16.04
RUN cd ~/
RUN apt-get update
RUN sed -i 's/us.archive.ubuntu.com/mirror.kakao.com/g' /etc/apt/sources.list
RUN sed -i 's/archive.ubuntu.com/mirror.kakao.com/g' /etc/apt/sources.list 
RUN sed -i 's/security.ubuntu.com/mirror.kakao.com/g' /etc/apt/sources.list
RUN sed -i 's/extras.ubuntu.com/mirror.kakao.com/g' /etc/apt/sources.list && apt-get update
RUN apt-get install vim git curl libssl-dev libffi-dev build-essential terminator -y && apt-get install libc6-i386 gcc-multilib -y && apt-get install python3 python3-pip -y
RUN apt-get install wget -y && wget https://bootstrap.pypa.io/pip/3.5/get-pip.py
RUN python3 get-pip.py
RUN pip3 install -U pwntools
RUN git clone https://github.com/pwndbg/pwndbg
RUN cd pwndbg && ./setup.sh
RUN cd / && rm get-pip.py