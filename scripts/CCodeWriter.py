
class CCodeWriter:
	def __init__(self, file):
		self.file = file
		self.indent = 0

	def write(self, data):
		lines = data.split("\n")
		for i, line in enumerate(lines):
			if line.strip() == "}":
				self.file.write("\t" * (self.indent - 1))
			else:
				self.file.write("\t" * self.indent)
			self.file.write(line.strip())

			self.indent += line.count("{");
			self.indent -= line.count("}");
			if i < len(lines) - 1:
				self.file.write("\n")

	def write_line(self, data):
		self.write(data)
		self.file.write("\n")

	def close(self):
		self.file.close()