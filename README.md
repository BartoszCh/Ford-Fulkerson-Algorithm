### Projekt zaliczeniowy z Teorii Grafów - Informatyka i Systemy Inteligentne 2021

## Część analityczna
Część analityczną projektu umieściłem w tym repozytorium, w pliku "część analityczna.pdf". Tam znajdują się wszystkie komentarze co do znalezionych przeze mnie rozwiązań.

## Część programistyczna
Algorytm Forda Fulkersona szukający maksymalnego przepływu danych w grafie skierowanym.
Projekt wykonałem w języku C++. Algorytm napisałem stosując metodę Edmondsa-Karpa. Testowałem go na kilku grafach umieszczonych w sprawdzonych miejscach (np. graf z https://pl.wikipedia.org/wiki/Algorytm_Edmondsa-Karpa) i w każdym przypadku program zwraca poprawny wynik.

# Instrukcja obsługi
Graf, którego przepływ chcemy zbadać, należy umieścić w pliku "graf.txt". Musi on być przedstawiony za pomocą macierzy krawędzi. Macierz ta ma liczbę rzędów równą liczbie
krawędzi w grafie oraz trzy kolumny, kolejno określające wierzchołek początkowy krawędzi, wierzchołek końcowy krawędzi oraz wagę. Wierzchołki należy numerować kolejnymi liczbami naturalnymi zaczynając od 0, waga każdej krawędzi musi być również liczbą naturalną. Każdy kolejny wiersz macierzy powinien być umieszczony w nawiasach kwadratowych, a poszczególne wartości w wierszu oddzielone przecinkami. Na przykład, dla grafu składającego się z trzech wierzchołków 0 1 i 2, z krawędziami poprowadzonymi od 0 do 1, od 0 do 2 i od 1 do 2, gdzie każda krawędź ma wagę 2, taka macierz będzie wyglądać następująco:
[[0, 1, 2]
[0, 2, 2]
[1, 2, 2]
]
Po wpisaniu grafu do pliku program potwierdzi czy został on prawidłowo wczytany wyswietlając naszą macierz, następnie zapyta nas o to z którego do którego wierzchołka przepływ
chcemy zbadać. Po wykonaniu algorytmu, program wyświetli liczbę będącą maksymalnym przepływem między podanymi wierzchołkami.

# Analiza algorytmu
Algorytm ten rozwiązuje problemy związane z maksymalnym przepływem danych. Oczywiście dane te mogą mieć przeróżną postać, tak samo jak graf sam w sobie. Najbardziej znanym i powszechnym przykładem zastosowania takiego algorytmu jest sieć rur służąca do przepływu wody. W tym wypadku jako krawędzie oznaczamy poszczególne rury w sieci kanalizacyjnej, gdzie każda z nich ma określoną pojemność (wagę krawędzi). 
Oczywiście nie chcemy żeby któraś rura się przepełniła, ale również chcemy aby między punktem startowym a końcowym przepłynęło jak najwięcej wody. W tym wypadku możemy zastosować algorytm, który obliczy nam jaka jest maksymalna ilość płynu którą możemy w taki sposób przesłać. Bardziej zaawansowane programy pokierują nas również ile dokładnie wody należy przelać przez którą rurę i w jakiej kolejności, aby wynik był maksymalny. 
Oczywiście nie jest to jedyny przykład użycia tego algorytmu. Algorytm ten może być stosowany również np przez firmy kurierskie. Liczba danych w tym wypadku to ładowność przesyłek które mamy przesłać, wierzchołki symbolizują miasta, a krawędzie i ich wagi odpowiedznio połączenia między miastami oraz ładowność naszego transportu wiozącego przesyłki. W tym wypadku algorytm Forda Fulkersona pomoże znaleźć nam sposób, aby przesłać jak najwięcej przesyłek z jednego miasta do drugiego, oraz podpowie nam którymi połączeniami powinny one jechać. 
Jak widać, jest to algorytm który może być wykorzystywany na bardzo wiele sposobów i jest przydatny dla wielu firm i rodzajów branży, które ułatwiają nam życie codzienne.

# Bibliografia
Przy pisaniu projektu posiłkowałem się polskimi oraz angielskimi artykułami na Wikipedii, oraz artykułem z Georgia University:
https://digitalcommons.georgiasouthern.edu/cgi/viewcontent.cgi?article=2720&context=etd
