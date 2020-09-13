#include <lvgl.h>

/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifndef ROBOTO_CONDENSED_REGULAR_18
#define ROBOTO_CONDENSED_REGULAR_18 1
#endif

#if ROBOTO_CONDENSED_REGULAR_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+21 "!" */
    0xff, 0xff, 0xc3, 0xc0,

    /* U+22 "\"" */
    0xb6, 0xd0,

    /* U+23 "#" */
    0x13, 0x12, 0x32, 0xff, 0x26, 0x26, 0x24, 0x24,
    0xff, 0x64, 0x4c, 0x4c, 0x48,

    /* U+24 "$" */
    0x10, 0x21, 0xf6, 0x6c, 0x78, 0xf0, 0x38, 0x7c,
    0x38, 0x1e, 0x3c, 0x7d, 0xdf, 0x8, 0x10,

    /* U+25 "%" */
    0x60, 0x24, 0x9, 0x32, 0x48, 0x96, 0x19, 0x0,
    0xc0, 0x2e, 0x14, 0x4d, 0x12, 0x44, 0x91, 0x3,
    0x80,

    /* U+26 "&" */
    0x3c, 0x33, 0x19, 0x8c, 0xc6, 0xc1, 0xc0, 0xe0,
    0xd2, 0xcd, 0x63, 0xb1, 0x8c, 0xe3, 0xd0,

    /* U+27 "'" */
    0xf0,

    /* U+28 "(" */
    0x1, 0x26, 0x64, 0xcc, 0xcc, 0xcc, 0xcc, 0x66,
    0x23, 0x10,

    /* U+29 ")" */
    0x8, 0xc6, 0x62, 0x33, 0x33, 0x33, 0x33, 0x66,
    0x4c, 0x80,

    /* U+2A "*" */
    0x18, 0x18, 0x99, 0xff, 0x38, 0x3c, 0x66, 0x0,

    /* U+2B "+" */
    0x18, 0x30, 0x60, 0xcf, 0xe3, 0x6, 0xc, 0x18,

    /* U+2C "," */
    0x6d, 0xe0,

    /* U+2D "-" */
    0xf0,

    /* U+2E "." */
    0xf0,

    /* U+2F "/" */
    0x4, 0x30, 0x82, 0x18, 0x41, 0xc, 0x20, 0x86,
    0x18, 0x41, 0xc, 0x0,

    /* U+30 "0" */
    0x38, 0xdb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1b, 0x63, 0x80,

    /* U+31 "1" */
    0x1b, 0xf6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x80,

    /* U+32 "2" */
    0x3c, 0xdb, 0x1e, 0x30, 0x61, 0xc3, 0xe, 0x18,
    0x61, 0x87, 0xf, 0xe0,

    /* U+33 "3" */
    0x38, 0xdb, 0x18, 0x30, 0x61, 0x8e, 0x6, 0x6,
    0xf, 0x1f, 0x67, 0x80,

    /* U+34 "4" */
    0x6, 0xe, 0xe, 0x1e, 0x16, 0x36, 0x66, 0x66,
    0xc6, 0xff, 0x6, 0x6, 0x6,

    /* U+35 "5" */
    0x7f, 0x83, 0x6, 0xf, 0x99, 0x81, 0x83, 0x7,
    0xe, 0x1e, 0x67, 0x80,

    /* U+36 "6" */
    0x18, 0xc1, 0x6, 0xf, 0xdc, 0xb1, 0xe3, 0xc7,
    0x8f, 0x1b, 0x23, 0x80,

    /* U+37 "7" */
    0xfe, 0xc, 0x10, 0x20, 0xc1, 0x2, 0xc, 0x10,
    0x60, 0xc1, 0x6, 0x0,

    /* U+38 "8" */
    0x38, 0xdb, 0x1e, 0x3c, 0x6d, 0x8e, 0x36, 0xc7,
    0x8f, 0x1b, 0x63, 0x80,

    /* U+39 "9" */
    0x38, 0xdb, 0x1e, 0x3c, 0x78, 0xdb, 0xbf, 0x6,
    0xc, 0x30, 0x63, 0x0,

    /* U+3A ":" */
    0xf0, 0x0, 0xf0,

    /* U+3B ";" */
    0x6c, 0x0, 0x0, 0x6d, 0xa0,

    /* U+3C "<" */
    0x4, 0x73, 0xb8, 0xc1, 0xc1, 0xc1,

    /* U+3D "=" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+3E ">" */
    0x81, 0xc0, 0xe0, 0x70, 0xe7, 0x38, 0x40,

    /* U+3F "?" */
    0x7b, 0x3c, 0xc3, 0xc, 0x61, 0x8c, 0x30, 0x0,
    0xc, 0x30,

    /* U+40 "@" */
    0xf, 0x81, 0xc, 0x20, 0x24, 0x2, 0x47, 0x18,
    0x99, 0x89, 0x19, 0x91, 0x99, 0x19, 0x11, 0x91,
    0x19, 0xb2, 0xcc, 0xc4, 0x0, 0x60, 0x3, 0x0,
    0x1f, 0x0,

    /* U+41 "A" */
    0xc, 0x3, 0x0, 0xe0, 0x68, 0x1a, 0x4, 0xc3,
    0x30, 0xc4, 0x3f, 0x98, 0x66, 0x9, 0x3, 0x40,
    0xc0,

    /* U+42 "B" */
    0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xcc, 0xf8, 0xc6,
    0xc3, 0xc3, 0xc3, 0xc6, 0xfc,

    /* U+43 "C" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+44 "D" */
    0xf8, 0xc6, 0xc2, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc2, 0xc6, 0xf8,

    /* U+45 "E" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x3f, 0xe0, 0xc1,
    0x83, 0x6, 0xf, 0xe0,

    /* U+46 "F" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x3f, 0x60, 0xc1,
    0x83, 0x6, 0xc, 0x0,

    /* U+47 "G" */
    0x3c, 0x66, 0xc3, 0xc0, 0xc0, 0xc0, 0xcf, 0xc3,
    0xc3, 0xc3, 0xc3, 0x63, 0x3e,

    /* U+48 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0xff,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x18,

    /* U+49 "I" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+4A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0xf, 0x1f, 0x67, 0x80,

    /* U+4B "K" */
    0xc3, 0x63, 0x31, 0x99, 0x8d, 0x86, 0x83, 0xe1,
    0xd0, 0xcc, 0x63, 0x31, 0x98, 0x6c, 0x10,

    /* U+4C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x6, 0xf, 0xe0,

    /* U+4D "M" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7f, 0x1f, 0xa2,
    0xf4, 0x5e, 0xdb, 0xca, 0x79, 0x4f, 0x29, 0xe2,
    0x3c, 0x46,

    /* U+4E "N" */
    0xc1, 0xf0, 0xf8, 0x7e, 0x3d, 0x1e, 0xcf, 0x27,
    0x9b, 0xc5, 0xe3, 0xf0, 0xf8, 0x7c, 0x18,

    /* U+4F "O" */
    0x3e, 0x31, 0x90, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x4c, 0x63, 0xe0,

    /* U+50 "P" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+51 "Q" */
    0x3e, 0x31, 0x90, 0x58, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0, 0x18,
    0x6,

    /* U+52 "R" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xcc,
    0xc4, 0xc6, 0xc6, 0xc3, 0xc3,

    /* U+53 "S" */
    0x3c, 0x66, 0xc3, 0xc3, 0xe0, 0x70, 0x3e, 0xe,
    0x3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+54 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+55 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+56 "V" */
    0x40, 0xd8, 0x26, 0x19, 0x86, 0x21, 0xc, 0xc3,
    0x30, 0x48, 0x12, 0x7, 0x80, 0xe0, 0x30, 0xc,
    0x0,

    /* U+57 "W" */
    0x86, 0x1c, 0x63, 0xc6, 0x3c, 0xe3, 0x4f, 0x24,
    0x92, 0x49, 0x66, 0x96, 0x79, 0x67, 0x1c, 0x30,
    0xc3, 0xc, 0x30, 0xc0,

    /* U+58 "X" */
    0xc3, 0xc2, 0x66, 0x64, 0x3c, 0x18, 0x18, 0x38,
    0x3c, 0x66, 0x66, 0xc3, 0xc3,

    /* U+59 "Y" */
    0x40, 0x98, 0x66, 0x18, 0xcc, 0x33, 0x7, 0x81,
    0xe0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x0,

    /* U+5A "Z" */
    0xff, 0x3, 0x6, 0x6, 0xc, 0x8, 0x18, 0x30,
    0x30, 0x60, 0x60, 0xc0, 0xff,

    /* U+5B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x6d, 0xb6, 0xdc,

    /* U+5C "\\" */
    0x41, 0x6, 0x8, 0x20, 0xc3, 0x4, 0x18, 0x60,
    0x82, 0xc, 0x10, 0x40,

    /* U+5D "]" */
    0xed, 0xb6, 0xdb, 0x6d, 0xb6, 0xdb, 0x7c,

    /* U+5E "^" */
    0x23, 0x1c, 0xad, 0x6e, 0x60,

    /* U+5F "_" */
    0xfe,

    /* U+61 "a" */
    0x3d, 0x8f, 0x18, 0x33, 0xfc, 0xf1, 0xe3, 0xce,
    0xfc,

    /* U+62 "b" */
    0xc1, 0x83, 0x6, 0xf, 0xd9, 0xb1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0xdf, 0x80,

    /* U+63 "c" */
    0x3c, 0xcf, 0x1e, 0xc, 0x18, 0x30, 0x63, 0x66,
    0x78,

    /* U+64 "d" */
    0x6, 0xc, 0x18, 0x37, 0xec, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x36, 0x6f, 0xc0,

    /* U+65 "e" */
    0x3c, 0xcb, 0x1e, 0x3f, 0xf8, 0x30, 0x60, 0x66,
    0x78,

    /* U+66 "f" */
    0x3b, 0x18, 0xcf, 0x31, 0x8c, 0x63, 0x18, 0xc6,
    0x30,

    /* U+67 "g" */
    0x7e, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x66,
    0xfc, 0x18, 0x34, 0xcf, 0x0,

    /* U+68 "h" */
    0xc1, 0x83, 0x6, 0xf, 0xdc, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xc0,

    /* U+69 "i" */
    0xf3, 0xff, 0xff, 0xc0,

    /* U+6A "j" */
    0x6c, 0x36, 0xdb, 0x6d, 0xb6, 0xdb, 0xc0,

    /* U+6B "k" */
    0xc1, 0x83, 0x6, 0xc, 0x59, 0xb6, 0x68, 0xf1,
    0xf3, 0x66, 0x6c, 0x58, 0xc0,

    /* U+6C "l" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+6D "m" */
    0xfd, 0xec, 0x73, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63,

    /* U+6E "n" */
    0xfd, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+6F "o" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+70 "p" */
    0xfd, 0x9b, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xcd,
    0xfb, 0x6, 0xc, 0x18, 0x0,

    /* U+71 "q" */
    0x7e, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x66,
    0xfc, 0x18, 0x30, 0x60, 0xc0,

    /* U+72 "r" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc,

    /* U+73 "s" */
    0x7d, 0x8f, 0x1f, 0x7, 0x87, 0x83, 0xe3, 0xc6,
    0xf8,

    /* U+74 "t" */
    0x66, 0x6f, 0x66, 0x66, 0x66, 0x66, 0x30,

    /* U+75 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xce,
    0xfc,

    /* U+76 "v" */
    0x42, 0x8d, 0x9b, 0x22, 0x45, 0x8e, 0xc, 0x18,
    0x30,

    /* U+77 "w" */
    0x46, 0x28, 0xcd, 0x99, 0xb7, 0x26, 0xb4, 0x52,
    0x8a, 0x71, 0xce, 0x31, 0x82, 0x10,

    /* U+78 "x" */
    0x66, 0xcc, 0xb1, 0xe1, 0x83, 0xf, 0x16, 0x66,
    0x8c,

    /* U+79 "y" */
    0x87, 0x3c, 0xf2, 0x49, 0xe7, 0x8c, 0x30, 0xc3,
    0x8, 0x63, 0x0,

    /* U+7A "z" */
    0xfc, 0x31, 0x86, 0x30, 0xc6, 0x10, 0xc3, 0xf0,

    /* U+7B "{" */
    0x8, 0xcc, 0x63, 0x18, 0xc6, 0xc1, 0x8c, 0x63,
    0x18, 0xc3, 0x8,

    /* U+7D "}" */
    0x8c, 0x66, 0x66, 0x66, 0x12, 0x66, 0x66, 0x6c,
    0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 71, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 92, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 6, .adv_w = 158, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 142, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 34, .adv_w = 182, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 157, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 50, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 67, .adv_w = 90, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 77, .adv_w = 92, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 87, .adv_w = 124, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 95, .adv_w = 143, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 103, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 105, .adv_w = 71, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 106, .adv_w = 76, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 107, .box_w = 6, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 119, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 142, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 142, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 67, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 58, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 245, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 251, .adv_w = 138, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 255, .adv_w = 132, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 262, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 221, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 298, .adv_w = 166, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 157, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 163, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 164, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 143, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 138, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 170, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 179, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 72, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 139, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 157, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 137, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 218, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 178, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 173, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 527, .adv_w = 153, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 149, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 150, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 162, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 579, .adv_w = 161, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 219, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 159, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 629, .adv_w = 151, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 646, .adv_w = 150, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 72, .box_w = 3, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 666, .adv_w = 106, .box_w = 6, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 678, .adv_w = 72, .box_w = 3, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 685, .adv_w = 107, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 690, .adv_w = 117, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 691, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 700, .adv_w = 142, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 713, .adv_w = 133, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 722, .adv_w = 143, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 135, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 744, .adv_w = 91, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 753, .adv_w = 142, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 766, .adv_w = 139, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 779, .adv_w = 66, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 783, .adv_w = 64, .box_w = 3, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 790, .adv_w = 130, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 66, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 807, .adv_w = 217, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 841, .adv_w = 142, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 854, .adv_w = 144, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 867, .adv_w = 88, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 872, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 85, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 123, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 906, .adv_w = 187, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 920, .adv_w = 126, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 929, .adv_w = 120, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 940, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 948, .adv_w = 88, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 959, .adv_w = 88, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 33, .range_length = 63, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 27, .glyph_id_start = 64,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 125, .range_length = 1, .glyph_id_start = 91,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    2, 2,
    2, 7,
    2, 33,
    2, 64,
    2, 66,
    2, 67,
    2, 68,
    2, 70,
    2, 76,
    2, 77,
    2, 78,
    2, 79,
    2, 80,
    2, 82,
    2, 86,
    7, 2,
    7, 7,
    7, 33,
    7, 64,
    7, 66,
    7, 67,
    7, 68,
    7, 70,
    7, 76,
    7, 77,
    7, 78,
    7, 79,
    7, 80,
    7, 82,
    7, 86,
    8, 54,
    8, 55,
    8, 57,
    12, 2,
    12, 7,
    14, 2,
    14, 7,
    15, 15,
    33, 2,
    33, 7,
    33, 31,
    33, 35,
    33, 39,
    33, 47,
    33, 49,
    33, 52,
    33, 53,
    33, 54,
    33, 55,
    33, 57,
    33, 78,
    33, 83,
    33, 84,
    33, 85,
    33, 86,
    33, 88,
    33, 89,
    34, 52,
    34, 54,
    34, 57,
    35, 9,
    35, 52,
    35, 61,
    35, 91,
    36, 12,
    36, 14,
    36, 33,
    36, 52,
    36, 54,
    36, 56,
    36, 57,
    36, 58,
    37, 52,
    37, 66,
    37, 67,
    37, 68,
    37, 69,
    37, 70,
    37, 78,
    37, 80,
    37, 84,
    37, 85,
    37, 86,
    37, 88,
    38, 12,
    38, 14,
    38, 33,
    38, 42,
    38, 52,
    38, 64,
    38, 66,
    38, 67,
    38, 68,
    38, 70,
    38, 78,
    38, 80,
    38, 81,
    38, 84,
    38, 85,
    38, 88,
    40, 33,
    40, 52,
    40, 56,
    40, 57,
    41, 33,
    41, 52,
    41, 56,
    41, 57,
    42, 33,
    43, 13,
    43, 35,
    43, 39,
    43, 47,
    43, 49,
    43, 66,
    43, 67,
    43, 68,
    43, 70,
    43, 76,
    43, 77,
    43, 78,
    43, 79,
    43, 80,
    43, 84,
    43, 85,
    43, 86,
    43, 88,
    44, 2,
    44, 7,
    44, 33,
    44, 35,
    44, 39,
    44, 47,
    44, 49,
    44, 52,
    44, 53,
    44, 54,
    44, 55,
    44, 57,
    44, 84,
    44, 85,
    44, 86,
    44, 88,
    45, 33,
    45, 52,
    45, 56,
    45, 57,
    46, 33,
    46, 52,
    46, 56,
    46, 57,
    47, 12,
    47, 14,
    47, 33,
    47, 52,
    47, 54,
    47, 56,
    47, 57,
    47, 58,
    48, 12,
    48, 14,
    48, 33,
    48, 42,
    48, 56,
    48, 58,
    48, 64,
    48, 66,
    48, 67,
    48, 68,
    48, 70,
    48, 78,
    48, 80,
    48, 83,
    48, 85,
    48, 88,
    49, 52,
    49, 54,
    49, 55,
    49, 57,
    50, 52,
    50, 54,
    50, 57,
    52, 12,
    52, 13,
    52, 14,
    52, 33,
    52, 35,
    52, 39,
    52, 42,
    52, 47,
    52, 49,
    52, 51,
    52, 52,
    52, 54,
    52, 55,
    52, 57,
    52, 64,
    52, 66,
    52, 67,
    52, 68,
    52, 70,
    52, 76,
    52, 77,
    52, 78,
    52, 79,
    52, 80,
    52, 81,
    52, 82,
    52, 84,
    52, 85,
    52, 86,
    52, 87,
    52, 88,
    52, 89,
    53, 33,
    54, 9,
    54, 12,
    54, 13,
    54, 14,
    54, 33,
    54, 35,
    54, 39,
    54, 47,
    54, 49,
    54, 61,
    54, 64,
    54, 66,
    54, 67,
    54, 68,
    54, 70,
    54, 78,
    54, 80,
    54, 81,
    54, 84,
    54, 85,
    54, 88,
    54, 91,
    55, 9,
    55, 12,
    55, 13,
    55, 14,
    55, 33,
    55, 52,
    55, 61,
    55, 64,
    55, 66,
    55, 67,
    55, 68,
    55, 70,
    55, 78,
    55, 80,
    55, 81,
    55, 84,
    55, 91,
    56, 13,
    56, 35,
    56, 39,
    56, 47,
    56, 49,
    56, 54,
    56, 66,
    56, 67,
    56, 68,
    56, 70,
    56, 78,
    56, 80,
    56, 84,
    56, 85,
    56, 88,
    57, 6,
    57, 9,
    57, 10,
    57, 12,
    57, 13,
    57, 14,
    57, 33,
    57, 35,
    57, 39,
    57, 42,
    57, 47,
    57, 49,
    57, 51,
    57, 52,
    57, 53,
    57, 54,
    57, 55,
    57, 56,
    57, 57,
    57, 61,
    57, 64,
    57, 66,
    57, 67,
    57, 68,
    57, 69,
    57, 70,
    57, 76,
    57, 77,
    57, 78,
    57, 79,
    57, 80,
    57, 81,
    57, 82,
    57, 83,
    57, 84,
    57, 85,
    57, 87,
    57, 88,
    57, 89,
    57, 91,
    58, 33,
    58, 35,
    58, 39,
    58, 47,
    58, 49,
    58, 66,
    58, 67,
    58, 68,
    58, 70,
    58, 78,
    58, 80,
    58, 84,
    58, 85,
    58, 86,
    58, 88,
    59, 42,
    59, 53,
    64, 2,
    64, 7,
    64, 85,
    64, 88,
    65, 2,
    65, 7,
    65, 85,
    65, 87,
    65, 88,
    65, 89,
    66, 2,
    66, 7,
    68, 2,
    68, 7,
    68, 85,
    68, 88,
    69, 2,
    69, 7,
    69, 9,
    69, 61,
    69, 66,
    69, 67,
    69, 68,
    69, 70,
    69, 80,
    69, 91,
    71, 2,
    71, 7,
    74, 66,
    74, 67,
    74, 68,
    74, 70,
    74, 80,
    76, 2,
    76, 7,
    77, 2,
    77, 7,
    78, 2,
    78, 7,
    78, 85,
    78, 87,
    78, 88,
    78, 89,
    79, 2,
    79, 7,
    79, 85,
    79, 87,
    79, 88,
    79, 89,
    81, 2,
    81, 7,
    81, 12,
    81, 14,
    81, 64,
    81, 66,
    81, 67,
    81, 68,
    81, 69,
    81, 70,
    81, 78,
    81, 80,
    81, 83,
    81, 85,
    81, 86,
    81, 88,
    83, 78,
    85, 2,
    85, 7,
    85, 12,
    85, 14,
    85, 64,
    85, 66,
    85, 67,
    85, 68,
    85, 69,
    85, 70,
    85, 78,
    85, 80,
    86, 12,
    86, 14,
    87, 66,
    87, 67,
    87, 68,
    87, 70,
    87, 78,
    87, 80,
    88, 2,
    88, 7,
    88, 12,
    88, 14,
    88, 64,
    88, 66,
    88, 67,
    88, 68,
    88, 69,
    88, 70,
    88, 78,
    88, 80,
    89, 66,
    89, 67,
    89, 68,
    89, 70,
    89, 78,
    89, 80,
    90, 42,
    90, 53
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -15, -15, -17, -7, -8, -8, -8, -8,
    -3, -3, -9, -3, -8, -11, 2, -15,
    -15, -17, -7, -8, -8, -8, -8, -3,
    -3, -9, -3, -8, -11, 2, 3, 3,
    3, -24, -24, -24, -24, -31, -17, -17,
    -9, -2, -2, -2, -2, -18, -2, -12,
    -10, -13, -2, -2, -2, -7, -5, -7,
    2, -4, -3, -8, -4, -4, -2, -2,
    -14, -14, -3, -4, -3, -3, -6, -3,
    3, -3, -3, -3, -3, -3, -3, -3,
    -2, -4, -3, -4, -33, -33, -24, -37,
    3, -5, -3, -3, -3, -3, -3, -3,
    -4, -3, -3, -3, 3, -4, 2, -4,
    3, -4, 2, -4, -3, -9, -4, -4,
    -4, -4, -4, -4, -4, -4, -3, -3,
    -4, -3, -4, -3, -6, -9, -6, -47,
    -47, 3, -9, -9, -9, -9, -39, -8,
    -25, -20, -34, -6, -19, -13, -19, 3,
    -4, 2, -4, 3, -4, 2, -4, -14,
    -14, -3, -4, -3, -3, -6, -3, -46,
    -46, -19, -28, -4, -4, -2, -2, -2,
    -2, -2, -2, -2, 2, 2, 2, -6,
    -4, -3, -5, -11, -3, -7, -31, -33,
    -31, -11, -4, -4, -34, -4, -4, -2,
    2, 2, 2, 2, -16, -14, -14, -14,
    -14, -15, -15, -14, -15, -14, -11, -16,
    -13, -10, -8, -11, -10, -8, -3, 3,
    -32, -5, -32, -11, -2, -2, -2, -2,
    2, -6, -6, -6, -6, -6, -6, -6,
    -4, -4, -2, -2, 3, 2, -17, -8,
    -17, -6, 2, 2, -5, -4, -4, -4,
    -4, -4, -4, -3, -3, 2, -6, -4,
    -4, -4, -4, 2, -4, -4, -4, -4,
    -3, -4, -3, -4, -4, -4, 3, -7,
    -30, -7, -30, -13, -4, -4, -13, -4,
    -4, -2, 2, -13, 3, 2, 2, 3,
    3, -10, -9, -9, -9, -3, -9, -6,
    -6, -9, -6, -9, -6, -8, -3, -5,
    -3, -3, -3, -4, 3, 2, -4, -4,
    -4, -4, -3, -3, -3, -3, -3, -3,
    -3, -4, -4, -4, -3, -3, -9, -9,
    -2, -2, -4, -4, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, 2, 2,
    3, 3, -3, -3, -3, -3, -3, 3,
    -15, -15, -3, -3, -3, -3, -3, -15,
    -15, -15, -15, -19, -19, -2, -3, -2,
    -2, -4, -4, -2, -2, -2, -2, 2,
    2, -17, -17, -6, -3, -3, -3, 2,
    -3, -3, -3, 7, 3, 2, 3, -3,
    2, 2, -15, -15, -2, -2, -2, -2,
    2, -2, -2, -2, -17, -17, -3, -3,
    -3, -3, -3, -3, 2, 2, -15, -15,
    -2, -2, -2, -2, 2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -3, -3
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 432,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t roboto_condensed_regular_18 = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};

#endif /*#if ROBOTO_CONDENSED_REGULAR_18*/

