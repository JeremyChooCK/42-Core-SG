# Tell the system where from to build the image, in which OS to build upon
FROM debian:buster

# install nginx and update the system (debian is limited with its package manager so run apt-get
RUN apt-get update && \
	apt-get  -y install nginx && \
	apt-get install openssl

# nginx SSL
RUN mkdir  /etc/nginx/ssl

# Copy our config file in the nginx config folder
# COPY ./conf/default /etc/nginx/sites-available
COPY ./conf/nginx.conf /etc/nginx/sites-available
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/
#Create the self signed SSL certificates and out them in your own files (place them in a new folder)
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/jechoo.crt \
	-keyout /etc/nginx/ssl/jechoo.key \
	#You could also save them in the ssl folder directly
	# 	-out /etc/ssl/certs/jechoo.crt \
	# -keyout /etc/ssl/private/jechoo.key \ 
	-subj "/CN=jechoo.42.fr/"

#the only port allowed gets exposed from the Docker file
EXPOSE	443

#The CMD command will run nginx, but since it runs in the background we need to 
#leave it running in the foreground with the "daemon off;" flag otherwise when the image is
#finished being built nginx will stop.
CMD ["nginx", "-g", "daemon off;"]

#-----------------------------
