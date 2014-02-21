# TS3 Python Plugin

TS3 Plugin to allow python scripts to be written in interface with TeamSpeak 3. Note: uses Python 2.7

## Compiling
For *nix run

```
make
```

For Windows, open the project in the TS3 Python Plugin. Check your python header include path and the python library incude path. Optionally there is a precompiled version in the Release directory.

## Installing
Copy the .so or .dll file to your TeamSpeak 3 plugin directory. Also copy the Python folder to your plugin directory. Your path should look like below.

```
<ts3-client-folder>/plugins/<plugin-name.so|dll>
<ts3-client-folder>/plugins/python/main.py
<ts3-client-folder>/plugins/python/TS3/__init__.py
...
```

## Using
Create a new directory in the plugins/python folder with a \_\_init\_\_.py file in it. This file is autoloaded by the plugin. See the provided EchoModule for a more complete example.

## Example
```
import TS3

class MyHandler(TS3.ClientEventHandler):
	def onTextMessageEvent(self, connection = None, **kwargs):
		message = kwargs['message']
		connection.printMessageToCurrentTab(message = message)

TS3.register_callback_handler(MyHandler())

###
