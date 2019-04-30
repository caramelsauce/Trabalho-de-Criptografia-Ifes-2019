Trabalho Cripitografia em C Prog2 Ifes

O algoritimo lê uma string e printa ela criptografada e em seguida printa ela descriptografada

REGRAS DE CRIPTOGRAFIA:

Língua do AU: cada vogal (a, e, i, o, u) deve ser trocada pela substring AU obedecendo o seguinte esquema: a: AU e: AUAU i: AUAUAU o: AUAUAUAU u: AUAUAUAUAU

Enxerto EI: conta o número de vezes (n) que o caracter ‘x’ aparece na substring. Em seguida acrescenta a substring “EI” n vezes no inicio e no final da substring.

Inversão total: a substring é redefinida sendo escrita de trás para frente. Ex: “abcd” será transformado em “dcba”.

Inversão 2 a 2: promove a troca entre pares de caracteres.

Junção: primeiro é aplicado o Língua do AU, depois o Enxerto EI, em seguida a Inversão total e finalmente a Inversão 2 a 2.

A ordem de aplicação dos padrões de criptografia nas substrings da string principal é: Língua do AU, Enxerto EI, Inversão Total, Inversão 2 a 2 e Junção, em seguida começa-se o processo novamente.
