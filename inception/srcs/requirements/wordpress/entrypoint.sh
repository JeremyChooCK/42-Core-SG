#!/bin/bash

# Path to the object-cache.php file
OBJECT_CACHE_FILE="/var/www/wordpress/wp-content/object-cache.php"

# Check if the object-cache.php file exists and remove it
if [ -f "$OBJECT_CACHE_FILE" ]; then
    echo "Removing object-cache.php to disable Redis caching..."
    rm -f "$OBJECT_CACHE_FILE"
fi

cd /var/www/wordpress

wp core download "--allow-root"

wp core config "--dbhost=$WORDPRESS_DB_HOST" \
                "--dbname=$WORDPRESS_DB_NAME" \
                "--dbuser=$WORDPRESS_DB_USER" \
                "--dbpass=$WORDPRESS_DB_PASSWORD" \
                "--allow-root"

wp core install "--title=$WP_TITLE" \
                "--admin_user=$WP_ADMIN_USER" \
                "--admin_password=$WP_ADMIN_PASSWORD" \
                "--admin_email=$WP_ADMIN_MAIL" \
                "--url=$WP_URL" \
                "--allow-root"

# wp theme install chique-photography.1.1.1.zip -activate (Uncomment if you want to install a specific theme)
wp user create $WP_USER $WP_USER_MAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root

wp option update home 'http://localhost' --allow-root
wp option update siteurl 'http://localhost' --allow-root

# Launch PHP FPM in foreground, ignoring daemonize from conf file (-F)
php-fpm7.3 -F
