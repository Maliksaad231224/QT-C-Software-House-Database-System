**Project Documentation**

**Framework and Language Used**

The project has been developed using QT framework. The backend is written using C++ and SQL. We are connecting the App with MYSQL database. All the frontend was written in QML i.e the descriptive language of QT framework. 

**Files Description**

The project files are in QtPro folder. It cantains a main.cpp file where the objects are called and the main application is shown, a mainwindow.h file cantaining the class mainwindow cantaining the memebr variables and function definitions, and finally a mainwindow.cpp file where the fucntion declarations are written. It is the same file where the backend code will be written. In case anyone faces issues in compiling the app, disable your antivirus. if he problem persists, simply delete the "qtPro.pro.user" file only . this will solve the problem. The resource.qrc file acts as a remote cantainer cantaining all the pictures and icons. We can extract the file paths from the resource files. This way we donot need to mantain separate folder cantaining pictures and icons files. All the pics and icons are saved in the resource.qrc file.

**Total Pages**

This application consists of a total of 24 pages all stacked on top of each other using QT stacked widgets. The buttons are connected using Qt Signals and Slots.

**End Users of DBMS**

End users include Manager and Hr professionals

**Manager View and Access**

Manager will have access to only displaying. searching records of all departments, projects, teams, employees, He doesnot have access to modify the remords

**HR Professional View and Access**

HR Professional will have access to all the CRUD operations and he can perform these operations on employees, teams, projects and departments tables.
He cannot delete departments.

**Page Transitions**

The pages are connected with QT signals and slots for seamless transitions. each page has a "move to home" button where the user can move back to the main page after completing the operations he wants to perform.

**Time Spent on Frontend Development**

It took only 3 days from 16 May to 18 May to complete the frontend and connecting the pages. 
