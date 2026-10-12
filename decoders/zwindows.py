#!/usr/bin/env python3
"""Freedom Fighters front-end layout (ZWINDOWS in FF-StartUp.GMS).

usage: python3 -I zwindows.py FF-StartUp.GMS [--prm FF-StartUp.PRM] [--menu NAME]

Prints every text item of the menu windows: window, item, screen position (640x480, from the GMS hierarchy),
text (a LOC key, or literal text when it starts with '%'), font object and RGB colour. With --prm also prints the
sprite list of each BackGroundPictures entry (count, tile size classes, material groups).

How it reads the data (all checked on FF-StartUp):
* positions: gms_world.load_scene, summed parent-relative positions (ZWINDOWS root at 0,0).
* properties: the geom's data block (record +0x20, pathfind.parse_dblk). For a text (class 0x20002d) the first
  string item is the text, the first tag-0x88 ref is the font geom (1-based geom index, low 24 bits) and the three
  doubles are R, G, B (0..255).
* fonts (class 0x20003a): the string item is the TTF path inside FF-StartUp.ZGF; the TEX holds one atlas per font
  object in the same order (GFB 14, GFBEI 22, GFB 12, GFXC 14, GFSU 16).
* pictures (class 0x200046): the last int item is a PRM offset: u32 n, then n x 40-byte sprites
  (centre x, centre y [y up, origin at screen centre], z, u0, u1, v1, v0, width-1, height-1, u32 colour). Just
  before it: k x 32-byte material records (u32 0x00020100, u32 id, ...) preceded by k x (u32 count, u32 first
  sprite) groups; sprites of a group share one material.
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gms_world  # noqa: E402
import pathfind  # noqa: E402

TEXT, PICTURE, FONT = 0x20002D, 0x200046, 0x20003A


def items(scene, body, i):
    off = struct.unpack_from('<I', body, scene.geoms[i]['rec'] + 0x20)[0]
    d = pathfind.parse_dblk(body, off)
    return d['items'] if isinstance(d, dict) else d


def screen_pos(scene, i):
    x = y = 0.0
    while i is not None and i >= 0:
        p = scene.geoms[i]['pos']
        x += p[0]
        y += p[1]
        i = scene.geoms[i]['parent']
    return x, y


def window_of(scene, i):
    path = []
    while i is not None and i >= 0:
        path.append(scene.geoms[i]['name'])
        i = scene.geoms[i]['parent']
    path.reverse()
    return path[1] if len(path) > 1 else path[0]


def sprite_list(prm, off):
    n = struct.unpack_from('<I', prm, off)[0]
    sprites = [struct.unpack_from('<9fI', prm, off + 4 + 40 * k) for k in range(n)]
    k_max = 0
    while struct.unpack_from('<I', prm, off - 32 * (k_max + 1))[0] == 0x00020100:
        k_max += 1
    groups = None
    for k in range(1, k_max + 1):
        m = off - 32 * k
        g = [struct.unpack_from('<2I', prm, m - 8 * k + 8 * i) for i in range(k)]
        if sum(c for c, _ in g) == n and g[0][1] == 0 and all(g[i][1] + g[i][0] == g[i + 1][1] for i in range(k - 1)):
            groups = g
            break
    return sprites, groups


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    scene = gms_world.load_scene(argv[1])
    body = gms_world.load_gms(argv[1])
    only = argv[argv.index('--menu') + 1] if '--menu' in argv else None
    for i, g in enumerate(scene.geoms):
        if g['cls'] != TEXT:
            continue
        win = window_of(scene, i)
        if only and win != only:
            continue
        its = items(scene, body, i)
        text = next((it['value'] for it in its if it['type'] in (4, 5)), None)
        refs = [it['value'] & 0xFFFFFF for it in its if it['type'] == 8 and it['tag'] == 0x88]
        font = scene.geoms[refs[0] - 1]['name'] if refs and refs[0] else '-'
        rgb = [int(it['value']) for it in its if it['type'] == 1][:3]
        x, y = screen_pos(scene, i)
        print('%-24s %-14s %-12s (%5.0f,%5.0f) %-12s %-15s %s' % (
            win, scene.geoms[g['parent']]['name'], g['name'], x, y, font, rgb, text))
    if '--prm' in argv:
        prm = open(argv[argv.index('--prm') + 1], 'rb').read()
        for i, g in enumerate(scene.geoms):
            if g['cls'] != PICTURE:
                continue
            ints = [it['value'] for it in items(scene, body, i) if it['type'] == 3]
            off = ints[-1] if ints else 0
            if not 0 < off < len(prm):
                continue
            sprites, groups = sprite_list(prm, off)
            sizes = {}
            for s in sprites:
                key = '%dx%d' % (s[7] + 1, s[8] + 1)
                sizes[key] = sizes.get(key, 0) + 1
            print('picture %-28s PRM 0x%06x: %3d sprites, %s groups, sizes %s' % (
                window_of(scene, i) + '/' + g['name'], off, len(sprites), len(groups) if groups else '?', sizes))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
