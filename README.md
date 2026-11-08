# ASCII Text Analyzer

An ASCII text metrics analyzer written in modern C23.

---

## Upcoming Features

- **Dynamic Buffer Allocation:** Resizable memory management using `malloc` and `realloc` with geometric growth to handle arbitrary input lengths (*N* characters).
- **Text Metrics:**
  - Total characters count (with and without whitespace).
  - Whitespace count (spaces, tabs, newlines).
  - Word count.
  - Vowel and consonant counts for standard ASCII characters.
- **Multi-line Stream Handling:** Full support for pasted multiline text terminating cleanly on stream completion (`EOF` / `Ctrl + D`).
- **Memory Safety & Portability:** Strict standard library reliance (`<ctype.h>`, `<stdlib.h>`), explicit memory deallocation (`free`), and zero undefined behavior on unexpected byte values.

---

## Requirements

- C23 compliant compiler (GCC 14+, Clang 18+)
- CMake 4.2+