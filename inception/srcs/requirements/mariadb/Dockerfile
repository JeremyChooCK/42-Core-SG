#=========MariaDB DOCKERFILE===========

# Tell the system where from to build the image, in which OS to build upon
FROM debian:buster

# DEPENDANCIES
RUN apt-get update && apt-get install -y \
	mariadb-server mariadb-client && \
	rm -rf /var/lib/apt/lists/*

# Remove the original config file from mariadb and replace it with your own
RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf
COPY conf/my.conf /etc/mysql/mariadb.conf.d
RUN mysql_install_db 

# You can use ENV to set permanently the environment variables during build time, 
# if you use this then take the out "args" from the docker-compose.yml, else use ARG instead
ARG DB_NAME=${DB_DATABASE}
ARG DB_USER=${DB_USER}
ARG DB_PASSWORD=${DB_PASSWORD}
ARG DB_ROOT_PASSWORD=${DB_ROOT_PASSWORD}

# Copy the script to create your user in your desired folder where you will run it from
COPY ./tools/init_db.sh /

#RUN chmod +x ./create_user.sh  to give permission
RUN bash ./init_db.sh
RUN service mysql stop

# Do mind that this port will only be exposed for other docker containers but not for the host
EXPOSE	3306

#The CMD command will run nginx, but since it runs in the background we need to 
#leave it running in the foreground with the "daemon off;" flag otherwise when the image is
#finished being built nginx will stop.
CMD ["mysqld_safe"]

#-----------------------------