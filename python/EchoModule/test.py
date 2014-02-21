import TS3

class MyHandler(TS3.ClientEventHandler):
	def onTextMessageEvent(self, connection = None, **kwargs):
		message = kwargs['message']
		connection.printMessageToCurrentTab(message = message)

TS3.register_callback_handler(MyHandler())