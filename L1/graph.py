import matplotlib.pyplot as plt
import sys

text = sys.stdin.read()
text = text.split()

pos = []
vel = []

ticker = True

for i in range(len(text)):
    if (i+1) % 2 == 0:
        if ticker:
            pos.append(text[i])
            ticker = False
        else:
            vel.append(text[i])
            ticker = True

plt.plot(pos, label='position')
plt.plot(vel, label='velocity')
plt.legend()
plt.ylabel('position and velocity')
plt.show()
