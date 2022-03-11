#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;
string TP[118] = {"Hidrogenio", "Helio", "Litio", "Berilio", "Boro", "Carbono", "Nitrogenio", "Oxigenio", "Fluor", "Neonio", "Sodio", "Magnesio", "Aluminio", "Silicio", "Fosforo", "Enxofre", "Cloro", "Argonio", "Potassio", "Calcio", "Escandio", "Titanio", "Vanadio", "Cromio", "Manganes", "Ferro", "Cobalto", "Niquel", "Cobre", "Zinco", "Galio", "Germanio", "Arsenio", "Selenio", "Bromo", "Criptonio", "Rubidio", "Estroncio", "Itrio", "Zirconio", "Niobio", "Molibdenio", "Tecnecio", "Rutenio", "Rodio", "Paladio", "Prata", "Cadmio", "Indio", "Estanho", "Antimonio", "Telurio", "Iodo", "Xenonio", "Cesio", "Bario", "Lantanio", "Cerio", "Praseodimio", "Neodimio", "Promecio", "Samario", "Europio", "Gadolinio", "Terbio", "Disprosio", "Holmio", "Erbio", "Tulio", "Iterbio", "Lutecio", "Hafnio", "Tantalo", "Tungstenio", "Renio", "Osmio", "Iridio", "Platina", "Ouro", "Mercúrio", "Talio", "Chumbo", "Bismuto", "Polonio", "Astato", "Radonio", "Francio", "Radio", "Actinio", "Torio", "Protactinio", "Uranio", "Netunio", "Plutonio", "Americio", "Curio", "Berquelio", "Californio", "Einstenio", "Fermio", "Mendelevio", "Nobelio", "Laurencio", "Rutherfordio", "Dubnio", "Seaborgio", "Bohrio", "Hassio", "Meitnerio", "Darmstadtio", "Roentgenio", "Copernicio", "Nihonio", "Flerovio", "Moscovio", "Livermorio", "Tennesso", "Oganesson"};

string STP[118] ={"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al","Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn","Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb","Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In","Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm","Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta","W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

int NTP[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};

int MTP[118] = {1, 4, 7, 9, 11, 12, 14, 16, 19, 20, 23, 24, 27, 28, 31, 32, 35, 40, 39, 40, 45, 48, 51, 52, 55, 56, 59, 59, 63, 65, 70, 73, 75, 79, 80, 84, 85, 88, 89, 91, 93, 96, 97, 101, 103, 106, 108, 112, 115, 119, 122, 128, 127, 131, 133, 137, 139, 140, 141, 144, 147, 150, 152, 157, 159, 162, 165, 167, 169, 173, 175, 178, 181, 184, 186, 190, 192, 195, 197, 201, 204, 207, 209, 210, 210, 222, 223, 226, 227, 232, 231, 238, 237, 239, 243, 247, 247, 251, 254, 257, 256, 259, 260, 261, 262, 263, 262, 265, 266, 269, 272, 285, 286, 289, 288, 292, 117, 294};

int F[16][32] = { {1, 3, 11, 19, 37, 55, 87}, {4, 12, 20, 38, 56, 88}, {5, 13, 31, 49, 81, 113}, {6, 14, 32, 50, 82, 114}, {7, 15, 33, 51, 83, 115}, {8, 16, 34, 52, 84, 116}, {9, 17, 35, 53, 85, 117}, {2, 10, 18, 36, 54, 86, 118}, {29, 47, 79, 111}, {30, 48, 80, 112}, {21, 39, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103}, {22, 40, 72, 104}, {23, 41, 73, 105}, {24, 42, 74, 106}, {25, 43, 75, 107}, {26, 27, 28, 44, 45, 46, 76, 77, 78, 108, 109, 110} };

vector<string> FTP[32] = { {"Hidrogênio", "Lítio", "Sódio", "Potássio", "Rubídio", "Césio", "Frâncio"}, {"Berílio", "Magnésio", "Cálcio", "Estrôncio", "Bário", "Rádio"}, {"Boro", "Alumínio", "Gálio", "Índio", "Tálio", "Nihônio"}, {"Carbono", "Silício", "Germânio", "Estanho", "Chumbo", "Fleróvio"}, {"Nitrogênio", "Fósforo", "Arsênio", "Antimônio", "Bismuto", "Moscóvio"}, {"Oxigênio", "Enxofre", "Selênio", "Telúrio", "Polônio", "Livermório"}, {"Flúor", "Cloro", "Bromo", "Iodo", "Astato", "Tennesso"} , {"Hélio",  "Neônio", "Argônio", "Criptônio", "Xenônio", "Radônio", "Oganessônio"}, {"Cobre", "Prata", "Ouro", "Roentgênio"}, {"Zinco", "Cádmio", "Mercúrio", "Copernício"}, {"Escândio", "Ítrio", "Lantânio", "Cério", "Praseodímio", "Neodímio", "Promécio", "Samário", "Európio", "Gadolínio", "Térbio", "Disprósio", "Hôlmio", "Érbio", "Túlio", "Itérbio", "Lutécio", "Actínio", "Tório", "Protactínio", "Urânio", "Neptúnio", "Plutônio", "Amerício", "Cúrio", "Berquélio", "Califórnio", "Einstênio", "Férmio", "Mendelévio", "Nobélio", "Laurêncio"},  {"Titânio", "Zircônio", "Háfnio", "Rutherfórdio"}, {"Vanádio", "Nióbio", "Tântalo", "Dúbnio"}, {"Crômio", "Molibdênio", "Tungstênio", "Seabórgio"}, {"Manganês", "Tecnécio", "Rênio", "Bóhrio"}, {"Ferro", "Rutênio", "Ósmio", "Hássio", "Cobalto", "Ródio", "Irídio", "Meitnério", "Níquel", "Paládio", "Platina", "Darmstádtio"} };

string f[16]= {"Família 1A ou Família dos Metais Alcalinos", "Família 2A ou Família dos Metais Alcalino-Terrosos", "Família 3A ou Família do Boro", "Família 4A ou Família do Carbono", "Família 5A ou Família do Nitrogênio", "Família 6A ou Família dos Calcogênios", "Família 7A ou Família dos Halogênios", "Família 8A ou Família dos Gases Nobres", "Família 1B", "Família 2B", "Família 3B", "Família 4B", "Família 5B", "Família 6B", "Família 7B", "Família 8B"};

int P[7][32] = { {1, 2}, {3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36}, {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54}, {55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86}, {87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118} };

string p[7] = {"1º Período", "2º Período", "3º Período", "4º Período", "5º Período", "6º Período", "7º Período"};

string G[16] = {"1A", "2A", "3A", "4A", "5A", "6A", "7A", "8A", "1B", "2B", "3B", "4B", "5B", "6B", "7B", "8B"};

string g[16] = { "Elemento membro da Família A, ou dos elementos representativos. Os elementos da Família 1A ou dos Metais Alcalinos(com exceção do Hidrogênio) reagem facilmente com a água. Essa reação forma hidróxidos, que são substâncias básicas ou alcalinas, ao liberar o hidrogênio. Além disso, esses metais também reagem com oxigênio produzindo óxidos.As principais características dos Metais Alcalinos são: baixa densidade, moles, muito reativos e eletropositivos.",
                "Elemento membro da Família A, ou dos elementos representativos. A Família 2A ou Família dos Metais Alcalino-Terrosos recebeu esse nome pois seus óxidos eram chamados de terras. Possuem propriedades básicas (alcalinas). Os Metais Alcalino-Terrosos tem baixa densidade, são coloridos e moles. Todos são sólidos. Apesar de não reagir com água tão rápido como os Metais Alcalinos, os Metais Alcalino-Terrosos também formam hidróxidos fortemente básicos. Na reação com Halogênios eles formam sais iônicos.",
                "Elemento membro da Família A, ou dos elementos representativos. Os elementos da Família 3A ou Família do Boro possuem tamanho reduzido e carga eletrônica elevada que favorece a covalência. A Família do Boro também é conhecida como Aluminóides. Escolher o boro (B) e o alumínio (Al) para batizar esse grupo se deve ao fato deles serem os elementos mais simples (mais leves) e abundantes da família.",
                "Elemento membro da Família A, ou dos elementos representativos. Família 4A ou Família do Carbono que, possui propriedades que o difere dos demais elementos do grupo. O principal fator diferenciador é a sua capacidade de se ligar a vários outros átomos de carbono, formando grandes cadeia. As ligações C-C são fortes, e as ligações Si-Si, Ge-Ge e Sn-Sn diminuem progressivamente de energia. Além disso, o carbono é o único capaz de formar ligações múltiplas (duplas e triplas ligações). As energias de ionização decrescem do carbono para o silício (Si) e a seguir variam de forma irregular. A quantidade de energia necessária para ionizar um átomo desse grupo é muito alta e, por isso, compostos iônicos simples são raros. O carbono apresenta ponto de fusão extremamente elevado (requer uma energia muito grande para romper as ligações covalentes fortes). Os elementos silício (Si) e germânio (Ge) fundem a temperaturas menores, porém, ainda assim, são bastante elevadas. Os pontos de fusão decrescem de cima para baixo porque as ligações M-M se tornam mais fracas à medida que os átomos aumentam de tamanho. Estanho (Sn) e chumbo (Pb) são metálicos e têm pontos de fusão baixos. Eles não aproveitam todos os quatro elétrons externos na ligação, contribuindo para a formação de uma ligação menos forte.",
                "Elemento membro da Família A, ou dos elementos representativos. Os elementos da Família 5A ou Família do Nitrogênio possuem alta energia de ionização. Dentre os elementos da Família do Nitrogênio, somente o elemento que da nome a família existe sob a forma de molécula diatômica. Os demais átomos desse grupo são grandes e seus tamanhos dificultam o estabelecimento de duas ligações. Nos hidretos destes elementos, a energia de ligação, a estabilidade e os ângulos de ligações se tornam menores à medida que se desce no grupo.",
                "Elemento membro da Família A, ou dos elementos representativos. Família 6A ou Família dos Calcogênios. O nome \"calcogênio\" vem do grego \"khalkos\", que significa cobre, e \"genos\", uma família de origem nobre. A junção dos nomes gera \"calcogênios\", que quer dizer \"originário do cobre\" ou \"que vem do cobre\". Todos os elementos dessa família são Não-Metais e o polônio (Po) é o único deles que é radiotivo. Eles formam compostos com metais e com o hidrogênio, quando o número de oxidação é -2. Os números de oxidação +2, +4 e +6 ocorrem quando os elementos do grupo formam compostos com outros elementos do seu próprio grupo, ou com os elementos do grupo dos Halogênios.",
                "Elemento membro da Família A, ou dos elementos representativos. Família 7A ou Família dos Halogênios. Seu significado (do grego) é \"formador de sais\". Na forma natural, são encontrados como moléculas diatômicas. Um Halogênio adquiri estabilidade química quando o seu último nível de energia recebe um elétron, transformando-se assim num íon mononegativo. Um dos sais mais famosos que possui esse íon é o cloreto de sódio, conhecido como sal de cozinha. Como os Halogênios são muito oxidantes eles reagem com os metais, Não-Metais, substâncias redutoras e até com os Gases Nobres. Os elementos dessa família são perigosos (e até mesmo letais) a seres vivos, já que são extremamente reativos. O cloro e o iodo, por exemplo, são usados como desinfetantes para água potável, piscinas, ferimentos, pois matam bactérias, fungos e outros microrganismos. O flúor e cloro são gasosos, o bromo é líquido, o iodo e o astato são sólidos. Exceto o iodo, são todos tóxicos.",
                "Elemento membro da Família A, ou dos elementos representativos. Família 8A ou Família dos Gases Nobres. Os Gases Nobres têm como característica a dificuldade de combinar com outros átomos, já que são pouco reativos (baixa reatividade). Esses gases existem em grande quantidade na atmosfera da Terra. Os Gases Nobres apresentam baixos pontos de fusão e ebulição, já que possuem forças de atração interatômicas muito fracas. Por conta disso, mesmo os que apresentam átomos mais pesados, em condições normais, são gasosos. Também não formam facilmente compostos químicos porque todos os gases possuem orbitais dos níveis de energia exteriores completos com elétrons. Apesar da dificuldade, os Gases Nobres podem formar compostos com outros metais. À medida que os átomos dos Gases Nobres crescem na extensão da série tornam-se ligeiramente mais reativos, então pode-se induzir o xenônio a formar compostos com o flúor, por exemplo.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B.",
                "Os Metais de Transição são definidos pela União Internacional de Química Pura e Aplicada (IUPAC) como \"Um elemento cujo átomo possui um subnível d incompleto ou que possa vir a formar cátions com um subnível d incompleto\". Os Lantanóides e Actinóides são considerados elementos de transição interna, porém alguns livros não os consideram metais de transição, já que possuem propriedades físicas e químicas que permitem separá-los em outros blocos. Os Metais de Tansição são duros e possuem alto ponto de fusão e ebulição. Por serem metais, conduzem bem o calor e a eletricidade. Podem formar ligas entre si, apresentam estados de oxidação variados (estados de oxidação mais amplos que os elementos de outros grupos) e normalmente formam compostos de coordenação com diferentes índices. O número de elétrons nos subníveis d é variável. Além disso, possuem potenciais negativos, ainda que muitos se tornem positivos e os complexos que geralmente se formam normalmente são coloridos ou apresentam paramagnetismo. Os Metais de Transição são muito empregados como catalisadores, tanto homogêneos como heterogêneos. Não há muitas peculiariadades entre as familias dentro da família B, a não ser pelos Lantanídeos e Actinídeos, porém, estão inclusos na Família 3B."};

string GDE[32] = {"1A", "2A", "3A", "4A", "5A", "6A", "7A", "8A", "3B", "4B", "5B", "6B", "7B", "8B", "8B", "8B", "1B", "2B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B", "3B"};

string de[32] = {"Termina-se a distribuição eletrônica em ns1.", "Termina-se a distribuição eletrônica em ns2.", "Termina-se a distribuição eletrônica em ns2 np1.", "Termina-se a distribuição eletrônica em ns2 np2.", "Termina-se a distribuição eletrônica em ns2 np3.", "Termina-se a distribuição eletrônica em ns2 np4.", "Termina-se a distribuição eletrônica em ns2 np5.", "Termina-se a distribuição eletrônica em ns2 np6.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d1.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d2.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d3.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d4.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d5.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d6.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d7.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d8.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d9.", "Termina-se a distribuição eletrônica em ns2 (n - 1)d10.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f1.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f2.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f3.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f4.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f5.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f6.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f7.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f8.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f9.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f10.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f11.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f12.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f13.", "Termina-se a distribuição eletrônica em ns2 (n - 2)f14."};

string P1[7] = {"1", "2", "3", "4", "5", "6", "7"};

vector<string> p1[32] = { {"Hidrogênio", "Hélio"}, {"Lítio", "Berílio", "Boro", "Carbono", "Nitrogênio", "Oxigênio", "Flúor", "Neônio"}, {"Sódio", "Magnésio", "Alumínio", "Silício", "Fósforo", "Enxofre", "Cloro", "Argônio"}, {"Potássio", "Cálcio", "Escândio", "Titânio", "Vanádio", "Crômio", "Manganês", "Ferro", "Cobalto", "Níquel", "Cobre", "Zinco", "Gálio", "Germânio", "Arsênio", "Selênio", "Bromo", "Criptônio"}, {"Rubídio", "Estrôncio", "Ítrio", "Zircônio", "Nióbio", "Molibdênio", "Tecnécio", "Rutênio", "Ródio", "Paládio", "Prata", "Cádmio",  "Índio", "Estanho", "Antimônio", "Telúrio", "Iodo", "Xenônio"}, {"Césio", "Bário", "Lantânio", "Cério", "Praseodímio", "Neodímio", "Promécio", "Samário", "Európio", "Gadolínio", "Térbio", "Disprósio", "Hôlmio", "Érbio", "Túlio", "Itérbio", "Lutécio", "Háfnio", "Tântalo", "Tungstênio", "Rênio", "Ósmio", "Irídio", "Platina", "Ouro", "Mercúrio", "Tálio", "Chumbo", "Bismuto", "Polônio", "Astato", "Radônio"}, {"Frâncio", "Rádio",  "Actínio", "Tório", "Protactínio", "Urânio", "Neptúnio", "Plutônio", "Amerício", "Cúrio", "Berquélio", "Califórnio", "Einstênio", "Férmio", "Mendelévio", "Nobélio", "Laurêncio", "Rutherfórdio", "Dúbnio", "Seabórgio", "Bóhrio", "Hássio", "Meitnério", "Darmstádtio", "Roentgênio", "Copernício",  "Nihônio", "Fleróvio", "Moscóvio", "Livermório", "Tennesso", "Oganessônio"} };

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

    cout << "Sobre o que você quer saber? Um elemento, uma família ou um período?[e/f/p]\n";
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
        cout <<  "O que você sabe sobre o elemento? O número atômico, o nome, a sigla ou a massa atômica?[NA/N/S/MA]\n";
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
            cout << "Digite um numero atômico, lembrando que há apenas entre 1 e 118!\n";
            cin >> NA;

            for(int i = 0; i < 118; i++){
                if(NA == NTP[i]){
                    ntp = (i + 1);
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    cout << "Você digitou o elemento " << tp << "(" << stp << "), que possui massa atômica igual a " << mtp << ", ";
                    vf = true;
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhum número atômico foi digitado! Lembre-se de que há apenas entre o 1 e o 118 atualmente.";
                    break;
                }
            }
            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "está localizado no " << p[x] << " e pertence à ";
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
                cout << "\n Deseja continuar descobrindo elementos pelos Números Atômicos, continuar descobrindo elementos, ou para de descobrir elementos? [NA/ E/ P] \n";
                cin >> opc3;
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "NA") goto inicio2A;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }
            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
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
            cout << "Qual o nome do elemento? Digite exatamente como na Tabela Periódica, mas sem acento!\n";

            cin >> N;

            for(int i = 0; i < 118; i++){
                if(N == TP[i]){
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    ntp = NTP[i];
                    vf = true;
                    cout << "O elemento " << tp << "(" << stp << ") possui " << ntp << " prótons, massa atômica igual a " << mtp << ", ";
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhum elemento químico foi digitado! Tente digitar com a primeira letra maiúscula e sem acento ou pesquisar o nome correto.";
                    break;
                }

            }

            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "está localizado no " << p[x] << " e pertence à ";
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
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "N") goto inicio2B;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }

            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
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
            cout << "Qual a sigla do elemento? Digite exatamente como na Tabela Periódica!\n";
            cin >> S;

            for(int i = 0; i < 118; i++){
                if(S == STP[i]){
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    ntp = NTP[i];
                    vf = true;
                    cout << "Você digitou o " << tp << ", que possui " << ntp << " prótons, massa atômica igual a " << mtp << ", ";
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhuma sigla de elemento químico foi digitado! Tente digitar com a primeira letra maiúscula e caso tenha duas letras, a segunda minúscula.";
                    break;
                }

            }

            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "está localizado no " << p[x] << " e pertence à ";
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
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "S") goto inicio2C;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }

            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
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
            cout << "Digite uma massa atômica, com os números inteiros e arredondados!\n";
            cin >> MA;
            for(int i = 0; i < 118; i++){
                if(MA == MTP[i]){
                    tp = TP[i];
                    stp = STP[i];
                    mtp = MTP[i];
                    ntp = NTP[i];
                    vf = true;
                    cout << "Você digitou o " << tp << "(" << stp << "), que possui " <<  ntp << " prótons, ";
                    break;
                }
                else if(i == (118 - 1) ){
                    cout << "Nenhuma massa atômica de um elemento químico foi digitado! Tente colocar o número arredondado e inteiro do digitado ou pesquisar.";
                    break;
                }
            }

            for(int x = 0; x < 7; x++){
                for(int y = 0; y < 32; y++){
                    if(ntp == P[x][y] && vf){
                        cout << "está localizado no " << p[x] << " e pertence à ";
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
                cout << "\n Deseja continuar descobrindo elementos pelas suas Massas Atômicas, continuar descobrindo elementos, ou para de descobrir elementos? [MA/ E/ P] \n";
                cin >> opc3;
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "MA") goto inicio2D;
                else if(opc3 == "E") goto inicio1A;
                goto inicio;
            }
            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ){
                goto inicio;
                }
            }
        }
        else{
            cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "Você quer limpar a tela atual?[s/n]\n";
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
        cout << "O que você deseja saber sobre as famílias? Características, elementos ou distribuição eletrônica[C/E/D]\n";
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
            cout << "As Famílias ou Grupos são as linhas da Tabela Períodica, e classificam os elementos quanto às características em comum! Não entendeu? Tente ver especificamente sobre uma Família: ";
            cout << "Qual Família você quer saber as características?[Exemplo: 1A/5B]\n";
            cin >> gn;
            for(int i = 0; i < 16; i++){
                if(gn == G[i]){
                    vf = true;
                    cout << "As características da Família " << gn << " são:\n" << g[i] << endl;
                    break;
                }
                else if(i == 15){
                    cout << "Nenhuma Família foi digitada! Lembre-se de há apenas de 1 a 8 das famílias A e B!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo Caracteristicas das Famílias, continuar descobrindo sobre as Famílias, ou para de descobrir sobre as Famílias? [C/ F/ P] \n";
                cin >> opc3;
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "C") goto inicio2E;
                else if(opc3 == "F") goto inicio1B;
                goto inicio;
            }
            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
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
            cout << "Qual Família você quer saber os elementos?[Exemplo: 1A/5B]\n";
            cin >> gn;
            for(int i = 0; i < 16; i++){
                if(gn == G[i]){
                    vf = true;
                    cout << "Os elementos da Família " << gn << " são:\n";
                    for(string j : FTP[i]) cout << j << "\n";
                    break;
                }
                else if(i == 15){
                    cout << "Nenhuma Família foi digitada! Lembre-se de há apenas de 1 a 8 das famílias A e B!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo Elementos das Famílias, continuar descobrindo sobre as Famílias, ou para de descobrir sobre as Famílias? [E/ F/ P] \n";
                cin >> opc3;
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "E") goto inicio2F;
                else if(opc3 == "F") goto inicio1B;
                goto inicio;
            }
            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
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
            cout << "Qual Família você quer saber a distribuição eletrônica?[Exemplo: 1A/5B]\n";
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
                        cout << "Na Família " << GDE[i] << " os elementos Escândio, Ítrio, Lutécio e Laurêncio " << de[8] << ", já os elementos do grupo dos Lantanídeos e dos Actínideos, os primeiros " << de[18] << ", os segundos " << de[19] << " e assim por diante até os últimos, que " << de[31];
                        de[8].insert(50, ".");
                        de[9].insert(50, ".");
                        de[10].insert(50, ".");
                        break;
                    }
                    else{
                        vf = true;
                        de[i].replace(0, 1, "t");
                        cout << "Na Família " << GDE[i] << " " << de[i];
                        break;
                    }
                }
                if(i == 31){
                    cout << "Nenhuma Família foi digitada! Lembre-se de há apenas de 1 a 8 das famílias A e B!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo Destribuição Eletrônica das Famílias, continuar descobrindo sobre as Famílias, ou para de descobrir sobre as Famílias? [D/ F/ P] \n";
                cin >> opc3;
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "D") goto inicio2G;
                else if(opc3 == "F") goto inicio1B;
                goto inicio;
            }
            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ) goto inicio;
            }
        }
        else{
            cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "Você quer limpar a tela atual?[s/n]\n";
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
        cout << "O que você deseja saber sobre os Períodos? Propriedades ou elementos[P/E]\n";
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
            cout << "Resumidamente, os Períodos são as colunas da Tabela periódica. Isso significa que os Períodos classificam os elementos quanto à sua camada de valência, ou seja, classifica quantas camadas o elemento possui! Por exemplo, o Ouro (Au), que pertence ao 5º Período da Tabela Períodica, tem 5 camadas: as camadas K, L, M, N e O. Até hoje em dia foram descobertas 7 camadas, porém, acredita-se que haja mais uma. Aliás, caso você ainda não tenha entendido, estamos falando da Tabela \"Periódica\". Essa ferramenta também nos ajuda a compreender por que o Sódio tem um raio atômico maior que o Lítio, por exemplo. O Sódio pertence ao 3°Período, ou seja, tem 3 camadas: As camadas K, L e M. O Lítio pertence ao 2ºPeríodo, ou seja, tem 2 camadas: As camadas K e L. Se o Sódio tem uma camada a mais que o Lítio, logo a sua esfera será maior, e portanto o seu raio atômico também! Essa é apenas mais uma das propriedades químicas dentre outras que os Períodos nos ajudam a identificar e portanto é muito útil e importante dominá-los\n";

            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar rever as Propriedades dos Períodos, continuar descobrindo sobre os Períodos, ou para de descobrir sobre os Períodos? [PO/ PE/ P] \n";
                cin >> opc3;
                cout << "Você quer limpar a tela atual?[s/n]\n \n";
                cin >> opc2;
                if(opc3 == "PO") goto inicio2H;
                else if(opc3 == "PE") goto inicio1C;
                goto inicio;
            }
            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
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
            cout << "De qual Período você quer saber os elementos? Exemplos: [1/6]\n";
            cin >> Periodo;
            for(int i = 0; i < 7; i++){
                if(Periodo == P1[i]){
                    vf = true;
                    for(string j : p1[i]) cout << j << " ";
                    break;
                }
                else if(i == 6){
                    cout << "Nenhum Período foi digitado! Lembre-se de há apenas de 7 Períodos!";
                    break;
                }
            }
            cout << "\nDeseja continuar descobrindo mais?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "\n Deseja continuar descobrindo os Elementos dos Períodos, continuar descobrindo sobre os Períodos, ou para de descobrir sobre os Períodos? [E/ Pe/ P] \n";
                cin >> opc3;
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                if(opc3 == "E") goto inicio2I;
                else if(opc3 == "Pe") goto inicio1C;
                goto inicio;
            }
            else{
                cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
                cin >> opc1;
                if( (opc1 == 'S') || (opc1 == 's') ) goto inicio;
            }
        }
        else{
            cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";

            cin >> opc1;

            if( (opc1 == 'S') || (opc1 == 's') ){
                cout << "Você quer limpar a tela atual?[s/n]\n";
                cin >> opc2;
                goto inicio;
            }
        }
    }

    else{
        cout << "Nenhuma das opções anteriores foi digitada! Deseja continuar?[s/n]\n";
        cin >> opc1;
        if( (opc1 == 'S') || (opc1 == 's') ){
            cout << "Você quer limpar a tela atual?[s/n]\n";
            cin >> opc2;
            goto inicio;
        }
    }

}
