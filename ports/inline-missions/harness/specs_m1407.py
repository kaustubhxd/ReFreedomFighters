"""specs_m1407.py - batch 1407: ZFFLevelController::SceneChange."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, stub, obj, hook_stub  # noqa: E402
from specs_m1401 import lctrl  # noqa: E402

# cdecl memset(dst, val, n): push edi; mov edi,[esp+8]; mov eax,[esp+12]; mov ecx,[esp+16]; rep stosb;
# mov eax,[esp+8]; pop edi; ret
MEMSET = bytes.fromhex('57 8b7c2408 8b44240c 8b4c2410 f3aa 8b442408 5f c3'.replace(' ', ''))

NEXT = ['MENU', 'KH04', 'KH02', 'K', 'MC01', 'RC02', 'C02A', 'C02R', 'C05B', 'x', '', 'MENUX', 'KH0']


def memset_stub(c):
    a = c.emu.alloc(32, 16)
    c.emu.wbytes(a, MEMSET)
    c.emu.w32(0x676260, a)


def g_scene(c):
    lc, p = lctrl(c)
    c.emu.wbytes(lc + 0x51, (c.rng.choice(NEXT) + '\0' * 8).encode())   # longer garbage would overflow the 0x100 path buffer
    if c.rng.random() < 0.3:
        c.emu.wbytes(lc + 0x48, b'C08R\0')
    c.emu.w8(lc + 0x1040, c.rng.choice([0, 0, 1]))
    memset_stub(c)
    disp = obj(c, 0x10, {0x60: stub(c, 2, this=True, rets=[c.rng.choice([0, 1, 0x100]), c.rng.choice([0, 1])]),
                         0x64: stub(c, 2, this=True)})
    mgr = obj(c, 0x40, {0xa4: stub(c, 0, this=True), 0xa0: stub(c, 1, this=True, skip=(0,), copy=(0, 0x100, None)),
                        0xb4: stub(c, 1, this=True)})
    sysi = obj(c, 0x100, {0xbc: stub(c, 0, this=True, ret=disp), 0xc: stub(c, 4, this=True)})
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(0x70039c, sysi)
    hook_stub(c, 0x5b02f0, 0, this=True)
    hook_stub(c, 0x5ae680, 0, this=True, ret=1)
    return [lc]


S(0x59c620, 'ZFFLevelController::SceneChange', 'thiscall', ret=None, gen=g_scene)
