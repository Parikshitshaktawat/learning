import matplotlib.pyplot as plt
import numpy as np

# Grid dimensions: 7 days per week for 52 weeks (approx. 12 months)
rows = 7
cols = 52

# Create a blank grid
grid = np.zeros((rows, cols))

# Function to mark contribution (1 means 'push', 0 means 'no push')
def mark_contributions(grid, positions):
    for pos in positions:
        row, col = pos
        grid[row, col] = 1

# Example coordinates to form "Hello World!" (You would adjust these to create the letters)
hello_world_positions = [
    # H
    (1, 2), (2, 2), (3, 2), (4, 2), (3, 3), (1, 4), (2, 4), (3, 4), (4, 4),
    # E
    (1, 6), (2, 6), (3, 6), (4, 6), (1, 7), (3, 7), (4, 7),
    # L
    (1, 9), (2, 9), (3, 9), (4, 9), (4, 10),
    # L
    (1, 12), (2, 12), (3, 12), (4, 12), (4, 13),
    # O
    (1, 15), (2, 15), (3, 15), (4, 15), (1, 16), (4, 16), (1, 17), (2, 17), (3, 17), (4, 17),
    # W
    (1, 20), (2, 20), (3, 20), (4, 20), (2, 21), (3, 21), (4, 21), (1, 22), (4, 22),
    # O
    (1, 24), (2, 24), (3, 24), (4, 24), (1, 25), (4, 25), (1, 26), (2, 26), (3, 26), (4, 26),
    # R
    (1, 28), (2, 28), (3, 28), (4, 28), (1, 29), (3, 29), (1, 30), (2, 30), (4, 30),
    # L
    (1, 32), (2, 32), (3, 32), (4, 32), (4, 33),
    # D
    (1, 35), (2, 35), (3, 35), (4, 35), (1, 36), (4, 36), (1, 37), (2, 37), (3, 37), (4, 37),
    # !
    (1, 39), (3, 39), (4, 39)
]

# Mark the positions on the grid
mark_contributions(grid, hello_world_positions)

# Plot the contribution graph
plt.figure(figsize=(10, 3))  # Set figure size
plt.imshow(grid, cmap="Greens", aspect="auto")  # Green color for the contribution effect
plt.title("Simulated GitHub Contribution Grid: 'Hello World!'")
plt.axis('off')  # Hide the axes
plt.show()

