#include<iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
class superAdmin;
superAdmin* constructorA();
superAdmin* supremeAdmin = constructorA();
const int vaccinePerCenter = 100;
int count1 = 1;
int count2 = 1;
int counter = 1;
bool absoluteAuthority = true;
bool checks[5] = { false,false ,false ,false ,false };
class FDO;
class Doctor;
class companies;
class admin;
class vaccinationCenter;
class  governmet_official;
class populationControl;
int no_Of_Doctors = 0;
int no_Of_Admins = 0;
int no_Of_VaccineCenters = 0;
int no_Of_Warehouses = 0;
class timex
{
public:
	static int noOfDayz;
	void OneDayHasPassed()
	{
		noOfDayz++;
	}
};
class populationControl
{
public:
	string* districts;
	string** citiies;
	int idxCity;
	int* noOfCities = new int[idxCity];
	int noOfDistricts;
	int** cityPopu;
	int* districtPopu;
	int totalPopulation;
	populationControl()
	{
		fstream fin;
		fin.open("Districts.txt", ios::in);
		int x, y;
		fin >> x;
		noOfDistricts = x;
		idxCity = x;
		districts = new string[x];
		citiies = new string * [x];
		districtPopu = new int[noOfDistricts] {};
		cityPopu = new int* [noOfDistricts];
		for (int i = 0; i < x; i++)
		{
			fin >> districts[i];
			fin >> y;
			citiies[i] = new string[y];
			cityPopu[i] = new int[y];
			for (int j = 0; j < y; j++)
			{
				fin >> citiies[i][j];
				fin >> cityPopu[i][j];
			}
			noOfCities[i] = y;
		}
		for (int i = 0; i < noOfDistricts; i++)
		{
			for (int j = 0; j < noOfCities[i]; j++)
			{
				districtPopu[i] += cityPopu[i][j];
			}
		}
		totalPopulation = 0;
		for (int i = 0; i < noOfDistricts; i++)
		{
			totalPopulation += districtPopu[i];
		}
	}
};

populationControl populat;
int getDistrictIDx(string x)
{
	for (int i = 0; i < populat.noOfDistricts; i++)
		if (x == populat.districts[i])
			return i;
	return -1;
}
class distributionP
{
public:
	static int noOfVaccineCenters;
	static int noOfWarehouses;
public:
	static void assignPopulation()
	{
		int x;
		noOfWarehouses = populat.noOfDistricts;
		for (int i = 0; i < populat.noOfDistricts; i++)
		{
			for (int j = 0; j < populat.noOfCities[i]; j++)
			{
				x = populat.cityPopu[i][j];
				if (x > 20000)
				{
					while (1)
					{
						if (x > 0)
						{
							x = x - 20000;
							noOfVaccineCenters++;
						}
						else
							break;
					}
				}
				else
				{
					noOfVaccineCenters++;
				}
			}
		}
	}

};
int distributionP::noOfVaccineCenters = 0;
int distributionP::noOfWarehouses = 0;
class person {
public:
	string firstname, lastname, email, contactNumber, ID;
public:
	void personinput(fstream& obj) {
		obj >> firstname >> lastname >> email >> contactNumber >> ID;
	}
	void personInput() {
		cout << "\nenter the name:";
		cin >> firstname;
		cout << "\nenter the lastname:";
		cin >> lastname;
		cout << "\nenter the email:";
		cin >> email;
		cout << "\nenter the contact number:";
		cin >> contactNumber;
		cout << "\nenter the id:";
		cin >> ID;

	}
	void output(fstream& obj) {
		obj << getFirstname();
		obj << endl << getlastname() << endl << getemail() << endl << getContactNumber() << endl << getID() << endl;
	}
	void personoutput() {
		cout << "\nname:" << getFirstname();
		cout << "\nlastname:" << getlastname();
		cout << "\nemail:" << getemail();
		cout << "\ncontact number:" << getContactNumber();
		cout << "\nid:" << getID();
	}
	string getID() {
		return ID;
	}
	string getContactNumber() {
		return contactNumber;
	}
	string getFirstname() {
		return firstname;
	}
	string getlastname() {
		return lastname;
	}
	string getemail() {
		return email;
	}
};
class citizen :public person {
	bool check1;
	bool check2;
	string age;
	string cnic;
	string blood_type;
	string city;
	string state;
	string address;
	string DOB;
	fstream patientfile;
	int part = 0;
	int full = 0;

public:
	friend FDO eligibility(FDO ob, citizen& obj);
	bool partialVaccine()
	{
		fstream fin;
		fin.open("PatientFile.txt", ios::in);
		string str[14];
		for (size_t i = 0; i < 14; i++)
		{
			getline(cin, str[i]);
		}

	}
	citizen()
	{

	}
	void citizenInputfromFile(string x)
	{
		fstream fin;
		fin.open("PatientFile.txt", ios::in);
		while (true)
		{
			fin >> firstname;
			fin >> lastname;
			fin >> email;
			fin >> contactNumber;
			fin >> ID;
			fin >> cnic;
			fin >> city;
			fin >> state;

			fin >> blood_type;
			fin >> address;
			fin >> DOB;
			if (email == x)
			{
				break;
			}
			else if (fin.eof())
			{
				break;
			}
		}
		cout << "Enter your age: ";
		cin >> age;
		check1 = true;
		check2 = true;
		fin.close();

	}
	void citizenInput() {
		personInput();
		int S;
		cout << "\nenter the cnic of citizen:";
		cin >> cnic;
		cout << "\nenter the district:";
		int I;
		for (I = 0; I < populat.noOfDistricts; I++)
		{
			cout << "Enter " << I << " for " << populat.districts[I] << endl;
		}
		cin >> S;
		state = populat.districts[S];
		cout << "\nenter the city:";
		for (int i = 0; i < populat.noOfCities[S]; i++)
		{
			cout << "Enter " << i << " for " << populat.citiies[S][i] << endl;
		}
		cin >> city;
		cout << "\nenter the blood type:";
		cin >> blood_type;
		cout << "\nenter the address:";
		cin >> address;
		cout << "\nenter the date of birth:";
		cin >> DOB;
		cout << "\nDo you have any history of severe allergic reaction to vaccines:";
		string s;
		cin >> s;
		if (s == "yes") {
			check1 = false;
		}
		else {
			check1 = true;
		}
		cout << "\nenter the age:";
		cin >> age;
		if (stoi(age) < 5) {
			check2 = false;
		}
		else {
			check2 = true;
		}

	}
	void store_data_in_file(fstream& obj) {
		output(obj);
		obj << cnic << endl << city << endl << state << endl << blood_type << endl << address << endl << DOB << endl;
	}
	void view_citizen_history() {
		cout << "\nfirst Name: " <<
			getFirstname();
		cout << "\nlast Name: " <<
			getlastname();
		cout << "\n Contact Number: " <<
			getContactNumber();
		cout << "\nEmail: " <<
			getemail();
		cout << "\nID: " <<
			getID();
		cout << "\nCNIC: " <<
			getcnic();
		cout << "\City: " <<
			getCity();
		cout << "\nState: " <<
			getstate();
		cout << "\nBlood_type: " <<
			getBlooodtype();
		cout << "\naddress: " <<
			getaddress();
		cout << "\nDate of Birth: " <<
			getDOB();
	}
	int getAge()
	{
		return stoi(age);
	}
	string getcnic() {
		return cnic;
	}
	string getDOB() {
		return DOB;
	}
	string getBlooodtype() {
		return blood_type;
	}
	string getaddress() {
		return address;
	}
	string getCity() {
		return city;
	}
	string getstate() {
		return state;
	}
	bool receive_cofirmation(bool c) {
		if (c == true) {
			cout << "\nyou have been registered in the system and get vaccinated any time by visiting FDO center:";
		}
		else {
			cout << "\nYour are not eligible:";
		}
		return c;
	}
	fstream& sendpatientFile() {
		patientfile.open("patient_file.txt", ios::in);
		return patientfile;
	}
};

class Doctor :public person {
public:
	friend class superAdmin;
	citizen ptr;
	string duty_days;
	static string  BP;
	static string Oxygen_level;
	static string glucose;
	fstream doctorfile;
public:
	void operator =(Doctor& obj)
	{
		firstname = obj.firstname;
		lastname = obj.lastname;
		ID = obj.ID;
		contactNumber = obj.contactNumber;
		email = obj.email;
		duty_days = obj.duty_days;
	}
	Doctor() {
		/*personInput();
		cout << "\nenter the duty days:";
		cin >> duty_days;*/
	}
	void doctor_infoupdate() {
		personInput();
		cout << "\nenter the duty days:";
		cin >> duty_days;
	}
	void doctor_input() {
		cout << "\nenter the duty days:";
		cin >> duty_days;
	}
	void Doctor_dataoutput() {
		personoutput();
		cout << "\nduty days:" << duty_days;
	}
	void Doctor_patient_input(int n) {

		doctorfile.open("patients_vitals", ios::app);
		for (int i = 0; i < n; i++) {
			ptr.citizenInput();
			cout << "\nenter the BP:";
			cin >> BP;
			cout << "\nenter the Oxygen level:";
			cin >> Oxygen_level;
			cout << "\nenter the glucose:";
			cin >> glucose;
		}
		readpatientdata(ptr.sendpatientFile());

	}
	static void Doctor_inputer(fstream& doctorfile) {
		cout << "\nenter the BP:";
		cin >> BP;
		cout << "\nenter the Oxygen level:";
		cin >> Oxygen_level;
		cout << "\nenter the glucose:";
		cin >> glucose;
		doctorfile << BP << endl << Oxygen_level << endl << glucose << endl;
	}
	void readpatientdata(fstream& obj1) {
		while (!obj1.eof()) {
			int index = 0;
			int count = 0;
			string s;
			obj1 >> s;
			doctorfile << s << endl;
			count++;
			if (count == 11) {
				count = 0;
				doctorfile << BP[index] << endl << Oxygen_level[index] << endl << glucose[index] << endl;
				index++;
			}
		}
	}

};
string  Doctor::BP;
string Doctor::Oxygen_level;
string Doctor::glucose;
bool SignIn(istream& file, string email, string password)
{
	bool istrue = false;
	string fileEmail;
	string filePassword;
	while (true)
	{
		file >> fileEmail;
		file >> filePassword;
		if (fileEmail == email && filePassword == password)
		{
			istrue = true;
		}
		if (file.eof())
		{
			break;
		}
	}
	if (istrue)
	{
		return true;
	}
	else
		return false;
}
class vaccine
{
public:
	string vacType;
	string vacName;
	int vacID;
	string NumberOfDoses;
	string price;
	string batchID;
	int quantity;
public:
	friend class vaccinationCenter;
	friend class wareHouse;
	vaccine(string a, string b, string c, string d)
	{
		NumberOfDoses = a;
		price = b;
		vacID = counter++;
		vacName = c;
		vacType = d;
	}
	vaccine()
	{
		NumberOfDoses = "LOL";
		price = "Null";
		vacID = 0;
		vacName = "Null";
		vacType = "Null";
	}
	void vaccine_display() {
		cout << "\nvaccine Name:" << vacName;
		cout << "\nVaccine No_of_Doses:" << NumberOfDoses;
		cout << "\nVaccine price: " << price;
		cout << "\nVaccine Batch ID: " << batchID;
		cout << "\n Vaccine quantity: " << quantity << endl;
	}
};
class companies : public vaccine
{
	string companyname;
	vaccine vac1;
	vaccine vac2;
	friend class admin;
public:
	companies()
	{
		companyname = "Loonay Wala Trades";
		vac1.quantity = populat.totalPopulation;
		vac2.quantity = populat.totalPopulation;
		vac1.NumberOfDoses = "1";
		vac1.price = "10$";
		vac1.vacType = "Virus Vector";
		vac1.vacName = "pfizer";
		vac2.NumberOfDoses = "2";
		vac2.price = "1000 RS.";
		vac2.vacType = "Nuclei Acid";
		vac2.vacName = "sinopharm";
	}

};
class admin :public person
{
public:
	friend class superAdmin;
	static vaccine vac1;
	static vaccine vac2;
public:
	admin() {
		personInput();
	}
	void admin_infoupdate() {
		personInput();
	}
	static void procuringVaccines(companies com)
	{

		vac1.batchID = com.vac1.batchID;
		vac1.NumberOfDoses = com.vac1.NumberOfDoses;
		vac1.price = com.vac1.price;
		vac1.quantity = vaccinePerCenter * distributionP::noOfVaccineCenters;
		com.vac1.quantity -= vaccinePerCenter * distributionP::noOfVaccineCenters;
		vac1.vacName = com.vac1.vacName;
		vac1.vacType = com.vac1.vacType;
		vac1.vacID = com.vac1.vacID;
		vac2.batchID = com.vac2.batchID;
		vac2.NumberOfDoses = com.vac2.NumberOfDoses;
		vac2.price = com.vac2.price;
		vac2.quantity = vaccinePerCenter * distributionP::noOfVaccineCenters;
		com.vac2.quantity -= vaccinePerCenter * distributionP::noOfVaccineCenters;
		vac2.vacName = com.vac2.vacName;
		vac2.vacType = com.vac2.vacType;
		vac2.vacID = com.vac2.vacID;
		cout << "\nImported Vaccines received from " << com.companyname << " are: " << vac1.quantity;
		cout << "\nLocal vaccines received from " << com.companyname << " are: " << vac2.quantity;
	}
	void admin_dataoutput() {
		personoutput();
	}
};
vaccine admin::vac1;
vaccine admin::vac2;
int noOfVaccineCentersPerDistrict(int idx)
{
	int x = 0;
	int noOfVaccineCenter = 0;
	for (int j = 0; j < populat.noOfCities[idx]; j++)
	{
		x = populat.cityPopu[idx][j];
		if (x > 20000)
		{
			while (1)
			{
				if (x > 0)
				{
					x = x - 20000;
					noOfVaccineCenter++;
				}
				else
					break;
			}
		}
		else
		{
			noOfVaccineCenter++;
		}
	}
	return noOfVaccineCenter;
}
int warehouseIDx = 0;
class wareHouse
{
	friend class vaccinationCenter;
	friend class superAdmin;
	string warehouseName;
	string warehouselocation;
	string warehousecapacity;

	vaccine vac1;
	vaccine vac2;
	int particularIDx;
public:
	wareHouse() {
		particularIDx = warehouseIDx;
		cout << "\nenter the warehouse " << warehouseIDx << " Name:";
		cin >> warehouseName;
		cout << "\nenter the warehouse " << warehouseIDx << " Location:";
		cin >> warehouselocation;
		cout << "\nenter warehouse " << warehouseIDx << " capacity:";
		cin >> warehousecapacity;
		warehouseIDx++;
	}
	void sentToWarehouse()
	{
		vac1.batchID = admin::vac1.batchID;
		vac1.NumberOfDoses = admin::vac1.NumberOfDoses;
		vac1.price = admin::vac1.price;
		vac1.quantity = (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		admin::vac1.quantity = admin::vac1.quantity - (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		vac1.vacName = admin::vac1.vacName;
		vac1.vacType = admin::vac1.vacType;
		vac1.vacID = admin::vac1.vacID;
		vac2.batchID = admin::vac2.batchID;
		vac2.NumberOfDoses = admin::vac2.NumberOfDoses;
		vac2.price = admin::vac2.price;
		vac2.quantity = (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		admin::vac2.quantity = admin::vac2.quantity - (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		vac2.vacName = admin::vac2.vacName;
		vac2.vacType = admin::vac2.vacType;
		vac2.vacID = admin::vac2.vacID;
		cout << "\nImported Vaccines received in warehouse " << warehouseName << " are: " << vac1.quantity;
		cout << "\nLocal vaccines received in warehouse " << warehouseName << " are: " << vac2.quantity;
	}
	void sentToWarehouse(int x)
	{
		vac1.batchID = admin::vac1.batchID;
		vac1.NumberOfDoses = admin::vac1.NumberOfDoses;
		vac1.price = admin::vac1.price;
		vac1.quantity = (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		admin::vac1.quantity = admin::vac1.quantity - (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		vac1.vacName = admin::vac1.vacName;
		vac1.vacType = admin::vac1.vacType;
		vac1.vacID = admin::vac1.vacID;
		vac2.batchID = admin::vac2.batchID;
		vac2.NumberOfDoses = admin::vac2.NumberOfDoses;
		vac2.price = admin::vac2.price;
		vac2.quantity = (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		admin::vac2.quantity = admin::vac2.quantity - (vaccinePerCenter * noOfVaccineCentersPerDistrict(particularIDx));
		vac2.vacName = admin::vac2.vacName;
		vac2.vacType = admin::vac2.vacType;
		vac2.vacID = admin::vac2.vacID;
		cout << "\nImported Vaccines received in warehouse " << warehouseName << " are: " << vac1.quantity;
		cout << "\nLocal vaccines received in warehouse " << warehouseName << " are: " << vac2.quantity;
	}
	void warehouse_dataoutput() {
		cout << "\nwarehouse Name:" << warehouseName << "\nwarehouse Location:"
			<< warehouselocation << "\nwarehouse Capacity:"
			<< warehousecapacity << endl;
	}
	void warwhouse_dataupdate() {
		cout << "\nenter the warehouse Name:";
		cin >> warehouseName;
		cout << "\nenter the warehouse Location:";
		cin >> warehouselocation;
		cout << "\nenter warehouse capacity:";
		cin >> warehousecapacity;
	}
};
class vaccinationCenter
{
	friend class superAdmin;
	vaccine vac1;
	vaccine vac2;
	int vacOld1 = 0;
	int vacOld2 = 0;
	static int vaccinationCenterIDx;
public:
	string name;
	bool canBeUpdateedVac1()
	{
		if (vac1.quantity < (vaccinePerCenter / 2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool canBeUpdateedVac2()
	{
		if (vac2.quantity < (vaccinePerCenter / 2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	vaccinationCenter()
	{
		vac1.quantity = 0;
		vac2.quantity = 0;
		cout << "\nEnter Name of Vaccination Center " << vaccinationCenterIDx << ": ";
		cin.ignore();
		getline(cin, name);
		vaccinationCenterIDx++;
	}
	/*vaccinationCenter() {};*/
	void sentToVaccinationCenter(wareHouse comp)
	{
		int xyz;
		vac1.batchID = comp.vac1.batchID;
		vac1.NumberOfDoses = comp.vac1.NumberOfDoses;
		vac1.price = comp.vac1.price;
		vacOld1 = vac1.quantity;
		xyz = vaccinePerCenter - vac1.quantity;
		vac1.quantity += xyz;
		comp.vac1.quantity -= xyz;
		vac1.vacName = comp.vac1.vacName;
		vac1.vacType = comp.vac1.vacType;
		vac1.vacID = comp.vac1.vacID;
		vac2.batchID = comp.vac2.batchID;
		vac2.NumberOfDoses = comp.vac2.NumberOfDoses;
		vac2.price = comp.vac2.price;
		vacOld2 = vac2.quantity;
		xyz = vaccinePerCenter - vac2.quantity;
		vac2.quantity += xyz;
		comp.vac2.quantity -= xyz;
		vac2.vacName = comp.vac2.vacName;
		vac2.vacType = comp.vac2.vacType;
		vac2.vacID = comp.vac2.vacID;
		cout << "\nImported Vaccines received in Vaccination Center " << name << " are: " << vac1.quantity;
		cout << "\nLocal vaccines received in Vaccination Center " << name << " are: " << vac2.quantity;

	}
	void vaccinationCenter_dataoutput()
	{
		cout << "\nlocal vaccine: ";
		vac1.vaccine_display();
		cout << "\nInternational vaccine:";
		vac2.vaccine_display();
	}
	void vaccinationCenter_update() {
		cout << "\nenter the quantity of local vaccines:";
		cin >> vac1.quantity;
		cout << "\nenter the quantity of international vaccines:";
		cin >> vac2.quantity;
	}
	void minusVac1()
	{
		vac1.quantity--;
	}
	void minusVac2()
	{
		vac2.quantity--;
	}
};
int vaccinationCenter::vaccinationCenterIDx = 0;
vaccinationCenter* vaccinationcenterOBJ;
class FDO :public person
{
	citizen* pointer;
	static int count;
public:
	int vaccine_count = 0;
	bool eligible = false;
	char q = '0';
	friend class citizen;
	friend FDO eligibility(FDO ob, citizen& obj);
	bool previousFullyVaccinated(string x)
	{
		fstream fin;
		fin.open("Fully vaccinated.txt", ios::in);
		string y;
		while (true)
		{
			if (fin.eof())
			{
				break;
			}
			fin >> y;
			if (y == x)
			{
				return true;
			}

		}
		fin.close();
		return false;

	}
	bool previousPatient(string x)
	{
		fstream fin;
		fin.open("VacinatedPeeps.txt", ios::in);
		string str[15];
		while (true)
		{
			for (size_t i = 0; i < 15; i++)
			{
				getline(fin, str[i]);
			}
			if (x == str[2])
			{
				return true;
			}
			if (fin.eof())
			{
				break;
			}
		}
		return false;
		fin.close();

	}
	bool previousRegistered(string x)
	{
		fstream fin;
		fin.open("register.txt", ios::in);
		string str[15];
		while (true)
		{
			for (size_t i = 0; i < 2; i++)
			{
				getline(fin, str[i]);
			}
			if (x == str[0])
			{
				return true;
			}
			if (fin.eof())
			{
				break;
			}
		}
		return false;
		fin.close();

	}
	int chooseVaccinationCenter(int x)
	{
		int sum = 0;
		int inte = 0;
		for (int i = 0; i < x; i++)
		{
			sum += populat.noOfCities[i];
		}
		cout << "\nChoose the prefered vaccination center\n";
		for (int i = 0; i < populat.noOfCities[x]; i++)
		{
			cout << "\nEnter " << sum + i << " For ";
			cout << vaccinationcenterOBJ[sum + i].name << " Vaccination Center." << endl;
		}
		cin >> inte;
		return inte;

	}
	/*void adminsiter() {
		if (eligible == true) {
			if (count == 1) {
				pointer = new citizen[count];
			}
			else {
				fstream object;
				object.open("patientfile.txt", ios::in);
				while (q != '1') {
					delete[]pointer;
					pointer = new citizen[count];
					for (int i = 0; i < count; i++) {
						if (i == count - 1) {
							pointer[count - 1].citizenInput();
						}
						else {
							pointer[i].personinput(object);
						}
					}
					vaccine_count++;
					count++;
					if (vaccine_count == vaccinePerCenter) {
						cout << "\ntoday's vaccine have been used completely:";
						q = '1';
					}
					cout << "\npress 1 to exit or any oter key to add another patient:";
					cin >> q;
				}
			}
		}
	}*/

};
FDO eligibility(FDO ob, citizen& obj)
{
	ob.eligible = obj.check1 && obj.check2;
	return ob;
}
class superAdmin
{

public:

	Doctor* createDoctor(int n)
	{
		Doctor* obj = new Doctor[n];
		return obj;
	}
	companies* createcompanies(int n)
	{
		companies* obj = new companies[n];
		return obj;
	}
	vaccinationCenter* createVaccinationcenter(int n)
	{
		vaccinationCenter* obj = new vaccinationCenter[n];
		return obj;
	}
	admin* createAdmin(int n)
	{
		admin* obj = new admin[n];
		return obj;
	}
	wareHouse* createwareHouse(int n)
	{
		wareHouse* obj = new wareHouse[n];
		return obj;
	}
	Doctor* deleteDoctor(Doctor* arr, int x = 0)
	{
		Doctor* temp;
		int count = 0;
		temp = new Doctor[no_Of_Doctors - 1];
		for (int i = 0; i < no_Of_Doctors; i++) {
			if (i != x)
			{
				temp[count] = arr[i];
				count++;
			}
		}
		delete[]arr;
		return temp;
	}
	admin* deleteAdmin(admin* arr, int x = 0)
	{
		admin* temp;
		int count = 0;
		temp = new admin[no_Of_Admins - 1];
		for (int i = 0; i < no_Of_Admins; i++) {
			if (i != x)
			{
				temp[count] = arr[i];
				count++;
			}
		}
		delete[]arr;
		return temp;
	}
	wareHouse* deleteWarehouses(wareHouse* arr, int x = 0)
	{
		wareHouse* temp;
		int count = 0;
		temp = new wareHouse[no_Of_Warehouses - 1];
		for (int i = 0; i < no_Of_Warehouses; i++) {
			if (i != x)
			{
				temp[count] = arr[i];
				count++;
			}
		}
		delete[]arr;
		return temp;
	}
	vaccinationCenter* deleteVaccinationCenter(vaccinationCenter* arr, int x = 0)
	{
		vaccinationCenter* temp;
		int count = 0;
		temp = new vaccinationCenter[no_Of_VaccineCenters - 1];
		for (int i = 0; i < no_Of_VaccineCenters; i++) {
			if (i != x)
			{
				temp[count] = arr[i];
				count++;
			}
		}
		delete[]arr;
		return temp;
	}
	void Doctor_output(Doctor object) {
		object.Doctor_dataoutput();
	}
	void Admin_output(admin object) {
		object.admin_dataoutput();
	}
	void VaccinationCenter_output(vaccinationCenter object) {
		object.vaccinationCenter_dataoutput();
	}
	void warehouse_output(wareHouse object) {
		object.warehouse_dataoutput();
	}
	void warehouse_update(wareHouse& object) {
		object.warwhouse_dataupdate();
	}
	void admin_update(admin& object) {
		object.admin_infoupdate();
	}
	void vaccination_centreupdate(vaccinationCenter& object) {
		object.vaccinationCenter_update();
	}
	void doctor_update(Doctor& object) {
		object.doctor_infoupdate();
	}
private:
	superAdmin()
	{
		int x = 10;
	}
	friend superAdmin* constructorA();
};
superAdmin* constructorA()
{
	superAdmin* obj = new superAdmin;
	return obj;
}
FDO fdoGbl;
//class governmet_official {//koi sense ha is baat ki? xD
//	int total_population, total_district, total_cities_per_district;
//	float PVP, DVP, amount_spend;
//	int* citywise,*vaccinated;
//	string specific, fully_vaccinated, booster;
//public:
//	void input() {
//		fstream file;
//		file.open("government_official.txt", ios::in);
//		file >> total_population;
//		file >> total_district;
//		file >> total_cities_per_district;
//		citywise = new int[total_cities_per_district];
//		vaccinated = new int[total_cities_per_district * total_district];
//		int count = 0;
//		for (int i = 0; i < total_cities_per_district * total_district; i++) {
//			file >> citywise[i];
//			file >> vaccinated[i];
//		}
//	}
//		float percenatge_of_vacciated_population() {
//			int sum1=0, sum2=0;
//			for (int i = 0; i < total_cities_per_district * total_district; i++) {
//				sum1 += citywise[i];
//				sum2 += vaccinated[i];
//			}
//			PVP = sum1 / static_cast<float>(sum2)*(100);
//			return PVP;
//		}
//		void percenatge_of_District_population() {
//			int sum1 = 0, sum2 = 0,count=0;
//			for (int i = 0; i < total_district; i++) {
//				if (count == total_cities_per_district) {
//					count = 0;
//					cout << (sum1 / static_cast<float>(sum2)*100);
//					sum1 = 0, sum2 = 0;
//				}
//				else {
//					sum1 += citywise[i];
//					sum2 += vaccinated[i];
//				}
//			}
//	}
//		void city_wise_data() {
//			int sum1 = 0, sum2 = 0;
//			for (int i = 0; i < total_district*total_cities_per_district; i++) {
//				sum1 += citywise[i];
//				sum2 += vaccinated[i];
//					cout << "\ntoal people in city " << i + 1 << ":" << sum1;
//					cout << "\ntoal vaccinated in city " << i + 1 << ":" << sum2;
//					sum1 = 0, sum2 = 0;
//		
//			}
//		}
//
//};
class govtOfficial
{
public:
	static int* full;
	static int* partial;
	static int vac1f;
	static int vac2f;
	static int* booster;
	static double percentD;
	static double fullPercent;
public:
	static void percentageOfVaccinatedPeepsPerDistrict()
	{
		cout << "Het";
		
		for (size_t i = 0; i < populat.noOfDistricts; i++)
		{
			cout << "\nFully Vaccinated Population is in district " << populat.districts[i] << " is: ";
			cout << ((long double)full[i]/ (long double)populat.districtPopu[i]) * 100;
			cout << "\nPartially Vaccinated Population is in district " << populat.districts[i] << " is: ";
			cout << ((long double)partial[i]/ (long double)populat.districtPopu[i]) * 100;
			cout << "\nBoosted Vaccinated Population is in district " << populat.districts[i] << " is: ";
			cout << ((long double)booster[i]/ (long double)populat.districtPopu[i]) * 100;
		}
		system("pause");

	}

};
int* govtOfficial::full;
int* govtOfficial::partial;
int govtOfficial::vac2f = 0;
int govtOfficial::vac1f = 0;
int* govtOfficial::booster;
double govtOfficial::percentD = 0;
double govtOfficial::fullPercent = 0;
bool checker()
{
	for (int i = 0; i < 5; i++)
	{
		if (checks[i] == false)
		{
			return false;
		}
		return true;
	}
}
admin* adminOBJ;
wareHouse* warehouseOBJ;
Doctor* doctorOBJ;
companies companiesOBJ;
citizen obj;
int main()
{
	fstream sAdminfile;
	string option;
	string x, y;
	int itg;
	cout << "Welcome for the first time\n";
	distributionP::assignPopulation();
	warehouseOBJ = new wareHouse[(distributionP::noOfWarehouses)];
	vaccinationcenterOBJ = new vaccinationCenter[(distributionP::noOfVaccineCenters)];
	doctorOBJ = new Doctor[((distributionP::noOfVaccineCenters) * 2)];
	system("pause");
	cout << distributionP::noOfWarehouses << "\nwarehouses have been successfully created\n";
	cout << distributionP::noOfVaccineCenters << "\nvaccination centers have been successfully created\n";
	cout << distributionP::noOfVaccineCenters * 2 << "\ndoctors have been assigned to vaccination centers\n";
	govtOfficial::full = new int[populat.noOfDistricts]{};
	govtOfficial::partial = new int[populat.noOfDistricts]{};
	govtOfficial::booster = new int[populat.noOfDistricts]{};
	while (true)
	{
		sAdminfile.open("sAdminfile.txt", ios::in);
		cout << "\nenter SUPERADMIN email\n";
		cin >> x;
		cout << "\nenter 123 password\n";
		cin >> y;
		if (SignIn(sAdminfile, x, y))
		{
			cout << "\nSuccessfully signed in\n";
			sAdminfile.close();
			break;
		}
		else
		{
			cout << "\nInvalid email or password please retry\n";
			sAdminfile.close();
			continue;
		}
	}
	/*cout << "enter:\n1 to Create Admin\n2 to Create Doctor\n3 to Create WareHouse\n4to Create Vaccination Center\n";
	cin >> option;*/
	system("cls");
	cout << "\n\nEnter num of admins to be created: ";
	cin >> itg;
	adminOBJ = supremeAdmin->createAdmin(itg);
	system("pause");

	while (1)
	{
		system("cls");
		cout << "enter:\n1 for super admin\n2 for admin\n3 for citizen\n4 for govt official\n0 to exit\n";
		cin >> option;
		if (option == "4")
		{
			govtOfficial::percentageOfVaccinatedPeepsPerDistrict();
		}
		if (option == "3")
		{
			string option;
			string x, y;
			fstream registe;
			while (1) {
				cout << "enter:\n1 to register\n2 to sign in\n3 to check for eligibility\n4 to check details\n0 to exit\n";
				cin >> option;
				if (option == "1")
				{
					cout << "\nenter email: ";
					cin >> x;
					cout << "\nenter password: ";
					cin >> y;
					if (fdoGbl.previousRegistered(x))
					{
						cout << "\nYou are already registed";
						continue;
					}
					registe.open("register.txt", ios::app);
					registe << x << endl;
					registe << y << endl;
					obj.citizenInput();
					fstream fout;
					fout.open("PatientFile.txt", ios::app);
					cout << "HERE";
					system("pause");
					obj.store_data_in_file(fout);
					Doctor::Doctor_inputer(fout);
					getDistrictIDx(obj.getstate());//usefull
					registe.close();
					fout.close();
				}
				if (option == "2")
				{
					while (true) {
						registe.open("register.txt", ios::in);
						cout << "\nenter email: ";
						cin >> x;
						cout << "\nenter password: ";
						cin >> y;
						if (SignIn(registe, x, y))
						{
							cout << "you have successfully signed in\n";
							obj.citizenInputfromFile(x);
							registe.close();
							break;
						}
						else
						{
							cout << "Error Try Again ^^";
							registe.close();
							continue;
						}

					}
				}
				if (option == "3")
				{
					srand(time(0));
					fstream fout;
					fout.open("VacinatedPeeps.txt", ios::app);
					fdoGbl = eligibility(fdoGbl, obj);
					if (fdoGbl.eligible)
					{
						cout << "\nyou're eligible\n";
						cout << "\nyou'll be referred to the doctor\n";

						if (obj.getAge() < 18)
						{

							vaccinationcenterOBJ[fdoGbl.chooseVaccinationCenter(getDistrictIDx(obj.getstate()))].minusVac1();
							govtOfficial::vac1f++;
							if (fdoGbl.previousFullyVaccinated(obj.email))
							{
								cout << "Your have been vaccinated again\n";
								govtOfficial::booster[getDistrictIDx(obj.getstate())]++;
							}
							else
							{
								fstream fout;
								cout << "it woeks\n";
								system("pause");
								fout.open("Fully vaccinated.txt", ios::app);
								fout << obj.email << endl;
								fout.close();
								fout.open("VacinatedPeeps.txt", ios::app);
								cout << "Your have been vaccinated\n";
								obj.store_data_in_file(fout);
								Doctor::Doctor_inputer(fout);
								fout << 'I' << endl;
								govtOfficial::full[getDistrictIDx(obj.getstate())]++;
								fout.close();
							}

						}
						if (obj.getAge() >= 18)
						{
							govtOfficial::vac2f++;
							vaccinationcenterOBJ[fdoGbl.chooseVaccinationCenter(getDistrictIDx(obj.getstate()))].minusVac2();
							if (fdoGbl.previousPatient(obj.email))
							{
								cout << "Your have been vaccinated again\n";

								if (fdoGbl.previousFullyVaccinated(obj.email))
								{
									govtOfficial::booster[getDistrictIDx(obj.getstate())]++;
								}
								else
								{
									fstream fout;
									fout.open("Fully vaccinated.txt", ios::app);
									fout << obj.email << endl;
									fout.close();
									govtOfficial::full[getDistrictIDx(obj.getstate())]++;
								}
							}
							else
							{
								cout << "Your have been vaccinated\n";
								obj.store_data_in_file(fout);
								Doctor::Doctor_inputer(fout);
								fout << 'L' << endl;;
								govtOfficial::partial[getDistrictIDx(obj.getstate())]++;

							}
						}
					}
					else
					{
						cout << "\nYou're not eligible\n";
					}

					fout.close();
				}
				if (option == "4")
				{
					cout << govtOfficial::vac1f << endl;
					cout << govtOfficial::vac2f << endl;
					for (int i = 0; i < populat.noOfDistricts; i++)
					{
						cout << govtOfficial::full[i] << endl;
						cout << govtOfficial::partial[i] << endl;
						cout << govtOfficial::booster[i] << endl;
					}

					obj.view_citizen_history();
				}
				if (option == "0")
				{
					break;
				}
			}
			continue;
		}
		int xy;
		if (option == "2")
		{
			while (true)
			{
				cout << "enter:\n1 to restock all warehouses and centers\n2to restock indiviually\n0 to exit\n";
				cin >> option;
				if (option == "1")
				{
					while (true)
					{
						cout << "enter:\n1 to equire vaccines from company\n2 to sent vaccines to warehouse\n3 to send vaccines to vaccination centers\n0 to exit\n";
						cin >> option;
						if (option == "1")
						{
							admin::procuringVaccines(companiesOBJ);
							continue;
						}
						if (option == "2")
						{
							for (int i = 0; i < distributionP::noOfWarehouses; i++)
								warehouseOBJ[i].sentToWarehouse();
							continue;
						}
						if (option == "3")
						{
							xy = 0;
							int k;
							k = 0;
							for (size_t i = 0; i < distributionP::noOfWarehouses; i++)
							{
								for (int j = 0; j < noOfVaccineCentersPerDistrict(i); j++)
								{
									vaccinationcenterOBJ[k++].sentToVaccinationCenter(warehouseOBJ[i]);//trust me it works...mostly xD
								}
							}
							continue;
						}
						if (option == "0")
						{
							break;
						}
					}
				}
				if (option == "2")
				{
					while (true)
					{

						cout << "enter:\n1 to equire vaccines from company individually\n2 to sent vaccines to warehouse individually\n3 to send vaccines to vaccination centers individually\n0 to exit\n";
						cin >> option;
						if (option == "1")
						{
							admin::procuringVaccines(companiesOBJ);
						}
						if (option == "2")
						{
							int i;
							cout << "\nEnter the idx of the warehouse: ";
							cin >> i;
							warehouseOBJ[i].sentToWarehouse();
						}
						if (option == "3")
						{
							int k, i;
							cout << "\nEnter the idx of the vaccination center: ";
							cin >> k;
							cout << "Enter the idx of the warehouse: ";
							cin >> i;
							if (vaccinationcenterOBJ[k].canBeUpdateedVac1() || vaccinationcenterOBJ[k].canBeUpdateedVac2())
							{
								vaccinationcenterOBJ[k].sentToVaccinationCenter(warehouseOBJ[i]);//trust me it works (mostly)
							}
							else
							{
								cout << "\nThere is still enough vaccine left";
							}
						}
						if (option == "0")
						{
							break;
						}
					}
				}
				if (option == "0")
				{
					break;
				}

			}
			continue;
		}

		if (option == "1")
		{
			while (!checks[0])
			{
				sAdminfile.open("sAdminfile.txt", ios::in);
				cout << "enter email\n";
				cin >> x;
				cout << "enter password\n";
				cin >> y;
				if (SignIn(sAdminfile, x, y))
				{
					cout << "Successfully signed in\n";
					checks[0] = true;
					sAdminfile.close();
				}
				else
				{
					cout << "Invalid email or password please retry\n";
					sAdminfile.close();
				}
			}
			while (1) {
				cout << "enter:\n1 to Create\n2 to Delete\n3 to Update\n4 to Retrieve\n";
				cin >> option;
				if (option == "1")
				{
					cout << "enter:\n1 to Create Admin\n2 to Create Doctor\n3 to Create WareHouse\n4to Create Vaccination Center\n";
					cin >> option;
					int itg;
					if (option == "1")
					{
						cout << "\nEnter num of admins to be created: ";
						cin >> itg;
						adminOBJ = supremeAdmin->createAdmin(itg);
					}
					if (option == "2")
					{
						cout << "\nEnter num of doctors to be created: ";
						cin >> itg;
						doctorOBJ = supremeAdmin->createDoctor(itg);
					}
					if (option == "3")
					{
						cout << "\nEnter num of Warehouses to be created: ";
						cin >> itg;
						warehouseOBJ = supremeAdmin->createwareHouse(itg);
					}
					if (option == "4")
					{
						cout << "\nEnter num of Vaccination Centers to be created: ";
						cin >> itg;
						vaccinationcenterOBJ = supremeAdmin->createVaccinationcenter(itg);
					}
					continue;
				}
				if (option == "2")
				{
					/*cout << "enter:\n1 to Delete Admin\n2 to Delete Doctor\n3 to Delete WareHouse\n4to Delete Vaccination Center\n";
					cin >> option;
					int itg;
					if (option == "1")
					{
						cout << "\nEnter the Index of admin to be deleted: ";
						cin >> itg;
						supremeAdmin->deleteAdmin(adminOBJ, itg);
					}
					if (option == "2")
					{
						cout << "\nEnter the Index of doctors to be deleted: ";
						cin >> itg;
						supremeAdmin->deleteDoctor(doctorOBJ, itg);
					}
					if (option == "3")
					{
						cout << "\nEnter index of Warehouses to be deleted: ";
						cin >> itg;
						supremeAdmin->deleteWarehouses(warehouseOBJ, itg);
					}
					if (option == "4")
					{
						cout << "\nEnter index of Vaccination Centers to be deleted: ";
						cin >> itg;
						supremeAdmin->deleteVaccinationCenter(vaccinationcenterOBJ, itg);
					}*/
					continue;
				}
				if (option == "3")
				{
					cout << "enter:\n1 to update Admin\n2 to update Doctor\n3 to update WareHouse\n4to update Vaccination Center\n";
					cin >> option;
					int itg;
					if (option == "1")
					{
						cout << "\nEnter the Index of admin to be updated: ";
						cin >> itg;
						supremeAdmin->admin_update(adminOBJ[itg]);
					}
					if (option == "2")
					{
						cout << "\nEnter the Index of doctors to be updated: ";
						cin >> itg;
						supremeAdmin->doctor_update(doctorOBJ[itg]);
					}
					if (option == "3")
					{
						cout << "\nEnter index of Warehouses to be updated: ";
						cin >> itg;
						supremeAdmin->warehouse_update(warehouseOBJ[itg]);
					}
					if (option == "4")
					{
						cout << "\nEnter index of Vaccination Centers to be updated: ";
						cin >> itg;
						supremeAdmin->vaccination_centreupdate(vaccinationcenterOBJ[itg]);
					}
					continue;
				}
				if (option == "4")
				{
					cout << "enter:\n1 to retrieve Admin\n2 to retrieve Doctor\n3 to retrieve WareHouse\n4to retrieve Vaccination Center\n0 to exit\n";
					cin >> option;
					int itg;
					if (option == "1")
					{
						cout << "\nEnter the Index of admin to be retrieved: ";
						cin >> itg;
						supremeAdmin->Admin_output(adminOBJ[itg]);
					}
					if (option == "2")
					{
						cout << "\nEnter the Index of doctors to be retrieved: ";
						cin >> itg;
						/*supremeAdmin->Doctor_output(doctorOBJ[itg]);*/
					}
					if (option == "3")
					{
						cout << "\nEnter index of Warehouses to be retrieved: ";
						cin >> itg;
						supremeAdmin->warehouse_output(warehouseOBJ[itg]);
					}
					if (option == "4")
					{
						cout << "\nEnter index of Vaccination Centers to be retrieved: ";
						cin >> itg;
						supremeAdmin->VaccinationCenter_output(vaccinationcenterOBJ[itg]);
					}
					if (option == "0")
					{
						break;
					}
					continue;
				}
			}
		}
		if (option == "0")
		{
			break;
		}
	}


}



