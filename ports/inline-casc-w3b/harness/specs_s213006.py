"""specs_s213006.py - batch 213006: class-table scanner twin and a selector-to-vtable dispatcher, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g625b30(c):
    clear_hooks(c)
    r = c.rng
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1d, 8, 0x14, 7, 8]
    tab = bytearray((r.choice(hot) if r.random() < 0.7 else r.getrandbits(8)) for _ in range(256))
    tab[0xaa] = 0x30
    c.emu.wbytes(base + 0x4c, bytes(tab))
    n = 0x200
    buf = bytearray(r.getrandbits(8) for _ in range(n))
    for i in range(0, n - 8):
        x = r.random()
        if x < 0.25:
            buf[i + 1] = 0
        elif x < 0.5:
            buf[i + 1] = r.randint(0xd8, 0xff)
        elif x < 0.6:
            buf[i + 1] = 0xff
            buf[i] = r.choice([0xfc, 0xfd, 0xfe, 0xff])
    for i in range(n - 8, n, 2):
        buf[i] = 0xaa
        buf[i + 1] = 0
    p = rnd(c, n + 8)
    c.emu.wbytes(p, bytes(buf))
    return [base, p]


def g469590(c):
    clear_hooks(c)
    r = c.rng
    slots = {}
    for off, na in ((8, 0), (0xc, 0), (0x38, 0), (0x3c, 0), (0x40, 1), (0x44, 2), (0x4c, 0)):
        slots[off] = pystub(c, na, ret=r.getrandbits(32), this=True)
    o = obj(c, 0x20, slots, nslots=0x20)
    sel = r.choice([1, 2, 3, 4, 8, 16, 32, 64, 65, r.randint(0, 0x45), r.randint(0, 0x45), r.getrandbits(32)])
    return [o, sel, r.getrandbits(32), r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x625b30, 'scan_class_run_c', 'cdecl', None, ret='eax', gen=g625b30)
S(0x469590, 'sel_to_vslot', 'thiscall', None, ret='eax', gen=g469590)
