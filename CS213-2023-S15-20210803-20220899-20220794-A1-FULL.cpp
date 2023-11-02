/*
Team members:
1. Name: Atem Abuok Deng Gai
   ID: 20210803
   Email: atemchapter733@gmail.com
2. Name: James Kuch Ngong Madut
   ID: 20220899
   Email: kushthii1@gmail.com
3. Name: Ajak Deng Ajak
   ID: 20220794
   Email: ajakdeng01@gmail.com
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char temp[SIZE][SIZE];
unsigned char mirror[SIZE][SIZE];

// Functions for loading, filtering and saving a gray scale image
void loadImage ();
void saveImage ();
void saveMirror ();
void BW();
void invert();
void merge();
void flipV();
void flipH();
void MergeloadImage();
void rotate90();
void rotate180();
void rotate270();
void rotateSaveImage();
void edge();
void lighter();
void darker();
void mirrorImageLeft();
void mirrorImageRight();
void mirrorImageUpper();
void mirrorImageLower();
void detectImageEdges();
void cropImage();
void cropImage(int len, int wid);

int main()
{
/*
The infinite while loop continuously run and displays options for applying the filters 
to a gray scale image and breaks when the user enters 0 (Exit).
*/
while (true){
    cout<<"\nPhoto Editor Tool\n";
    cout<<"Please select a filter to apply or 0 to exit:\n";
    cout<<"1. Black and White Filter\n";
    cout<<"2. Invert Filter\n";
    cout<<"3. Merge Filter\n";
    cout<<"4. Flip Filter\n";
    cout<<"5. Darken and Lighten Image\n";
    cout<<"6. Rotate Image\n";
    cout<<"7. Detect Image Edges\n";
    cout<<"8. Enlarge Image\n";
    cout<<"9. Shrink Image\n";
    cout<<"a. Mirror 1/2 Image\n";
    cout<<"b. Shuffle Image\n";
    cout<<"c. Blur Image\n";
    cout<<"d. Crop Image\n";
    cout<<"e. Skew Image Right\n";
    cout<<"f. Skew Image Up\n";
    cout<<"s. Save the image to a file\n";
    cout<<"0. Exit\n\n";

    char option;
    cout<<"Option > ";
    cin>>option;
    cout<<"\n";

    // This condition checks if the selected option is 1, it will apply a black and white filter
    if (option == '1'){
        cout<<"Selected filter: BLACK AND WHITE\n";
        char saveImg;
        loadImage();
        BW();
        cout<<"Do you want to save your filtered image? ( Y or N): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"Successful! Your filtered Black and White image is saved in the current working directory.\n";
        }
    }
    // This condition checks if the selected option is 2, it will apply the invert filter
    else if (option == '2'){
        cout<<"Selected filter: INVERT IMAGE\n";
        char saveImg;
        loadImage();
        invert();
        cout<<"Do you want to save your filtered image? ( Y or N): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"Successful! Your Inverted image is saved in the current working directory.\n";
        }
    }
    // This condition checks if the selected option is 3, it will apply merge images filter
    else if (option == '3'){
        cout<<"Selected filter: MERGE IMAGES\n";
        char saveImg;
        MergeloadImage();
        merge();
        cout<<"Do you want to save your filtered image? ( Y or N): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"Successful! Your merged image is saved in the current working directory.\n";
        }
    }
    // This condition checks if the selected option is 4, it will apply a flip image filter
    else if (option == '4'){
        cout<<"Selected filter: FLIP IMAGE\n";
        char saveImg, flipImg;
        loadImage();
        cout<<"Do you want to flip it Horizontally or Vertically? (H or V): ";
        cin>>flipImg;
        if (flipImg == 'H' || flipImg == 'h'){
            flipH();
        } else if (flipImg == 'V' || flipImg == 'v'){
            flipV();
        }
        cout<<"Do you want to save your filtered image? ( Y or N): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"Successful! Your flipped image is saved in the current working directory.\n";
        }
    }
    // This condition checks if the selected option is 5, it will apply a black and white filter
    else if (option == '5'){
        cout<<"Selected filter: DARKEN AND LIGHTEN FILTER\n";
        char saveImg, dImg;
        loadImage();
        cout<<"Do you want to darken or lighten the image? (D or L): ";
        cin>>dImg;
        if (dImg == 'D' || dImg == 'd'){
            darker();
        } else if (dImg == 'L' || dImg == 'l'){
            lighter();
        }
        cout<<"Do you want to save your filtered image? ( Y or N): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"Successful! Your image is saved in the current working directory.\n";
        }
    }
    // This condition checks if the selected option is 1, it will apply a black and white filter
    else if (option == '6'){
        cout<<"Selected filter: ROTATE IMAGE FILTER\n";
        char saveImg;
        string degree;
        loadImage();
        cout<<"Do you want to rotate the image? (90, 180, 270): ";
        cin>>degree;
        if (degree == "90"){
            rotate90();
        } else if (degree == "180"){
            rotate180();
        } else if (degree == "270"){
            rotate270();
        }
        cout<<"Do you want to save your filtered image? ( Y or N): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            rotateSaveImage();
            cout<<"Successful! Your image is saved in the current working directory.\n";
        }
    }
    // This condition checks if the selected option is 7, it will apply a detect image filter
    else if (option == '7'){
        cout<<"Selected filter: DETECT IMAGE EDGES\n";
        char saveImg;
        loadImage();
        detectImageEdges();
        cout<<"Do you want to rotate the image? ( Y or N): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
            cout<<"Successful! Your image is saved in the current working directory.\n";
        }
    }
    // This condition checks if the selected option is a, it will apply a mirror image filter
    else if (option == 'a'){
        cout<<"Selected filter: MIRROR 1/2 IMAGE\n";
        loadImage();
        char saveImg;
        string chos;
        cout<<"Mirror image Left, Right, Upper or Lower (LT, RT, UR or LR): ";
        cin>>chos;
        if (chos == "LT" || chos == "lt"){
            mirrorImageLeft();
        } else if (chos == "RT" || chos == "rt"){
            mirrorImageRight();
        } else if (chos == "UR" || chos == "ur"){
            mirrorImageUpper();
        } else if (chos == "LR" || chos == "lr"){
            mirrorImageLower();
        }
        cout<<"Do you want to save the image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveMirror();
        }
    }
    // This condition checks if the selected option is d, it will apply a crop image filter
    else if (option == 'd'){
        cout<<"Selected filter: CROP IMAGE\n";
        loadImage();
        char saveImg;
        int len, wid;
        cout<<"Enter the length: ";
        cin>>len;
        cout<<"Enter the width: ";
        cin>>wid;
        cropImage(len, wid);
        cout<<"Do you want to save the image? ( Y or N ): ";
        cin>>saveImg;
        if (saveImg == 'Y' || saveImg == 'y'){
            saveImage();
        }
    }
    // This condition checks if the selected option is 1, it will apply a black and white filter
    else if (option == '0'){
        break;
    }
}

  return 0;
}

//_________________________________________Perfect
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________Perfect
void MergeloadImage () {
   char imageFileName[100];
   char imageFileName2[100];

   // Get gray scale image file name
   cout << "Enter the source image file name 1: ";
   cin >> imageFileName;
   cout << "Enter the source image file name 2: ";
   cin >> imageFileName2;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   strcat (imageFileName2, ".bmp");
   readGSBMP(imageFileName, image);
   readGSBMP(imageFileName2, image2);
}



//_________________________________________Perfect
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________Perfect
void saveMirror () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, mirror);
}

void rotateSaveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, temp);
}



// _________________________________________Perfect
void BW() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}



// _________________________________________Perfect
void invert() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = 255 - image[i][j];
        }
    }
}



// _________________________________________Perfect
void merge() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = image[i][j]/2 + image2[i][j]/2;
        }
    }
}



// _________________________________________Perfect
void flipV() {
    const int ROWS = SIZE; const int COLS = SIZE;
    for (int i=0; i<ROWS/2; i++){
        for (int j=0; j<COLS; j++){
            unsigned char temP = image[i][j];
            image[i][j] = image[ROWS - i - 1][j];
            image[ROWS - i - 1][j] = temP;
        }
    }
}



// _________________________________________Perfect
void flipH() {
    const int ROWS = SIZE; const int COLS = SIZE;
    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLS/2; j++){
            unsigned char temP = image[i][j];
            image[i][j] = image[i][ROWS - j - 1];
            image[i][ROWS - j - 1] = temP;
        }
    }
}



// _________________________________________Perfect
void rotate90() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[j][SIZE - 1 - i] = image[i][j];
        }
    }
}



// _________________________________________Perfect
void rotate180() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[SIZE - 1 - i][SIZE - 1 - j] = image[i][j];
        }
    }
}




// _________________________________________Perfect
void rotate270() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            temp[SIZE - 1 - j][i] = image[i][j];
        }
    }
}




// _________________________________________Perfect
void lighter(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = (image[i][j]/2) + 127;
        }
    }
}




// _________________________________________Perfect
void darker(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = image[i][j]/2;
        }
    }
}




// _________________________________________Perfect
void detectImageEdges(){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            if (image[i][j] > 127 && image[i+1][j+1] < 127 || image[i][j] < 127 && image[i+1][j+1] > 127){
                image[i][j] = 0;
            } else {
                image[i][j] = 255;
            }
        }
    }
}




// _________________________________________Perfect
void mirrorImageLeft(){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE/2; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = 0;
    for(int i=0; i<SIZE; i++){
        int jj = SIZE-1;
        for(int j=0; j<SIZE/2; j++){
            mirror[ii][jj] = image[i][j];
            jj--;
        }
        ii++;
    }
}




// _________________________________________Perfect
void mirrorImageRight(){
    for(int i=0; i<SIZE; i++){
        for(int j=SIZE/2; j<SIZE; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = 0;
    for(int i=0; i<SIZE; i++){
        int jj = 0;
        for(int j=SIZE-1; j>=SIZE/2; j--){
            mirror[ii][jj] = image[i][j];
            jj++;
        }
        ii++;
    }
}




// _________________________________________Perfect
void mirrorImageUpper(){
    for(int i=0; i<SIZE/2; i++){
        for(int j=0; j<SIZE; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = SIZE-1;
    for(int i=0; i<SIZE/2; i++){
        int jj = 0;
        for(int j=0; j<SIZE; j++){
            mirror[ii][jj] = image[i][j];
            jj++;
        }
        ii--;
    }
}




// _________________________________________Perfect
void mirrorImageLower(){
    for(int i=SIZE/2; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            mirror[i][j] = image[i][j];
        }
    }
    int ii = SIZE/2;
    for(int i=SIZE/2; i<SIZE; i++){
        int jj = 0;
        for(int j=0; j<SIZE; j++){
            mirror[ii][jj] = image[i][j];
            jj++;
        }
        ii--;
    }
}




// _________________________________________Perfect
void cropImage(int len, int wid){
    for(int i=0; i<SIZE/wid; i++){
        for(int j=0; j<SIZE; j++){
            image[i][j] = 255;
        }
    }
    for(int i=SIZE-1; i>SIZE-(SIZE/wid); i--){
        for(int j=0; j<SIZE; j++){
           image[i][j] = 255;
        }
    }
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE/len; j++){
            image[i][j] = 255;
        }
    }
    for(int i=0; i<SIZE; i++){
        for(int j=SIZE-1; j>SIZE-(SIZE/len); j--){
            image[i][j] = 255;
        }
    }
}