import csv
import matplotlib.pyplot as plt

def load_data(filename):
    times = []
    angles = []
    with open(filename, newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            times.append(float(row["time"]))
            angles.append(float(row["angle"]))
    return times, angles

def main():
    scenarios = [
        ("data/underdamped.csv", "Underdamped (Kp=1.0)"),
        ("data/tuned.csv", "Tuned (Kp=5.0)"),
        ("data/overdamped.csv", "Overdamped (Kp=20.0)"),
    ]

    plt.figure(figsize=(8, 5))

    for filename, label in scenarios:
        times, angles = load_data(filename)
        plt.plot(times, angles, label=label)

    plt.axhline(0, color="gray", linestyle="--", linewidth=0.8, label="Upright (0 rad)")
    plt.xlabel("Time (s)")
    plt.ylabel("Angle (rad)")
    plt.title("Controlled Pendulum: Gain Comparison")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("docs/screenshots/gain_comparison.png")
    plt.show()

if __name__ == "__main__":
    main()