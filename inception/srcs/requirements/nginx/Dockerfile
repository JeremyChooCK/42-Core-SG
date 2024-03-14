FROM debian:buster

RUN apt-get update && \
	apt-get  -y install nginx && \
	apt-get install openssl

RUN mkdir  /etc/nginx/ssl

COPY ./conf/nginx.conf /etc/nginx/sites-available

RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/jechoo.crt \
	-keyout /etc/nginx/ssl/jechoo.key \
	-subj "/CN=jechoo.42.fr/"

EXPOSE	443

CMD ["nginx", "-g", "daemon off;"]

#-----------------------------
