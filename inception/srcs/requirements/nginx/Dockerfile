# Use the penultimate stable Debian image as the base
FROM debian:buster

# Install NGINX, openssl, and git
RUN apt-get update && apt-get install -y nginx openssl git

# Setup SSL certificates
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=US/ST=Denial/L=Springfield/O=Dis/CN=www.example.com"

# Clone the repository
RUN rm -rf /var/www/html/* && \
    git clone https://github.com/JeremyChooCK/2D-Car-learns-to-drive-with-N.E.A.T..git /var/www/html

# Adjust permissions to ensure NGINX can access the files
RUN chown -R www-data:www-data /var/www/html

# Copy the corrected NGINX configuration file
COPY conf/nginx.conf /etc/nginx/sites-available/myapp.conf

# Enable the site configuration and remove the default symlink
RUN ln -s /etc/nginx/sites-available/myapp.conf /etc/nginx/sites-enabled/ && \
    rm /etc/nginx/sites-enabled/default

# Expose the HTTPS port
EXPOSE 443

# Start NGINX in the foreground
CMD ["nginx", "-g", "daemon off;"]
