def calculate_subnet_mask(ip_address):
    octets = ip_address.split('.')
    first_octet = int(octets[0])
    if 1 <= first_octet <= 126:
        ip_class = 'A'
        subnet_mask = '255.0.0.0'
    elif 128 <= first_octet <= 191:
        ip_class = 'B'
        subnet_mask = '255.255.0.0'
    elif 192 <= first_octet <= 223:
        ip_class = 'C'
        subnet_mask = '255.255.255.0'
    elif 224 <= first_octet <= 239:
        ip_class = 'D (Multicast)'
        subnet_mask = 'N/A'
    elif 240 <= first_octet <= 255:
        ip_class = 'E (Reserved)'
        subnet_mask = 'N/A'
    else:
        ip_class = 'Invalid'
        subnet_mask = 'N/A'

    return ip_class, subnet_mask
ip_address = input("Enter an IP Address: ")

ip_class, subnet_mask = calculate_subnet_mask(ip_address)

print(f"IP Address: {ip_class}")
print(f"Class: {ip_class}")
print(f"Subnet Mask: {subnet_mask}")