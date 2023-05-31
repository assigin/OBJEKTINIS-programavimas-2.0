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
		studentas() : suma(0){}
		~studentas() {}
		void setVardas(string vard) { vardas = vard; }
		void setPavarde(string pavard) { pavarde = pavard; }
		void setPazymiai(int paz) { pazymiai.push_back(paz); }
		void clearPazymiai() { pazymiai.clear(); }
		void setEgzaminas(double egz) { egzaminas = egz; }
		void setMed(double medi) { med = medi; }
		void setSuma(int sum) { suma = sum+suma; }
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