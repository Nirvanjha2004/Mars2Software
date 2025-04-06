import cv2
import numpy as np
import math

# Camera specifications
REAL_ARROW_WIDTH_CM = 17.0
IMAGE_WIDTH_PX = 1280
IMAGE_HEIGHT_PX = 720
DIAGONAL_FOV_DEG = 55.0

def detect_arrow(image_path):
    # Read and preprocess image
    image = cv2.imread(image_path)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    edges = cv2.Canny(blurred, 50, 150)

    # Find contours
    contours, _ = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for cnt in contours:
        approx = cv2.approxPolyDP(cnt, 0.02 * cv2.arcLength(cnt, True), True)

        if len(approx) == 7:  # Arrow shape heuristic
            cv2.drawContours(image, [approx], 0, (0, 255, 0), 3)
            print("Arrow detected!")

            # Get bounding box
            x, y, w, h = cv2.boundingRect(approx)
            perceived_width = max(w, h)  # Depending on arrow orientation

            # Calculate distance
            distance = find_distance(perceived_width)
            print(f"Estimated Distance: {distance:.2f} cm")

    cv2.imshow('Detected Arrow', image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def find_distance(perceived_width_px):
    # Approximate horizontal FOV from diagonal
    diagonal_resolution = math.hypot(IMAGE_WIDTH_PX, IMAGE_HEIGHT_PX)
    horizontal_fov_rad = 2 * math.atan(math.tan(math.radians(DIAGONAL_FOV_DEG) / 2) * (IMAGE_WIDTH_PX / diagonal_resolution))

    # Focal length using horizontal FOV
    focal_length_px = (IMAGE_WIDTH_PX / 2) / math.tan(horizontal_fov_rad / 2)

    # Distance using pinhole model
    distance_cm = (REAL_ARROW_WIDTH_CM * focal_length_px) / perceived_width_px
    return distance_cm

# Run detection
image_path = 'arrow.jpg'
detect_arrow(image_path)