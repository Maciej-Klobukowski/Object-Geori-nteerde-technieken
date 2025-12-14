
## Object-Geori-nteerde-technieken

#Functionele beschrijving

Het project simuleert een eenvoudig tekenprogramma waarin verschillende vormen (zoals cirkels en rechthoeken) worden beheerd en “getekend”. Elke vorm heeft zijn eigen eigenschappen en gedrag, maar wordt via een gemeenschappelijke interface aangesproken. Hierdoor kan het programma flexibel omgaan met verschillende objecttypes.

#Objectgeoriënteerd ontwerp

Het project maakt correct gebruik van de volgende OOP-principes:

Klassen
Elke vorm en hulpmiddel wordt gemodelleerd als een aparte class, wat zorgt voor een duidelijke en herbruikbare structuur.

Abstractie
Een abstracte basisklasse Shape definieert wat elke vorm moet kunnen doen, zonder de implementatie vast te leggen.

Encapsulatie
Gegevens zoals afmetingen zijn privé en alleen toegankelijk via getters en setters, waardoor de interne toestand beschermd blijft.

Overerving (Inheritance)
Klassen zoals Circle en Rectangle erven van Shape, wat codehergebruik mogelijk maakt en duplicatie voorkomt.

Polymorfisme
Via virtuele functies wordt tijdens runtime bepaald welke draw()-implementatie wordt uitgevoerd, afhankelijk van het objecttype.

Objectcompositie
Hulpmiddelen zoals een DrawingTool gebruiken objecten van het type Shape zonder ervan te erven, wat zorgt voor een flexibel ontwerp.

Constructors en destructors

#Het project bevat:

Meerdere default constructors

Meerdere geparametriseerde constructors

Copy constructors

Destructors voor het correct vrijgeven van objecten

Member initialization lists voor efficiënte initialisatie

Constructor forwarding voor nette en onderhoudbare code

Dit project toont een correcte en doordachte toepassing van objectgeoriënteerd programmeren in C++. Door het gebruik van abstractie, encapsulatie, overerving en polymorfisme is de code overzichtelijk, onderhoudbaar en uitbreidbaar. Het project voldoet volledig aan de gestelde OOP-eisen en vormt een solide basis voor verdere uitbreiding


