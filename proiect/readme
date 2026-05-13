# Descrierea Generatoarelor de Teste pentru Algoritmi de Sortare

Acest document detaliază seturile de date generate pentru testarea și evaluarea performanței, corectitudinii și robusteții unei game variate de algoritmi de sortare. Testele sunt create pentru două dimensiuni principale:
*   **`SMALL_N`**: 20.000 de elemente
*   **`BIG_N`**: 10.000.000 de elemente

Algoritmii vizați de aceste teste sunt:
*   Heapsort
*   Quicksort
*   Mergesort
*   Introsort
*   Patience Sorting
*   Radix Sort
*   Bubble Sort
*   Insertion Sort
*   Gnome Sort

---

### 1. Vectori Sortați Crescător (`generatorIncreasing`)

*   **Descriere**: Generează un vector cu elemente în ordine strict crescătoare (ex: 1, 2, 3, ..., N).
*   **Scop**: Testează performanța algoritmilor în cazul cel mai favorabil ("best-case") pentru unii și în cazul cel mai nefavorabil ("worst-case") pentru alții.
*   **Impact pe Algoritmi**:
    *   **Best-case (complexitate O(n))**: Pentru `Bubble Sort` (cu optimizare), `Insertion Sort` și `Gnome Sort`, acest test reprezintă scenariul ideal.
    *   **Worst-case (complexitate O(n²))**: Pentru o implementare naivă de `Quicksort` (care alege mereu primul/ultimul element ca pivot), acest set de date duce la degradarea maximă a performanței.
    *   **Performanță Standard (O(n log n))**: `Heapsort`, `Mergesort` și `Introsort` vor avea performanța lor standard, nefiind influențați semnificativ.

---

### 2. Vectori Sortați Descrescător (`generatorDecreasing`)

*   **Descriere**: Generează un vector cu elemente în ordine strict descrescătoare (ex: N, N-1, ..., 1).
*   **Scop**: Reprezintă scenariul "worst-case" pentru mulți algoritmi de sortare simpli și pentru implementări naive de Quicksort.
*   **Impact pe Algoritmi**:
    *   **Worst-case (complexitate O(n²))**: Acesta este cel mai rău scenariu pentru `Bubble Sort`, `Insertion Sort`, `Gnome Sort` și `Quicksort`-ul naiv, forțându-i să execute numărul maxim de comparații și interschimbări.
    *   **Performanță Standard (O(n log n))**: `Heapsort`, `Mergesort` și `Introsort` nu sunt afectate și își mențin complexitatea specifică.

---

### 3. Vectori cu Elemente Aleatorii (`generatorRandom`)

Acest generator creează mai multe tipuri de teste pentru a simula diverse scenarii realiste.

*   #### 3.1. Distribuție Uniformă Largă (`generatorRandom(N, N)` și `generatorRandom(N, BIG_N)`)
    *   **Descriere**: Generează numere aleatorii într-un interval larg, rezultând puține duplicate.
    *   **Scop**: Simulează cazul mediu ("average-case") pentru toți algoritmii de sortare. Acesta este cel mai comun scenariu de utilizare.
    *   **Impact**: Toți algoritmii ar trebui să ruleze cu complexitatea lor medie. `Quicksort` și `Introsort` sunt de obicei cei mai rapizi în acest scenariu.

*   #### 3.2. Distribuție Uniformă Îngustă (Multe Duplicate) (`generatorRandom(N, 20)` și `generatorRandom(N, 1000)`)
    *   **Descriere**: Generează numere aleatorii într-un interval restrâns, ceea ce duce la apariția unui număr mare de elemente duplicate.
    *   **Scop**: Testează eficiența algoritmilor în gestionarea seturilor de date cu o diversitate redusă de valori.
    *   **Impact**: Performanța `Quicksort` poate degrada dacă partiționarea nu gestionează eficient duplicatele. Implementările cu partiționare pe 3 căi (3-way partitioning) sunt ideale aici. `Radix Sort` este foarte eficient dacă intervalul valorilor (și deci numărul de biți) este mic.

*   #### 3.3. Toate Elementele Identice (`generatorRandom(N, 1)`)
    *   **Descriere**: Toate elementele din vector au aceeași valoare.
    *   **Scop**: Un caz extrem pentru a verifica corectitudinea și stabilitatea algoritmilor.
    *   **Impact**: Similar cu vectorii sortați pentru `Bubble Sort` și `Insertion Sort`. O implementare `Quicksort` naivă poate intra în complexitate O(n²), dar o implementare bună va rula în O(n).

---

### 4. Vectori Aproape Sortați (`generatorIncreasingDecreasing`)

*   **Descriere**: Se pornește de la un vector sortat (crescător sau descrescător) și se efectuează un număr fix de interschimbări aleatorii (`swap`).
*   **Scop**: Simulează seturi de date din lumea reală care sunt "aproape sortate", cum ar fi o listă la care se adaugă câteva elemente noi.
*   **Impact pe Algoritmi**:
    *   **Performanță Excelentă (aproape O(n))**: Algoritmii adaptivi precum `Insertion Sort`, `Bubble Sort` și `Gnome Sort` excelează pe aceste date, deoarece necesită foarte puține operații pentru a restabili ordinea.
    *   **Performanță Standard**: `Heapsort`, `Mergesort`, `Quicksort` și `Introsort` nu beneficiază în mod special de ordinea parțială și vor rula cu complexitatea lor medie, O(n log n).

---

### 5. Test de Predicție de Ramură (`generatorBranchPrediciton`)

*   **Descriere**: Generează un vector cu o secvență foarte predictibilă și repetitivă de valori (0, 99, 192, 0, 99, 192, ...).
*   **Scop**: Testează impactul arhitecturii procesorului (specific, unitatea de predicție a ramurilor - branch prediction) asupra performanței algoritmilor bazați pe comparații.
*   **Impact**: În algoritmi precum `Quicksort` sau `Insertion Sort`, comparațiile `if (element1 < element2)` vor urma un model predictibil. Un procesor modern poate "învăța" acest model și poate executa codul speculativ mult mai rapid, ducând la o performanță neașteptat de bună.

---

### 6. Test Specific pentru Radix Sort (`generatorRADIX`)

*   **Descriere**: Generează numere mari, construite ca string-uri, majoritatea având un prefix comun ("1").
*   **Scop**: Creează un scenariu ideal pentru `Radix Sort` și unul potențial lent pentru algoritmii bazați pe comparații.
*   **Impact pe Algoritmi**:
    *   **`Radix Sort`**: Va fi extrem de eficient, deoarece poate procesa numerele pe "bucăți" (digiți sau grupuri de biți), iar prefixul comun este gestionat rapid.
    *   **Algoritmi bazați pe comparații**: Aceștia trebuie să compare numerele mari în întregime, ceea ce poate fi mai lent. Testul este conceput pentru a evidenția superioritatea `Radix Sort` în contexte favorabile acestuia.
