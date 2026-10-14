"""specs_s34033.py - cascade tier E, batch 34033.
0x63d7d0: [a+0x54] is a list object (never null) whose record [s+0xc] carries the dword 0x100000 flag at +0x23 in half the cases (the assert hook is set otherwise); node chain of 0..3 nodes written
through slot 0x50 of s (stack pointer argument); this slot 0x50 is a recorder.
0x6485c0: current chunk null / full (0x3fc) / partially filled; [this+4] slot 8 returns a fresh chunk or 0 (a fifth); p points to a random dword.
0x4288f0: the three counts are within their array bounds (0..2, 0..3, 0..16: the first two arrays are short because the counts at +0xc and +0x1c sit inside the pointer ranges) with the extremes covered; every element is an object with a slot 0x28 / 0x50 recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g63d7d0(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    n = r.choice([0, 1, 2, 3])
    nodes = [(r.getrandbits(32) | 0x10000000) for _ in range(n)]
    seq = nodes + [0]

    def nxt(em, k):
        em.w32(em.arg32(0), seq[k + 1] if k + 1 < len(seq) else 0)
    rec = rnd(c, 0x40)
    w = r.getrandbits(32)
    w = (w | 0x100000) if r.random() < 0.5 else (w & ~0x100000)
    c.emu.wbytes(rec + 0x23, w.to_bytes(4, 'little'))
    s = obj(c, 0x40, {0x50: pystub(c, 1, this=True, side=nxt, stackmark=(0,))}, nslots=0x60 // 4)
    c.emu.w32(s + 0xc, rec)
    c.emu.w32(s + 8, seq[0])
    a = rnd(c, 0x60)
    c.emu.w32(a + 0x54, s)
    me = obj(c, 0x40, {0x50: pystub(c, 1, this=True)}, nslots=0x60 // 4)
    return [me, a]


def _g6485c0(c):
    clear_hooks(c)
    r = c.rng
    nb = 0 if r.random() < 0.2 else rnd(c, 0x40)
    src = obj(c, 0x20, {8: pystub(c, 0, ret=nb, this=True)}, nslots=4)
    me = rnd(c, 0x40)
    c.emu.w32(me + 4, src)
    k = r.random()
    if k < 0.33:
        cur = 0
    else:
        cur = rnd(c, 0x60)
        c.emu.w32(cur, 0x3fc if k < 0.66 else r.randint(0, 6))
    c.emu.w32(me + 0x10, cur)
    return [me, rnd(c, 0x10)]


def _g4288f0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x70)
    st28 = pystub(c, 0, this=True)
    st50 = pystub(c, 0, this=True)
    mk = lambda slot, st: obj(c, 0x20, {slot: st}, nslots=0x60 // 4)
    counts = [r.choice([0, 1, 2, r.randint(0, 2)]), r.choice([0, 1, 3, r.randint(0, 3)]), r.choice([0, 1, 5, 16, r.randint(0, 16)])]
    for i in range(2):
        c.emu.w32(me + 4 + 4 * i, mk(0x28, st28))
    for i in range(3):
        c.emu.w32(me + 0x10 + 4 * i, mk(0x28, st28))
    for i in range(16):
        c.emu.w32(me + 0x20 + 4 * i, mk(0x50, st50))
    c.emu.w32(me + 0xc, counts[0])
    c.emu.w32(me + 0x1c, counts[1])
    c.emu.w32(me + 0x60, counts[2])
    return [me]


S(0x63d7d0, 'GUESS feed every node of a list to this', 'thiscall', None, ret=None, gen=_g63d7d0, note='batch34033')
S(0x6485c0, 'GUESS append dword to chunked list', 'thiscall', None, ret='al', gen=_g6485c0, note='batch34033')
S(0x4288f0, 'GUESS tick three object arrays', 'thiscall', None, ret=None, gen=_g4288f0, note='batch34033')
