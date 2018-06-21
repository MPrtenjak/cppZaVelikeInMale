// izraz a = a / 3; lahko zapišemo krajše kot

a /= 3;

// izraz c = c + 1; lahko zapišemo krajše kot

c++;

// izraz d = d - 1; lahko zapišemo krajše kot

d--;

// izraz a = a / (3*b+c); lahko zapišemo krajše kot

a /= (3*b*c);

// izraza a = 3 * b; NE MOREMO zapisati krajše, ker na desni strani izraza
//                   ni spremenljivke a

// izraza a = 2 / a; NE MOREMO zapisat krajše, ker je a na napaèni strani
//                   operatorje


a /= 2;  // NAPAKA !!!!!, saj to pomeni a = a / 2 in NE a = 2 / a; !


   a = 3 * b;
   a = 2 / a;
