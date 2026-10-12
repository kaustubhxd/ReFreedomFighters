"""specs_s6354.py - unclaimed-63 core residue 2, batch 54: 0x5a8360 (ZOnScreenDisplay::GetSpriteInfo; thiscall, one stack argument s,
ret 4, returns this + 12 * (n + 2)). No stubs of the function's own; the import 0x67625c (strstr, cdecl) is a fake: it searches the global
string at 0x6ed270 for s (a heap string of letters and ';' characters), returns the match or 0.
The needle is a substring of the haystack in about two thirds of the cases (so the ';' count is non-trivial), otherwise random (0)."""
from pilot import S


def _gen_8360(c):
    e = c.emu
    hay = bytes(c.rng.choice(b'ab;c;d') for _ in range(c.rng.randint(0, 40)))
    hs = e.alloc(len(hay) + 4, 4)
    e.wbytes(hs, hay + b'\x00')
    e.w32(0x6ed270, hs)

    def strstr(em, a):
        p, s = em.arg32(0), em.arg32(1)
        hb = bytes(em.rbytes(p, 0x100)).split(b'\x00')[0]
        sb = bytes(em.rbytes(s, 0x100)).split(b'\x00')[0]
        i = hb.find(sb)
        em.calllog.append(('strstr', None, None, (p, s)))
        em.ret(eax=(p + i) if i >= 0 else 0, argbytes=0)
    e.w32(0x67625c, e.stub_fn('strstr 0x67625c', strstr))
    if hay and c.rng.random() < 2 / 3:
        a = c.rng.randrange(0, len(hay))
        b = c.rng.randrange(a, len(hay) + 1)
        needle = hay[a:b]
    else:
        needle = bytes(c.rng.choice(b'xyz') for _ in range(c.rng.randint(1, 3)))
    ns = e.alloc(len(needle) + 4, 4)
    e.wbytes(ns, needle + b'\x00')
    this = e.alloc(0x100, 4)
    e.wbytes(this, bytes(0x100))
    e.mu.ctl_flush_tb()
    return [this, ns]


S(0x5a8360, 'ZOnScreenDisplay::GetSpriteInfo thiscall', 'thiscall', None, ret='eax', gen=_gen_8360,
  note='unclaimed-63 core residue 2 batch 54; strstr import stubbed')
