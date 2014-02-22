
class ConnectStatus:
	#There is no activity to the server, this is the default value
	STATUS_DISCONNECTED = 0
	#We are trying to connect, we haven't got a clientID yet, we haven't been accepted by the server
	STATUS_CONNECTING = 1             
	#The server has accepted us, we can talk and hear and we got a clientID, but we don't have the channels and clients yet, we can get server infos (welcome msg etc.)
	STATUS_CONNECTED = 2              
	#we are CONNECTED and we are visible
	STATUS_CONNECTION_ESTABLISHING = 3
	#we are CONNECTED and we have the client and channels available
	STATUS_CONNECTION_ESTABLISHED = 4 
