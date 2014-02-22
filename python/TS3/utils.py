import constants

# Various classes to simplify basic operations

NEW_CHANNEL_ID = 0

class Channel:
	@classmethod
	def get_all_channels(cls, conn):
		channels = []
		for channel in conn.getChannelList():
			channels.append(Channel(conn, channel))
		return channels

	@classmethod
	def create_channel(cls, conn, name, parent, return_code = ""):
		conn.setChannelVariableAsString(
			channelID = NEW_CHANNEL_ID,
			flag = constants.ChannelProperties.CHANNEL_NAME,
			value = name)
		conn.setChannelVariableAsInt(
			channelID = 0,
			flag = constants.ChannelProperties.CHANNEL_FLAG_PERMANENT,
			value = 1)
		conn.flushChannelCreation(
			channelParentID = parent.channel_id,
			returnCode = return_code)

	def __init__(self, conn, channel_id):
		self.conn = conn
		self.channel_id = channel_id

	def get_clients(self):
		clients = []
		client_id_list = self.conn.getChannelClientList(
			channelID = self.channel_id)
		for client_id in client_id_list:
			clients.append(Client(self.conn, client_id))
		return clients

	def get_parent(self):
		return Channel(self.conn.getParentChannelOfChannel(
			channelID = self.channel_id
			))

	def get_name(self):
		return self.conn.getChannelVariableAsString(
			channelID = self.channel_id,
			flag = constants.ChannelProperties.CHANNEL_NAME)

	def set_name(self, name):
		conn.setChannelVariableAsString(
			channelID = self.channel_id,
			flag = constants.ChannelProperties.CHANNEL_NAME,
			value = name)

	def flush_updates(self, returnCode = ""):
		self.conn.flushChannelUpdates(
			channelID = self.channel_id,
			returnCode = returnCode)

class Client:
	@classmethod
	def get_all_clients(cls, conn):
		clients = []
		for client_id in conn.getClientList():
			clients.append(Client(conn, client_id))

	def __init__(self, conn, client_id):
		self.conn = conn
		self.client_id = client_id

	def send_private_message(self, message, returnCode = ""):
		self.conn.requestSendPrivateTextMsg(
			message = message,
			targetClientID = self.client_id,
			returnCode = returnCode)
