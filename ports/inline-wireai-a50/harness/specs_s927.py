"""specs_s927.py - batch 927: 0x62add0 (cdecl: object, s, end, out; returns s32). The object's class table at +0x4c (drawn class bytes, including
values past the map), and the three handler pointers at +0x164, +0x168, +0x16c (stood in: cdecl, two words, log, return a drawn int). The input
is a short byte string of '-', '>', and other characters with a random length; the output pointer is a heap dword. Every branch (no dash, dash
at end, the class cases, '->', short input) is reached by the drawn data."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    obj = rnd(c, 0x200)
    classes = [0, 1, 2, 3, 5, 6, 7, 8, 9, 27, 28, 40, 255]
    tab = bytearray(r.choice(classes) for _ in range(256))
    if r.random() < 0.7:
        tab[ord('-')] = 27                 # the dash takes the class that reaches the '->' test
    tab[ord('>')] = r.choice([0, 1, 27])
    tab = bytes(tab)
    e.wbytes(obj + 0x4c, tab)
    rets = {}

    def mk(name):
        def h(e, rr):
            obj_p, sp = e.arg32(0), e.arg32(1)
            e.calllog.append(('h.' + name, e.r8(sp), e.r8(sp + 1)))
            e.ret(eax=rets[name], argbytes=0)
        return h

    names = ['164', '168', '16c']
    for n in names:
        rets[n] = r.choice([0, 0, 1])
        e.w32(obj + int('0x' + n, 16), e.stub_fn('h' + n, mk(n)))
    chars = b'-->-a-bx-' if r.random() < 0.8 else b'-a-\x00x-'
    n = r.randint(0, 12)
    buf = rnd(c, 16)
    e.wbytes(buf, bytes(r.choice(chars) for _ in range(16)))
    start = buf + r.choice([0, 0, 1])
    end = start + n
    out = rnd(c, 4)
    return [obj, start, end, out]


S(0x62add0, 'scan62add0 (no name in map; cdecl)', 'cdecl', None, ret='eax', gen=_gen, note='area50 batch927 (option scanner)')
