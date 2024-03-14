FROM debian:buster

RUN apt-get update && apt-get install -y \
	mariadb-server mariadb-client && \
	rm -rf /var/lib/apt/lists/*

RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf
COPY conf/my.conf /etc/mysql/mariadb.conf.d
RUN mysql_install_db 

ARG DB_NAME=${DB_DATABASE}
ARG DB_USER=${DB_USER}
ARG DB_PASSWORD=${DB_PASSWORD}
ARG DB_ROOT_PASSWORD=${DB_ROOT_PASSWORD}

COPY ./tools/init_db.sh /

RUN bash ./init_db.sh
RUN service mysql stop

EXPOSE	3306

CMD ["mysqld_safe"]

#-----------------------------