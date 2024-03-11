# Use the penultimate stable Debian image as the base
FROM debian:buster

# Install Nginx and other necessary tools
RUN apt-get update && \
    apt-get install -y nginx git

# Remove the default Nginx configuration
RUN rm /etc/nginx/sites-enabled/default

# Clone your GitHub repository
RUN git clone https://github.com/JeremyChooCK/2D-Car-learns-to-drive-with-N.E.A.T..git /var/www/html/myapp

# Create a simple Nginx configuration to serve your project
RUN echo "server {\n\
    listen 80;\n\
    server_name _;\n\
    root /var/www/html/myapp;\n\
    index index.html;\n\
    location / {\n\
        try_files \$uri \$uri/ =404;\n\
    }\n\
}" > /etc/nginx/sites-available/myapp

# Enable the Nginx configuration
RUN ln -s /etc/nginx/sites-available/myapp /etc/nginx/sites-enabled/

# Expose port 80 to access Nginx
EXPOSE 80

# Start Nginx in the foreground
CMD ["nginx", "-g", "daemon off;"]
