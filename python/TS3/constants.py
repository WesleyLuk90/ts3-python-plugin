
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


class ChannelProperties:
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_NAME = 0
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_TOPIC = 1
	#Must be requested (=> requestChannelDescription)
	CHANNEL_DESCRIPTION = 2
	#not available client side
	CHANNEL_PASSWORD = 3
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_CODEC = 4
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_CODEC_QUALITY = 5
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_MAXCLIENTS = 6
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_MAXFAMILYCLIENTS = 7
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_ORDER = 8
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_FLAG_PERMANENT = 9
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_FLAG_SEMI_PERMANENT = 10
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_FLAG_DEFAULT = 11
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_FLAG_PASSWORD = 12
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_CODEC_LATENCY_FACTOR = 13
	#Available for all channels that are "in view", always up-to-date
	CHANNEL_CODEC_IS_UNENCRYPTED = 14
	#Not available client side, not used in teamspeak, only SDK. Sets the options+salt for security hash.
	CHANNEL_SECURITY_SALT = 15
	#How many seconds to wait before deleting this channel
	CHANNEL_DELETE_DELAY = 16
	CHANNEL_ENDMARKER = 17
