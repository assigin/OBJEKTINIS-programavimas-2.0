# OBJEKTINIS-programavimas-2.0
# OBJEKTINIS programavimas
## V0.1

- Programa, kuri paskaičiuoja studento galutinį įvertinimą su mediana ir vidurkiu. (Pagal formulę)
- Pasirenkama, ar vartotojas įveda pažymius, ar juos atsitiktinai sugeneruoja.

## V0.2

- Pridėtas studento duomenų skaitymas iš failo.

## V0.3

- išskirstyta funkcijos ir struktūros į kitus failus.
- Įdėtas išimčių valdymas, jei būtų bandoma skaityti duomenis iš failo, kurio nėra.

## V0.4

- Programa gali sugeneruoti visus duomenis.
- Surūšiuoja studentus į du failus pagal galutinį balą.
- Surūšiuoja studentus failuose pagal vidurkį.
- matuojamas programos veikimo greitis.

| Failo generavimo lentelė||||||
|-------------------------|-----|-----|-----|-----|-----|
|laikas(s)|0,043|0,34|3,5|34,2|334,9|
|dydis| 1000 |10000|100000|1000000|10000000|

|Funkcijų atlikimo greičio lentelė||||||
|-------------------------|-----|-----|-----|-----|-----|
|dydis| 1000 |10000|100000|1000000|10000000|
|Nuskaitymas (s)|0,042|0,47|0,64|29|228|
|Rūšiavimas(s)|0,0067|0,05|0,69|6,9|65|
|Skirstymas(s)|0,0046|0,059|0,52|5,5|70|
|Išlaikiusiu vedimas į failą (s)|0,1|0,09|0,95|9,3|90|
|Neišlaikiusiu vedimas į failą (s)|0,063|0,06|0,66|6,2|62|
|Visas programos veikimo laikas be failo generavimo (s)|0,216|0.729|3,46|61.8|515|

## V0.5

- Matuojamas konteinerių greitis (vector, deque, list) prikklausantis nuo failų dydžių.

Kompiuterio parametrai
- CPU i3-9100F
- RAM 16GB
- SSD 256GB
- HDD 1TB

Vector

|Funkcijų atlikimo greičio lentelė||||||
|-------------------------|-----|-----|-----|-----|-----|
|dydis| 1000 |10000|100000|1000000|10000000|
|Nuskaitymas|0,042|0,47|0,64|29|228|
|Rūšiavimas(s)|0,0067|0,05|0,69|6,9|65|
|Skirstymas(s)|0,0046|0,059|0,52|5,5|70|
|Visų funkcijų veikimo laikas (s)|0,0533|0,579|1,85|41,4|363|

Deque

|Funkcijų atlikimo greičio lentelė||||||
|-------------------------|-----|-----|-----|-----|-----|
|dydis| 1000 |10000|100000|1000000|10000000|
|Nuskaitymas (s)|0,025|0,6|8,3|35|250|
|Rūšiavimas(s)|0,0075|0,06|0,83|7,4|80|
|Skirstymas(s)|0,003|0,055|0,67|4,2|60|
|Visų funkcijų veikimo laikas (s)|0,0355|1,21|9,8|46,6|390|

List

|Funkcijų atlikimo greičio lentelė||||||
|-------------------------|-----|-----|-----|-----|-----|
|dydis| 1000 |10000|100000|1000000|10000000|
|Nuskaitymas|0,023|0,54|6,9|30|235|
|Rūšiavimas(s)|0,0002|0,0027|0,049|0,77|11|
|Skirstymas(s)|0,0032|0,06|0,74|4|90|
|Visų funkcijų veikimo laikas (s)|0,0264|0.6027|7,689|34,77|336|

## V1.0

- Padarytos dvi strategijos vector, deque, list konteineriams.
- 1 strategija - studentai skirstomi į du naujus konteinerius
 Greitis abiejomis strategijomis buvo matuojamas su 100000 studentų įrašų.
 
|Skirstymo greičio lentelė||
|-------------------------|-----|
|vector| 0,52|
|deque| 0,51| 
|list| 0,74|

- 2 strategija - studentai skirstomi į vieną naują konteinerį ir atnaujinamas pradinis studentų konteineris

|Skirstymo greičio lentelė||
|-------------------------|-----|
|vector| 0,26|
|deque| 0,67|
|list| 0,34|

## V1.1
- Iš struktūros pereinama į klasę.

|skirstymo greičio lyginimas|||
|-------------------------|-----|-----|
|dydis|100000|1000000|
|struktūra strategija 2|0,26|2,7|
|Klasė|0,56|6,5|

## V1.2
- Padaryta "Rule of Five" (copy constructor, move constructor, copy assignment, move assignment).
## V1.5
- Sukurta bazinė klasė žmogus iš  kurios išvesta klasė studentas.

## Vector klasė
