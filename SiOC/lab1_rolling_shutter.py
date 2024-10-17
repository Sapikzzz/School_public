import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter
from PIL import Image

N = 5  # Ilość łopatek

def propeller(theta, m, N):
    return np.sin(N * theta + m * np.pi / 10)

thetas = np.linspace(-np.pi, np.pi, 1000)

square_side = 8  # zmienne używane do obliczenia rozdzielczości wykresu
dots_per_inch = 64

y_axis = square_side * dots_per_inch  # pozwala na pracowanie na dowolnej rozdzielczości, określa także ilość klatek w gifie

figure = plt.figure(figsize=(square_side, square_side), dpi=dots_per_inch)
plot = plt.polar([])[0]

def animate(frame):
    propeller_curve = propeller(thetas, frame, N)
    plot.set_data((thetas, propeller_curve))

animation = FuncAnimation(figure, animate, frames=y_axis, interval=25)
animation.save("rotating_propeller.gif", writer=PillowWriter(fps=25))

gif = Image.open("rotating_propeller.gif")
frame_width, frame_height = gif.size

multi = 2  # ilość pikseli pobieranych w dół
temp = 0
parts = []

try:
    while True:
        frame = gif.copy()
        part = frame.crop((0, temp * multi, y_axis, temp * multi + multi))
        parts.append(part)
        gif.seek(len(parts))
        temp += 1
except EOFError:
    pass

merged_image = Image.new("RGB", (frame_width, frame_height))
temp = 0

for i, part in enumerate(parts):
    merged_image.paste(part, (0, temp * multi))
    temp += 1
    if (temp * multi > y_axis):
        break
merged_image.save("merged_image.png")
if True == 0:
    print("xdd")
#xdd
#xddasd
#xddasd
#test sstasadf
#kolejny xdd 