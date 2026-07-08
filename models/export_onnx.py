from ultralytics import YOLO
from ultralytics import NAS

from argparse import ArgumentParser

if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("-m", "--model", default="yolov8n.pt", type=str, help="Model to download")
    parser.add_argument("-n", "--nas", help="Download NAS model instead of YOLO", action="store_true")
    parser.add_argument("-s", "--static", help="Download static instead of dynamic", action="store_true")
    args = parser.parse_args()

    if args.nas:
        print("~~~ Download NAS model", args.model, "~~~")
        model = NAS(args.model)


    else:
        print("~~~ Downloading YOLO model", args.model, "~~~")
        model = YOLO(args.model)

    print("~~~ Exporting model as", "static" if args.static else "dynamic", "~~~")
    model.export(format="onnx", dynamic=not args.static, opset=11)

# Example: Export with dynamic batch size for batch inference support
# Uncomment the following lines to export a dynamic model
# This will create an ONNX model with dynamic batch dimension (batch size = -1)
# Useful for batch processing multiple images at once

