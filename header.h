//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<string>
//#include <cstring>

const int MAX_STUDENTS = 25;
const int MAX_COURSES = 3;
const int MAX_CODES = 15;

class FileHandler;
class Authentication;
class Student;
class Course;
class Attendance;
class Marks;
class System;

//shuffle codes
void shuffleCodes(string codes[], int numCodes)
{
    for (int i = numCodes - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(codes[i], codes[j]);
    }
}

//assign codes
void assignCodes(const string& ifilename, int numCodes)
{
    ifstream file(ifilename);
    if (!file.is_open())
    {
        cout << "Failed to open input file." << endl;
        return;
    }

    ofstream outfile("output.txt", ios::app);
    if (!outfile.is_open())
    {
        cout << "Failed to open output file." << endl;
        file.close();
        return;
    }
    string codes[MAX_CODES];
    int count = 0;
    string temp;
    while (count < MAX_CODES && file >> temp)
    {
        if (temp.length() == 5 && isdigit(temp[0]) && isdigit(temp[1]) && isdigit(temp[2]) && isalpha(temp[3]) && isalpha(temp[4]))
        {
            codes[count] = temp;
            ++count;
        }
    }

    shuffleCodes(codes, count);

    if (numCodes > count)
    {
        cout << "Not enough codes in the file." << endl;
        file.close();
        outfile.close();
        return;
    }

    cout << "Assigned Codes: ";
    for (int i = 0; i < numCodes; ++i)
    {
        cout << codes[i] << ",";
    }
    cout << endl;
    outfile << "Assigned Courses: ";
    for (int i = 0; i < numCodes; ++i)
    {
        outfile << codes[i] << ",";
    }
    outfile << " ";
    outfile << endl;

    file.close();
    outfile.close();
}

//before access statements
void beforeAccess(sf::RenderWindow& window, sf::Font& font)
{
    // Create a text object
    sf::Text text, text1, text2, text3, text4, text5, text6;
    //flex
    text.setFont(font);
    text.setCharacterSize(120);
    text.setFillColor(sf::Color::Blue);
    //academic portal
    text1.setFont(font);
    text1.setCharacterSize(32);
    text1.setFillColor(sf::Color::Blue);
    //for pass ...............
    text2.setFont(font);
    text2.setCharacterSize(32);
    text2.setFillColor(sf::Color::White);
    //sign in
    text3.setFont(font);
    text3.setCharacterSize(32);
    text3.setFillColor(sf::Color::Black);
    //roll no.
    text4.setFont(font);
    text4.setCharacterSize(32);
    text4.setFillColor(sf::Color::Black);
    //welcom
    text5.setFont(font);
    text5.setCharacterSize(32);
    text5.setFillColor(sf::Color::White);
    //eg roll
    text6.setFont(font);
    text6.setCharacterSize(24);
    text6.setFillColor(sf::Color::Blue);
    //instuctions
    sf::Text t1, t2;
    t1.setFont(font);
    t1.setCharacterSize(24);
    t1.setFillColor(sf::Color::Red);
    //academic portal
    t2.setFont(font);
    t2.setCharacterSize(24);
    t2.setFillColor(sf::Color::Magenta);
    // Set the text content
    text.setString("Flex");
    text1.setString("---------------\n  Academic Portal\n");
    text2.setString("For Roll No. related queries contact concerned Academic Officer on nu.edu.pk\n");
    text3.setString("Sign In\n");
    text4.setString("Roll No.\n");
    text5.setString("Welcome to Flex\n");
    text6.setString("Roll Number i.e (1234)\n");
    t1.setString("INSTRUCTIONS:\n");
    t2.setString("        1. Enter Your Four Digit Roll.no\n\n        2. Press Enter When You Are Done\n");
    sf::FloatRect textBounds7 = t1.getLocalBounds();
    t1.setPosition((window.getSize().x - textBounds7.width) / 1.8, 410);
    //acdemic prtl
    sf::FloatRect textBounds8 = t2.getLocalBounds();
    t2.setPosition((window.getSize().x - textBounds8.width) / 1.6, 450);
    // Center the text in the window
    //flex
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition((window.getSize().x - textBounds.width) / 2, 100);
    //acdemic prtl
    sf::FloatRect textBounds1 = text1.getLocalBounds();
    text1.setPosition((window.getSize().x - textBounds1.width) / 2, 220);
    //fo que..............
    sf::FloatRect textBounds2 = text2.getLocalBounds();
    text2.setPosition((window.getSize().x - textBounds2.width) / 2, 60);
    //sign in
    sf::FloatRect textBounds3 = text3.getLocalBounds();
    text3.setPosition((window.getSize().x - textBounds3.width) / 2, 300);
    //roll.no
    sf::FloatRect textBounds4 = text4.getLocalBounds();
    text4.setPosition((window.getSize().x - textBounds4.width) / 14, 400);
    //wlcom
    sf::FloatRect textBounds5 = text5.getLocalBounds();
    text5.setPosition((window.getSize().x - textBounds5.width) / 2, 15);
    //roll ie
    sf::FloatRect textBounds6 = text6.getLocalBounds();
    text6.setPosition((window.getSize().x - textBounds6.width) / 14, 600);
    //sprite
    sf::Sprite sprite;
    sf::Texture spriteTexture;
    if (spriteTexture.loadFromFile("flex.jpg")) 
    {
        sprite.setTexture(spriteTexture);
        // Set position and size for the sprite
        sprite.setPosition(400.f, 120.f);
        sprite.setScale(1.0f, 1.0f); // Adjust the scale as needed

        // Draw the sprite
        window.draw(sprite);
    }

    // Draw the text
    window.draw(text);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.draw(text5);
    window.draw(text6);
    window.draw(t1);
    window.draw(t2);
}

//after access is garantees
void accessGaranteed()
{
    cout << "                                           WELCOME TO FLEX\n"
        << "Choose Your Option!!\n";
}
 
//acceess denial
void accessDenied(sf::RenderWindow& window1, sf::Font& font)
{
    sf::Text text, text1, inputText;
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Red);
    text1.setFont(font);
    text1.setCharacterSize(60);
    text1.setFillColor(sf::Color::Red);
    text1.setString("!!!!!!!!WARNING!!!!!!!!!!!\n");
    text.setString("Student with roll number entered,\nis not Authenticated.\n"
        "So Authentication failed.\nPlease double-check your roll number\nThen re-run the program\n\n");
    sf::FloatRect textBounds4 = text.getLocalBounds();
    text.setPosition((window1.getSize().x - textBounds4.width) / 18, 100);
    sf::FloatRect textBounds = text1.getLocalBounds();
    text1.setPosition((window1.getSize().x - textBounds.width) / 2, 25);
    inputText.setFont(font);
        inputText.setCharacterSize(96);
        inputText.setFillColor(sf::Color::Black);
        inputText.setString("~ENTER\n");
        sf::RectangleShape rectangle(sf::Vector2f(400, 100));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setOutlineThickness(5.f);
        rectangle.setOutlineColor(sf::Color::Red);
        float x, y;
        x = 500;
        y = 500;
        while (window1.isOpen())
        {
            sf::Event event;
            while (window1.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window1.close();
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    window1.close();
                }
                else if (sf::Mouse::getPosition(window1).x > rectangle.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window1).x < rectangle.getGlobalBounds().left +
                    rectangle.getGlobalBounds().width && sf::Mouse::getPosition(window1).y >
                    rectangle.getGlobalBounds().top && sf::Mouse::getPosition(window1).y
                    < (rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height) &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    window1.close(); 
                }
            }
            sf::FloatRect textBounds = inputText.getLocalBounds();
            inputText.setPosition((window1.getSize().x - textBounds.width) / 2.1, 500);
            window1.clear();
            window1.draw(rectangle);
            window1.draw(inputText);
            window1.draw(text);
            window1.draw(text1);
            window1.display();
            rectangle.setPosition(sf::Vector2f(x, y));
        }
}

//program exit
void programExit(sf::RenderWindow& window1, sf::Font& font)
{
    sf::Text text, text1;
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Magenta);
    text1.setFont(font);
    text1.setCharacterSize(60);
    text1.setFillColor(sf::Color::Magenta);
    text1.setString("!!!!!!!!EXITTED SUCCESSFULLY!!!!!!!\n");
    text.setString("THANKYOU FOR USING FLEX,\nHOPEFULLY IT ENTERTAINED YOU.\n"
        "(As per you requirements).\nPlease choose Enter to close program!\n");
    sf::FloatRect textBounds4 = text.getLocalBounds();
    text.setPosition((window1.getSize().x - textBounds4.width) / 20, 100);
    sf::FloatRect textBounds = text1.getLocalBounds();
    text1.setPosition((window1.getSize().x - textBounds.width) / 20, 50);
    window1.draw(text);
    window1.draw(text1);
}

//authentication class(complete)
class Authentication
{
public:
    bool authenticateStudent(int);
};

//student class(complete)
class Student
{
public:
    Student();
    Student(string, int, int, string, int, int, int, int);
    // Methods
    void display();
    void addStudent();
    void removeStudent();
    void editStudentDetail();
    ~Student();
protected:
    string name;
    int roll_num;
    int age;
    string contact;
    int courses;
    int attandance;
    int marks;
    int batch;
};

// Child class 1: Course (inherits from Student)
class Course : public Student
{
public:
    Course();
    Course(int, string, string, int, string);
    ~Course();
    void displayAvailableCourses();
    void AddCourse();
    void removeCourse();
    void displayupdated();
    void displayenrolledcourses();
    void dropCourse();
    void updateStudentRecord(const string&, int);
private:
    int code;
    string dept;
    string coursename;
    string credits;
    int capacity;
};


// Child class 2: Attendance (inherits from Student)
class Attendance
{

public: 
    void markAttendance();
    void displayAttendance();
};

// Child class 3: Marks (inherits from Student)
class Marks
{
public:
    void assignMarks();
    void displayMarks();
};

//system classa(inherits all)
class System : public Student, public Course, public Attendance, public Marks
{
public:
    // Constructor
    System();
    // Method to display the main menu
    void displayMainMenu();
    // Method to display the student menu
    void displayStudentMenu();
    // Method to display the course menu
    void displayCourseMenu();
    // Method to display the Attandance menu
    void displayattandanceMenu();
    // Method to display the marks menu
    void displaymarksMenu();
    // Method to display the coursewithdraw menu
    void displayCoursewithdrawMenu();
    // Method to get user input
    int getUserInput();
    // Method to validate user input
    bool validateInput(int, int, int);
    // Method to perform actions based on user input
    void performAction(int);
    ~System();
private:
    // Attributes
    string mainMenu;
    string studentMenu;
    string courseMenu;
    string attandanceMenu;
    string marksMenu;
    string coursewithdrawMenu;
    // Private methods for managing students and courses
    void manageStudents();
    void manageCourses();
    void manageAttandance();
    void manageMarks();
    void manageCW();
};

//class filehandler
class FileHandler
{
private:
    string filename;
    fstream file;
    char* data;

public:
    FileHandler(const string& fname)
        : filename(fname), data(nullptr) {}

    void openFile(ios_base::openmode);
    bool isOpen() const;
    void closeFile();
    bool readLine(string& line);
    void readFile();
    void writeFile(const char*);
    ~FileHandler();
};