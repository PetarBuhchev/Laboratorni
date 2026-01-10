import matplotlib.pyplot as plt
import numpy as np

# Данни
t = np.linspace(0, 10, 100)
alpha = 0.5 * t  # линейна зависимост

# Графика
plt.figure(figsize=(6,4))
plt.plot(t, alpha, label='α = k·t', linewidth=2)
plt.title("Зависимост на ъгловото ускорение от времето")
plt.xlabel("време t")
plt.ylabel("ъглово ускорение α")
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.show()
