ARG VARIANT="noble"
FROM buildpack-deps:${VARIANT}-curl

# Label for features
LABEL dev.containers.features="common"

# Delete 'ubuntu' user if the variant is 'noble'
ARG VARIANT
RUN [ "$VARIANT" = "noble" ] && id "ubuntu" &>/dev/null && userdel -f -r ubuntu || echo "User 'ubuntu' not found or deletion skipped"

# User and workspace setup
ARG user_id=1000
ARG group_id=${user_id}
ARG usr=bensimmersdev
ARG workspace_env_name=workspace

ENV FRONTEND=noninteractive \
  LANG=en_US.UTF-8 \
  LANGUAGE=en_US:en \
  LC_ALL=en_US.UTF-8 \
  SHELL=/bin/bash

# Install packages and clean up
RUN apt-get update && apt-get install -y --no-install-recommends \
  bash bash-completion sudo git ssh vim wget curl dpkg gnupg \
  apt-transport-https ca-certificates build-essential software-properties-common \
  libicu-dev unzip jq htop less man net-tools iputils-ping dnsutils \
  libncurses5-dev libncursesw5-dev \
  iproute2 man-db manpages nano tmux locales neofetch && \
  apt-get clean && rm -rf /var/lib/apt/lists/*




# Generate locale
RUN echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && locale-gen && update-locale LANG=en_US.UTF-8

# Create user and set permissions
RUN groupadd --gid ${group_id} ${usr} && \
  useradd --uid ${user_id} --gid ${group_id} -m ${usr} && \
  echo "${usr} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/${usr} && \
  chmod 0440 /etc/sudoers.d/${usr} && \
  mkdir -p /${workspace_env_name} && \
  chown -R ${user_id}:${group_id} /home/${usr} /${workspace_env_name}

USER ${usr}
WORKDIR /${workspace_env_name}

RUN mkdir -p ~/bin ~/scripts
