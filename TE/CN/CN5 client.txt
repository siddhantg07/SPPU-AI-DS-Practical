import socket

def start_client():

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


    server_ip = '127.0.0.1'  # Localhost for testing; replace with actual server IP in a real network
    server_port = 12345
    client_socket.connect((server_ip, server_port))


    client_socket.sendall("Hello from Client!".encode())


    data = client_socket.recv(1024).decode()
    print(f"Server says: {data}")


    client_socket.close()

if __name__ == "__main__":
    start_client()
