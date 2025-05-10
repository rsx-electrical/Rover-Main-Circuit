import serial
import serial.tools.list_ports


def list_all_ports():
	ports = [port.device for port in serial.tools.list_ports.comports()]
	return ports


ports = list_all_ports()

if len(ports) == 0:
	print("No port found. Exiting.")
	import sys
	sys.exit(0)
elif len(ports) > 1:
	print("There are multiple ports connected:")
	for port in ports:
		print(f"\t{port}")
	port = input("Please enter the port name you want: ")
else:
	port = ports[0]

board = serial.Serial(port=port, baudrate=115200, timeout=1)

def write_read(x): 
	board.write(bytes(x, 'utf-8')) 
	return

if __name__ == "__main__":
	write_read(input())