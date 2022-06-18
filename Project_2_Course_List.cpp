#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

#include <thread>																					// Thread and chrono are included solely for
#include <chrono>																					// aesthetic timings between actions and outputs.

using namespace std;

//==================================================================
// Global Definitions
//==================================================================

struct Course {																						// Course structure to store course information.
	string courseId;
	string title;
	string prereq1;
	string prereq2;

	Course() {																						// Default "prereq1" and "prereq2" to nothing.
		prereq1 = "";
		prereq2 = "";
	}
};

//==================================================================
// Forward Declarations
//==================================================================

int Search(const vector<Course>& courseList, string courseId);
void PrintCourse(const vector<Course>& courseList, string courseId);
void PrintCourseList(const vector<Course>& courseList);
void SkipBOM(ifstream& in);
vector<Course> LoadAllCourses(string fileName);
int Partition(vector<Course>& courses, int begin, int end);
void QuickSort(vector<Course>& courses, int begin, int end);

//==================================================================
// Function Definitions
//==================================================================

/*
 * Search for a particular course.
 * 
 * @param reference to course list vector, course ID string
 * @return int representing element index in course list vector
 */
int Search(const vector<Course>& courseList, string courseId) {										// Returns an integer in a sort of boolean
																									// mindset to pre-emptively determine
	int index = -1;																					// console output depending on search
																									// resuts.
	for (unsigned int i = 0; i < courseList.size(); i++) {

		if (courseId == courseList.at(i).courseId) {
			index = i;
		}
	}

	return index;
}

/*
 * Display a singular course and all of its information.
 *
 * @params reference to course list vector, course ID string.
 */
void PrintCourse(const vector<Course>& courseList, string courseId) {

	for (unsigned int j = 0; j < courseId.size(); j++) {											// Make user input all-caps to match
		courseId[j] = toupper(courseId[j]);															// loaded courses.
	}

	int index = Search(courseList, courseId);

	if (index > -1) {

		cout << "\t------------- SELECTED COURSE -------------" << endl;

		cout << "\t" << courseList.at(index).courseId << ": "										// Print course ID and title...
			 << courseList.at(index).title << endl;

		if (courseList.at(index).prereq1 != "") {													// ... as well as prerequisite(s)

			if (courseList.at(index).prereq2 != "") {												// ... if it/they exist.

				cout << "\tPrerequisites: " << courseList.at(index).prereq1 << "\n"
					 << "\t               " << courseList.at(index).prereq2 << endl;
			}
			else {
				cout << "\tPrerequisite: " << courseList.at(index).prereq1 << endl;
			}
		}

		cout << "\t-------------------------------------------" << endl;
	}
	else {
		cout << "\t" << courseId << " does not exist." << endl;
	}
}

/*
 * Display all course IDs and their titles.
 *
 * @params reference to course list vector, course ID string.
 */
void PrintCourseList(const vector<Course>& courseList) {

	cout << "\t--------------- COURSE LIST ---------------" << endl;
	
	for (unsigned int i = 0; i < courseList.size(); i++) {											// Linearly print one course at a time.

		cout << "\t" << courseList.at(i).courseId << ": "
			 << courseList.at(i).title << endl;
	}

	cout << "\t-------------------------------------------" << endl;
}

/*
 * Skip Byte Order Mark (BOM) created by file's
 * creator application.  The internet helped with
 * this one...
 * 
 * @param reference to in-stream utilized for file parsing.
 */
void SkipBOM(ifstream& in) {																		// This function is vitally important in
																									// removing the Byte Order Mark (BOM) from
	char test[3] = {0};																				// the beginning of the file.
	in.read(test, 3);																				//
																									// The BOM was added in by the application
	if ((unsigned char)test[0] == 0xEF &&															// that created the .txt file.  This func-
		(unsigned char)test[1] == 0xBB &&															// tion in its entirety (and its respec-
		(unsigned char)test[2] == 0xBF) {															// tive call on line 168) can be removed
																									// if the .txt file loaded does not have a
		return;																						// BOM added in -- the one used for tes-
	}																								// ting this program does.

	in.seekg(0);
}

/*
 * Load CSV file courses into created course list vector.
 * 
 * @param file name string.
 * @return course list vector with added file courses.
 */
vector<Course> LoadAllCourses(string fileName) {

	cout << "\tLoading file: " << fileName << ".";
	this_thread::sleep_for(chrono::seconds(1));														// Aesthetically print periods sequen-
	cout << ".";																					// tially utiliing THREAD and CHRONO
	this_thread::sleep_for(chrono::seconds(1));														// to harken to console loading anima-
	cout << ".";																					// tions.
	this_thread::sleep_for(chrono::seconds(1));

	vector<Course> courses;

	vector<string> words;
	string line;
	string word;

	try {

		ifstream newFile(fileName);																	// Create in-stream for parsing file.
		SkipBOM(newFile);																			// Skip the potentially-added BOM.

		if (!newFile.is_open()) {
			throw false;
		}
		else {

			while (getline(newFile, line)) {

				Course* course = new Course();														// Course pointer for temporarily storing course info.
				stringstream strstr(line);															// Create string stream for line perusal.

				while (getline(strstr, word, ',')) {												// Separate words via delimiter comma and add them to temporary word vector.
					words.push_back(word);
				}

				course->courseId = words.at(0);														// Add these words to
				course->title = words.at(1);														// their respective...

				if (words.size() > 2) {
					course->prereq1 = words.at(2);													// ...course info...

					if (words.size() > 3) {
						course->prereq2 = words.at(3);												// ... slots.
					}
				}

				courses.push_back(*course);															// Add this newly created course to the course list.
				delete course;																		// Delete the course pointer for memory's sake.

				words.clear();																		// "Refresh" word list for next line perusal.
				words.resize(0);																	// Resize word list for next line perusal.
			}

			cout << endl;
			cout << "\tDone." << endl;
		}
	}
	catch (...) {
		cout << endl;
		cout << "\n\tERROR: could not open file." << endl;
		cout << "\t(File data is corrupted or file does not exist)" << endl;
	}

	return courses;
}

/*
 * Set a partition section for quick sorting the course list
 * vector.
 * 
 * @params reference to course list vector, ints begin and end
 *		   to represent beginning and ending of partition sec-
 *		   tion.
 */
int Partition(vector<Course>& courses, int begin, int end) {										// Utilizing the QUICKSORT mindset, this func-
	int low = begin;																				// -tion partitions the course list in halves
	int high = end;																					// for sorting.
	int midpoint = low + (high - low) / 2;															// 
																									// This manner of sorting was chosen for its
	Course pivot = courses.at(midpoint);															// namesake as it is easy-on-the-memory and
																									// has great average runtime complexity
	bool done = false;																				// performance.

	while (!done) {

		while (courses.at(low).courseId < pivot.courseId) {
			low += 1;
		}

		while (pivot.courseId < courses.at(high).courseId) {
			high -= 1;
		}

		if (low >= high) {
			done = true;
		}
		else {
			swap(courses.at(low), courses.at(high));

			low += 1;
			high -= 1;
		}
	}

	return high;
}

/*
 * "Quickly sort" course list vector alphanumerically.
 * Average logarithmic runtime complexity; worst-case linear.
 * 
 * @params reference to course list vector, ints begin and end
 *		   representing beginning and ending of partition sec-
 *		   tion.
 */
void QuickSort(vector<Course>& courses, int begin, int end) {										// Utilizing the PARTITIONING done prior,
																									// this function sorts the course list in
	int midpoint = 0;																				// halves via recursive method calling.
																									// 
	if (begin >= end) {																				// This manner of sorting was chosen for its
		return;																						// nameksake as it is easy-on-the-memory and
	}																								// has great average runtime complexity
																									// performance.
	midpoint = Partition(courses, begin, end);
	QuickSort(courses, begin, midpoint);
	QuickSort(courses, midpoint + 1, end);
}

//==================================================================
// The one and only main()!
//==================================================================

int main() {

	//=========================
	// Establishing variables.
	//=========================

	const char* MENU_PROMPT = "-----------MENU-----------\n"
							  "1. Load Vector Course List\n"
							  "2. Print Course List\n"
							  "3. Print Course\n"
							  "9. Exit\n"
							  "--------------------------";

	string menuInput = "a";
	char menuChoice = 'a';

	string fileName = "";
	string courseId = "";

	vector<Course> courses;

	//=========================================
	// Performing the project's requirements.
	//=========================================

	while (menuChoice != '9') {

		cin.clear();																				// Clear cin for next input, to be safe.

		this_thread::sleep_for(chrono::seconds(2));

		cout << MENU_PROMPT << endl;
		cout << "Selection: ";

		try {

			getline(cin, menuInput);

			if (menuInput.size() == 0) {
				throw('\n');
			}
			else if (menuInput.size() >= 2) {
				throw(menuInput);
			}
			else {
				menuChoice = toupper(menuInput[0]);
			}

			switch(menuChoice) {

				case '1':
					
					cout << endl;
					cout << "\tKeep in mind case sensitivity and file extension." << endl;			// Remind user of case sensitivity in
					cout << "\tEnter name of file from which to load courses: ";					// file look-up.
					getline(cin, fileName);

					cout << endl;
					courses = LoadAllCourses(fileName);

					break;

				case '2':

					cout << endl;
					QuickSort(courses, 0, courses.size() - 1);										// Sort course list prior to printing.
					PrintCourseList(courses);

					break;

				case '3':

					cout << endl;
					cout << "\tDesired course ID (subject and number): ";
					getline(cin, courseId);

					cout << endl;
					PrintCourse(courses, courseId);

					break;

				case '4':
				case '5':
				case '6':
				case '7':
				case '8':

					cout << endl;
					cout << "\t" << menuChoice << " is not a valid numerical selection." << endl;
					break;

				case '9':

					break;

				default:

					throw(menuChoice);
			}
		}
		catch (string selection) {

			cout << endl;
			cout << "\tInvalid input.";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "  Only one-character numerics are allowed." << endl;
		}
		catch (char selection) {

			if (selection == '\n') {

				cout << selection << "\tPlease select a menu option." << endl;
			}
			else {

				cout << endl;
				cout << "\t\"" << selection << "\" is invalid input.";
				this_thread::sleep_for(chrono::seconds(1));
				cout << "  Only numerics 1 through 9 are accepted." << endl;
			}
		}

		cout << endl;
	}

	cout << "\t _________" << endl;
	cout << "\t/         \\" << endl;
	cout << "\t| GOODBYE |" << endl;
	cout << "\t\\_________/" << endl;
	this_thread::sleep_for(chrono::seconds(2));

	return 0;
}