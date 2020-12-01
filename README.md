# Badescu Madalina 211

Proiectul meu se intituleaza "Gestionarea unei agentii de turism". 
In cadrul acestuia, am 4 clase: Angajat, Client, Destinatie, Oferta. 
Functionalitatea clasei Angajat ma informeaza in legatura cu salariul anual al fiecarui angajat.
Cea de-a doua clasa are functionalitatea de a ma informa despre retul platit de fiecare client, in urma efectuarii unei reduceri.
Clasa Destinatie are ca functionalitate informatia legata de cat costa o saptamana de cazare in fiecare locatie.
Functionalitatea clasei Oferta ma informeaza in legatura cu suma maxima care se poate oferi in cadrul unei reduceri.

In a doua parte a proiectului, am adaugat doua clase derivate ale claselor Destinatie si Oferta.
Derivata clasei Destinatie este Romania, avand atributul nou string judet si metoda noua afisareEroare, care anunta daca destinatia introdusa nu este din Romania.
Derivata clasei Oferta este SarbatoriIarna, avand atributul nou string luna si metoda noua afisareEroare, care anunta daca oferta nu se aplica iarna.
Am creat si o interfata intitulata Buget, cu metodele virtuale Salariu si Profit.
De asemenea, am creat o clasa abstracta Locatii, care are doua clase derivate: Hotel si Apartament.
Clasa Locatii are metoda virtuala pretMin.
Am construit clasa RestaurantHotel, care devine un atribut nou al clasei Hotel, cu relatie de tip HAS-A.
