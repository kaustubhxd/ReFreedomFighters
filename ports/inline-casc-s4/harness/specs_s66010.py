"""specs_s66010.py - cascade s4 batch 66010: 0x427150 (map an address through a chunk table read with fseek / fread)."""
from pilot import S
from recruits_util import clear_hooks


def _g427150(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = r.choice([0, 0x10, 0x100])
    n = r.choice([0, 1, 2, 3, 5])
    img = bytearray(0x400)

    def put(o, v):
        img[o:o + 4] = (v & 0xffffffff).to_bytes(4, 'little')
    recs = []
    for i in range(n):
        o = base + 0x28 * i
        a = r.choice([0, 0x1000, 0x2000, 0x8000, r.getrandbits(16) << 4])
        b = r.choice([0, 0x10, 0x800, 0x1000])
        put(o, 0 if (i == n - 1 and r.random() < 0.5) else r.getrandbits(32) | 1)
        put(o + 0xc, a)
        put(o + 0x10, b)
        put(o + 0x14, r.getrandbits(32))
        recs.append((a, b))
    if r.random() < 0.15:
        put(base, 0)
    pos = [0]

    def fseek(em, rr):
        f, off, org = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('fseek', f, off, org))
        pos[0] = off
        em.ret(eax=0, argbytes=0)

    def fread(em, rr):
        buf, sz, cnt, f = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        o = pos[0]
        data = bytes(img[o:o + 4]) if 0 <= o < len(img) - 3 else bytes(4)
        pos[0] += 4
        em.calllog.append(('fread', sz, cnt, f, data))
        em.wbytes(buf, data)
        em.ret(eax=1, argbytes=0)
    e.stub_import('fseek', fseek)
    e.stub_import('fread', fread)
    if recs and r.random() < 0.7:
        a, b = r.choice(recs)
        addr = (a + r.choice([0, 0, 1, max(b - 1, 0), b, 5])) & 0xffffffff
    else:
        addr = r.getrandbits(32)
    return [r.getrandbits(32), base, addr]


S(0x427150, 'GUESS map an address through a chunk table in a file', 'stdcall', None, ret='eax', gen=_g427150, note='batch66010')
