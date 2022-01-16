# 🎒 KnapsackProblem

Knapsack problem solution project for PJC.


<h2> 📚 Popis: </h2>

Projekt je řešením klasického problému s batohem, ve kterém každź item má 2 parametry – cenu a váhu a batoh má omezenou kapacitu.
Úkolem je najít optimální řešení, při kterém předměty s maximální hodnotou zůstanou v batohu, s přihlédnutím ke kapacitě aktovky. 

<h2> 📚 Implementace: </h2>

<p>Tento program řeší problém pomocí metody dynamického programování.</p>
Řešení je připraveno pouze pro variantu úlohy 0-1, což znamená, že každá položka se může do portfolia dostat pouze 1x nebo vůbec. <br>
Podstatou řešení je sestavení dvourozměrného pole (tabulky), které zohledňuje počet položek a kapacitu batohu, díky čemuž máme pomocí cyklů možnost rozdělit úkol na menší dílčí úkoly a vypočítat různé konfigurace pro batohy o velikostech od 1 do N. <br>
Poté, co věci hodnotíme podle jejich hodnoty, určíme, která věc je pro dané místo v buňce nejlepší.<br>
Po vyplnění tabulky bude naše odpověď v úplně poslední buňce tabulky. 

<h2>📚 Funkce: </h2>

 - --help = Vypiše všechny možné příkazy, které je možné použit v programu.
 - --run = Spuštění programu pomocí konfigurací ve formátu json. Je povoleno používat jak předpřipravené programy, tak své vlastní, umístěné před tím ve složce projektu. 
 - --solve = Spuštění programu pomocí zadaní proměnných, včetně počtu objektů, jejich názvu, ceny, hmotnosti a kapacity batohu. 
 - --tests = Spuštění připravených testů pro různé případy toku programu. 

 <h2>📚 Input format: </h2>

V případě --solution (příklad):


`3                 = počet itemů`<br>
`Necklace 4 4000   = 1.item (název, vaha, cena)`<br>
`Ring 1 2500       = 2.item (název, vaha, cena)`<br>
`Pendent 3 2000    = 3.item (název, vaha, cena)`<br>
`4                 = knapsack size`

 <h2>📚 Měření: </h2>

 Program používá 1 vlákno. <br>
 Bohužel se mi nepodařilo rozdělit dvourozměrné pole do více vláken, ale v jiných typech implementace je to docela možné. <br>
 Měření byla provedena na: Intel(R) Core(TM) i7-9750H CPU @ 2.60GHz 2.59 GHz 6 Core(s), 12 threads. CLion.

| items count | knapsack size |result(ms)|
| ------ | ------ |-------|
| 10   | 10   |   0    |
| 100   | 1000   |    3   |
| 250   | 10000   |    9   |

  <h2>🎒 Knihovny: </h2>

  V projectu byli použity knihovny (ve složce /lib):<br>
  - jsoncpp = pro čtení configurace batohu a itemu ve formatu json, <br>
  - googletest = pro testovací metody ve složce /Tests - jsou tam unit testy pro různé případy toku programu. 

