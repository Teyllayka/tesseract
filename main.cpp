#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>

int main()
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("lieciba.jpg");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    //char *token = strtok(outText, "ar Sadam");
    //printf("%s\n", token);

    std::string str(outText);

    unsigned first = str.find("pabeidza");
    unsigned last = str.find("ar Sadam");
    std::string strNew = str.substr(first+9,last-first-9);

    std::cout << strNew << std::endl;
    first = str.find("Vards, uzvards");
    last = str.find("personas kods");
    strNew = str.substr(first+15,last-first-15);

    std::cout << strNew << std::endl;

    first = str.find("personas kods");
    last = str.find("apguva");
    strNew = str.substr(first+14,last-first-14);
    
    std::cout << strNew << std::endl;

    first = str.find("sekmém:");

    strNew = str.substr(first+8);
    
    std::cout << strNew << std::endl;

    
    //printf("OCR output:\n%s", outText);

    // Destroy used object and release memory




    api->End();
    delete api;
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
