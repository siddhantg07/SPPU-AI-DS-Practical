import socket

def start_server():

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


    server_ip = '127.0.0.1'
    server_port = 12345
    server_socket.bind((server_ip, server_port))


    server_socket.listen(1)
    print(f"Server is listening on {server_ip}:{server_port}...")


    conn, client_address = server_socket.accept()
    print(f"Connection established with {client_address}")


    data = conn.recv(1024).decode()
    print(f"Client says: {data}")


    conn.sendall("Hello from Server!".encode())


    conn.close()

if __name__ == "__main__":
    start_server()
