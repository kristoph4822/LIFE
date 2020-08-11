# Conway's Game of Life
### Działanie
Program przyjmuje od użytkownika konfigurację początkową żywych komórek. Następnie możemy przeprowadzić zadaną liczbę generacji. Program tworzy pliki PNG, które wizualizują poszczególne generacje.

Przykładowe 3 pliki wygenerowane przez program, obrazujące kolejne generacje:

![genA](https://user-images.githubusercontent.com/46055596/89939921-05ee0700-dc19-11ea-8f36-6000d9ea8045.png)
![genB](https://user-images.githubusercontent.com/46055596/89939925-07b7ca80-dc19-11ea-9995-0a04f8a73c53.png)
![genC](https://user-images.githubusercontent.com/46055596/89939931-08e8f780-dc19-11ea-9587-e4f784f9fc4a.png)

Dokładne działanie i funkcjonalność programu wyjaśniona jest w specyfikacjach.

### Parametry wywołania programu
* -f FILE - plik wejściowy ze współrzędnymi komórek pierwszej generacji;
* -w width - szerokość planszy;
* -h height - wysokość planszy;
* -n generations - liczba przeprowadzonych generacji;
* -o OFILE - plik tekstowy do którego zapiszemy ostatnią generację w postaci współrzędnych punktów;
* -p pics - liczba wygenerowanych plików PNG z przedstawieniem danej generacji, domyślnie 2(pierwsza i ostatnia generacja).
