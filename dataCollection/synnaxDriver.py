import socket
import struct
import synnax as sy

# --- Socket Setup ---
UDP_IP = "192.168.1.100"     # Listen on all interfaces
UDP_PORT = 5005        # Must match Arduino's destination port

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))
print(f"Listening for UDP packets on {UDP_IP}:{UDP_PORT} ...")

# --- Synnax Setup ---
client = sy.Synnax(
    host="localhost",
    port=9090,
    username="synnax",
    password="seldon",
)

# Create index (time) channel
index_channel = client.channels.create(
    name="arduino_time",
    is_index=True,
    data_type="timestamp",
    retrieve_if_name_exists=True,
)

# Create sensor data channels
channels = {
    "dht_temp": client.channels.create(
        name="dht_temperature",
        index=index_channel.key,
        data_type="float32",
        retrieve_if_name_exists=True,
    ),
    "dht_hum": client.channels.create(
        name="dht_humidity",
        index=index_channel.key,
        data_type="float32",
        retrieve_if_name_exists=True,
    ),
}

print("Connected to Synnax and channels ready.")

# --- Stream Data ---
with client.open_writer(
    start=sy.TimeStamp.now(),
    channels=["arduino_time", *[ch.name for ch in channels.values()]],
    enable_auto_commit=True
) as writer:
    while True:
        data, addr = sock.recvfrom(1024)
        if len(data) == 8:  # Expect 4 floats (4 bytes each)
            dhtT, dhtH = struct.unpack('ff', data)
            print(f"From {addr}: DHT_T={dhtT:.2f}°C, DHT_H={dhtH:.2f}%")

            writer.write({
                "arduino_time": sy.TimeStamp.now(),
                "dht_temperature": dhtT,
                "dht_humidity": dhtH,
            })