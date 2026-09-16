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
    times, angles = load_data("data/uncontrolled.csv")

    plt.figure(figsize=(8, 5))
    plt.plot(times, angles, label="Angle (uncontrolled)")
    plt.axhline(0, color="gray", linestyle="--", linewidth=0.8, label="Upright (0 rad)")
    plt.xlabel("Time (s)")
    plt.ylabel("Angle (rad)")
    plt.title("Uncontrolled Inverted Pendulum: Angle vs. Time")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("docs/screenshots/uncontrolled_fall.png")
    plt.show()

if __name__ == "__main__":
    main()