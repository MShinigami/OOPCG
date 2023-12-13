#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class Pub 
{
protected:
    string title;
    float price;

public:
    Pub() : title(""), price(0.0) {}
    Pub(string t, float p) : title(t), price(p) {}

    void display() 
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Pub 
{
private:
    int pages;

public:
    Book() : pages(0) {}
    Book(string t, float p, int pg) : Pub(t, p), pages(pg) {}

    void display() 
    {
        Pub::display();
        cout << "Pages: " << pages << endl;
    }
};

class Tape : public Pub 
{
private:
    float playTime;

public:
    Tape() : playTime(0.0) {}
    Tape(string t, float p, float pt) : Pub(t, p), playTime(pt) {}

    void display() 
    {
        Pub::display();
        cout << "Playing Time (minutes): " << playTime << endl;
    }
};

int main() 
{
    string title;
    float price;
    char choice, another;
    string bookTitle, tapeTitle;
    float bookPrice, tapePrice;
    int bookPages;
    float tapePlayTime;
    int record = 0;
    int bookRec = 0;
    int audioRec = 0;
    int pubRec = 0;

    do 
    {
        try 
        {
            cout << "\n\t*-*-*Menu*-*-*\t\n" << endl;
            cout << "1) Insert the publication record" << endl;
            cout << "2) Insert the Book record." << endl;
            cout << "3) Insert the Audio Cassette record." << endl;
            cout << "4) Display the Data Recorded." << endl;
            cout << "5) Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == '1') 
            {
                cout << "\n\tPublications" << endl;
                cout << "Enter the Title: ";
                cin >> ws;
                cin >> title;
                cin.ignore();
                cout << "Enter the Price: ";
                cin >> price;
                record++;
                pubRec++;
                cout << "Total number of records created -" << record << endl;
                cout << "Publications - " << pubRec << endl;
            } 
            else if (choice == '2') 
            {
                cout << "\n\tBOOK" << endl;
                cout << "Enter the title: ";
                cin >> ws;
                cin >> bookTitle;
                cout << "Enter the price: ";
                cin >> bookPrice;
                cout << "Enter the page count: ";
                cin >> bookPages;
                record++;
                bookRec++;
                cout << "Total number of records created -" << record << endl;
                cout << "Books - " << bookRec << endl;
            } 
            else if (choice == '3') 
            {
                cout << "\n\tAudio Cassette" << endl;
                cout << "Enter the title: ";
                cin >> ws;
                cin >> tapeTitle;
                cout << "Enter the price: ";
                cin >> tapePrice;
                cout << "Enter the playing time (in minutes): ";
                cin >> tapePlayTime;
                record++;
                audioRec++;
                cout << "Total number of records created -" << record << endl;
                cout << "Audio Cassette - " << audioRec << endl;
            } 
            else if (choice == '4') 
            {
                cout << "Total number of records created -" << record << endl;
                cout << "Publications - " << pubRec << endl;
                cout << "Books - " << bookRec << endl;
                cout << "Audio Cassette - " << audioRec << endl;

                Pub pub(title, price);
                cout << "\n\tPublication Information" << endl;
                pub.display();

                Book book(bookTitle, bookPrice, bookPages);
                cout << "\n\tBook Information" << endl;
                book.display();

                Tape tape(tapeTitle, tapePrice, tapePlayTime);
                cout << "\n\tAudio Cassette Information" << endl;
                tape.display();
            } 
            else if (choice == '5') 
            {
                break;
            } 
            else 
            {
                continue;
            }
        } 
        catch (...) 
        {
            cerr << "An exception occurred. Setting all data members to zero." << endl;
            Book book("", 0.0, 0);
            Tape tape("", 0.0, 0.0);

            cout << "\nReset Information:" << endl;
            cout << "\nBook Information:" << endl;
            book.display();

            cout << "\nAudio Cassette Information:" << endl;
            tape.display();
        }
        cout << "Do you want to enter more publication(y/n)?: ";
        cin >> another;

    } 
    while (another == 'y' || another == 'Y');
    return 0;
}
