import serial
import matplotlib.pyplot as plt

# Configure the serial port (replace 'COM3' with your Arduino's port)
ser = serial.Serial('COM3', 9600, timeout=1)

# Initialize empty lists to store data
angles = []
distances = []

# Create a live plot
plt.ion()
fig, ax = plt.subplots()
ax.set_xlim(0, 180)
ax.set_ylim(0, 200)
line, = ax.plot([], [], 'b-')
ax.set_xlabel('Angle (degrees)')
ax.set_ylabel('Distance (cm)')

plt.title('Ultrasonic Radar System')

# Read and plot data in real-time
try:
    while True:
        data = ser.readline().decode('utf-8').strip()
        if data:
            angle, distance = map(int, data.split(','))
            angles.append(angle)
            distances.append(distance)

            # Update the plot
            line.set_data(angles, distances)
            plt.pause(0.01)
except KeyboardInterrupt:
    ser.close()
