// izraz a = a / 3; lahko zapi�emo kraj�e kot

a /= 3;

// izraz c = c + 1; lahko zapi�emo kraj�e kot

c++;

// izraz d = d - 1; lahko zapi�emo kraj�e kot

d--;

// izraz a = a / (3*b+c); lahko zapi�emo kraj�e kot

a /= (3*b*c);

// izraza a = 3 * b; NE MOREMO zapisati kraj�e, ker na desni strani izraza
//                   ni spremenljivke a

// izraza a = 2 / a; NE MOREMO zapisat kraj�e, ker je a na napa�ni strani
//                   operatorje


a /= 2;  // NAPAKA !!!!!, saj to pomeni a = a / 2 in NE a = 2 / a; !


   a = 3 * b;
   a = 2 / a;
