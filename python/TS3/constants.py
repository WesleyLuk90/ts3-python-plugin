
class ConnectStatus:
	#There is no activity to the server this is the default value
	STATUS_DISCONNECTED = 0
	#We are trying to connect we haven't got a clientID yet we haven't been accepted by the server
	STATUS_CONNECTING = 1
	#The server has accepted us we can talk and hear and we got a clientID but we don't have the channels and clients yet we can get server infos (welcome msg etc.)
	STATUS_CONNECTED = 2
	#we are CONNECTED and we are visible
	STATUS_CONNECTION_ESTABLISHING = 3
	#we are CONNECTED and we have the client and channels available
	STATUS_CONNECTION_ESTABLISHED = 4


class ChannelProperties:
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_NAME = 0
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_TOPIC = 1
	#Must be requested (=> requestChannelDescription)
	CHANNEL_DESCRIPTION = 2
	#not available client side
	CHANNEL_PASSWORD = 3
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_CODEC = 4
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_CODEC_QUALITY = 5
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_MAXCLIENTS = 6
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_MAXFAMILYCLIENTS = 7
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_ORDER = 8
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_FLAG_PERMANENT = 9
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_FLAG_SEMI_PERMANENT = 10
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_FLAG_DEFAULT = 11
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_FLAG_PASSWORD = 12
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_CODEC_LATENCY_FACTOR = 13
	#Available for all channels that are "in view" always up-to-date
	CHANNEL_CODEC_IS_UNENCRYPTED = 14
	#Not available client side not used in teamspeak only SDK. Sets the options+salt for security hash.
	CHANNEL_SECURITY_SALT = 15
	#How many seconds to wait before deleting this channel
	CHANNEL_DELETE_DELAY = 16
	CHANNEL_ENDMARKER = 17



class TalkStatus:
	STATUS_NOT_TALKING = 0
	STATUS_TALKING = 1
	STATUS_TALKING_WHILE_DISABLED = 2


class CodecType:
	# mono   16bit  8kHz bitrate dependent on the quality setting
	CODEC_SPEEX_NARROWBAND = 0
	# mono   16bit 16kHz bitrate dependent on the quality setting
	CODEC_SPEEX_WIDEBAND = 1
	# mono   16bit 32kHz bitrate dependent on the quality setting
	CODEC_SPEEX_ULTRAWIDEBAND = 2
	# mono   16bit 48kHz bitrate dependent on the quality setting
	CODEC_CELT_MONO = 3
	# mono   16bit 48khz bitrate dependent on the quality setting optimized for voice
	CODEC_OPUS_VOICE = 4
	# stereo 16bit 48khz bitrate dependent on the quality setting optimized for music
	CODEC_OPUS_MUSIC = 5


class CodecEncryptionMode:
	CODEC_ENCRYPTION_PER_CHANNEL = 0
	CODEC_ENCRYPTION_FORCED_OFF = 1
	CODEC_ENCRYPTION_FORCED_ON = 2


class TextMessageTargetMode:
	TextMessageTarget_CLIENT = 1
	TextMessageTarget_CHANNEL = 2
	TextMessageTarget_SERVER = 3
	TextMessageTarget_MAX = 4


class MuteInputStatus:
	MUTEINPUT_NONE = 0
	MUTEINPUT_MUTED = 1


class MuteOutputStatus:
	MUTEOUTPUT_NONE = 0
	MUTEOUTPUT_MUTED = 1


class HardwareInputStatus:
	HARDWAREINPUT_DISABLED = 0
	HARDWAREINPUT_ENABLED = 1


class HardwareOutputStatus:
	HARDWAREOUTPUT_DISABLED = 0
	HARDWAREOUTPUT_ENABLED = 1


class InputDeactivationStatus:
	INPUT_ACTIVE = 0
	INPUT_DEACTIVATED = 1


class ReasonIdentifier:
	# no reason data
	REASON_NONE = 0
	#:SectionInvoker}
	REASON_MOVED = 1
	# no reason data
	REASON_SUBSCRIPTION = 2
	# reasonmsg=reason
	REASON_LOST_CONNECTION = 3
	#:SectionInvoker} reasonmsg=reason               #:SectionInvoker} is only added server->client
	REASON_KICK_CHANNEL = 4
	#:SectionInvoker} reasonmsg=reason               #:SectionInvoker} is only added server->client
	REASON_KICK_SERVER = 5
	#:SectionInvoker} reasonmsg=reason bantime=time  #:SectionInvoker} is only added server->client
	REASON_KICK_SERVER_BAN = 6
	# reasonmsg=reason
	REASON_SERVERSTOP = 7
	# reasonmsg=reason
	REASON_CLIENTDISCONNECT = 8
	# no reason data
	REASON_CHANNELUPDATE = 9
	#:SectionInvoker}
	REASON_CHANNELEDIT = 10
	# reasonmsg=reason
	REASON_CLIENTDISCONNECT_SERVER_SHUTDOWN = 11


class ClientProperties:
	# automatically up-to-date for any client "in view" can be used to identify this particular client installation
	CLIENT_UNIQUE_IDENTIFIER = 0
	# automatically up-to-date for any client "in view"
	CLIENT_NICKNAME = 1
	# for other clients than ourself this needs to be requested (=> requestClientVariables)
	CLIENT_VERSION = 2
	# for other clients than ourself this needs to be requested (=> requestClientVariables)
	CLIENT_PLATFORM = 3
	# automatically up-to-date for any client that can be heard (in room / whisper)
	CLIENT_FLAG_TALKING = 4
	# automatically up-to-date for any client "in view" this clients microphone mute status
	CLIENT_INPUT_MUTED = 5
	# automatically up-to-date for any client "in view" this clients headphones/speakers/mic combined mute status
	CLIENT_OUTPUT_MUTED = 6
	# automatically up-to-date for any client "in view" this clients headphones/speakers only mute status
	CLIENT_OUTPUTONLY_MUTED = 7
	# automatically up-to-date for any client "in view" this clients microphone hardware status (is the capture device opened?)
	CLIENT_INPUT_HARDWARE = 8
	# automatically up-to-date for any client "in view" this clients headphone/speakers hardware status (is the playback device opened?)
	CLIENT_OUTPUT_HARDWARE = 9
	# only usable for ourself not propagated to the network
	CLIENT_INPUT_DEACTIVATED = 10
	# internal use
	CLIENT_IDLE_TIME = 11
	# only usable for ourself the default channel we used to connect on our last connection attempt
	CLIENT_DEFAULT_CHANNEL = 12
	# internal use
	CLIENT_DEFAULT_CHANNEL_PASSWORD = 13
	# internal use
	CLIENT_SERVER_PASSWORD = 14
	# automatically up-to-date for any client "in view" not used by TeamSpeak free storage for sdk users
	CLIENT_META_DATA = 15
	# only make sense on the client side locally "1" if this client is currently muted by us "0" if he is not
	CLIENT_IS_MUTED = 16
	# automatically up-to-date for any client "in view"
	CLIENT_IS_RECORDING = 17
	# internal use
	CLIENT_VOLUME_MODIFICATOR = 18
	# sign
	CLIENT_VERSION_SIGN = 19			
	# SDK use not used by teamspeak. Hash is provided by an outside source. A channel will use the security salt + other client data to calculate a hash which must be the same as the one provided here.
	CLIENT_SECURITY_HASH = 20
	CLIENT_ENDMARKER = 21


class VirtualServerProperties:
	# available when connected can be used to identify this particular server installation
	VIRTUALSERVER_UNIQUE_IDENTIFIER = 0
	# available and always up-to-date when connected
	VIRTUALSERVER_NAME = 1
	# available when connected  (=> requestServerVariables)
	VIRTUALSERVER_WELCOMEMESSAGE = 2
	# available when connected
	VIRTUALSERVER_PLATFORM = 3
	# available when connected
	VIRTUALSERVER_VERSION = 4
	# only available on request (=> requestServerVariables) stores the maximum number of clients that may currently join the server
	VIRTUALSERVER_MAXCLIENTS = 5
	# not available to clients the server password
	VIRTUALSERVER_PASSWORD = 6
	# only available on request (=> requestServerVariables)
	VIRTUALSERVER_CLIENTS_ONLINE = 7
	# only available on request (=> requestServerVariables)
	VIRTUALSERVER_CHANNELS_ONLINE = 8
	# available when connected stores the time when the server was created
	VIRTUALSERVER_CREATED = 9
	# only available on request (=> requestServerVariables) the time since the server was started
	VIRTUALSERVER_UPTIME = 10
	# available and always up-to-date when connected
	VIRTUALSERVER_CODEC_ENCRYPTION_MODE = 11
	VIRTUALSERVER_ENDMARKER = 12


class ConnectionProperties:
	# average latency for a round trip through and back this connection
	CONNECTION_PING = 0
	# standard deviation of the above average latency
	CONNECTION_PING_DEVIATION = 1
	# how long the connection exists already
	CONNECTION_CONNECTED_TIME = 2
	# how long since the last action of this client
	CONNECTION_IDLE_TIME = 3
	# IP of this client (as seen from the server side)
	CONNECTION_CLIENT_IP = 4
	# Port of this client (as seen from the server side)
	CONNECTION_CLIENT_PORT = 5
	# IP of the server (seen from the client side) - only available on yourself not for remote clients not available server side
	CONNECTION_SERVER_IP = 6
	# Port of the server (seen from the client side) - only available on yourself not for remote clients not available server side
	CONNECTION_SERVER_PORT = 7
	# how many Speech packets were sent through this connection
	CONNECTION_PACKETS_SENT_SPEECH = 8
	CONNECTION_PACKETS_SENT_KEEPALIVE = 9
	CONNECTION_PACKETS_SENT_CONTROL = 10
	# how many packets were sent totally (this is PACKETS_SENT_SPEECH + PACKETS_SENT_KEEPALIVE + PACKETS_SENT_CONTROL)
	CONNECTION_PACKETS_SENT_TOTAL = 11
	CONNECTION_BYTES_SENT_SPEECH = 12
	CONNECTION_BYTES_SENT_KEEPALIVE = 13
	CONNECTION_BYTES_SENT_CONTROL = 14
	CONNECTION_BYTES_SENT_TOTAL = 15
	CONNECTION_PACKETS_RECEIVED_SPEECH = 16
	CONNECTION_PACKETS_RECEIVED_KEEPALIVE = 17
	CONNECTION_PACKETS_RECEIVED_CONTROL = 18
	CONNECTION_PACKETS_RECEIVED_TOTAL = 19
	CONNECTION_BYTES_RECEIVED_SPEECH = 20
	CONNECTION_BYTES_RECEIVED_KEEPALIVE = 21
	CONNECTION_BYTES_RECEIVED_CONTROL = 22
	CONNECTION_BYTES_RECEIVED_TOTAL = 23
	CONNECTION_PACKETLOSS_SPEECH = 24
	CONNECTION_PACKETLOSS_KEEPALIVE = 25
	CONNECTION_PACKETLOSS_CONTROL = 26
	# the probability with which a packet round trip failed because a packet was lost
	CONNECTION_PACKETLOSS_TOTAL = 27
	# the probability with which a speech packet failed from the server to the client
	CONNECTION_SERVER2CLIENT_PACKETLOSS_SPEECH = 28
	CONNECTION_SERVER2CLIENT_PACKETLOSS_KEEPALIVE = 29
	CONNECTION_SERVER2CLIENT_PACKETLOSS_CONTROL = 30
	CONNECTION_SERVER2CLIENT_PACKETLOSS_TOTAL = 31
	CONNECTION_CLIENT2SERVER_PACKETLOSS_SPEECH = 32
	CONNECTION_CLIENT2SERVER_PACKETLOSS_KEEPALIVE = 33
	CONNECTION_CLIENT2SERVER_PACKETLOSS_CONTROL = 34
	CONNECTION_CLIENT2SERVER_PACKETLOSS_TOTAL = 35
	# howmany bytes of speech packets we sent during the last second
	CONNECTION_BANDWIDTH_SENT_LAST_SECOND_SPEECH = 36
	CONNECTION_BANDWIDTH_SENT_LAST_SECOND_KEEPALIVE = 37
	CONNECTION_BANDWIDTH_SENT_LAST_SECOND_CONTROL = 38
	CONNECTION_BANDWIDTH_SENT_LAST_SECOND_TOTAL = 39
	# howmany bytes/s of speech packets we sent in average during the last minute
	CONNECTION_BANDWIDTH_SENT_LAST_MINUTE_SPEECH = 40
	CONNECTION_BANDWIDTH_SENT_LAST_MINUTE_KEEPALIVE = 41
	CONNECTION_BANDWIDTH_SENT_LAST_MINUTE_CONTROL = 42
	CONNECTION_BANDWIDTH_SENT_LAST_MINUTE_TOTAL = 43
	CONNECTION_BANDWIDTH_RECEIVED_LAST_SECOND_SPEECH = 44
	CONNECTION_BANDWIDTH_RECEIVED_LAST_SECOND_KEEPALIVE = 45
	CONNECTION_BANDWIDTH_RECEIVED_LAST_SECOND_CONTROL = 46
	CONNECTION_BANDWIDTH_RECEIVED_LAST_SECOND_TOTAL = 47
	CONNECTION_BANDWIDTH_RECEIVED_LAST_MINUTE_SPEECH = 48
	CONNECTION_BANDWIDTH_RECEIVED_LAST_MINUTE_KEEPALIVE = 49
	CONNECTION_BANDWIDTH_RECEIVED_LAST_MINUTE_CONTROL = 50
	CONNECTION_BANDWIDTH_RECEIVED_LAST_MINUTE_TOTAL = 51
	CONNECTION_ENDMARKER = 52


class LogTypes:
	LogType_NONE = 0x0000
	LogType_FILE = 0x0001
	LogType_CONSOLE = 0x0002
	LogType_USERLOGGING = 0x0004
	LogType_NO_NETLOGGING = 0x0008
	LogType_DATABASE = 0x0010


class LogLevel:
	# these messages stop the program
	LogLevel_CRITICAL = 0
	# everything that is really bad but not so bad we need to shut down
	LogLevel_ERROR = 1
	# everything that *might* be bad
	LogLevel_WARNING = 2
	# output that might help find a problem
	LogLevel_DEBUG = 3
	# informational output like "starting database version x.y.z"
	LogLevel_INFO = 4
	# developer only output (will not be displayed in release mode)
	LogLevel_DEVEL = 5

class GroupWhisperType:
	GROUPWHISPERTYPE_SERVERGROUP = 0
	GROUPWHISPERTYPE_CHANNELGROUP = 1
	GROUPWHISPERTYPE_CHANNELCOMMANDER = 2
	GROUPWHISPERTYPE_ALLCLIENTS = 3
	GROUPWHISPERTYPE_ENDMARKER = 4


class GroupWhisperTargetMode:
	GROUPWHISPERTARGETMODE_ALL = 0
	GROUPWHISPERTARGETMODE_CURRENTCHANNEL = 1
	GROUPWHISPERTARGETMODE_PARENTCHANNEL = 2
	GROUPWHISPERTARGETMODE_ALLPARENTCHANNELS = 3
	GROUPWHISPERTARGETMODE_CHANNELFAMILY = 4
	GROUPWHISPERTARGETMODE_ANCESTORCHANNELFAMILY = 5
	GROUPWHISPERTARGETMODE_SUBCHANNELS = 6
	GROUPWHISPERTARGETMODE_ENDMARKER = 7


class MonoSoundDestination:
	# Send mono sound to all available speakers
  MONO_SOUND_DESTINATION_ALL =0
  # Send mono sound to front center speaker if available
  MONO_SOUND_DESTINATION_FRONT_CENTER =1
  # Send mono sound to front left/right speakers if available
  MONO_SOUND_DESTINATION_FRONT_LEFT_AND_RIGHT =2


class SecuritySaltOptions:
	# put nickname into security hash
	SECURITY_SALT_CHECK_NICKNAME = 1
	# put (game)meta data into security hash
	SECURITY_SALT_CHECK_META_DATA = 2


class ClientCommand:
	CLIENT_COMMAND_requestConnectionInfo =  0
	CLIENT_COMMAND_requestClientMove =  1
	CLIENT_COMMAND_requestXXMuteClients =  2
	CLIENT_COMMAND_requestClientKickFromXXX =  3
	CLIENT_COMMAND_flushChannelCreation =  4
	CLIENT_COMMAND_flushChannelUpdates =  5
	CLIENT_COMMAND_requestChannelMove =  6
	CLIENT_COMMAND_requestChannelDelete =  7
	CLIENT_COMMAND_requestChannelDescription =  8
	CLIENT_COMMAND_requestChannelXXSubscribeXXX =  9
	CLIENT_COMMAND_requestServerConnectionInfo = 10
	CLIENT_COMMAND_requestSendXXXTextMsg = 11
	CLIENT_COMMAND_ENDMARKER = 11


# Access Control List
class ACLType:
	ACL_NONE = 0
	ACL_WHITE_LIST = 1
	ACL_BLACK_LIST = 2
