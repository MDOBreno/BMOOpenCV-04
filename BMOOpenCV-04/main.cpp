//
//  main.cpp
//  BMOOpenCV-04
//
//  Created by Breno Medeiros on 28/03/20.
//  Copyright © 2020 ProgramasBMO. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include "stdint.h"

using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    String caminho = "/Users/brenomedeiros/Documents/ProgramasBMO/Cpp/BMOOpenCV-04/BMOOpenCV-04/";
    String caminhoImagens = "/Users/brenomedeiros/Documents/ProgramasBMO/Cpp/BMOOpenCV-04/BMOOpenCV-04/Images/";
    
    Mat original = imread(caminhoImagens+"Me.jpeg", CV_LOAD_IMAGE_COLOR);
    Mat cinzaEscuro = imread(caminhoImagens+"Me.jpeg", CV_LOAD_IMAGE_GRAYSCALE);
    Mat coloridoEscuro = imread(caminhoImagens+"Me.jpeg", CV_LOAD_IMAGE_COLOR);
    
    for (int linha=0; linha<coloridoEscuro.rows; linha++) {
        for (int coluna=0; coluna<coloridoEscuro.cols; coluna++) {
            cinzaEscuro.at<uint8_t>(linha, coluna) = cinzaEscuro.at<uint8_t>(linha,coluna) * 0.5f; //Azul
            cinzaEscuro.at<uint8_t>(linha, coluna) = cinzaEscuro.at<uint8_t>(linha,coluna) * 0.5f; //Verde
            coloridoEscuro.at<cv::Vec3b>(linha, coluna)[0] = coloridoEscuro.at<cv::Vec3b>(linha,coluna)[0] * 0.5f; //Azul
            coloridoEscuro.at<cv::Vec3b>(linha, coluna)[1] = coloridoEscuro.at<cv::Vec3b>(linha,coluna)[1] * 0.5f; //Verde
            coloridoEscuro.at<cv::Vec3b>(linha, coluna)[2] = coloridoEscuro.at<cv::Vec3b>(linha,coluna)[2] * 0.5f; //Vermelho
        }
    }
    
    imshow("Original", original);
    imshow("Cinza Escuro", cinzaEscuro);
    imshow("Colorido Escuro", coloridoEscuro);
    
    waitKey();

    return 0;
}
