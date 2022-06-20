from PIL import Image, ImageFilter
from cs50 import get_string
import sys

picture = sys.argv[1]

input = get_string("What filter do you want (black and white/blur)")

image = Image.open(f"{picture}")

if input == ("black and white"):
    image = image.convert("L")
    image.save("after.jpeg")

if input == ("blur"):
    image = image.filter(ImageFilter.BLUR)
    image.save(p"{picture} after")
