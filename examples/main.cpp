#include <yolos/yolos.hpp>

#include <opencv2/opencv.hpp>

#include <string>

int main(int argc, char** argv) {
    int cam = argc > 1 ? std::stoi(argv[1]) : 0;

    cv::VideoCapture cap(cam);

    yolos::pose::YOLOPoseDetector detector("yolov8n-pose.onnx", "", true);

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