#pragma once
#pragma once
#include "lib.h"

class studentas
{
private:
	string vardas, pavarde;
	vector<int> pazymiai;
	int egzaminas;
	double vid;
	double med;
	int suma;

public:
	studentas(const std::string& v = "vardas", const std::string& p = "pavarde")
		: vardas(v), pavarde(p), suma(0) {}
	~studentas() {}

	studentas(const studentas& stud)
	{
		cout << "copy konstruktorius" << endl;
		vardas = stud.vardas;
		pavarde = stud.pavarde;
		pazymiai = stud.pazymiai;
		egzaminas = stud.egzaminas;
		vid = stud.vid;
		med = stud.med;
		suma = stud.suma;
	}

	studentas(const studentas&& stud) noexcept
	{
		cout << "move konstruktorius" << endl;
		vardas = stud.vardas;
		pavarde = stud.pavarde;
		pazymiai = move(stud.pazymiai);
		egzaminas = stud.egzaminas;
		vid = stud.vid;
		med = stud.med;
		suma = stud.suma;
		stud.~studentas();
	}
	studentas& operator=(studentas& stud_2)
	{
		cout << "copy darbas" << endl;
		if (this != &stud_2)
		{
			vardas = stud_2.vardas;
			pavarde = stud_2.pavarde;
			pazymiai = stud_2.pazymiai;
			egzaminas = stud_2.egzaminas;
			vid = stud_2.vid;
			med = stud_2.med;
			suma = stud_2.suma;
		}
		return *this;
	}
	studentas& operator=(studentas&& stud_2) noexcept
	{
		cout << "move darbas" << endl;
		if (this != &stud_2)
		{
			vardas = move(stud_2.vardas);
			pavarde = move(stud_2.pavarde);
			pazymiai = move(stud_2.pazymiai);
			egzaminas = move(stud_2.egzaminas);
			vid = move(stud_2.vid);
			med = move(stud_2.med);
			suma = move(stud_2.suma);
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const studentas& stud) {
		os << "Vardas: " << stud.vardas << std::endl;
		os << "Pavarde: " << stud.pavarde << std::endl;
		// Output other member variables as needed
		return os;
	}
	friend istream& operator>>(istream& input, studentas& studentas) {
		input >> studentas.vardas >> studentas.pavarde >> studentas.egzaminas;
		return input;
	}

	void setVardas(string vard) { vardas = vard; }
	void setPavarde(string pavard) { pavarde = pavard; }
	void setPazymiai(int paz) { pazymiai.push_back(paz); }
	void clearPazymiai() { pazymiai.clear(); }
	void setEgzaminas(double egz) { egzaminas = egz; }
	void setMed(double medi) { med = medi; }
	void setSuma(int sum) { suma = sum + suma; }
	void clearSuma() { suma = 0; }
	void setVid(double vidu) { vid = vidu; }

	string getVardas() { return vardas; }
	string getPavarde() { return pavarde; }
	vector<int> getPazymiai() { return pazymiai; }
	double getEgzaminas() { return egzaminas; }
	double getMed() { return med; }
	int getSuma() { return suma; }
	double getVid() { return vid; }
};

void ivedimas(studentas& temp);
void galutinis(studentas& temp);
void mediana(studentas& temp);
void skaitymas_is_failo(string read_vardas, vector<studentas>& mas, studentas& temp);
void spausdinimas(vector<studentas> mas);
bool rusiavimas(studentas& pirm, studentas& kit);
void visiskas_generavimas(studentas& temp, int& x, int& n);
bool rusiavimas_2(studentas& pirm, studentas& kit);
bool rusiavimas_3(studentas& pirm, studentas& kit);
void spaus(vector<studentas>& mas, char b, string file_name);
void skirstymas(vector<studentas>& zino, vector<studentas>& nezino, char& b, vector<studentas>& mas);