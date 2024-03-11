# Use the penultimate stable Debian image as the base
FROM debian:buster

# Install MariaDB
RUN apt-get update && apt-get install -y mariadb-server

# Copy our custom configuration (if any)
COPY conf/my.cnf /etc/mysql/mariadb.conf.d/

# Copy the entrypoint script
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# Copy initialization script to execute when the container starts
COPY tools/init_db.sh /docker-entrypoint-initdb.d/
RUN chmod +x /docker-entrypoint-initdb.d/init_db.sh

# Expose the default MariaDB port
EXPOSE 3306

# Use the entrypoint script to initialize and start MariaDB
ENTRYPOINT ["entrypoint.sh"]
