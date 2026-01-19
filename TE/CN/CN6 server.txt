import socket
import os


def send_file(file_name, server_address):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    file_size = os.path.getsize(file_name)
    with open(file_name, 'rb') as f:
        bytes_sent = 0
        while bytes_sent < file_size:
            bytes_data = f.read(1024)
            sock.sendto(bytes_data, server_address)
            bytes_sent += len(bytes_data)
            print(f"Sending {file_name}: Sent {len(bytes_data)} bytes")

    sock.sendto(b'', server_address)  # End of transmission signal
    print(f"{file_name} sent successfully.")
    sock.close()


def get_file_choice():
    print("Select the type of file you want to send:")
    print("1. Script file (.py)")
    print("2. Text file (.txt)")
    print("3. Audio file (.mp3)")
    print("4. Video file (.mp4)")
    print("5. Other file types")

    choice = input("Enter the number corresponding to your choice: ")

    if choice in ['1', '2', '3', '4', '5']:
        file_type = {
            '1': 'script',
            '2': 'text',
            '3': 'audio',
            '4': 'video',
            '5': 'other'
        }[choice]
        return file_type
    else:
        print("Invalid choice, please try again.")
        return get_file_choice()


if __name__ == "__main__":
    # Change to receiver's IP address and port number
    server_address = ('127.0.0.1', 12345)
    file_type = get_file_choice()

    file_name = input(f"Enter the name of the {file_type} file to send (with extension): ")
    if os.path.isfile(file_name):
        send_file(file_name, server_address)
    else:
        print("File does not exist. Please check the file name and try again.")
