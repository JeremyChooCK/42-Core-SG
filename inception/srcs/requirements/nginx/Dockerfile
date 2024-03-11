# Use the penultimate stable Debian image as the base
FROM debian:buster

# Install NGINX
RUN apt-get update && apt-get install -y nginx openssl

# Setup SSL certificates
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=US/ST=Denial/L=Springfield/O=Dis/CN=www.example.com"

# Remove the default configuration and add our custom configuration
RUN rm /etc/nginx/sites-enabled/default
COPY conf/nginx.conf /etc/nginx/sites-available/

# Symlink to enable our site
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/

# Expose the HTTPS port
EXPOSE 443

# Start NGINX in the foreground
CMD ["nginx", "-g", "daemon off;"]
