#!/usr/bin/env python2

#Serwer

import os
import sys
import json
import os

class App(object):
#sprawdzamy pakiet, pobieramy dlugosc
	try:
		packet_leng = int(environ.get('CONTENT_LENGTH', 0))
	except (ValueError):
		packet_leng = 0

#pobieramy caly pakiet
	packet = environ['wsgi.input'].read(packet_leng)
	orders = json.loads(packet)

#dodac wybieranie z jsona informacji, obsluga modelu

	ret_packet = json.dump(x)
	stat = '200 OK'

	response_headers = [('Content-Type', 'application/json'), ('Content-Length', str(len(ret_packet)))]
	start_response(stat, response_headers)
	return [ret_packet]


#jesli jest to glowny modul, wlaczamy serwer
if __name__ == '__main__':
	from flup.server.fcgi import WSGIServer
	WSGIServer(App).run()
