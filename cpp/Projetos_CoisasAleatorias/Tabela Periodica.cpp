#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;
string TP[118] = {"Hidrogenio", "Helio", "Litio", "Berilio", "Boro", "Carbono", "Nitrogenio", "Oxigenio", "Fluor", "Neonio", "Sodio", "Magnesio", "Aluminio", "Silicio", "Fosforo", "Enxofre", "Cloro", "Argonio", "Potassio", "Calcio", "Escandio", "Titanio", "Vanadio", "Cromio", "Manganes", "Ferro", "Cobalto", "Niquel", "Cobre", "Zinco", "Galio", "Germanio", "Arsenio", "Selenio", "Bromo", "Criptonio", "Rubidio", "Estroncio", "Itrio", "Zirconio", "Niobio", "Molibdenio", "Tecnecio", "Rutenio", "Rodio", "Paladio", "Prata", "Cadmio", "Indio", "Estanho", "Antimonio", "Telurio", "Iodo", "Xenonio", "Cesio", "Bario", "Lantanio", "Cerio", "Praseodimio", "Neodimio", "Promecio", "Samario", "Europio", "Gadolinio", "Terbio", "Disprosio", "Holmio", "Erbio", "Tulio", "Iterbio", "Lutecio", "Hafnio", "Tantalo", "Tungstenio", "Renio", "Osmio", "Iridio", "Platina", "Ouro", "Merc�rio", "Talio", "Chumbo", "Bismuto", "Polonio", "Astato", "Radonio", "Francio", "Radio", "Actinio", "Torio", "Protactinio", "Uranio", "Netunio", "Plutonio", "Americio", "Curio", "Berquelio", "Californio", "Einstenio", "Fermio", "Mendelevio", "Nobelio", "Laurencio", "Rutherfordio", "Dubnio", "Seaborgio", "Bohrio", "Hassio", "Meitnerio", "Darmstadtio", "Roentgenio", "Copernicio", "Nihonio", "Flerovio", "Moscovio", "Livermorio", "Tennesso", "Oganesson"};

string STP[118] ={"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al","Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn","Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb","Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In","Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm","Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta","W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

int NTP[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};

int MTP[118] = {1, 4, 7, 9, 11, 12, 14, 16, 19, 20, 23, 24, 27, 28, 31, 32, 35, 40, 39, 40, 45, 48, 51, 52, 55, 56, 59, 59, 63, 65, 70, 73, 75, 79, 80, 84, 85, 88, 89, 91, 93, 96, 97, 101, 103, 106, 108, 112, 115, 119, 122, 128, 127, 131, 133, 137, 139, 140, 141, 144, 147, 150, 152, 157, 159, 162, 165, 167, 169, 173, 175, 178, 181, 184, 186, 190, 192, 195, 197, 201, 204, 207, 209, 210, 210, 222, 223, 226, 227, 232, 231, 238, 237, 239, 243, 247, 247, 251, 254, 257, 256, 259, 260, 261, 262, 263, 262, 265, 266, 269, 272, 285, 286, 289, 288, 292, 117, 294};

int F[16][32] = { {1, 3, 11, 19, 37, 55, 87}, {4, 12, 20, 38, 56, 88}, {5, 13, 31, 49, 81, 113}, {6, 14, 32, 50, 82, 114}, {7, 15, 33, 51, 83, 115}, {8, 16, 34, 52, 84, 116}, {9, 17, 35, 53, 85, 117}, {2, 10, 18, 36, 54, 86, 118}, {29, 47, 79, 111}, {30, 48, 80, 112}, {21, 39, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103}, {22, 40, 72, 104}, {23, 41, 73, 105}, {24, 42, 74, 106}, {25, 43, 75, 107}, {26, 27, 28, 44, 45, 46, 76, 77, 78, 108, 109, 110} };

vector<string> FTP[32] = { {"Hidrog�nio", "L�tio", "S�dio", "Pot�ssio", "Rub�dio", "C�sio", "Fr�ncio"}, {"Ber�lio", "Magn�sio", "C�lcio", "Estr�ncio", "B�rio", "R�dio"}, {"Boro", "Alum�nio", "G�lio", "�ndio", "T�lio", "Nih�nio"}, {"Carbono", "Sil�cio", "Germ�nio", "Estanho", "Chumbo", "Fler�vio"}, {"Nitrog�nio", "F�sforo", "Ars�nio", "Antim�nio", "Bismuto", "Mosc�vio"}, {"Oxig�nio", "Enxofre", "Sel�nio", "Tel�rio", "Pol�nio", "Liverm�rio"}, {"Fl�or", "Cloro", "Bromo", "Iodo", "Astato", "Tennesso"} , {"H�lio",  "Ne�nio", "Arg�nio", "Cript�nio", "Xen�nio", "Rad�nio", "Oganess�nio"}, {"Cobre", "Prata", "Ouro", "Roentg�nio"}, {"Zinco", "C�dmio", "Merc�rio", "Copern�cio"}, {"Esc�ndio", "�trio", "Lant�nio", "C�rio", "Praseod�mio", "Neod�mio", "Prom�cio", "Sam�rio", "Eur�pio", "Gadol�nio", "T�rbio", "Dispr�sio", "H�lmio", "�rbio", "T�lio", "It�rbio", "Lut�cio", "Act�nio", "T�rio", "Protact�nio", "Ur�nio", "Nept�nio", "Plut�nio", "Amer�cio", "C�rio", "Berqu�lio", "Calif�rnio", "Einst�nio", "F�rmio", "Mendel�vio", "Nob�lio", "Laur�ncio"},  {"Tit�nio", "Zirc�nio", "H�fnio", "Rutherf�rdio"}, {"Van�dio", "Ni�bio", "T�ntalo", "D�bnio"}, {"Cr�mio", "Molibd�nio", "Tungst�nio", "Seab�rgio"}, {"Mangan�s", "Tecn�cio", "R�nio", "B�hrio"}, {"Ferro", "Rut�nio", "�smio", "H�ssio", "Cobalto", "R�dio", "Ir�dio", "Meitn�rio", "N�quel", "Pal�dio", "Platina", "Darmst�dtio"} };

string f[16]= {"Fam�lia 1A ou Fam�lia dos Metais Alcalinos", "Fam�lia 2A ou Fam�lia dos Metais Alcalino-Terrosos", "Fam�lia 3A ou Fam�lia do Boro", "Fam�lia 4A ou Fam�lia do Carbono", "Fam�lia 5A ou Fam�lia do Nitrog�nio", "Fam�lia 6A ou Fam�lia dos Calcog�nios", "Fam�lia 7A ou Fam�lia dos Halog�nios", "Fam�lia 8A ou Fam�lia dos Gases Nobres", "Fam�lia 1B", "Fam�lia 2B", "Fam�lia 3B", "Fam�lia 4B", "Fam�lia 5B", "Fam�lia 6B", "Fam�lia 7B", "Fam�lia 8B"};

int P[7][32] = { {1, 2}, {3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36}, {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54}, {55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86}, {87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118} };

string p[7] = {"1� Per�odo", "2� Per�odo", "3� Per�odo", "4� Per�odo", "5� Per�odo", "6� Per�odo", "7� Per�odo"};

string G[16] = {"1A", "2A", "3A", "4A", "5A", "6A", "7A", "8A", "1B", "2B", "3B", "4B", "5B", "6B", "7B", "8B"};

string g[16] = { "Elemento membro da Fam�lia A, ou dos elementos representativos. Os elementos da Fam�lia 1A ou dos Metais Alcalinos(com exce��o do Hidrog�nio) reagem facilmente com a �gua. Essa rea��o forma hidr�xidos, que s�o subst�ncias b�sicas ou alcalinas, ao liberar o hidrog�nio. Al�m disso, esses metais tamb�m reagem com oxig�nio produzindo �xidos.As principais caracter�sticas dos Metais Alcalinos s�o: baixa densidade, moles, muito reativos e eletropositivos.",
                "Elemento membro da Fam�lia A, ou dos elementos representativos. A Fam�lia 2A ou Fam�lia dos Metais Alcalino-Terrosos recebeu esse nome pois seus �xidos eram chamados de terras. Possuem propriedades b�sicas (alcalinas). Os Metais Alcalino-Terrosos tem baixa densidade, s�o coloridos e moles. Todos s�o s�lidos. Apesar de n�o reagir com �gua t�o r�pido como os Metais Alcalinos, os Metais Alcalino-Terrosos tamb�m formam hidr�xidos fortemente b�sicos. Na rea��o com Halog�nios eles formam sais i�nicos.",
                "Elemento membro da Fam�lia A, ou dos elementos representativos. Os elementos da Fam�lia 3A ou Fam�lia do Boro possuem tamanho reduzido e carga eletr�nica elevada que favorece a coval�ncia. A Fam�lia do Boro tamb�m � conhecida como Alumin�ides. Escolher o boro (B) e o alum�nio (Al) para batizar esse grupo se deve ao fato deles serem os elementos mais simples (mais leves) e abundantes da fam�lia.",
                "Elemento membro da Fam�lia A, ou dos elementos representativos. Fam�lia 4A ou Fam�lia do Carbono que, possui propriedades que o difere dos demais elementos do grupo. O principal fator diferenciador � a sua capacidade de se ligar a v�rios outros �tomos de carbono, formando grandes cadeia. As liga��es C-C s�o fortes, e as liga��es Si-Si, Ge-Ge e Sn-Sn diminuem progressivamente de energia. Al�m disso, o carbono � o �nico capaz de formar liga��es m�ltiplas (duplas e triplas liga��es). As energias de ioniza��o decrescem do carbono para o sil�cio (Si) e a seguir variam de forma irregular. A quantidade de energia necess�ria para ionizar um �tomo desse grupo � muito alta e, por isso, compostos i�nicos simples s�o raros. O carbono apresenta ponto de fus�o extremamente elevado (requer uma energia muito grande para romper as liga��es covalentes fortes). Os elementos sil�cio (Si) e germ�nio (Ge) fundem a temperaturas menores, por�m, ainda assim, s�o bastante elevadas. Os pontos de fus�o decrescem de cima para baixo porque as liga��es M-M se tornam mais fracas � medida que os �tomos aumentam de tamanho. Estanho (Sn) e chumbo (Pb) s�o met�licos e t�m pontos de fus�o baixos. Eles n�o aproveitam todos os quatro el�trons externos na liga��o, contribuindo para a forma��o de uma liga��o menos forte.",
                "Elemento membro da Fam�lia A, ou dos elementos representativos. Os elementos da Fam�lia 5A ou Fam�lia do Nitrog�nio possuem alta energia de ioniza��o. Dentre os elementos da Fam�lia do Nitrog�nio, somente o elemento que da nome a fam�lia existe sob a forma de mol�cula diat�mica. Os demais �tomos desse grupo s�o grandes e seus tamanhos dificultam o estabelecimento de duas liga��es. Nos hidretos destes elementos, a energia de liga��o, a estabilidade e os �ngulos de liga��es se tornam menores � medida que se desce no grupo.",
                "Elemento membro da Fam�lia A, ou dos elementos representativos. Fam�lia 6A ou Fam�lia dos Calcog�nios. O nome \"calcog�nio\" vem do grego \"khalkos\", que significa cobre, e \"genos\", uma fam�lia de origem nobre. A jun��o dos nomes gera \"calcog�nios\", que quer dizer \"origin�rio do cobre\" ou \"que vem do cobre\". Todos os elementos dessa fam�lia s�o N�o-Metais e o pol�nio (Po) � o �nico deles que � radiotivo. Eles formam compostos com metais e com o hidrog�nio, quando o n�mero de oxida��o � -2. Os n�meros de oxida��o +2, +4 e +6 ocorrem quando os elementos do grupo formam compostos com outros elementos do seu pr�prio grupo, ou com os elementos do grupo dos Halog�nios.",
                "Elemento membro da Fam�lia A, ou dos elementos representativos. Fam�lia 7A ou Fam�lia dos Halog�nios. Seu significado (do grego) � \"formador de sais\". Na forma natural, s�o encontrados como mol�culas diat�micas. Um Halog�nio adquiri estabilidade qu�mica quando o seu �ltimo n�vel de energia recebe um el�tron, transformando-se assim num �on mononegativo. Um dos sais mais famosos que possui esse �on � o cloreto de s�dio, conhecido como sal de cozinha. Como os Halog�nios s�o muito oxidantes eles reagem com os metais, N�o-Metais, subst�ncias redutoras e at� com os Gases Nobres. Os elementos dessa fam�lia s�o perigosos (e at� mesmo letais) a seres vivos, j� que s�o extremamente reativos. O cloro e o iodo, por exemplo, s�o usados como desinfetantes para �gua pot�vel, piscinas, ferimentos, pois matam bact�rias, fungos e outros microrganismos. O fl�or e cloro s�o gasosos, o bromo � l�quido, o iodo e o astato s�o s�lidos. Exceto o iodo, s�o todos t�xicos.",
                "Elemento membro da Fam�lia A, ou dos elementos representativos. Fam�lia 8A ou Fam�lia dos Gases Nobres. Os Gases Nobres t�m como caracter�stica a dificuldade de combinar com outros �tomos, j� que s�o pouco reativos (baixa reatividade). Esses gases existem em grande quantidade na atmosfera da Terra. Os Gases Nobres apresentam baixos pontos de fus�o e ebuli��o, j� que possuem for�as de atra��o interat�micas muito fracas. Por conta disso, mesmo os que apresentam �tomos mais pesados, em condi��es normais, s�o gasosos. Tamb�m n�o formam facilmente compostos qu�micos porque todos os gases possuem orbitais dos n�veis de energia exteriores completos com el�trons. Apesar da dificuldade, os Gases Nobres podem formar compostos com outros metais. � medida que os �tomos dos Gases Nobres crescem na extens�o da s�rie tornam-se ligeiramente mais reativos, ent�o pode-se induzir o xen�nio a formar compostos com o fl�or, por exemplo.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B.",
                "Os Metais de Transi��o s�o definidos pela Uni�o Internacional de Qu�mica Pura e Aplicada (IUPAC) como \"Um elemento cujo �tomo possui um subn�vel d incompleto ou que possa vir a formar c�tions com um subn�vel d incompleto\". Os Lantan�ides e Actin�ides s�o considerados elementos de transi��o interna, por�m alguns livros n�o os consideram metais de transi��o, j� que possuem propriedades f�sicas e qu�micas que permitem separ�-los em outros blocos. Os Metais de Tansi��o s�o duros e possuem alto ponto de fus�o e ebuli��o. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxida��o variados (estados de oxida��o mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordena��o com diferentes �ndices. O n�mero de el�trons nos subn�veis d � vari�vel. Al�m disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente s�o coloridos ou apresentam paramagnetismo. Os Metais de Transi��o s�o muito empregados como catalisadores, tanto homog�neos como heterog�neos. N�o h� muitas peculiariadades entre as familias dentro da fam�lia B, a n�o ser pelos Lantan�deos e Actin�deos, por�m, est�o inclusos na Fam�lia 3B."};

string GDE[32] = {"1A", "2A", "3A", "4A", "5A", "6A", "7A", "8A", "3B", "4B", "5B", "6B", "7B", "8B", "8B", "8B", "1B", "2B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B"};

string de[32] = {"Termina-se a distribui��o eletr�nica em ns1.", "Termina-se a distribui��o eletr�nica em ns2.", "Termina-se a distribui��o eletr�nica em ns2 np1.", "Termina-se a distribui��o eletr�nica em ns2 np2.", "Termina-se a distribui��o eletr�nica em ns2 np3.", "Termina-se a distribui��o eletr�nica em ns2 np4.", "Termina-se a distribui��o eletr�nica em ns2 np5.", "Termina-se a distribui��o eletr�nica em ns2 np6.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d1.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d2.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d3.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d4.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d5.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d6.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d7.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d8.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d9.", "Termina-se a distribui��o eletr�nica em ns2 (n - 1)d10.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f1.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f2.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f3.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f4.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f5.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f6.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f7.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f8.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f9.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f10.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f11.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f12.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f13.", "Termina-se a distribui��o eletr�nica em ns2 (n - 2)f14."};

string P1[7] = {"1", "2", "3", "4", "5", "6", "7"};

vector<string> p1[32] = { {"Hidrog�nio", "H�lio"}, {"L�tio", "Ber�lio", "Boro", "Carbono", "Nitrog�nio", "Oxig�nio", "Fl�or", "Ne�nio"}, {"S�dio", "Magn�sio", "Alum�nio", "Sil�cio", "F�sforo", "Enxofre", "Cloro", "Arg�nio"}, {"Pot�ssio", "C�lcio", "Esc�ndio", "Tit�nio", "Van�dio", "Cr�mio", "Mangan�s", "Ferro", "Cobalto", "N�quel", "Cobre", "Zinco", "G�lio", "Germ�nio", "Ars�nio", "Sel�nio", "Bromo", "Cript�nio"}, {"Rub�dio", "Estr�ncio", "�trio", "Zirc�nio", "Ni�bio", "Molibd�nio", "Tecn�cio", "Rut�nio", "R�dio", "Pal�dio", "Prata", "C�dmio",  "�ndio", "Estanho", "Antim�nio", "Tel�rio", "Iodo", "Xen�nio"}, {"C�sio", "B�rio", "Lant�nio", "C�rio", "Praseod�mio", "Neod�mio", "Prom�cio", "Sam�rio", "Eur�pio", "Gadol�nio", "T�rbio", "Dispr�sio", "H�lmio", "�rbio", "T�lio", "It�rbio", "Lut�cio", "H�fnio", "T�ntalo", "Tungst�nio", "R�nio", "�smio", "Ir�dio", "Platina", "Ouro", "Merc�rio", "T�lio", "Chumbo", "Bismuto", "Pol�nio", "Astato", "Rad�nio"}, {"Fr�ncio", "R�dio",  "Act�nio", "T�rio", "Protact�nio", "Ur�nio", "Nept�nio", "Plut�nio", "Amer�cio", "C�rio", "Berqu�lio", "Calif�rnio", "Einst�nio", "F�rmio", "Mendel�vio", "Nob�lio", "Laur�ncio", "Rutherf�rdio", "D�bnio", "Seab�rgio", "B�hrio", "H�ssio", "Meitn�rio", "Darmst�dtio", "Roentg�nio", "Copern�cio",  "Nih�nio", "Fler�vio", "Mosc�vio", "Liverm�rio", "Tennesso", "Oganess�nio"} };

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    string tp, stp, opc3;
    int ntp, mtp;
    bool vf = false;

    int NA, MA;
    string S, gn, N, Periodo;

    char opc1, opc2;
    string info, info1;

    inicio:

    info = ' ';
    info1 = " ";
    NA = 0;
    N = " ";
    S = " ";
    MA = 0;
    tp = " ";
    stp = " ";
    ntp = 0;
    mtp = 0;
    gn = " ";
    vf = false;


    if( (opc2 == 's') || (opc2 == 'S') ){
        system("cls");
    }
    setlocale(LC_ALL, "portuguese");

    cout << "Sobre o que voc� quer saber? Um elemento, uma fam�lia ou um per�odo?[e/f/p]\n";
    cin >> info;
    if( (info == "e") || (info == "E") ){
        inicio1A:

        info = ' ';
        info1 = " ";
        NA = 0;
        N = " ";
        S = " ";
        MA = 0;
        tp = " ";
        stp = " ";
        ntp = 0;
        mtp = 0;
        gn = " ";
        vf = false;
        if( (opc2 == 's') || (opc2 == 'S') ){
        system("cls");
    }
        cout <<  "O que voc� sabe sobre o elemento? O n�mero at�mico, o nome, a sigla ou a massa at�mica?[NA/N/S/MA]\n";
        cin >> info1;
        if( (info1 == "na") || (info1 == "NA") || (info1 == "Na") ){
            inicio2A:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ){
                system("cls");
            }
            cout << "Digite um numero at�mico, lembrando que h� apenas entre 1 e 118!\n";
            cin >> NA;

            for(int i = 0; i < 118; i++){
                if(NA == NTP[i]){
                    ntp = (i + 1);
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    cout << "Voc� digitou o elemento " << tp << "(" << stp << "), que possui massa at�mica igual a " << mtp << ", ";
                    vf = true;
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhum n�mero at�mico foi digitado! Lembre-se de que h� apenas entre o 1 e o 118 atualmente.";
                    break;
                }
            }
            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "est� localizado no " << p[x] << " e pertence � ";
                        break;
                    }
                }
            }

            for(int x = 0; x < 16; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == F[x][y] && vf){
                        cout << f[x] << ".\n";
                        break;
                    }
                }
            }

            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo elementos pelos N�meros At�micos, continuar descobrindo elementos, ou para de descobrir elementos? [NA/ E/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "NA") goto inicio2A;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }
            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ){
                    goto inicio;
                }
            }
        }
        else if( (info1 == "N") || (info1 == "n")){
            inicio2B:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "Qual o nome do elemento? Digite exatamente como na Tabela Peri�dica, mas sem acento!\n";

            cin >> N;

            for(int i = 0; i < 118; i++){
                if(N == TP[i]){
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    ntp = NTP[i];
                    vf = true;
                    cout << "O elemento " << tp << "(" << stp << ") possui " << ntp << " pr�tons, massa at�mica igual a " << mtp << ", ";
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhum elemento qu�mico foi digitado! Tente digitar com a primeira letra mai�scula e sem acento ou pesquisar o nome correto.";
                    break;
                }

            }

            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "est� localizado no " << p[x] << " e pertence � ";
                        break;
                    }
                }
            }

            for(int x = 0; x < 16; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == F[x][y] && vf){
                    cout << f[x] << ".\n";
                    break;
                    }
                }
            }

            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 's') || (opc1 == 'S') ){
                cout << "\n Deseja continuar descobrindo elementos pelos seus Nomes, continuar descobrindo elementos, ou para de descobrir elementos? [N/ E/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "N") goto inicio2B;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }

            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ){
                    goto inicio;
                }
            }
        }
        else if( (info1 == "S") || (info1 == "s")){
            inicio2C:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "Qual a sigla do elemento? Digite exatamente como na Tabela Peri�dica!\n";
            cin >> S;

            for(int i = 0; i < 118; i++){
                if(S == STP[i]){
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    ntp = NTP[i];
                    vf = true;
                    cout << "Voc� digitou o " << tp << ", que possui " << ntp << " pr�tons, massa at�mica igual a " << mtp << ", ";
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhuma sigla de elemento qu�mico foi digitado! Tente digitar com a primeira letra mai�scula e caso tenha duas letras, a segunda min�scula.";
                    break;
                }

            }

            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "est� localizado no " << p[x] << " e pertence � ";
                        break;
                    }
                }
            }

            for(int x = 0; x < 18; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == F[x][y] && vf){
                    cout << f[x] << ".\n";
                    break;
                    }
                }
            }

            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 's') || (opc1 == 'S') ){
                cout << "\n Deseja continuar descobrindo elementos pelas suas siglas, continuar descobrindo elementos, ou para de descobrir elementos? [S/ E/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "S") goto inicio2C;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }

            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ){
                goto inicio;
                }
            }
        }
        else if( (info1 == "MA") || (info1 == "ma") || (info1 == "Ma") ){
            inicio2D:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "Digite uma massa at�mica, com os n�meros inteiros e arredondados!\n";
            cin >> MA;
            for(int i = 0; i < 118; i++){
                if(MA == MTP[i]){
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    ntp = NTP[i];
                    vf = true;
                    cout << "Voc� digitou o " << tp << "(" << stp << "), que possui " <<  ntp << " pr�tons, ";
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhuma massa at�mica de um elemento qu�mico foi digitado! Tente colocar o n�mero arredondado e inteiro do digitado ou pesquisar.";
                    break;
                }
            }

            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "est� localizado no " << p[x] << " e pertence � ";
                        break;
                    }
                }
            }

            for(int x = 0; x < 16; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == F[x][y] && vf){
                    cout << f[x] << ".\n";
                    break;
                    }
                }
            }

            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo elementos pelas suas Massas At�micas, continuar descobrindo elementos, ou para de descobrir elementos? [MA/ E/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "MA") goto inicio2D;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }
            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ){
                goto inicio;
                }
            }
        }
        else{
            cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                goto inicio;
            }
        }
    }
    else if( (info == "f") || (info == "F") ){
        inicio1B:

        info = ' ';
        info1 = " ";
        NA = 0;
        N = " ";
        S = " ";
        MA = 0;
        tp = " ";
        stp = " ";
        ntp = 0;
        mtp = 0;
        gn = " ";
        vf = false;
        if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
        cout << "O que voc� deseja saber sobre as fam�lias? Caracter�sticas, elementos ou distribui��o eletr�nica[C/E/D]\n";
        cin >> info1;
        if( (info1 == "C") || (info1 == "c") ){
            inicio2E:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "As Fam�lias ou Grupos s�o as linhas da Tabela Per�odica, e classificam os elementos quanto �s caracter�sticas em comum! N�o entendeu? Tente ver especificamente sobre uma Fam�lia: ";
            cout << "Qual Fam�lia voc� quer saber as caracter�sticas?[Exemplo: 1A/5B]\n";
            cin >> gn;
            for(int i = 0; i < 16; i++){
                if(gn == G[i]){
                    vf = true;
                    cout << "As caracter�sticas da Fam�lia " << gn << " s�o:\n" << g[i] << endl;
                    break;
                }
                else if(i == 15){
                    cout << "Nenhuma Fam�lia foi digitada! Lembre-se de h� apenas de 1 a 8 das fam�lias A e B!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo Caracteristicas das Fam�lias, continuar descobrindo sobre as Fam�lias, ou para de descobrir sobre as Fam�lias? [C/ F/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "C") goto inicio2E;
                else if(opc3 == "F") goto inicio1B;
                goto inicio;
            }
            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ) goto inicio;
            }
        }

        else if( (info1 == "E") || (info1 == "e") ){
            inicio2F:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "Qual Fam�lia voc� quer saber os elementos?[Exemplo: 1A/5B]\n";
            cin >> gn;
            for(int i = 0; i < 16; i++){
                if(gn == G[i]){
                    vf = true;
                    cout << "Os elementos da Fam�lia " << gn << " s�o:\n";
                    for(string j : FTP[i]) cout << j << "\n";
                    break;
                }
                else if(i == 15){
                    cout << "Nenhuma Fam�lia foi digitada! Lembre-se de h� apenas de 1 a 8 das fam�lias A e B!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo Elementos das Fam�lias, continuar descobrindo sobre as Fam�lias, ou para de descobrir sobre as Fam�lias? [E/ F/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "E") goto inicio2F;
                else if(opc3 == "F") goto inicio1B;
                goto inicio;
            }
            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ) goto inicio;
            }
        }
        else if( (info1 == "D") || (info1 == "d") ){
            inicio2G:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "Qual Fam�lia voc� quer saber a distribui��o eletr�nica?[Exemplo: 1A/5B]\n";
            cin >> gn;

            for(int i = 0; i < 32; i++){
                if(gn == GDE[i]){
                    if(gn == GDE[8]){
                        vf = true;
                        de[8].replace(0, 1, "t");
                        de[8].replace(7, 3, "m");
                        de[8].erase(51, 1);
                        de[18].replace(0, 1, "t");
                        de[18].replace(7, 3, "m");
                        de[18].erase(51, 1);
                        de[19].replace(0, 1, "t");
                        de[19].replace(7, 3, "m");
                        de[19].erase(51, 1);
                        de[31].replace(0, 1, "t");
                        de[31].replace(7, 3, "m");
                        cout << "Na Fam�lia " << GDE[i] << " os elementos Esc�ndio, �trio, Lut�cio e Laur�ncio " << de[8] << ", j� os elementos do grupo dos Lantan�deos e dos Act�nideos, os primeiros " << de[18] << ", os segundos " << de[19] << " e assim por diante at� os �ltimos, que " << de[31];
                        de[8].insert(50, ".");
                        de[9].insert(50, ".");
                        de[10].insert(50, ".");
                        break;
                    }
                    else{
                        vf = true;
                        de[i].replace(0, 1, "t");
                        cout << "Na Fam�lia " << GDE[i] << " " << de[i];
                        break;
                    }
                }
                if(i == 31){
                    cout << "Nenhuma Fam�lia foi digitada! Lembre-se de h� apenas de 1 a 8 das fam�lias A e B!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo Destribui��o Eletr�nica das Fam�lias, continuar descobrindo sobre as Fam�lias, ou para de descobrir sobre as Fam�lias? [D/ F/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "D") goto inicio2G;
                else if(opc3 == "F") goto inicio1B;
                goto inicio;
            }
            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ) goto inicio;
            }
        }
        else{
            cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                goto inicio;
            }
        }
    }

    else if( (info == "P") || (info == "p") ){
        inicio1C:

        info = ' ';
        info1 = " ";
        NA = 0;
        N = " ";
        S = " ";
        MA = 0;
        tp = " ";
        stp = " ";
        ntp = 0;
        mtp = 0;
        gn = " ";
        vf = false;
        if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
        cout << "O que voc� deseja saber sobre os Per�odos? Propriedades ou elementos[P/E]\n";
        cin >> info1;
        if( (info1 == "P") || (info1 == "p") ){
            inicio2H:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "Resumidamente, os Per�odos s�o as colunas da Tabela peri�dica. Isso significa que os Per�odos classificam os elementos quanto � sua camada de val�ncia, ou seja, classifica quantas camadas o elemento possui! Por exemplo, o Ouro (Au), que pertence ao 5� Per�odo da Tabela Per�odica, tem 5 camadas: as camadas K, L, M, N e O. At� hoje em dia foram descobertas 7 camadas, por�m, acredita-se que haja mais uma. Ali�s, caso voc� ainda n�o tenha entendido, estamos falando da Tabela \"Peri�dica\". Essa ferramenta tamb�m nos ajuda a compreender por que o S�dio tem um raio at�mico maior que o L�tio, por exemplo. O S�dio pertence ao 3�Per�odo, ou seja, tem 3 camadas: As camadas K, L e M. O L�tio pertence ao 2�Per�odo, ou seja, tem 2 camadas: As camadas K e L. Se o S�dio tem uma camada a mais que o L�tio, logo a sua esfera ser� maior, e portanto o seu raio at�mico tamb�m! Essa � apenas mais uma das propriedades qu�micas dentre outras que os Per�odos nos ajudam a identificar e portanto � muito �til e importante domin�-los\n";

            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar rever as Propriedades dos Per�odos, continuar descobrindo sobre os Per�odos, ou para de descobrir sobre os Per�odos? [PO/ PE/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n \n";
                cin >> opc2;
                if(opc3 == "PO") goto inicio2H;
                else if(opc3 == "PE") goto inicio1C;
                goto inicio;
            }
            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ) goto inicio;
            }
        }
        else if( (info1 == "E") || (info1 == "e") ){
            inicio2I:

            info = ' ';
            info1 = " ";
            NA = 0;
            N = " ";
            S = " ";
            MA = 0;
            tp = " ";
            stp = " ";
            ntp = 0;
            mtp = 0;
            gn = " ";
            vf = false;
            if( (opc2 == 's') || (opc2 == 'S') ) system("cls");
            cout << "De qual Per�odo voc� quer saber os elementos? Exemplos: [1/6]\n";
            cin >> Periodo;
            for(int i = 0; i < 7; i++){
                if(Periodo == P1[i]){
                    vf = true;
                    for(string j : p1[i]) cout << j << " ";
                    break;
                }
                else if(i == 6){
                    cout << "Nenhum Per�odo foi digitado! Lembre-se de h� apenas de 7 Per�odos!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo os Elementos dos Per�odos, continuar descobrindo sobre os Per�odos, ou para de descobrir sobre os Per�odos? [E/ Pe/ P] \n";
                cin >> opc3;
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "E") goto inicio2I;
                else if(opc3 == "Pe") goto inicio1C;
                goto inicio;
            }
            else{
                cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ) goto inicio;
            }
        }
        else{
            cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "Voc� quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                goto inicio;
            }
        }
    }

    else{
        cout << "Nenhuma das op��es anteriores foi digitada! Deseja continuar?[s/n]\n";
        cin >> opc1;
        if( (opc1 == 'S') || (opc1 == 's') ){
            cout << "Voc� quer limpar a tela atual?[s/n]\n";
            cin >> opc2;
            goto inicio;
        }
    }

}
