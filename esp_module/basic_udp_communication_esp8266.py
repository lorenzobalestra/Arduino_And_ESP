import socket, time

# create our udp socket
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
except s.error:
    print("Oops, something went wrong connecting the socket")
    print("Is the ESP on and did you connect to the wifi?")
    exit()

#s.settimeout(3.5) # sets the listening timeout. If no timeout, the program will wait until response is received, which might be dangerous if the system glitches/stops working unexpectedly. 

try:
    message = "Hello from the PC"
    print("Sending message: " + message)
	s.sendto(message, ("192.168.1.25", 4100))
except socket.error as e:
	print("Error! {}".format(e))
	exit()

while 1:
    try:

        # output the response (if any)
        data, ip = s.recvfrom(1024)

        print("{}: {}".format(ip, data.decode()))

    except socket.error as e:
        print("Error! {}".format(e))
        exit()

    time.sleep(0.005)
