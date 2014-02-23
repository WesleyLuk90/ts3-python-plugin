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
		return Channel(self.conn, self.conn.getParentChannelOfChannel(
			channelID = self.channel_id
			))

	def get_children(self):
		children = []
		for channel in Channel.get_all_channels(self.conn):
			if channel.get_parent() == self:
				children.append(channel)
		return children

	def get_name(self):
		return self.conn.getChannelVariableAsString(
			channelID = self.channel_id,
			flag = constants.ChannelProperties.CHANNEL_NAME)

	def set_name(self, name):
		self.conn.setChannelVariableAsString(
			channelID = self.channel_id,
			flag = constants.ChannelProperties.CHANNEL_NAME,
			value = name)

	def flush_updates(self, returnCode = ""):
		self.conn.flushChannelUpdates(
			channelID = self.channel_id,
			returnCode = returnCode)

	def delete(self, returnCode = ""):
		self.conn.requestChannelDelete(
			channelID = self.channel_id,
			force = False,
			returnCode = returnCode)

	def move_to_channel(self, password = "", returnCode = ""):
		self.conn.requestClientMove(
			clientID = Client.get_self(self.conn).client_id,
			newChannelID = self.channel_id,
			password = password,
			returnCode = returnCode)

	def __eq__(self, other):
		return self.channel_id == other.channel_id

	def __ne__(self, other):
		return not (self.channel_id == other.channel_id)

	def set_client_channel_group(self, group, dbid, returnCode = ""):
		self.conn.requestSetClientChannelGroup(
			channelGroupIDArray = [group],
			channelIDArray = [self.channel_id],
			clientDatabaseIDArray = [dbid],
			arraySize = 1,
			returnCode = returnCode)

class Client:
	@classmethod
	def get_all_clients(cls, conn):
		clients = []
		for client_id in conn.getClientList():
			clients.append(Client(conn, client_id))
		return clients

	@classmethod
	def get_self(cls, conn):
		return Client(conn, conn.getClientID())

	def __init__(self, conn, client_id):
		self.conn = conn
		self.client_id = client_id

	def get_name(self, returnCode = ""):
		return self.conn.getClientVariableAsString(
			clientID = self.client_id,
			flag = constants.ClientProperties.CLIENT_NICKNAME,
			returnCode = returnCode)

	def send_private_message(self, message, returnCode = ""):
		self.conn.requestSendPrivateTextMsg(
			message = message,
			targetClientID = self.client_id,
			returnCode = returnCode)

	def get_unique_identifier(self, returnCode = ""):
		return self.conn.getClientVariableAsString(
			clientID = self.client_id,
			flag = constants.ClientProperties.CLIENT_UNIQUE_IDENTIFIER,
			returnCode = returnCode)

	def request_dbid(self, returnCode = ""):
		self.conn.requestClientDBIDfromUID(
			clientUniqueIdentifier = self.get_unique_identifier(),
			returnCode = returnCode)

	def get_channel(self):
		return Channel(self.conn, self.conn.getChannelOfClient(clientID = self.client_id))