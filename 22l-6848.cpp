////c++ libraries
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<string>
//#include <cstring>
//using namespace std;
//
////sfml libraries
//#include <sfml/Graphics.hpp>
//#include <SFML/Window.hpp>
//
////header file
//#include"header.h"
//
////file handler(MEthod calling)
//void FileHandler::openFile(ios_base::openmode mode)//function to open the file
//{
//    file.open(filename, mode);
//
//    if (!file.is_open())
//    {
//        cout << "Error opening file: " << filename << endl;
//    }
//}
//bool FileHandler::isOpen() const//function to check if the file is open 
//{
//    return file.is_open();
//}
//void FileHandler::closeFile()//function to close file
//{
//    if (file.is_open())
//    {
//        file.close();
//    }
//}
//bool FileHandler::readLine(string& line)//function to read whats in the line
//{
//    if (file.is_open())
//    {
//        return static_cast<bool>(getline(file, line));
//    }
//    else
//    {
//        cout << "File is not open." << endl;
//        return false;
//    }
//}
//void FileHandler::readFile()//function to read the whole file
//{
//    if (file.is_open())
//    {
//        // Get the length of the file
//        file.seekg(0, ios::end);
//        streampos length = file.tellg();
//        file.seekg(0, ios::beg);
//
//        // Allocate memory to read the file
//        data = new char[length];
//
//        // Read the file
//        file.read(data, length);
//
//        // Output the content
//        cout << "File content:\n" << data << endl;
//    }
//    else
//    {
//        cout << "File is not open." << endl;
//    }
//}
//void FileHandler::writeFile(const char* content)//function to add something or write something in the file
//{
//    if (file.is_open())
//    {
//        // Write to the file
//        file << content << endl;
//    }
//    else
//    {
//        cout << "File is not open." << endl;
//    }
//}
//FileHandler::~FileHandler()//destructor
//{
//    closeFile();
//    if (data != nullptr) {
//        delete[] data;
//    }
//}
//
////authentication class(method calling)
//bool Authentication::authenticateStudent(int rollNumber)//function to check if the student is present in the file
//{
//    ifstream inputFile("student.txt"); // open the input file
//
//    if (inputFile.is_open())
//    {
//        string line;
//        while (getline(inputFile, line))
//        {
//            istringstream iss(line);
//            int studentRollNumber;
//            if (iss >> studentRollNumber)
//            {
//                if (studentRollNumber == rollNumber)
//                {
//                    //cout << "Student with roll number " << rollNumber << " is Authenticated.\n\n";
//                    inputFile.close();
//                    return true;
//                }
//            }
//        }
//        inputFile.close();
//        return false;
//    }
//    else
//    {
//        cout << "Error: could not open file for authentication.\n";
//        return false;
//    }
//}
//
////student class(method calling)
//Student::Student()//default studetn constructor
//{}
//Student::~Student()//student destructor
//{}
//Student::Student(string n, int r, int a, string c, int crs, int att, int m, int b)//student parametrized constructor
//{
//    name = n;
//    roll_num = r;
//    age = a;
//    contact = c;
//    courses = crs;
//    attandance = att;
//    marks = m;
//    batch = b;
//}
//void Student::display()//display students present in the file
//{
//    // displaying student details
//    cout << "Already Enrolled Students are:" << endl;
//    ifstream inputFile("student.txt"); // open the input file
//
//    if (inputFile.is_open())// check if the file could not be opened
//    {
//        char ch;
//        while (inputFile.get(ch)) {
//            cout << ch;
//        }
//    }
//    else
//    {
//        cout << "Error: could not open file." << endl;
//    }
//    inputFile.close(); // close the input file
//    //cout << endl;
//}
//void Student::addStudent()//add studetns to the list
//{
//    marks = 0;
//    attandance = 0;
//    ifstream infile("student.txt");
//    if (!infile.is_open())
//    {
//        cout << "Error opening the file!\n";
//    }
//    ofstream outfile("student.txt", ios::app);
//    if (!outfile.is_open())
//    {
//        cout << "Error opening the file!\n";
//    }
//    ofstream outfile1("Attendance.txt", ios::app);//roll <<present <<absent<<late<<totl
//    if (!outfile.is_open())
//    {
//        cout << "Error opening the file!\n";
//    }
//    ofstream outfile2("marks.txt", ios::app);//roll<<q1<<q2<<a1<<a2
//    if (!outfile.is_open())
//    {
//        cout << "Error opening the file!\n";
//    }
//    cout << "Enter the four digit roll_num: ";
//    int rollNumberToRemove;
//    cin >> rollNumberToRemove;
//    string line, line1, line2;
//    bool studentFound = false;
//
//    while (getline(infile, line))
//    {
//        istringstream iss(line);
//        int rollNumber;
//        if (iss >> rollNumber)
//        {
//            if (rollNumber == rollNumberToRemove)
//            {
//                studentFound = true;
//                break;
//            }
//        }
//    }
//    infile.close();
//    //outfile.close();
//    if (studentFound)
//    {
//        cout << "Student already present cannot add!\n";
//    }
//    else
//    {
//        cout << "Enter the batch: ";
//        cin >> batch;
//        cout << "Enter the six digit contact number: ";
//        cin >> contact;
//        cout << "Enter the age: ";
//        cin >> age;
//        cout << "Enter the number of courses: ";
//        cin >> courses;
//        if (courses <= 3)
//        {
//            cin.ignore();
//            cout << "Enter the name: ";
//            getline(cin, name);
//            outfile << rollNumberToRemove << "-" << batch << "L" << "    " << courses << "    " << contact << "   " << age << "     " << name << endl;
//            outfile1 << rollNumberToRemove << "-" << batch << "L" << "      " << attandance << "        " << attandance << "        " << attandance << "        " << attandance << "        " << endl;
//            outfile2 << rollNumberToRemove << "-" << batch << "L" << "     " << marks << "        " << marks << "        " << marks << "        " << marks << '\n';
//
//            outfile.close();
//            outfile1.close();
//            outfile2.close();
//            cout << "Name has been added to the list.\n";
//        }
//        else
//        {
//            cout << "Courses cannot be more than three! not added!!" << endl;
//        }
//    }
//}
//void Student::removeStudent()//remove any student from the list
//{
//    int rollNumberToRemove;
//    cout << "Enter the first four digits of roll number of student you want to remove: ";
//    cin >> rollNumberToRemove;
//    cin.ignore();
//    ifstream inFile("student.txt");
//    if (!inFile.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//    ifstream inFile1("marks.txt");
//    if (!inFile1.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//    ifstream inFile2("Attendance.txt");
//    if (!inFile2.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//    ofstream outFile2("temp2.txt");
//    if (!outFile2.is_open())
//    {
//        cout << "Error creating temporary file!\n";
//        inFile2.close();
//        return;
//    }
//    ofstream outFile1("temp1.txt");
//    if (!outFile1.is_open())
//    {
//        cout << "Error creating temporary file!\n";
//        inFile1.close();
//        return;
//    }
//    ofstream outFile("temp.txt");
//    if (!outFile.is_open())
//    {
//        cout << "Error creating temporary file!\n";
//        inFile.close();
//        return;
//    }
//
//    string line, line1, line2;
//    bool studentFound = false;
//
//    while (getline(inFile, line) && getline(inFile1, line1) && getline(inFile2, line2))
//    {
//        istringstream iss(line), iss1(line1), iss2(line2);
//        int rollNumber;
//        if (iss >> rollNumber && iss1 >> rollNumber && iss2 >> rollNumber)
//        {
//            if (rollNumber == rollNumberToRemove)
//            {
//                studentFound = true;
//                continue;
//            }
//        }
//        outFile << line << '\n';
//        outFile1 << line1 << '\n';
//        outFile2 << line2 << '\n';
//    }
//    inFile.close();
//    outFile.close();
//    inFile1.close();
//    outFile1.close();
//    inFile2.close();
//    outFile2.close();
//    if (studentFound)
//    {
//        if (remove("student.txt") != 0)
//        {
//            cout << "Error removing original file!\n";
//        }
//        if (rename("temp.txt", "student.txt") != 0)
//        {
//            cout << "Error renaming file!\n";
//        }
//        if (remove("marks.txt") != 0)
//        {
//            cout << "Error removing original file1!\n";
//        }
//        if (rename("temp1.txt", "marks.txt") != 0)
//        {
//            cout << "Error renaming file1!\n";
//        }
//        if (remove("Attendance.txt") != 0)
//        {
//            cout << "Error removing original file1!\n";
//        }
//        if (rename("temp2.txt", "Attendance.txt") != 0)
//        {
//            cout << "Error renaming file1!\n";
//        }
//        else
//        {
//            cout << "Student with roll number " << rollNumberToRemove << " has been removed.\n";
//        }
//    }
//    else
//    {
//        cout << "Student with roll number " << rollNumberToRemove << " not found.\n";
//        remove("temp.txt");
//        remove("temp1.txt");
//        remove("temp2.txt");
//    }
//}
//void Student::editStudentDetail()//edit any students detail
//{
//    int rollNumberToEdit;
//    cout << "Enter the first four digits of the roll number of the student you want to edit: ";
//    cin >> rollNumberToEdit;
//    cin.ignore();
//
//    ifstream inFile("student.txt");
//    if (!inFile.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//
//    ofstream outFile("temp.txt");
//    if (!outFile.is_open())
//    {
//        cout << "Error creating a temporary file!\n";
//        inFile.close();
//        return;
//    }
//
//    string line;
//    bool studentFound = false;
//
//    while (getline(inFile, line))
//    {
//        istringstream iss(line);
//        int rollNumber;
//        if (iss >> rollNumber)
//        {
//            if (rollNumber == rollNumberToEdit)
//            {
//                int choice;
//                cout << "Select the detail to update:\n";
//                cout << "1. Roll Number\n";
//                cout << "2. Batch\n";
//                cout << "3. course\n";
//                cout << "4. contact\n";
//                cout << "5. Age\n";
//                cout << "6. Name\n";
//                cout << "7. Back\n";
//                cout << "Enter your choice: ";
//                cin >> choice;
//
//                if (choice == 1)
//                {
//                    int newRollNumber;
//                    cout << "Enter the new roll number: ";
//                    cin >> newRollNumber;
//                    outFile << newRollNumber << iss.str().substr(4) << '\n';
//                }
//                else if (choice == 2)
//                {
//                    int newBatch;
//                    cout << "Enter the new batch: ";
//                    cin >> newBatch;
//                    outFile << rollNumber << "-" << newBatch << "L" << line.substr(8) << '\n';
//                }
//                else if (choice == 3)
//                {
//                    int newCourse;
//                    cout << "Enter the new course: ";
//                    cin >> newCourse;
//                    if (newCourse <= 3)
//                    {
//                        outFile << rollNumber << "-" << line.substr(5, 2) << "L" << "    " << newCourse << "  " << line.substr(15) << '\n';
//
//                    }
//                    else
//                    {
//                        cout << "Exceeding course limit!" << endl;
//                    }
//                }
//                else if (choice == 4)
//                {
//                    int newContact;
//                    cout << "Enter the new contact: ";
//                    cin >> newContact;
//                    outFile << rollNumber << "-" << line.substr(5, 2) << "L" << "  " << line.substr(10, 7) << newContact << "  " << line.substr(25) << '\n';
//                }
//                else if (choice == 5)
//                {
//                    int newAge;
//                    cout << "Enter the new number of Age: ";
//                    cin >> newAge;
//                    outFile << rollNumber << "-" << line.substr(5, 2) << "L" << "  " << line.substr(10, 16) << newAge << " " << line.substr(29) << '\n';
//                }
//                else if (choice == 6)
//                {
//                    cin.ignore(); // Ignore the newline character left in the buffer
//                    string newName;
//                    cout << "Enter the new name: ";
//                    getline(cin, newName);
//                    outFile << rollNumber << "-" << line.substr(5, 2) << "L" << "  " << line.substr(10, 23) << newName << '\n';
//                }
//                else if (choice == 7)
//                {
//                    break;
//                }
//                else
//                {
//                    cout << "Invalid choice. No updates made.\n";
//                    // outFile << line << '\n'; // Keep the original line in the file
//                }
//
//                studentFound = true;
//            }
//            else
//            {
//                outFile << line << '\n';
//            }
//        }
//        else
//        {
//            outFile << line << '\n';
//        }
//    }
//
//    inFile.close();
//    outFile.close();
//
//    if (studentFound)
//    {
//        if (remove("student.txt") != 0)
//        {
//            cout << "Error deleting the original file!\n";
//            return;
//        }
//        if (rename("temp.txt", "student.txt") != 0)
//        {
//            cout << "Error renaming the temporary file!\n";
//            return;
//        }
//
//        cout << "Student details updated successfully.\n";
//    }
//    else
//    {
//        cout << "Student with the given roll number not found.\n";
//        remove("temp.txt");
//    }
//}
//
////course class(method Calling)
//Course::Course()//course default constructor
//{}
//Course::~Course()//course destructoe
//{}
//Course::Course(int c, string cn, string cr, int cap, string d)//course parametrized constructor
//{
//    code = c;
//    dept = d;
//    coursename = cn;
//    credits = cr;
//    capacity = cap;
//}
//void Course::displayAvailableCourses()//display all courses present in the file
//{
//    // displaying student details
//    cout << "Available Courses are:" << endl;
//    ifstream inputFile("course.txt"); // open the input file
//
//    if (inputFile.is_open()) // check if the file could not be opened
//    {
//        char ch;
//        while (inputFile.get(ch))
//        {
//            cout << ch;
//        }
//    }
//    else
//    {
//        cout << "Error: could not open file." << endl;
//    }
//    inputFile.close(); // close the input file
//    //cout << endl;
//}
//void Course::AddCourse()//add course in the list of courses (file)
//{
//    cout << "Enter the three digit course code: ";
//    int CourseToRemove;
//    cin >> CourseToRemove;
//    ofstream outfile("course.txt", ios::app);
//    if (!outfile.is_open())
//    {
//        cout << "Error opening the file!\n";
//    }
//    ifstream inFile("course.txt");
//    if (!inFile.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//    string line;
//    bool CourseFound = false;
//
//    while (getline(inFile, line))
//    {
//        istringstream iss(line);
//        int course;
//        if (iss >> course)
//        {
//            if (course == CourseToRemove)
//            {
//                CourseFound = true;
//                break;
//            }
//        }
//    }
//    inFile.close();
//
//    if (CourseFound)
//    {
//        cout << "Course Already present cannot be added!\n";
//    }
//    else
//    {
//        cout << "Enter the capacity: ";
//        cin >> capacity;
//        cin.ignore();
//        cout << "Enter the credit hours: ";
//        getline(cin, credits);
//        cout << "Enter the department code(dept code is only two alphabets): ";
//        getline(cin, dept);
//        cout << "Enter the coursename: ";
//        getline(cin, coursename);
//        outfile << CourseToRemove << dept << "         " << credits << "         " << coursename << endl;
//        outfile.close();
//        cout << "course has been added to the list.\n";
//    }
//}
//void Course::removeCourse()//Remove course from the file(file)
//{
//    int CourseToRemove;
//    cout << "Enter the first three digits of roll number of student you want to remove: ";
//    cin >> CourseToRemove;
//    cin.ignore();
//    ifstream inFile("course.txt");
//    if (!inFile.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//
//    ofstream outFile("temp.txt");
//    if (!outFile.is_open())
//    {
//        cout << "Error creating temporary file!\n";
//        inFile.close();
//        return;
//    }
//
//    string line;
//    bool CourseFound = false;
//
//    while (getline(inFile, line))
//    {
//        istringstream iss(line);
//        int course;
//        if (iss >> course)
//        {
//            if (course == CourseToRemove)
//            {
//                CourseFound = true;
//                continue;
//            }
//        }
//        outFile << line << '\n';
//    }
//    inFile.close();
//    outFile.close();
//
//    if (CourseFound)
//    {
//        if (remove("course.txt") != 0)
//        {
//            cout << "Error removing original file!\n";
//        }
//        if (rename("temp.txt", "course.txt") != 0)
//        {
//            cout << "Error renaming file!\n";
//        }
//        else
//        {
//            cout << "Course with course code " << CourseToRemove << " has been removed.\n";
//        }
//    }
//    else
//    {
//        cout << "Course with course code " << CourseToRemove << " not found.\n";
//        remove("temp.txt");
//    }
//}
//void Course::displayupdated()//display updated file of students with their courses(after anyone of them have dropped any course)
//{
//    // displaying student details
//    cout << "Available Courses are:" << endl;
//    ifstream inputFile("output.txt"); // open the input file
//
//    if (inputFile.is_open()) // check if the file could not be opened
//    {
//        char ch;
//        while (inputFile.get(ch))
//        {
//            cout << ch;
//        }
//    }
//    else
//    {
//        cout << "Error: could not open file." << endl;
//    }
//    inputFile.close(); // close the input file
//    //cout << endl;
//}
//void Course::displayenrolledcourses()//display the courses that students have been given
//{
//    ifstream inputFile("student.txt");
//    if (!inputFile.is_open())
//    {
//        cout << "Error opening input file." << endl;
//        return;
//    }
//    ofstream outputFile("output.txt", ios::app);
//    if (!outputFile.is_open())
//    {
//        cout << "Error opening output file." << endl;
//        inputFile.close();
//        return;
//    }
//    int linenumber = 0;
//    for (string line; getline(inputFile, line); ++linenumber)
//    {
//        if (linenumber == 0)
//        {
//            continue;
//        }
//
//        istringstream iss(line);
//        string rollNumber;
//        int numCourses;
//        if (iss >> rollNumber >> numCourses)
//        {
//            cout << "Roll Number: " << rollNumber << " ";
//            // Output to both console and file
//            outputFile << "Roll Number: " << rollNumber << " ";
//            assignCodes("course.txt", numCourses);
//            outputFile << endl;
//        }
//        else
//        {
//            cout << "Error reading line: " << line << endl;
//            break;
//        }
//    }
//
//    inputFile.close();
//    outputFile.close();
//}
//void Course::dropCourse()//option for student to drop any of the picked course
//{
//    string rollNumber;
//    cout << "Enter your completer Roll Number in cluding batch i-e(1234-12L): ";
//    cin >> rollNumber;
//
//    ifstream inFile("output.txt");
//    ofstream outFile("temp.txt");
//
//    string line, currentLine, previousLine;
//    int coursesDropped = 0;
//    bool found = false;
//
//    if (inFile.is_open() && outFile.is_open()) {
//        while (getline(inFile, line)) {
//            currentLine = line;
//            if (currentLine.find("Roll Number: " + rollNumber) != string::npos) {
//                cout << "Assigned Courses for " << rollNumber << ": " << previousLine << endl;
//
//                string courseToDrop;
//                cout << "Enter the course you want to drop: ";
//                cin >> courseToDrop;
//
//                size_t pos = previousLine.find(courseToDrop);
//                if (pos != string::npos) {
//                    previousLine.erase(pos, courseToDrop.length() + 1);
//                    cout << "Updated Course List: " << previousLine << endl;
//                    outFile << previousLine << endl;
//                    outFile << currentLine << endl;
//                    coursesDropped++;
//                }
//                else {
//                    cout << "Course not found in the list." << endl;
//                    outFile << previousLine << endl;
//                    outFile << currentLine << endl;
//                }
//
//                found = true;
//                previousLine = "";
//                continue;
//            }
//
//            if (!previousLine.empty()) {
//                outFile << previousLine << endl;
//            }
//
//            previousLine = currentLine;
//        }
//
//
//
//
//        if (!previousLine.empty()) {
//            outFile << previousLine << endl;
//        }
//
//        inFile.close();
//        outFile.close();
//
//        if (!found) {
//            cout << "No courses found for Roll Number: " << rollNumber << endl;
//            remove("temp.txt");
//        }
//        else {
//            remove("output.txt");
//            rename("temp.txt", "output.txt");
//            Course::updateStudentRecord(rollNumber, coursesDropped);
//        }
//    }
//    else {
//        cout << "Unable to open file";
//    }
//}
//void Course::updateStudentRecord(const string& rollNumber, int coursesDropped)
//{
//    ifstream inFile("student.txt");
//    ofstream outFile("temp_student.txt");
//    string line;
//
//    if (!inFile.is_open() || !outFile.is_open()) {
//        cerr << "Unable to open student file." << endl;
//        return;
//    }
//
//    bool rollNumberFound = false;
//
//    while (getline(inFile, line))
//    {
//        istringstream iss(line);
//        string currentRoll;
//        int courseCount;
//        string contact, age, name, name1;
//
//        // Read the roll number and other information
//        if (iss >> currentRoll >> courseCount >> contact >> age >> name1 >> name)
//        {
//            // Check if the read roll number matches the desired one
//            if (currentRoll == rollNumber)
//            {
//                rollNumberFound = true;
//                courseCount = courseCount - 1;
//
//                // Write the updated information to the output file
//                outFile << currentRoll << "    " << courseCount << "    " << contact << "   " << age << "     " << name1 << name << endl;
//
//               // outFile << currentRoll << " " << batch << " " << courseCount << " " << contact << " " << age << " " << name << '\n';
//            }
//            else
//            {
//                // Write the existing information for other students
//                outFile << currentRoll << "    " << courseCount << "    " << contact << "   " << age << "     " << name1 << name << endl;
//            }
//        }
//        else
//        {
//            outFile << line << '\n';
//        }
//    }
//
//    
//
//    inFile.close();
//    outFile.close();
//
//    if (rollNumberFound) 
//    {
//        remove("student.txt");
//        rename("temp_student.txt", "student.txt");
//    }
//    else 
//    {
//        cout << "Roll number not found in the student file." << endl;
//        remove("temp_student.txt");  // Remove the temporary file if roll number is not found
//    }
//}
//
////Attendance class(method Calling)
//void Attendance::markAttendance()//mark or add any students attendance 
//{
//    string rollNumberToMark;
//    cout << "Enter the complete roll number of the student you want to mark attendance for: ";
//    cin >> rollNumberToMark;
//    cin.ignore();
//
//    ifstream inFile("Attendance.txt");
//
//    if (!inFile.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//
//    ofstream outFile("temp.txt");
//
//    if (!outFile.is_open())
//    {
//        cout << "Error creating temporary file!\n";
//        inFile.close();
//        return;
//    }
//
//    string line;
//    bool studentFound = false;
//
//    while (getline(inFile, line))
//    {
//        istringstream iss(line);
//        string rollNumber;
//        int presentCount, absentCount, latecount, totalCount;
//
//        // Read the roll number as a string to include hyphens
//        if (iss >> rollNumber >> presentCount >> absentCount >> latecount >> totalCount)
//        {
//            // Check if the read roll number matches the desired one
//            if (rollNumber == rollNumberToMark)
//            {
//                studentFound = true;
//                cout << "'P' for present\n"
//                    << "'A' for absent\n"
//                    << "'L' for late\n"
//                    << "Please enter any of the following:\n";
//                char att;
//                cin >> att;
//
//                if (att == 'P' || att == 'p')
//                {
//                    presentCount++;
//                    totalCount++;
//                    cout << "Attendance marked!!" << endl;
//                }
//                else if (att == 'A' || att == 'a')
//                {
//                    absentCount++;
//                    totalCount++;
//                    cout << "Attendance marked!!" << endl;
//                }
//                else if (att == 'L' || att == 'l')
//                {
//                    latecount++;
//                    totalCount++;
//                    cout << "Attendance marked!!" << endl;
//                }
//                else
//                {
//                    cout << "Invalid input!!\n";
//                    return;
//                }
//
//                // Write the updated information to the output file
//                outFile << rollNumber << "     " << presentCount << "        " << absentCount << "        " << latecount << "        " << totalCount << '\n';
//            }
//            else
//            {
//                // Write the existing information for other students
//                outFile << rollNumber << "     " << presentCount << "        " << absentCount << "        " << latecount << "        " << totalCount << '\n';
//            }
//        }
//        else
//        {
//            outFile << line << '\n';
//        }
//    }
//
//    inFile.close();
//    outFile.close();
//
//    if (studentFound)
//    {
//        if (remove("Attendance.txt") != 0)
//        {
//            cout << "Error removing the original file!\n";
//        }
//        if (rename("temp.txt", "Attendance.txt") != 0)
//        {
//            cout << "Error renaming the file!\n";
//        }
//        else
//        {
//            cout << "Attendance for the student with roll number " << rollNumberToMark << " marked.\n";
//        }
//    }
//    else
//    {
//        cout << "Student with roll number " << rollNumberToMark << " not found.\n";
//        remove("temp.txt");
//    }
//}
//void Attendance::displayAttendance()//display the all students attendance
//{
//    // displaying student details
//    cout << "Maks Report is:" << endl;
//    ifstream inputFile("Attendance.txt"); // open the input file
//
//    if (inputFile.is_open())// check if the file could not be opened
//    {
//        char ch;
//        while (inputFile.get(ch)) {
//            cout << ch;
//        }
//    }
//    else
//    {
//        cout << "Error: could not open file." << endl;
//    }
//    inputFile.close(); // close the input file
//    //cout << endl;
//}
//
////Marks class(methd callinf)
//void Marks::assignMarks()//assign marks to students
//{
//    string rollNumberToMark;
//    cout << "Enter the complete roll number of the student you want to assign marks to: ";
//    cin >> rollNumberToMark;
//    cin.ignore();
//
//    ifstream inFile("marks.txt");
//
//    if (!inFile.is_open())
//    {
//        cout << "Error opening the file!\n";
//        return;
//    }
//
//    ofstream outFile("temp.txt");
//
//    if (!outFile.is_open())
//    {
//        cout << "Error creating temporary file!\n";
//        inFile.close();
//        return;
//    }
//
//    string line;
//    bool studentFound = false;
//
//    while (getline(inFile, line))
//    {
//        istringstream iss(line);
//        string rollNumber;
//        string q1, q2, a1, a2;
//
//        // Read the roll number as a string to include hyphens
//        if (iss >> rollNumber >> q1 >> q2 >> a1 >> a2)
//        {
//
//            // Check if the read roll number matches the desired one
//            if (rollNumber == rollNumberToMark)
//            {
//                studentFound = true;
//                cout << "1. Quiz1\n"
//                    << "2. Quiz2\n"
//                    << "3. Assigment1\n"
//                    << "4. Assigment2\n"
//                    << "Enter the number carefully from above:\n";
//                int selectedPart;
//                cin >> selectedPart;
//
//                if (selectedPart == 1)
//                {
//                    cout << "Enter the new value for Quiz1: ";
//                    cin >> q1;
//                }
//                else if (selectedPart == 2)
//                {
//                    cout << "Enter the new value for Quiz2: ";
//                    cin >> q2;
//                }
//                else if (selectedPart == 3)
//                {
//                    cout << "Enter the new value for Assigment1: ";
//                    cin >> a1;
//                }
//                else if (selectedPart == 4)
//                {
//                    cout << "Enter the new value for Assigment2: ";
//                    cin >> a2;
//                }
//                else
//                {
//                    cout << "Invalid selection. No update performed." << endl;
//                    return;
//                }
//
//                // Write the updated information to the output file
//                outFile << rollNumber << "\t" << q1 << "\t\t" << q2 << "\t\t" << a1 << "\t\t" << a2 << '\n';
//            }
//            else
//            {
//                // Write the existing information for other students
//                outFile << rollNumber << "\t" << q1 << "\t\t" << q2 << "\t\t" << a1 << "\t\t" << a2 << '\n';
//            }
//        }
//        else
//        {
//            outFile << line << '\n';
//        }
//    }
//
//    inFile.close();
//    outFile.close();
//
//    if (studentFound)
//    {
//        if (remove("marks.txt") != 0)
//        {
//            cout << "Error removing original file!\n";
//        }
//        if (rename("temp.txt", "marks.txt") != 0)
//        {
//            cout << "Error renaming file!\n";
//        }
//        else
//        {
//
//            cout << "Marks for student with roll number " << rollNumberToMark << " assigned.\n";
//        }
//    }
//    else
//    {
//        cout << "Student with roll number " << rollNumberToMark << " not found.\n";
//        remove("temp.txt");
//    }
//}
//void Marks::displayMarks()//display marks detail of students
//{
//    // displaying student details
//    cout << "Maks Report is:" << endl;
//    ifstream inputFile("marks.txt"); // open the input file
//
//    if (inputFile.is_open())// check if the file could not be opened
//    {
//        char ch;
//        while (inputFile.get(ch)) {
//            cout << ch;
//        }
//    }
//    else
//    {
//        cout << "Error: could not open file." << endl;
//    }
//    inputFile.close(); // close the input file
//    //cout << endl;
//}
//
////system clas(method calling)
//System::System()//default constructor which is given default values
//{
//    // Initialize menus and other attributes
//    mainMenu = "\t\t\t1.ENROLL A STUDENT\t\t2.COURSE REGISTRATION\n\t\t\t . Display\t\t\t . Display Available\n\t\t\t . Add Student\t\t\t . Add Course\n\t\t\t . Remove Student\t\t . Remove Course\n\t\t\t . Edit Student\t\t\t . Back\n\t\t\t3. ATTENDANCE\t\t\t4. MARKS\n\t\t\t . Veiw Attendance\t\t . Veiw Marks\n\t\t\t . Marks Attendance\t\t . Assign Marks\n\t\t\t\t\t5. Course Withdraw\n\t\t\t\t\t . Display Enrolled Students\n\t\t\t\t\t . Drop A Course\n\t\t\t\t\t . Display Updated File\n\t\t\t\t\t6. Exit Program";
//    studentMenu = "1. View Students\n2. Add Student\n3. Remove Students\n4. Edit student detail\n5. Go Back\n";
//    courseMenu = "1. View Courses\n2. Add Course\n3. Remove Course\n4. Go Back";
//    attandanceMenu = "1. View Attandance\n2. Mark Attandance\n3. Go Back";
//    marksMenu = "1. View marks\n2. Assign Mark\n3. Go Back";
//    coursewithdrawMenu = "1. Enrolled Courses\n2. Drop Course\n3. Display File with dropped Course\n4. Go back";
//}
//System::~System()//destructor
//{}
//void System::displayMainMenu()
//{
//    cout << "                       -----------------------MAIN MENU------------------------\n" << mainMenu << endl;
//}
//void System::displayStudentMenu()
//{
//    cout << "Student Menu:\n" << studentMenu << endl;
//}
//void System::displayCourseMenu()
//{
//    cout << "Course Menu:\n" << courseMenu << endl;
//}
//void System::displayattandanceMenu()
//{
//    cout << "Attandance Menu:\n" << attandanceMenu << endl;
//}
//void System::displaymarksMenu()
//{
//    cout << "Marks Menu:\n" << marksMenu << endl;
//}
//void System::displayCoursewithdrawMenu()
//{
//    cout << "Coursewithdraw Menu:\n" << coursewithdrawMenu << endl;
//}
//int System::getUserInput()//returns the choice that user enters
//{
//    int choice;
//    cout << "Enter your choice: ";
//    cin >> choice;
//    return choice;
//}
//bool System::validateInput(int input, int min, int max)//validates the input of the user
//{
//    return input >= min && input <= max;
//}
//void System::performAction(int choice)//takes the choice from getuserinput and performs tasks accordingly
//{
//    if (choice == 1)
//    {
//        // Manage Students
//        manageStudents();
//    }
//    else if (choice == 2)
//    {
//        // Manage Courses
//        manageCourses();
//    }
//    else if (choice == 3)
//    {
//        //manage Attandance
//        manageAttandance();
//    }
//    else if (choice == 4)
//    {
//        //manage marks
//        manageMarks();
//    }
//    else if (choice == 5)
//    {
//        //manage cw
//        manageCW();
//    }
//    else if (choice == 6)
//    {
//        sf::Font font;
//        font.loadFromFile("font.otf");
//        sf::Text inputText;
//        inputText.setFont(font);
//        inputText.setCharacterSize(96);
//        inputText.setFillColor(sf::Color::Black);
//        inputText.setString("~ENTER\n");
//        sf::RectangleShape rectangle(sf::Vector2f(400, 100));
//        rectangle.setFillColor(sf::Color::White);
//        rectangle.setOutlineThickness(5.f);
//        rectangle.setOutlineColor(sf::Color::Magenta);
//        float x, y;
//        x = 500;
//        y = 500;
//        sf::RenderWindow window(sf::VideoMode(1400, 800), "Flex");
//        while (window.isOpen())
//        {
//            sf::Event event;
//            while (window.pollEvent(event))
//            {
//                if (event.type == sf::Event::Closed)
//                {
//                    window.close();
//                }
//                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
//                {
//                    window.close();
//                }
//                else if (sf::Mouse::getPosition(window).x > rectangle.getGlobalBounds().left &&
//                    sf::Mouse::getPosition(window).x < rectangle.getGlobalBounds().left +
//                    rectangle.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
//                    rectangle.getGlobalBounds().top && sf::Mouse::getPosition(window).y
//                    < (rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height) &&
//                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
//                {
//                    window.close(); 
//                }
//            }
//            sf::FloatRect textBounds = inputText.getLocalBounds();
//            inputText.setPosition((window.getSize().x - textBounds.width) / 2.1, 500);
//            window.clear();
//            programExit(window, font);
//            window.draw(rectangle);
//            window.draw(inputText);
//            window.display();
//            rectangle.setPosition(sf::Vector2f(x, y));
//        }
//        return;
//    }
//    else
//    {
//        cout << "Invalid choice. Please try again." << endl;
//    }
//}
//void System::manageStudents()//studetns options calling
//{
//    int studentChoice;
//    do {
//        displayStudentMenu();
//        studentChoice = getUserInput();
//        if (validateInput(studentChoice, 1, 5))
//        {
//            if (studentChoice == 1)
//            {
//                Student::display();
//                cout << endl;
//            }
//            if (studentChoice == 2)
//            {
//                Student::addStudent();
//            }
//            if (studentChoice == 3)
//            {
//                Student::removeStudent();
//            }
//            if (studentChoice == 4)
//            {
//                Student::editStudentDetail();
//            }
//            if (studentChoice == 5)
//            {
//                break;
//            }
//        }
//        else
//        {
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (studentChoice != 5);
//}
//void System::manageCourses()//course options calling
//{
//    int courseChoice;
//    do {
//        displayCourseMenu();
//        courseChoice = getUserInput();
//        if (validateInput(courseChoice, 1, 4))
//        {
//            if (courseChoice == 1)
//            {
//                Course::displayAvailableCourses();
//                cout << endl;
//            }
//            if (courseChoice == 2)
//            {
//                Course::AddCourse();
//            }
//            if (courseChoice == 3)
//            {
//                Course::removeCourse();
//            }
//            if (courseChoice == 4)
//            {
//                break;
//            }
//        }
//        else
//        {
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (courseChoice != 4);
//}
//void System::manageAttandance()//Attendance options calling
//{
//    int attChoice;
//    do {
//        displayattandanceMenu();
//        attChoice = getUserInput();
//        if (validateInput(attChoice, 1, 3))
//        {
//            if (attChoice == 1)
//            {
//                Attendance::displayAttendance();
//                cout << endl;
//            }
//            if (attChoice == 2)
//            {
//                Attendance::markAttendance();
//            }
//            if (attChoice == 3)
//            {
//                break;
//            }
//        }
//        else
//        {
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (attChoice != 3);
//}
//void System::manageMarks()//Marks options calling
//{
//    int MChoice;
//    do
//    {
//        displaymarksMenu();
//        MChoice = getUserInput();
//        if (validateInput(MChoice, 1, 3))
//        {
//            if (MChoice == 1)
//            {
//                Marks::displayMarks();
//                cout << endl;
//            }
//            if (MChoice == 2)
//            {
//                Marks::assignMarks();
//            }
//            if (MChoice == 3)
//            {
//                break;
//            }
//        }
//        else
//        {
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (MChoice != 3);
//}
//void System::manageCW()//course withdraw options calling
//{
//    int cwChoice;
//    do {
//        displayCoursewithdrawMenu();
//        cwChoice = getUserInput();
//        if (validateInput(cwChoice, 1, 4))
//        {
//            if (cwChoice == 1)
//            {
//                Course::displayenrolledcourses();
//                cout << endl;
//            }
//            if (cwChoice == 2)
//            {
//                Course::dropCourse();
//            }
//            if (cwChoice == 3)
//            {
//                Course::displayupdated();
//            }
//            if (cwChoice == 4)
//            {
//                break;
//            }
//        }
//        else
//        {
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (cwChoice != 4);
//}
//
//int main()
//{
//    Authentication authentication;
//    System mySystem;
//
//    sf::RectangleShape rectangle(sf::Vector2f(2000, 2000));
//    rectangle.setFillColor(sf::Color::White);
//    float x, y;
//    x = 0;
//    y = 120;
//    //rollnumber box
//    sf::RectangleShape rectangle1(sf::Vector2f(300, 100));
//    rectangle1.setFillColor(sf::Color::Black);
//    rectangle1.setOutlineThickness(5.f);
//    rectangle1.setOutlineColor(sf::Color::Blue);
//    float x1, y1;
//    x1 = 200;
//    y1 = 450;
//    //roll se pehlay wali yakkian
//    sf::RectangleShape rectangle2(sf::Vector2f(100, 100));
//    rectangle2.setFillColor(sf::Color::Blue);
//    rectangle2.setOutlineThickness(5.f);
//    rectangle2.setOutlineColor(sf::Color::Blue);
//    float x2, y2;
//    x2 = 100;
//    y2 = 450;
//    //person headmaking
//    sf::CircleShape shape(20.f);
//    shape.setFillColor(sf::Color::Blue);
//    shape.setOutlineThickness(5.f);
//    shape.setOutlineColor(sf::Color::White);
//    sf::CircleShape shape1(25.f);
//    shape1.setFillColor(sf::Color::Blue);
//    shape1.setOutlineThickness(5.f);
//    shape1.setOutlineColor(sf::Color::White);
//    sf::RectangleShape rectangle3(sf::Vector2f(100, 50));
//    rectangle3.setFillColor(sf::Color::White);
//    float x3, y3;
//    x3 = 100;
//    y3 = 555;
//    string inputStr;
//    //font
//    sf::Font font;
//    font.loadFromFile("font.otf");
//    sf::RenderWindow window(sf::VideoMode(1400, 800), "Flex");
//    sf::Text inputText1;
//    inputText1.setFont(font);
//    inputText1.setCharacterSize(96);
//    inputText1.setFillColor(sf::Color::Red);
//    inputText1.setPosition(240, 440);
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//            else if (event.type == sf::Event::TextEntered)
//            {
//                if (event.text.unicode == 13)// Enter key pressed
//                {
//                    // Validate and return the input if it's a 4-digit integer
//                    if (inputStr.size() == 4 && std::all_of(inputStr.begin(), inputStr.end(), ::isdigit))
//                    {
//                        if (authentication.authenticateStudent(stoi(inputStr)))
//                        {
//                            window.close();
//                            ifstream file("student.txt");
//                            if (!file.is_open()) {
//                                cout << "Error opening file." << std::endl;
//                                return 1;
//                            }
//                            string line;
//                            while (getline(file, line)) {
//                                // Use stringstream to parse the line
//                                istringstream iss(line);
//                                // Read the roll number and compare with the input
//                                string roll;
//                                iss >> roll;
//
//                                // Check if the first four digits of the roll number match the input
//                                if (roll.substr(0, 4) == inputStr) {
//                                    // Display the name associated with the matching roll number
//                                    string name, contact, name1;
//                                    int age, crs;
//                                    iss >> crs >> contact >> age >> name >> name1;
//                                    cout << " Signed in as " << name << name1 << endl;
//                                    break; // Stop searching after finding the first match
//                                }
//                            }
//
//                            // Close the file
//                            file.close();
//                            accessGaranteed();
//                            //system to display menues
//                            int userChoice;
//                            do {
//                                mySystem.displayMainMenu();
//                                userChoice = mySystem.getUserInput();
//
//                                if (mySystem.validateInput(userChoice, 1, 6))
//                                {
//                                    mySystem.performAction(userChoice);
//                                }
//                                else
//                                {
//                                    cout << "Invalid input!!." << endl;
//                                }
//
//                            } while (userChoice != 6);
//                        }
//                        else
//                        {
//                            sf::Font font1;
//                            font1.loadFromFile("font.otf");
//                            sf::RenderWindow window1(sf::VideoMode(1400, 800), "Flex");
//                            while (window1.isOpen())
//                            {
//                                sf::Event event1;
//                                while (window1.pollEvent(event1))
//                                {
//                                    if (event1.type == sf::Event::Closed)
//                                    {
//                                        window1.close();
//                                    }
//                                    else if (event1.type == sf::Event::KeyPressed && event1.key.code == sf::Keyboard::Enter)
//                                    {
//                                        window1.close();
//                                    }
//                                }
//                                window1.clear();
//                                window.close();
//                                accessDenied(window1, font1);
//                                window1.display();
//                            }
//                        }
//                    }
//                    else
//                    {
//                        //window.close();
//                        accessDenied(window, font);
//                        inputStr.clear();
//                    }
//                }
//                else if (event.text.unicode == 8)
//                {
//                    if (!inputStr.empty()) 
//                    {
//                        inputStr.pop_back();
//                    }
//                }
//                else if (event.text.unicode >= '0' && event.text.unicode <= '9')
//                {
//                    inputStr += static_cast<char>(event.text.unicode);
//                }
//            }
//        }
//        inputText1.setString(inputStr);
//        window.clear();
//        window.draw(rectangle);
//        beforeAccess(window, font);
//        window.draw(inputText1);
//        window.draw(rectangle1);
//        window.draw(rectangle2);
//        window.draw(inputText1);
//        window.draw(shape);
//        window.draw(shape1);
//        window.draw(rectangle3);
//        window.display();
//        rectangle.setPosition(sf::Vector2f(x, y));
//        rectangle1.setPosition(sf::Vector2f(x1, y1));
//        rectangle2.setPosition(sf::Vector2f(x2, y2));
//        rectangle3.setPosition(sf::Vector2f(x3, y3));
//        shape.setPosition(133.f, 475.f);
//        shape1.setPosition(129.f, 520.f);
//
//    }   
//}