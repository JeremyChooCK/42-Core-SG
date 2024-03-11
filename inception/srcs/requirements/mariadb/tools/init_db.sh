#!/bin/bash

# Wait for MariaDB to start
sleep 10

# Commands to create your database and users
mysql -u root -p"Password123!" <<-EOSQL
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS 'wp_user'@'%' IDENTIFIED BY 'wp_password';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wp_user'@'%';
FLUSH PRIVILEGES;
EOSQL
