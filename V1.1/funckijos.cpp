#include "funcheader.h"


void galutinis(studentas& temp)
{
    temp.setVid(0.6 * temp.getEgzaminas() + 0.4 * ((1.0 * temp.getSuma()) / temp.getPazymiai().size()));
}
void mediana(studentas& temp)
{
    auto pazymiai = temp.getPazymiai();
    sort(pazymiai.begin(), pazymiai.end());
    double vid;
    vid = temp.getPazymiai().size() / 2;

    double mediana;

    if (temp.getPazymiai().size() % 2 == 0) {
        mediana = (temp.getPazymiai()[vid - 1] + temp.getPazymiai()[vid]) / 2.0;
        temp.setMed(mediana);
    }
    else {
        mediana = temp.getPazymiai()[vid];
        temp.setMed(mediana);
    }
    temp.setMed(0.6 * temp.getEgzaminas() + 0.4 * temp.getMed());
}
void ivedimas(studentas& temp)
{
    char kdr;
    int x;
    int a = 1;
    string v, p;
    int laik;
    cout << "Iveskite varda ir pavarde: "; cin >> v >> p;
    temp.setVardas(v);
    temp.setPavarde(p);
    cout << "Jei norite jog sugeneruotu skaicius automatiskai spauskite y, jei ne, tai bet koki kita klavisa" << endl;
    cin >> kdr;
    if (kdr == 'y' || kdr == 'Y')
    {
        cout << "Iveskite kiek norite jog sugeneruotu pazymiu" << endl;
        cin >> x;
        while (a == 1)
        {
            if (x <= 0 || isdigit(x))
            {
                cout << "Iveskite pazymiu kieki is naujo: " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> x;
            }
            else
            {
                random_device rd;
                mt19937 mt(rd());
                uniform_int_distribution<int>dist(1, 10);
                for (int i = 0; i < x; i++)
                {

                    temp.setPazymiai(dist(mt));
                    temp.setSuma(dist(mt));
                }
                break;
            }
        }
    }
    else
    {
        cout << "Iveskite pazymius, o baige juos ivest, iveskite bet kokia raide: ";
        while (cin >> x)
        {
            if (x >= 0 && x <= 10)
            {
                temp.setPazymiai(x);
                temp.setSuma(x);
            }
            else cout << "Rezultatas neatitinka reikalavimu, veskite rezultata intervale nuo 0 iki 10." << endl;
        }
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "Iveskite egzamina: ";
    cin >> laik;
    temp.setEgzaminas(laik);
    if (temp.getEgzaminas() <= 0 || temp.getEgzaminas() >= 10 || isdigit(temp.getEgzaminas())) {
        while (a == 1) {
            if (temp.getEgzaminas() <= 0 || temp.getEgzaminas() > 10 || isdigit(temp.getEgzaminas())) {
                cout << "Iveskite egzamino bala is naujo intervale nuo 1 iki 10: " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> laik;
                temp.setEgzaminas(laik);
            }
            else
                break;
        }
    }
}
void skaitymas_is_failo(string read_vardas, vector<studentas>& mas, studentas& temp)
{
    auto start = std::chrono::high_resolution_clock::now();
    string eil, v, p;
    int sk, x, a;
    ifstream open_f;
    try
    {
        open_f.open(read_vardas);
        if (open_f.fail())throw read_vardas;
    }
    catch (string pav)
    {
        cout << "Nera tokio failo: " << pav << endl;
        cout << "Patikrinkite ar toks failas egzistuoja." << endl;
    }

    getline(open_f, eil);
    sk = count(eil.begin(), eil.end(), 'D');
    int ee = 0;

    while (open_f)
    {
        if (!open_f.eof())
        {
            open_f >> v >> p;
            temp.setVardas(v);
            temp.setPavarde(p);
            for (int i = 0; i < sk; i++)
            {
                open_f >> x;
                temp.setPazymiai(x);
                temp.setSuma(x);//sita pasalint manau reiktu ir perkeltn i funkcijas kuriose bus naudojamas
            }

            open_f >> a;
            temp.setEgzaminas(a);
            galutinis(temp);// labai neefektyvu nes kreipiasi i kitas funkcijas
            mediana(temp);
            mas.push_back(temp);
            temp.clearPazymiai();
            temp.clearSuma();
        }
        else break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas uztruko: " << diff.count() << " s." << endl;
}
void spausdinimas(vector<studentas> mas)
{
    ofstream rf("rezultatai.txt");
    rf << "Vardas" << setw(15) << "Pavarde" << setw(10) << " Galutinis (Vid.) / Galutinis (Med.)" << endl;
    for (auto& i : mas)
    {
        rf << i.getVardas() << setw(15) << i.getPavarde() << setw(15) << setprecision(2) << i.getVid() << setw(10) << setprecision(2) << i.getMed() << endl;
    }
    cout << "Programa baige darba. Patikrinkite rezultatai.txt faila jog pamatytumet juos." << endl;
}
bool rusiavimas(studentas& pirm, studentas& kit)
{
    if (pirm.getVardas() == kit.getVardas())
    {
        return pirm.getVardas() < kit.getVardas();
    }
    else return pirm.getPavarde() < kit.getPavarde();
}
void visiskas_generavimas(studentas& temp, int& x, int& n)
{
    auto start = std::chrono::high_resolution_clock::now();
    int pazymiai, egzaminas;
    ofstream rf("gen_stud.txt");
    rf << "Vardas" << setw(12) << "Pavarde ";
    for (int i = 0; i < x; i++)
    {
        rf << "ND " + to_string(i + 1);
    }
    rf << "Egzaminas" << endl;
    for (int i = 0; i < n; i++)
    {
        string vardas = "Vardas", pavarde = "Pavarde";
        vardas += to_string(i + 1);
        pavarde += to_string(i + 1);
        rf << vardas << setfill(' ') << setw(18) << pavarde << setfill(' ') << setw(18);
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int>dist(1, 10);
        for (int j = 0; j < x; j++)
        {
            pazymiai = (dist(mt));
            rf << " " << pazymiai;
        }
        egzaminas = dist(mt);
        rf << " " << egzaminas << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo generavimas uztruko: " << diff.count() << " s." << endl;
}
bool rusiavimas_2(studentas& pirm, studentas& kit)
{
    if (pirm.getMed() == kit.getMed())
    {
        return pirm.getMed()< kit.getMed();
    }
    else return kit.getMed() < pirm.getMed();
}
bool rusiavimas_3(studentas& pirm, studentas& kit)
{
    if (pirm.getVid() == kit.getVid())
    {
        return pirm.getVid() < kit.getVid();
    }
    else return kit.getVid() < pirm.getVid();
}
void spaus(vector<studentas>& mas, char b, string file_name)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream rf(file_name);
    if (b == 'y' || b == 'Y')//mediana
    {
        rf << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (Med.)" << endl;
        for (auto i : mas)
        {
            rf << i.getVardas() << setw(15) << i.getPavarde() << setw(15) << setprecision(2) << i.getMed() << setw(10) << endl;
        }
    }
    else//vidurkis
    {
        rf << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (Vid.)" << endl;
        for (auto i : mas)
        {
            rf << i.getVardas() << setw(15) << i.getPavarde() << setw(15) << setprecision(2) << i.getVid() << setw(10) << endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo atspausdinimas i failus uztruko: " << diff.count() << " s." << endl;
}
void skirstymas(vector<studentas>& zino, vector<studentas>& nezino, char& b, vector<studentas>& mas)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (b == 'y' || b == 'Y')// skirstymas pagal mediana
    {
        for (auto& i : mas)
        {
            if (i.getMed() >= 5)
            {
                zino.push_back(i);
            }
            else
            {
                nezino.push_back(i);
            }
        }
    }
    else//skirstymas pagal vidurki
    {
        for (auto i : mas)
        {
            if (i.getVid() >= 5)
            {
                zino.push_back(i);
            }
            else
            {
                nezino.push_back(i);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo skirstymas i dvi grupes uztruko: " << diff.count() << " s." << endl;
}