# Compito vacanze di Natale
Il compito è suddiviso in tre parti. Forkare il progetto, creando il proprio personale.




# Parte 1 (comune a tutti)
Scrivere un programma per la **generazione casuale di una targa** (es. ZT459QA).
Il primo, secondo, sesto e settimo charattere sono sempre **char** in formato **minuscolo**.
Il terzo, quarto e quinto carattere sono sempre **numeri** da 1 a 9.

### Regole per la generazione di ogni elemento della targa
- **Elemento 1**: A partire da una stringa costante definita globalmente, lunga almeno 10 lettere, viene presa dalla quarta posizione della parola costante. la lettera deve essere una consonante. nel caso in cui sia una vocale gestire la casistica (prendere valore successivo, precedente, altro)

- **Elemento 2**: viene generato un numero casuale e trasformato in lettera mediante codice ascii corrispondente (maiuscolo) . Utilizzare funzione chr(num_generato).
La lettera deve essere una consonante. nel caso in cui sia una vocale gestire la casistica (prendere valore successivo, precedente o altro). Se il valore estratto corrisponde alla lettera precedente rigenerarlo.

- **Elementi 3,4,5**: numeri generati random mediante funzione apposita

- **Elementi 6,7**:viene generato un numero casuale, sempre e solo dispari. Il nnumero viene poi trasformato in lettera mediante codice ascii corrispondente (maiuscolo).  Le due lettere possono essere uguali. 


**Vincoli**: 
- Utilizzare il metodo di concatenazione `concat()` per costruire la targa quindi no "+".
- Definire **funzioni** al fine di riutilizzare il codice (anche in previsione delle parti successive)


# Parte 2 (specifica su 2 gruppi)
La seconda parte dell'esercizio prevede l'implementazione di 3 funzioni e di un menù utente che permetta di chiamare le 3 funzioni. 
Le 3 funzioni da implementare dipendono dal gruppo assegnato in classe Giovedi 18 Dicembre. 
L'implementazione del menù utente è invece comune a tutti.

**Gruppo destra**
- (1) La funzione prende in input una targa e ne restituisce una nuova, sostituendo dalla targa in input la seconda e la penultima lettera con il simbolo “%”.

- (3) La funzione prende in input una targa e ne restituisce una nuova invertita. Utilizzare obbligatoriamente il metodo `substring()`.

- (5) La funzione prende in input una targa e un char e restituisce la presenza o meno del char passato in input all'interno della stringa. Utilizzare obbligatoriamente il metodo `find()`.


**Gruppo sinistra**
- (2) La funzione prende in input una targa e ne restituisce una nuova, uguale alla precedente con il char 'X' dove prima erano invece presenti i numeri.

- (4) La funzione prende in input una targa e ne restituisce una nuova invertita. Utilizzare obbligatoriamente il metodo `at()`.

- (5) La funzione prende in input una targa e un intero e restituisce la presenza o meno del numero passato in input all'interno della stringa. Utilizzare obbligatoriamente il metodo `find()`.


## Comportamento finale atteso del programma
Il programma, quando eseguito, deve inizialmente stampare la targa generata casualmente e successivamente mostrare il menu, rimanendo in attesa di una scelta da parte dell’utente. L’utente può scegliere uno tra i tre comportamenti possibili (dipendono dal gruppo) e, successivamente alla sua scelta, verrà eseguita la funzione corrispondente e il programma mostrerà il risultato. 
Il programma si mette poi in attesa di una nuova scelta da parte dell'utente. 
N.B. La targa generata inizialmente, non viene mai modificata dai punti specifici del menu, quindi chiamando tante volte la stessa funzione, si ha tutte le volte lo stesso risultato. 

# Parte 3 - Creazione classe Targa (comune a tutti)
Creare una classe chiamata `TargaCasuale` in modo da gestire in maniera più chiara e controllata tutto quello definito sopra (in un nuovo file). 

### Attributi (stato) e metodi (comportamento) della classe
La classe ha come **stato** (attributi):
- il valore della stringa targa
  
La classe ha come **comportamenti** (metodi): 
- generazione casuale della targa (secondo la parte comune). Nome `generaTarga()`
- Funzione 1/2 (secondo la parte specifica, dipendente dal gruppo). Nome: parlante rispetto al comportamento della funzione
- Funzione 3/4 (secondo la parte specifica, dipendente dal gruppo). Nome: parlante rispetto al comportamento della funzione
- Funzione 5/6 (secondo la parte specifica, dipendente dal gruppo). Nome: parlante rispetto al comportamento della funzione

## Comportamento finale atteso dalla classe
Ci si attende che un nuovo oggetto di tipo targa possa essere creato così:  

```cpp
TargaCasuale t`

```
valorizzato con

```cpp
t.generaTarga(); //valorizza lo stato dell'oggetto con una targa generata casualmente (secondo quanto definito nella parte 1)
```
e utilizzato con 
```cpp
t.targa; // valore di targa
t.sostituisciPerc(); // ritorna nuova stringa con seconda e penultima lettera con il simbolo “%” (funzione 1 del gruppo di destra, il nome è un esempio)
//tutte le altre funzioni
```

#### Punti di attenzione
Nella seconda parte si definiscono tre funzioni che prendono in input una targa, nel momento in cui le stesse funzioni vengono implementate all'interno della classe, non sarà necessario mantenere quell'input, in quanto la stringa è già contenuta all'interno dello stato dell'oggetto. 
