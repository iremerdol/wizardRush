# wizardRush
group16 CENG201 team project

-----------------------------------------------------------------------------
 You should download Qt Creator from their official site. Here is the link: https://www.qt.io/download

 Unfortunately Qt does not give proper .exe file to just play the game because it's not open source. So you must install Qt Creator to open the game in your computer.
 You will have to sign up to the site because it wants you to sign in while installing the application. You should select that you're not in a company so Qt gives you the community(free) version.
 Then please install Qt 6.6.0 version. For SDK please select both MinGW 64-Bit and MSVC2019 64-Bit(Visual Studio 2019). Configure the project for both of these SDKs. 

 If it doesn't work anyways you can just open a new project and add same named files to the project. {You should do it in Qt's file edit part -If you just do it in file explorer Qt will not see those-.. After creating the files in Qt edit, you should copy the inside of the original files.
 If you right-click to Sources -which includes all .cpp files- and select "add new" then you will see C/C++ please click that. Select adding h/cpp[C Class] it should create both h and cpp for the same name.
 And for the resources first you should copy our "assets" folder to your new project file. Then you just have to right-click the project folder select "add new" again and you will see Qt please click that. you will see the qrc[Qt Resource File] if you select that Qt will create a new qrc file and open that afterwards. You should name it "assets" in order to match the parameter in the code QPixmap. After that you should click to add prefix and delete the prefix's name from the text edit portion for prefix(again to match the parameter in the code QPixmap). Then you should click to add files and select all the images in the assets file in your project and add them all. If you do that all, hopefully the project will work on your computer this time. I did this process a hundred times just because Qt Creator does not configure the project properly. Sorry, Qt is a bit of a pain :( } 
