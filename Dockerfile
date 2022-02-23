FROM ros:melodic-ros-base-bionic

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get -y upgrade && apt-get install -y \
    ros-melodic-rosserial \
    ros-melodic-rosserial-arduino \
    ros-melodic-joy 
    # wget 
    # python-pip \
    # ros-melodic-rqt-ez-publisher


RUN useradd -m -d /home/DockerUser DockerUser -p $(perl -e 'print crypt("DockerUser", "salt"),"\n"') && \
    echo "DockerUser ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# setup entrypoint
COPY ./ros_entrypoint.sh /
ENTRYPOINT ["/ros_entrypoint.sh"]

WORKDIR /home/DockerUser/
ENV USER DockerUser
USER DockerUser
RUN mkdir -p /home/DockerUser/arduino 

CMD ["bash"]