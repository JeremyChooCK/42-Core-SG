#========= WORDPRESS  DOCKERFILE ===========

FROM debian:buster

RUN apt-get update && apt-get -y install \
	mariadb-client \
	wget \
	curl \
	bash \
	php \
	php-cgi \
	php-mysql \
	php-fpm \
	php-pdo \
	php-gd php-cli \
	php-mbstring \
	&& rm -rf /var/lib/apt/lists/*
# I need to install wp_cli command and put it in the right directory /usr/local/bin
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

# Copy the .conf in the html directory 
RUN mkdir -p /etc/php/7.3/fpm
COPY ./www.conf /etc/php/7.3/fpm/pool.d

#Create the folder to enable php start
RUN mkdir /run/php

#we copy the script, give the right to launch it in local on our computer
COPY ./entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

# make the working directory the one where the WP files are stored
WORKDIR /var/www/wordpress
#We expose the 9000 port
EXPOSE 9000
