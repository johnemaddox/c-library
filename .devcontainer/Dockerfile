FROM gcc:latest

RUN apt-get update \
    && apt-get upgrade -y

RUN apt-get install -y \
        gdb \
        cmake \
        vim \
        googletest

RUN cd /usr/src/googletest \
    && cmake -S . -B build \
    && make -C build install

# https://code.visualstudio.com/remote/advancedcontainers/add-nonroot-user
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# # create user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

# # login as user
USER $USERNAME
