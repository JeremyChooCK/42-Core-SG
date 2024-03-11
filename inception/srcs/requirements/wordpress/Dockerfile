# Use the penultimate stable Debian image as the base
FROM debian:buster

RUN mkdir -p /run/php

# Install WordPress dependencies and php-fpm
RUN apt-get update && apt-get install -y php-fpm php-mysql wget

# Create the /var/www directory
RUN mkdir -p /var/www

# Download and extract WordPress
RUN wget https://wordpress.org/latest.tar.gz -O /tmp/wordpress.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /var/www/ && \
    chown -R www-data:www-data /var/www/wordpress

# Configure php-fpm to listen on a socket
RUN sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/' /etc/php/7.3/fpm/pool.d/www.conf

# Expose the port php-fpm is listening on
EXPOSE 9000

# Start php-fpm in the foreground
CMD ["php-fpm7.3", "-F"]
