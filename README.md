# Hash
## EKSPERIMENTINĖ ANALIZĖ
1.
1.1  Testiniai failai ***1a.txt*** ir ***1b.txt*** sudaryti iš vieno, tačiau skirtingo simbolio.
| Input| Hash |
| --- | --- |
| `a` | 5273f64633c65c92818ef72bf19445c4cbc8fe2548d47acb7d85b10d52fc11ff |
| `b` | 4b2d06b62a98ac6298d007dbe8cab534d2960ed5518a8a3b64db41fd4ba2e10f |

1.2 Testiniai failai ***10000a.txt*** ir ***10000b.txt*** sudaryti iš 10 000 skirtingų simbolių.
| Input | Hash |
| --- | --- |
| `6ry...EQW` | 05cdc49264786e46d630c5ffa62a77109c76ccf11f6a481f2a3b83d90542232b |
| `vuX...dE5` | 9411e669f5a44cbd47ece70437f655eb0daaee0a8eb66ae4bbe7a122949e01d0 |

1.3 Testiniai failai ***10000c.txt*** ir ***10000d.txt*** sudaryti iš 10 000, tačiau skiriasi tik vienu simboliu.
| Input| Hash |
| --- | --- |
| `htb...i...ezB` | 1076658571c3cf51c38b64e8b391d60789cd6de60ad1e9083f8022ce10f9823c |
| `htb...P...ezB` | 10765c8571c3f651c38b5de8b391ef0789cd54e60ad1d0083f801bce10f9bb3c |

1.4 Iš tuščio failo ***empty.txt*** hash'as nesugeneruojamas.

2. Nepriklausomai nuo Input'o, Output'ai visada yra vienodo dydžio, o to paties failo hash'as yra tas pats.

3. Hash'uojamų eilučių iš failo ***konstitucija.txt*** laikų analizė:

| Eilučių skaičius | Vidutinis laikas |
|------------------|------------------|
| 1                | 0,00106830       |
| 2                | 0,00201534       |
| 4                | 0,00328946       |
| 8                | 0,00611086       |
| 16               | 0,01355982       |
| 32               | 0,02609470       |
| 64               | 0,05234570       |
| 128              | 0,11965080       |
| 256              | 0,25259840       |
| 512              | 0,54868560       |

![image](https://user-images.githubusercontent.com/92882227/193467755-3ae47e91-f756-4768-8238-1bb2495f7569.png)

Dvigubai padidėjus input'ų skaičiui maždaug dvigubai padidėja ir laikas, funkcijos sudėtingumas O(n).

4. Sugeneruotas 100 000 skirtingų string'ų porų failas ***t.txt***: 25 000 porų, kurių ilgis 10 simbolių, 25 000 porų, kurių ilgis -
100, 25 000 poros - 500, ir 25 000 poros, kurių ilgis - 1000 simbolių.

5. Suhash'avus 4 žingsnyje sugeneruotas 100 000 string'ų porų gauta **0 kolizijų**.
