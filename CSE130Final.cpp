/*Daniel Yanez (#5535343)
April 23, 2024
The purpose of this project is to create a program that randomly selects a given sample of patients and determines
whether they have Covid-19, a cold, the flu, or other disease. It will then show how many patients have each disease
and the total percentage for each disease.
*/

#include <iostream>
#include <time.h>
//namespace
using namespace std;

//Base class
class PatientTracker {
private:
	int patients;
public:
	PatientTracker(int p) {
		patients = p;
	}
	
	int getPatients() {
		return patients;
	}
	
	void setPatient(int p) {
		patients = p;
	}
};

//DDerived class
class Checker : public PatientTracker {
private:
	int covid;
	int cold; 
	int flu;
	int other;
public:
	Checker(int p) : PatientTracker(p) {
		covid = 0;
		cold = 0; 
		flu = 0;
		other = 0;
	}
	
	int getCovid() {
		return covid;
	}
	
	int getCold() {
		return cold;
	}
	
	int getFlu() {
		return flu;
	}
	
	int getOther() {
		return other;
	}	
	
	void patientSymptoms() {
	    string result[] = {"present", "absent"};
		
	    for (int i = 0; i < getPatients(); i++) {
	        string answer;
	        bool fever, cough, breath, runny, headache, sneeze, fatigue;
	
	        answer = rand() % 2 == 0 ? result[0] : result[1];
	        fever = answer == "present" ? true : false;
	
	        answer = rand() % 2 == 0 ? result[0] : result[1];
	        cough = answer == "present" ? true : false;
	
	        answer = rand() % 2 == 0 ? result[0] : result[1];
	        breath = answer == "present" ? true : false;
	
	        answer = rand() % 2 == 0 ? result[0] : result[1];
	        runny = answer == "present" ? true : false;
	
	        answer = rand() % 2 == 0 ? result[0] : result[1];
	        headache = answer == "present" ? true : false;
	
	        answer = rand() % 2 == 0 ? result[0] : result[1];
	        sneeze = answer == "present" ? true : false;
	
	        answer = rand() % 2 == 0 ? result[0] : result[1];
	        fatigue = answer == "present" ? true : false;
						
	
			if (fever == true && cough == true && breath == false && headache == true && sneeze == false && fatigue == true) {
				flu++;
			} else if (fever == true && cough == true && breath == true && sneeze == false) {
				covid++;
			} else if (breath == false && runny == true && sneeze == true) {
				cold++;
			} else {
				other++;
			}
		}
	}
	
	void patientResults() {
		cout << "========================================" << endl;
		cout << "Symptoms Tracker Checker...." << endl;
		cout << getCovid() <<  " patients have symptoms of COVID-19" << endl;
		cout << getCold() << " patients have symptoms of Cold" << endl;
		cout << getFlu() << " patients have symptoms of Flu" << endl;
		cout << getOther() << " patients may have some other illness" << endl;
		cout << "========================================" << endl;	
	}
	
	void printPercentageIllness() {
		float covidResult = (float)getCovid()/(float)getPatients() * 100;
		float coldResult = (float)getCold()/(float)getPatients() * 100;
		float fluResult = (float)getFlu()/(float)getPatients() * 100;
		float otherResult = (float)getOther()/(float)getPatients() * 100;
		
		cout << "Percentage of each illness:" << endl;
		if (getPatients() == 0) {
			cout << "Covid-19: [" << 0 << "%]" << endl;
		} else {
			cout << "Covid-19: [" << covidResult << "%]" << endl;
			for (int i = 0; i < getCovid(); i++) {
				cout << "+";
			}	
		}
		cout << endl;

		if (getPatients() == 0) {
			cout << "Cold: [" << 0 << "%]" << endl;
		} else {
			cout << "Cold: [" << coldResult << "%]" << endl;
			for (int i = 0; i < getCold(); i++) {
				cout << "+";
			}	
		}
		cout << endl;

		if (getPatients() == 0) {
			cout << "Flu: [" << 0 << "%]" << endl;
		} else {
			cout << "Flu: [" << fluResult << "%]" << endl;
			for (int i = 0; i < getFlu(); i++) {
				cout << "+";
			}
		}
		cout << endl;
		
		if (getPatients() == 0) {
			cout << "Other illness: [" << 0 << "%]" << endl;
		} else {
			cout << "Other illness: [" << otherResult << "%]" << endl;
			for (int i = 0; i < getOther(); i++) {
				cout << "+";
			}
		}
		cout << endl;
	}	
};

void printTable() {
	cout << "Welcome to Symptoms Checker\n" << endl;
	cout << "Guide: * Common  + Sometimes/Rarely  - NO" << endl;
	cout << "========================================" << endl;
	cout << "Symptoms           |COVID-19 |Cold|Flu |" << endl;
	cout << "========================================" << endl;
	cout << "Fever              | *       |	+  | * |" << endl;
	cout << "Cough              | *       |	+  | * |" << endl;
	cout << "Shortness of Breath| *       |	-  | - |" << endl;
	cout << "Runny Nose         | +       |	*  | + |" << endl;
	cout << "Headaches          | +       |	+  | * |" << endl;
	cout << "Sneezing           | -       |	*  | - |" << endl;
	cout << "Fatigue            | +       |	+  | * |" << endl;
	cout << "========================================" << endl;	
}

int main() {
	srand(time(0));
	printTable();
	int iPatients;
	cout << "\nEnter the number of patients: " << endl;
	cin >> iPatients;
	cout << "Thank you..." << endl;
	Checker patients(iPatients);
	patients.patientSymptoms();
	cout << endl;
	patients.patientResults();
	cout << endl;
	patients.printPercentageIllness();
	return 0;
}