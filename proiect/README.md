# Descrierea Testelor Generate

Codul generează fișiere de intrare pentru a testa performanța următorilor algoritmi de sortare în diverse scenarii:

*   Heapsort
*   Quicksort
*   Mergesort
*   Introsort
*   Patience Sorting
*   Radix Sort
*   Bubble Sort
*   Insertion Sort
*   Gnome Sort

Testele sunt generate pentru **20.000 (`SMALL_N`)** și **10.000.000 (`BIG_N`)** de elemente.

---

### 1. Vector Sortat Crescător (`generatorIncreasing`)
*   **Ce face**: Generează `1, 2, 3, ..., N`.
*   **Scop**: Cazul ideal pentru `Bubble Sort` și `Insertion Sort` (timp O(n)). Cazul cel mai rău pentru un `Quicksort` naiv (timp O(n²)).

### 2. Vector Sortat Descrescător (`generatorDecreasing`)
*   **Ce face**: Generează `N, N-1, ..., 1`.
*   **Scop**: Cazul cel mai rău pentru `Bubble Sort`, `Insertion Sort`, `Gnome Sort` și `Quicksort`-ul naiv.

### 3. Vectori Aleatorii (`generatorRandom`)

*   **3.1. Numere aleatorii, puține duplicate**:
    *   **Ce face**: Numere la întâmplare dintr-un interval foarte larg.
    *   **Scop**: Simulează cazul mediu, cel mai întâlnit în practică. Măsoară performanța generală.

*   **3.2. Numere aleatorii, multe duplicate**:
    *   **Ce face**: Numere la întâmplare dintr-un interval mic (ex: 1-20).
    *   **Scop**: Testează cum se descurcă algoritmii când setul de date are puține valori unice. `Quicksort` poate fi lent dacă nu e implementat cu partiționare pe 3 căi.

*   **3.3. Toate elementele identice**:
    *   **Ce face**: Toate elementele din vector sunt la fel.
    *   **Scop**: Un caz extrem pentru a verifica corectitudinea și a stresa implementările naive de `Quicksort`.

### 4. Vector Aproape Sortat (`generatorIncreasingDecreasing`)
*   **Ce face**: Pornește de la un vector sortat și face câteva interschimbări (`swap`) la întâmplare.
*   **Scop**: Simulează date aproape ordonate. `Insertion Sort` și `Gnome Sort` ar trebui să fie extrem de rapide aici.

### 5. Test pentru Predicția de Ramură (`generatorBranchPrediciton`)
*   **Ce face**: Generează secvența repetitivă `0, 99, 192, 0, 99, 192, ...`.
*   **Scop**: Verifică dacă optimizările procesorului (branch prediction) influențează viteza. Comparațiile din `if`-uri devin predictibile, ceea ce poate accelera execuția.

### 6. Test Specific pentru Radix Sort (`generatorRADIX`)
*   **Ce face**: Generează numere foarte mari, majoritatea având același prefix.
*   **Scop**: Un scenariu construit special pentru a favoriza `Radix Sort`, care procesează numerele pe bucăți (digiți) și este foarte eficient în acest caz.
