import parse_callbacks
import callback_class_generator
import callback_c_bindings_generator
import parse_ts3_functions
import ts3_function_bindings_generator
import ts3_python_functions_class_generator

functions = parse_callbacks.parse()
callback_class_generator.generate(functions)
callback_c_bindings_generator.generate(functions)

functions = parse_ts3_functions.parse()
ts3_function_bindings_generator.generate(functions)
ts3_python_functions_class_generator.generate(functions)