# wizardRush
group16 CENG201 team project

-----------------------------------------------------------------------------

 We have our executable in the "executable" directory. When you play the game there are just arrow buttons to control players. First and third player is controlled by just up and down arrow buttons, second player is controlled by all the arrow buttons. You will also be using mouse to click the buttons on start menu, character selection menu and game over menu. But incase it does not work on your computer this is how you should open it:
 
 Firstly you should download Qt Creator from their official site. Here is the link: https://www.qt.io/download
 You will have to sign up to the site because it wants you to sign in while installing the application. You should select that you're not in a company so Qt gives you the community(free) version.
 Then please install Qt 6.6.0 version. For SDK please select both MinGW 64-Bit and MSVC2019 64-Bit(Visual Studio 2019). Configure the project for both of these SDKs. You will start the game by clicking the green start button on the bottom left of Qt Creator. 

 If it doesn't work anyways you can just open a new project and add same named files to the project. {You should do it in Qt's file edit part -If you just do it in file explorer Qt will not see those-.. After creating the files in Qt edit, you should copy the inside of the original files.
 If you right-click to Sources -which includes all .cpp files- and select "add new" then you will see C/C++ please click that. Select adding h/cpp[C Class] it should create both h and cpp for the same name.
 And for the resources first you should copy our "assets" folder to your new project file. Then you just have to right-click the project folder select "add new" again and you will see Qt please click that. you will see the qrc[Qt Resource File] if you select that Qt will create a new qrc file and open that afterwards. You should name it "assets" in order to match the parameter in the code QPixmap. After that you should click to add prefix and delete the prefix's name from the text edit portion for prefix(again to match the parameter in the code QPixmap). Then you should click to add files and select all the images in the assets file in your project and add them all. If you do that all, hopefully the project will work on your computer this time. I did this process a hundred times just because Qt Creator does not configure the project properly. Sorry, Qt is a bit of a pain :( } 

 Doxygen output is in the "doc" directory. I couldn't commit it without zipping it, so please unzip it. You can open index.html file to open the initial page of the site.
