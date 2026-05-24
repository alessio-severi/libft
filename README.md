![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen)

*This project has been created as part of the 42 curriculum by aseveri.*

## Description

Libft è una libreria C che reimplementa funzioni standard della libc e aggiunge funzioni di utilità per la manipolazione di stringhe, memoria e liste concatenate. L'obiettivo è comprendere il funzionamento interno di queste funzioni implementandole da zero, senza dipendenze esterne. La libreria viene compilata come archivio statico `libft.a` e può essere riutilizzata nei progetti successivi del cursus 42.

## Instructions

```bash
make        # compila la libreria libft.a
make clean  # rimuove i file oggetto (.o)
make fclean # rimuove i file oggetto e libft.a
make re     # esegue fclean e ricompila da zero
```

Per usare la libreria in un progetto:
```bash
#include "libft.h"
# compilare con:
cc -Wall -Wextra -Werror main.c -L. -lft
```

## Library

La libreria è divisa in tre parti:

### Parte 1 — Reimplementazione funzioni libc

Funzioni che replicano il comportamento delle originali della libc, prefissate con `ft_`:

| Funzione | Descrizione |
|---|---|
| `ft_isalpha` | Controlla se il carattere è alfabetico. Restituisce 1 se lo è, 0 altrimenti. |
| `ft_isdigit` | Controlla se il carattere è una cifra decimale. Restituisce 1 se lo è, 0 altrimenti. |
| `ft_isalnum` | Controlla se il carattere è alfanumerico. Restituisce 1 se lo è, 0 altrimenti. |
| `ft_isascii` | Controlla se il carattere rientra nel set ASCII (0-127). Restituisce 1 se lo è, 0 altrimenti. |
| `ft_isprint` | Controlla se il carattere è stampabile. Restituisce 1 se lo è, 0 altrimenti. |
| `ft_strlen` | Restituisce la lunghezza di una stringa. |
| `ft_memset` | Riempie un'area di memoria con un byte specificato. |
| `ft_bzero` | Azzera un'area di memoria. |
| `ft_memcpy` | Copia n byte da una zona di memoria a un'altra (non gestisce overlap). |
| `ft_memmove` | Copia n byte gestendo correttamente le sovrapposizioni di memoria. |
| `ft_strlcpy` | Copia una stringa con garanzia di terminazione null, restituisce la lunghezza della sorgente. |
| `ft_strlcat` | Concatena `src` a `dst` entro `dstsize` byte con garanzia di terminazione  `'\0'`. Restituisce `dstsize + src_len` se `dst` non rientra in `dstsize` byte; altrimenti `dst_len + src_len`, utile per rilevare troncamenti su `src` in `dst`. |
| `ft_toupper` | Converte un carattere minuscolo in maiuscolo. |
| `ft_tolower` | Converte un carattere maiuscolo in minuscolo. |
| `ft_strchr` | Cerca la prima occorrenza di un carattere in una stringa, restituisce un `char *` alla posizione trovata, `NULL` se non presente. |
| `ft_strrchr` | Cerca l'ultima occorrenza di un carattere in una stringa, restituisce un `char *` alla posizione trovata, `NULL` se non presente. |
| `ft_strncmp` | Confronta al massimo i primi n caratteri di due stringhe. |
| `ft_memchr` | Cerca la prima occorrenza di un byte in un'area di memoria, restituisce un `void *` alla posizione trovata, `NULL` se non presente. |
| `ft_memcmp` | Confronta due aree di memoria byte per byte. |
| `ft_strnstr` | Cerca la sottostringa `needle` in `haystack` entro i primi `len` caratteri. Restituisce un `char *` alla prima occorrenza trovata, `haystack` stesso se `needle` è vuoto, `NULL` se non trovata o `len` è 0. |
| `ft_atoi` | Converte una stringa in intero. |
| `ft_calloc` | Alloca memoria inizializzata a zero. Gestisce il caso nmemb o size uguale a 0. |
| `ft_strdup` | Duplica una stringa allocando la memoria necessaria. |

### Parte 2 — Funzioni aggiuntive

Funzioni non presenti nella libc o presenti in forma diversa:

| Funzione | Descrizione |
|---|---|
| `ft_substr` | Alloca e restituisce una sottostringa di `s` a partire da `start` di lunghezza massima `len`. |
| `ft_strjoin` | Alloca e restituisce la concatenazione di due stringhe `s1` e `s2`. |
| `ft_strtrim` | Alloca e restituisce una copia di `s1` senza i caratteri del set `set` agli estremi. |
| `ft_split` | Divide una stringa usando un carattere delimitatore e restituisce un array di stringhe allocate. |
| `ft_itoa` | Converte un intero (inclusi negativi) in stringa allocata dinamicamente. |
| `ft_strmapi` | Applica una funzione a ogni carattere di una stringa creando una nuova stringa dei risultati. |
| `ft_striteri` | Applica una funzione a ogni carattere di una stringa passando l'indice e l'indirizzo del carattere. |
| `ft_putchar_fd` | Scrive un carattere sul file descriptor specificato. |
| `ft_putstr_fd` | Scrive una stringa sul file descriptor specificato. |
| `ft_putendl_fd` | Scrive una stringa seguita da newline sul file descriptor specificato. |
| `ft_putnbr_fd` | Scrive un intero sul file descriptor specificato. |

### Parte 3 — Liste concatenate

Funzioni per la manipolazione di liste concatenate tramite la `struct s_list`, accessibile tramite il typedef `t_list`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

| Funzione | Descrizione |
|---|---|
| `ft_lstnew` | Alloca e restituisce un nuovo nodo con `content` inizializzato e `next` a `NULL`. |
| `ft_lstadd_front` | Aggiunge un nodo all'inizio della lista. |
| `ft_lstsize` | Conta e restituisce il numero di nodi nella lista. |
| `ft_lstlast` | Restituisce l'ultimo nodo della lista. |
| `ft_lstadd_back` | Aggiunge un nodo alla fine della lista. |
| `ft_lstdelone` | Libera il contenuto di un nodo con la funzione `del` e libera il nodo stesso. |
| `ft_lstclear` | Elimina e libera un nodo e tutti i suoi successori, imposta il puntatore a `NULL`. |
| `ft_lstiter` | Itera sulla lista applicando la funzione `f` al contenuto di ogni nodo. |
| `ft_lstmap` | Itera sulla lista applicando `f` a ogni nodo e crea una nuova lista con i risultati. La funzione `del` viene utilizzata per eliminare il contenuto di un nodo, se necessario.|

## Resources

- [Linux Man Pages](https://man7.org/linux/man-pages/) — riferimento principale per il comportamento atteso di ogni funzione
- [42 Norm](https://github.com/42School/norminette) — norminette per il rispetto delle regole di stile

## Copyright and licensing

Copyright (C) 2026 Alessio Severi

Il codice sorgente contenuto in questo repository è stato scritto da me. Il subject originale appartiene a 42 Roma Elis.

Questo codice sorgente è distribuito sotto la licenza GNU General Public License v3.0. Per maggiori dettagli, consultare il file LICENSE.
