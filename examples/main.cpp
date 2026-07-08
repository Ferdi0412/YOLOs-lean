#include <yolos/yolos.hpp>

#include <opencv2/opencv.hpp>

#include <string>

int main(int argc, char** argv) {
    int cam = 0;
    std::string device = "cpu";

    for ( int i = 0; i < argc; i++ ) {
        try {
            cam = std::stoi(argv[i]);
        }
        catch ( const std::exception& e ) {
            device = argv[i];
        }


    }

    cv::VideoCapture cap(cam);

    yolos::pose::YOLOPoseDetector detector("yolov8n-pose.onnx", device);

    while ( cap.isOpened() ) {
        cv::Mat frame;

        if ( !cap.read(frame) )
            break;

        auto detections = detector.detect(frame);

        detector.drawPoses(frame, detections);

        cv::imshow("yolos", frame);

        int key = cv::waitKey(1);

        if ( key == 'q' || key == 27 /* 'ESC' */ )
            break;
    }

    cap.release();
    cv::destroyAllWindows();
}