## Descriere
Acest proiect implementează un sistem automatizat de urmărire a soarelui pentru un panou fotovoltaic, folosind **Arduino Uno**, senzori de lumină și două servomotoare (180° și 360°). Scopul este optimizarea orientării panoului în funcție de poziția soarelui pentru a crește eficiența energetică.

Sistemul citește intensitatea luminii din patru direcții diferite și ajustează unghiul panoului pe două axe, asigurând orientarea optimă pe tot parcursul zilei.

---

## Obiective
- Creșterea eficienței captării energiei solare prin orientare automată.
- Utilizarea a patru senzori de lumină pentru determinarea direcției optime.
- Controlul mișcării panoului cu două servomotoare:
  - **Servo 180°** pentru înclinarea verticală.
  - **Servo 360°** pentru rotația orizontală.
- Alimentare independentă printr-o baterie de 9V și stabilizator de tensiune.

---

## Funcționalități
- Măsurarea intensității luminii din patru direcții.
- Calcularea diferenței dintre senzori pentru determinarea direcției de mișcare.
- Ajustare automată a poziției panoului la fiecare 50 ms.
- Rotație controlată cu semnal PWM:
  - **90** → motorul stă pe loc.
  - Sub/Peste **90** → rotație în sens trigonometric sau ceasornic, cu viteză variabilă.
- Aprinderea unui LED când panoul primește suficientă lumină.

---

## Componente utilizate
- Arduino Uno
- 4 senzori de lumină
- Servo motor 180°
- Servo motor 360°
- Breadboard
- Mini panou fotovoltaic
- Fire tată-tată și mamă-tată
- LED + rezistență 1kΩ
- Display LCD
- Baterie 9V
- Stabilizator de tensiune
- Piese imprimate 3D pentru susținerea structurii

---

## Implementare hardware
- **Servo 180°**: ajustează înălțimea panoului în funcție de diferența dintre perechile de senzori.
- **Servo 360°**: rotește panoul pe orizontală pentru alinierea cu sursa de lumină.
- Alimentarea servomotoarelor este realizată printr-o sursă stabilizată la 5V pentru a preveni suprasolicitarea Arduino.

---

## Testare
- Prima versiune a fost realizată pe un prototip din polistiren, dar a prezentat probleme mecanice.
- Versiunea finală utilizează o structură imprimată 3D, mai stabilă.
- Sistemul a fost testat cu surse de lumină simulate (lanternă de telefon) și a răspuns corect la schimbările de iluminare.
- Reglajele fine au inclus fixarea mai bună a firelor și ajustarea pragurilor de declanșare în cod.

---

## Contribuții
- **Luntraru Maria-Alexandra** – programare, dezvoltare logică control servomotoare.
- **Sultzer Roxana-Maria** – proiectare piese și adaptarea dimensiunilor.
- **Tudor Mihaela** – conexiuni electrice și testare hardware.
- **Echipa** – selecție componente, optimizare structură, asamblare finală și testare.

---


##  Video demonstrație:
https://youtube.com/shorts/CvyycAO1Vh0?feature=share
