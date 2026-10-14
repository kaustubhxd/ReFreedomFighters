"""specs_s34126.py - 0x561180: this byte +0x87 in two thirds, s a short string in a roomy buffer, the name object [[[0x70039c]+0x9b]+0xae4] slot 0 returns a short string.
0x57f130: embedded list at +0x23c with slots 0x14 (count 0..3, constant) and 0x30; engine object [0x70038c] slot 0xcc returns an object or null; hooked 0x57d500 (writes nothing) and 0x57ee90.
0x59dae0: a null in a fifth; hooked 0x5eade0 (ecx = local block recorded as a marker), 0x5a2460 (low byte random), 0x5a2bd0; count at the unaligned +0x7ce 0..3."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g561180(c):
    clear_hooks(c)
    r = c.rng
    t = rnd(c, 0x20)
    c.emu.wbytes(t, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 3, 8]))) + b'\0')
    nameobj = obj(c, 0x20, {0: pystub(c, 2, ret=t, this=True)}, nslots=1)
    tbl = rnd(c, 0xaf0)
    c.emu.w32(tbl + 0xae4, nameobj)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    me = rnd(c, 0x90)
    c.emu.wbytes(me + 0x87, bytes([r.choice([0, 1, 1])]))
    s = rnd(c, 0x40)
    c.emu.wbytes(s, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 4, 9]))) + b'\0')
    return [me, s]


def _g57f130(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3])
    objs = [rnd(c, 0xe8) for _ in range(n)]
    hook_rec(c, 0x57d500, 2, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    hook_rec(c, 0x57ee90, 0, this=True, pop=0, ret=r.getrandbits(32))
    items = [r.getrandbits(32) for _ in range(n)]
    pick = {it: (objs[i] if r.random() < 0.7 else 0) for i, it in enumerate(items)}
    eng = obj(c, 0x20, {0xcc: pystub(c, 1, ret=lambda em, k: pick[items[k]] if k < len(items) else 0, this=True)}, nslots=0xd0 // 4)
    c.emu.w32(0x70038c, eng)
    me = rnd(c, 0x250)
    lst_vt = c.emu.alloc(0x40, 4)
    c.emu.w32(lst_vt + 0x14, pystub(c, 0, ret=n, this=True))
    c.emu.w32(lst_vt + 0x30, pystub(c, 1, ret=lambda em, k: items[k] if k < len(items) else 0, this=True))
    c.emu.w32(me + 0x23c, lst_vt)
    return [me, r.choice([0, 1, 0x100, 0x101])]


def _g59dae0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5eade0, 5, this='mark', ret=r.getrandbits(32))
    hook_rec(c, 0x5a2460, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]), stackmark=(0,))
    hook_rec(c, 0x5a2bd0, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x7f0)
    c.emu.wbytes(me + 0x7ce, r.choice([0, 1, 2, 3]).to_bytes(4, 'little'))
    a = 0 if r.random() < 0.2 else r.getrandbits(32) | 1
    return [me, a, r.getrandbits(32), r.getrandbits(32), r.choice([0, 1, 0x100, 0x101]), r.getrandbits(32)]


S(0x561180, 'GUESS append suffix and name', 'thiscall', None, ret=None, gen=_g561180, note='batch34126')
S(0x57f130, 'GUESS refresh every listed object', 'thiscall', None, ret=None, gen=_g57f130, note='batch34126')
S(0x59dae0, 'GUESS resolve a request and record it', 'thiscall', None, ret='al', gen=_g59dae0, note='batch34126')
