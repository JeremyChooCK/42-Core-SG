#!/bin/bash

# Custom initialization logic before starting MariaDB (optional)

# Start MariaDB in the background
mysqld_safe &

# Wait for MariaDB to start
while ! mysqladmin ping --silent; do
    sleep 1
done

# Execute the init_db script
/docker-entrypoint-initdb.d/init_db.sh
