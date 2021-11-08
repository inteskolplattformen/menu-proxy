#ifndef _SHOCO_INTERNAL
#error This header file is only to be included by 'shoco.c'.
#endif
#pragma once
/*
This file was generated by 'generate_compressor_model.py'
so don't edit this by hand. Also, do not include this file
anywhere. It is internal to 'shoco.c'. Include 'shoco.h'
if you want to use shoco in your project.
*/

#define MIN_CHR 32
#define MAX_CHR 196

static const char chrs_by_chr_id[32] = {
  ' ', 's', 'a', 't', 'r', 'e', 'o', 'i', 'k', '\xc3', 'l', 'd', 'm', 'n', 'g', 'p', 'c', 'h', 'u', '\xb6', 'f', 'b', ',', 'v', '\xa5', '\xa4', 'y', 'K', 'j', 'S', 'P', 'F'
};

static const int8_t chr_ids_by_chr[256] = {
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 31, -1, -1, -1, -1, 27, -1, -1, -1, -1, 30, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, 21, 16, 11, 5, 20, 14, 17, 7, 28, 8, 10, 12, 13, 6, 15, -1, 4, 1, 3, 18, 23, -1, -1, 26, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, 24, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

static const int8_t successor_ids_by_chr_id_and_chr_id[32][32] = {
  {-1, 2, -1, 12, 6, -1, 1, -1, 4, 13, 10, 14, 0, -1, 7, 3, 11, -1, -1, -1, 8, 5, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1},
  {0, 7, 5, 1, -1, 4, 6, 12, 3, 2, 15, -1, 9, -1, 11, 13, -1, -1, -1, -1, -1, 10, 8, -1, -1, -1, 14, -1, -1, -1, -1, -1},
  {2, 1, -1, 0, 3, -1, -1, -1, 5, -1, 4, 6, 10, 7, 8, 12, 11, -1, -1, -1, 14, -1, 9, 13, -1, -1, -1, -1, 15, -1, -1, -1},
  {2, 4, 0, 3, 9, 5, 6, 1, -1, 7, 13, -1, -1, -1, -1, 11, -1, -1, 15, -1, 8, 12, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {5, 7, 1, 9, 14, 8, 4, 3, -1, 0, -1, 15, -1, 11, 12, -1, -1, -1, 10, -1, -1, -1, 13, 2, -1, -1, 6, -1, -1, -1, -1, -1},
  {3, 5, -1, 2, 1, 15, -1, -1, 8, -1, 7, 0, 9, 4, 6, -1, -1, 10, -1, -1, -1, 12, 11, -1, -1, -1, -1, -1, 13, -1, -1, -1},
  {13, 3, -1, 1, 2, -1, -1, -1, 4, -1, 7, 14, 8, 5, 9, 6, 0, -1, 10, -1, 11, 15, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1},
  {3, 0, 12, 4, 15, 11, -1, -1, 6, -1, 2, 14, 7, 1, 8, 13, 9, -1, -1, -1, 5, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1},
  {3, 6, 2, 1, 10, 4, 0, 8, 14, 7, 5, -1, -1, -1, 12, 15, -1, -1, -1, -1, -1, 13, 11, -1, -1, -1, 9, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, 1, 2, -1, -1, -1, -1, -1, -1},
  {4, 6, 1, 5, -1, 8, 7, 0, 10, 3, 2, -1, 15, -1, 9, -1, -1, -1, 13, -1, -1, 11, 14, -1, -1, -1, 12, -1, -1, -1, -1, -1},
  {0, 3, 5, -1, 7, 2, 13, 4, 14, -1, 12, 1, -1, -1, 15, 11, -1, -1, 10, -1, 9, 8, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {7, 14, 1, 10, -1, 0, 2, 6, 9, 3, 13, -1, 11, -1, 15, 8, -1, -1, 12, -1, -1, 5, -1, -1, -1, -1, -1, -1, 4, -1, -1, -1},
  {3, 0, 4, 14, -1, 2, 7, 9, 6, 15, -1, 8, -1, 5, 1, -1, 11, -1, 12, -1, 13, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {1, 11, 5, -1, 0, 2, 3, 12, 13, 8, -1, -1, -1, 6, 4, -1, -1, 10, 7, -1, 14, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {11, 8, 1, -1, 6, 3, 0, 7, 14, 4, 10, -1, -1, -1, -1, 2, -1, 15, 5, -1, -1, -1, 12, -1, -1, -1, 9, -1, -1, -1, -1, -1},
  {10, -1, 6, 11, 7, 8, 2, 5, 1, 12, 9, -1, -1, -1, -1, -1, 3, 0, 4, -1, -1, -1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1},
  {0, 8, 3, 15, 13, 1, 6, 2, -1, 5, 12, -1, -1, 7, 10, -1, -1, -1, 4, -1, -1, -1, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {10, 4, -1, 15, 1, -1, 8, 13, 2, -1, 0, 5, 11, 3, 7, 12, 14, -1, -1, -1, 6, -1, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1},
  {14, 6, -1, 2, 3, -1, -1, 11, 4, -1, 5, 1, 8, 0, 7, 12, -1, -1, -1, -1, 13, 10, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1},
  {4, 14, 6, 5, 3, 7, 10, 2, -1, 0, 8, -1, -1, -1, -1, -1, -1, -1, 11, -1, 1, -1, 9, -1, -1, -1, 12, -1, -1, -1, -1, -1},
  {11, 9, 2, -1, 1, 4, 6, 3, -1, 5, 7, -1, -1, -1, 10, 15, -1, -1, 0, -1, -1, 8, -1, -1, -1, -1, 13, -1, 12, -1, -1, -1},
  {0, 4, -1, 15, 6, -1, -1, -1, 8, 12, 11, -1, 3, -1, 2, 1, 14, -1, -1, -1, 13, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {2, 5, 1, 10, 4, 0, 12, 3, -1, 7, 13, -1, -1, 9, 8, -1, -1, -1, -1, -1, -1, 11, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {2, 0, -1, 12, 3, -1, 15, -1, 7, 10, 1, 4, 11, 5, 9, -1, -1, -1, -1, -1, 13, 8, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1},
  {14, 5, -1, 6, 0, -1, -1, -1, 11, -1, 10, 2, 4, 1, 3, 8, 7, -1, -1, -1, 13, 15, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1},
  {7, 4, 13, 0, 12, -1, 8, -1, -1, -1, 2, 6, -1, 5, 10, 15, 1, -1, -1, -1, 3, 9, 11, 14, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, 4, -1, 3, 5, 2, 7, -1, 0, 8, -1, -1, -1, -1, -1, -1, -1, 9, -1, -1, -1, -1, 12, -1, -1, 1, -1, -1, -1, -1, -1},
  {5, 4, 1, -1, -1, 6, 2, 9, -1, 3, -1, -1, -1, -1, 12, 13, -1, -1, 0, -1, 10, -1, 11, 7, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, 7, 0, -1, 6, 2, 14, 3, 10, 13, -1, 5, -1, -1, 1, 11, 15, -1, -1, -1, -1, -1, 9, -1, -1, -1, 8, -1, -1, -1, -1},
  {-1, -1, 0, -1, 5, 3, 1, 6, -1, 7, 8, -1, -1, -1, -1, -1, -1, 13, 4, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1},
  {15, -1, 2, -1, 1, 6, 7, 0, -1, 3, 4, -1, -1, -1, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1, 9, -1, -1, -1, -1, 11}
};

static const int8_t chrs_by_chr_and_successor_id[MAX_CHR - MIN_CHR][16] = {
  {'m', 'o', 's', 'p', 'k', 'b', 'r', 'g', 'f', 'v', 'l', 'c', 't', '\xc3', 'd', '&'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {' ', 'p', 'g', 'm', 's', 'b', 'r', '1', 'k', '2', '3', 'l', '\xc3', 'f', 'c', 't'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'i', 'r', 'a', '\xc3', 'l', ':', 'e', 'o', 'R', 'y', 'I', 'F', 'T', 'u', 'E', ' '},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\xc3', 'y', 'o', 'r', 'a', 'e', 'O', 'i', 'l', 'u', 'A', 'E', 'v', 'R', 'T', '-'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'a', 'o', 'y', 'e', 'u', 'r', 'i', '\xc3', 'l', 'I', 'A', 'O', 'L', 'h', 'C', ')'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'t', 'p', 'o', 'k', 'T', 'm', 'e', 'a', 'K', 'v', '\xc3', 'c', 'C', 'l', 'i', 'h'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'t', 's', ' ', 'r', 'l', 'k', 'd', 'n', 'g', ',', 'm', 'c', 'p', 'v', 'f', 'j'},
  {'u', 'r', 'a', 'i', 'e', '\xc3', 'o', 'l', 'b', 's', 'g', ' ', 'j', 'y', 'q', 'p'},
  {'h', 'k', 'o', 'c', 'u', 'i', 'a', 'r', 'e', 'l', ' ', 't', '\xc3', '\'', 'y', '\xc2'},
  {' ', 'd', 'e', 's', 'i', 'a', ',', 'r', 'b', 'f', 'u', 'p', 'l', 'o', 'k', 'g'},
  {'d', 'r', 't', ' ', 'n', 's', 'g', 'l', 'k', 'm', 'h', ',', 'b', 'j', 'x', 'e'},
  {'\xc3', 'f', 'i', 'r', ' ', 't', 'a', 'e', 'l', ',', 'o', 'u', 'y', ')', 's', '/'},
  {'r', ' ', 'e', 'o', 'g', 'a', 'n', 'u', '\xc3', ',', 'h', 's', 'i', 'k', 'f', '.'},
  {' ', 'e', 'i', 'a', 'u', '\xc3', 'o', 'n', 's', ':', 'g', ',', 'l', 'r', '.', 't'},
  {'s', 'n', 'l', ' ', 't', 'f', 'k', 'm', 'g', 'c', 'v', 'e', 'a', 'p', 'd', 'r'},
  {'u', 'a', 'o', '\xc3', 's', ' ', 'e', 'v', '!', 'i', 'f', ',', 'g', 'p', '.', '*'},
  {'o', 't', 'a', ' ', 'e', 'l', 's', '\xc3', 'i', 'y', 'r', ',', 'g', 'b', 'k', 'p'},
  {'i', 'a', 'l', '\xc3', ' ', 't', 's', 'o', 'e', 'g', 'k', 'b', 'y', 'u', ',', 'm'},
  {'e', 'a', 'o', '\xc3', 'j', 'b', 'i', ' ', 'p', 'k', 't', 'm', 'u', 'l', 's', 'g'},
  {'s', 'g', 'e', ' ', 'a', 'n', 'k', 'o', 'd', 'i', 'b', 'c', 'u', 'f', 't', '\xc3'},
  {'c', 't', 'r', 's', 'k', 'n', 'p', 'l', 'm', 'g', 'u', 'f', 'j', ' ', 'd', 'b'},
  {'o', 'a', 'p', 'e', '\xc3', 'u', 'r', 'i', 's', 'y', 'l', ' ', ',', '.', 'k', 'h'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\xc3', 'a', 'v', 'i', 'o', ' ', 'y', 's', 'e', 't', 'u', 'n', 'g', ',', 'r', 'd'},
  {' ', 't', '\xc3', 'k', 'e', 'a', 'o', 's', ',', 'm', 'b', 'g', 'i', 'p', 'y', 'l'},
  {'a', 'i', ' ', 't', 's', 'e', 'o', '\xc3', 'f', 'r', ',', 'p', 'b', 'l', 'z', 'u'},
  {'l', 'r', 'k', 'n', 's', 'd', 'f', 'g', 'o', 'v', ' ', 'm', 'p', 'i', 'c', 't'},
  {'e', 'a', ' ', 'i', 'r', 's', ',', '\xc3', 'g', 'n', 't', 'b', 'o', 'l', ')', '/'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'t', 'c', 'l', 'f', 's', 'n', 'd', ' ', 'o', 'b', 'g', ',', 'r', 'a', 'v', 'p'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'r', 'n', 'd', 'g', 'm', 's', 't', 'c', 'p', 'v', 'l', 'k', 'x', 'f', ' ', 'b'},
  {'s', 'l', ' ', 'r', 'd', 'n', 'v', 'k', 'b', 'g', '\xc3', 'm', 't', 'f', '\xa6', 'o'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'n', 'd', 't', 'r', 'k', 'l', 's', 'g', 'm', 'v', 'b', 'i', 'p', 'f', ' ', '.'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00'},
  {'\xb6', '\xa5', '\xa4', '\xa9', '\x84', '\xa8', '\x96', '\x85', '\xa1', '\xbc', '\xa0', '\xaa', '\x89', '\xba', '\xad', '\xae'}
};

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4324)    // structure was padded due to __declspec(align())
#endif

typedef struct Pack {
  const uint32_t word;
  const unsigned int bytes_packed;
  const unsigned int bytes_unpacked;
  const unsigned int offsets[8];
  const int16_t _ALIGNED masks[8];
  const char header_mask;
  const char header;
} Pack;

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#define PACK_COUNT 3
#define MAX_SUCCESSOR_N 8

static const Pack packs[PACK_COUNT] = {
  { 0x80000000, 1, 2, { 26, 24, 24, 24, 24, 24, 24 }, { 15, 3, 0, 0, 0, 0, 0 }, 0xc0, 0x80 },
  { 0xc0000000, 2, 4, { 25, 21, 18, 16, 16, 16, 16 }, { 15, 15, 7, 3, 0, 0, 0 }, 0xe0, 0xc0 },
  { 0xe0000000, 4, 8, { 24, 20, 16, 12, 9, 6, 3, 0 }, { 15, 15, 15, 15, 7, 7, 7, 7 }, 0xf0, 0xe0 }
};
