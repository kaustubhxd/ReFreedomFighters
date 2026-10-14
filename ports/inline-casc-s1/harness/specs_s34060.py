"""specs_s34060.py - cascade tier E, batch 34060.
0x518110: byte +0x133 zero in half the cases; the engine time dword at +0x40 and the dword at +0x35c are chosen around each other (equal, below, above); this slot 0x80 (two heap pointer args) is a recorder and slot 0x36c a custom stub that logs ECX and only the low byte of its argument (the original pushes EBX, whose upper bits are the caller's leftovers); dword +0x1650 is 1 in a third.
0x52b430: s slots 0x48 (writes n 0..4 into the first pointer, random dwords into the others) and 0x18 (pointer, size: fills the buffer with random bytes) are recorders with side effects; [this] points at an
0x100-byte random block.
0x54eca0: [this+4] is null in a seventh, else an object whose vtable slot 0x10 is a seven-argument stdcall recorder (ECX is not compared) returning a random HRESULT (negative in half the cases); the logger object at
0x700390 is set; the block at +8..+0x4c starts random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g518110(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    t = r.choice([0, 5, 0x400, 0x7fffffff, 0x80000000, r.getrandbits(32)])
    c.emu.w32(so + 0x40, t)
    def s36c(em, res_):   # the original pushes EBX, so only the low byte of the argument is meaningful: log just that
        em.calllog.append(('slot36c', em.reg('ecx'), em.arg32(0) & 0xff))
        em.ret(eax=0, argbytes=4)
    me = obj(c, 0x1660, {0x80: pystub(c, 2, this=True), 0x36c: c.emu.stub_fn('slot 0x36c', s36c)}, nslots=0x370 // 4)
    c.emu.wbytes(me + 0x133, bytes([0 if r.random() < 0.5 else r.randrange(1, 256)]))
    p = r.choice([t, (t - 1) & 0xffffffff, (t + 1) & 0xffffffff, r.getrandbits(32)])
    c.emu.w32(me + 0x35c, p)
    c.emu.w32(me + 0x1650, 1 if r.random() < 1 / 3 else r.getrandbits(32))
    return [me]


def _g52b430(c):
    clear_hooks(c)
    r = c.rng
    cnt = {'n': r.choice([0, 1, 2, 3, 4, -1])}

    def rd(em, k):
        em.w32(em.arg32(0), (cnt['n'] & 0xffffffff) if k == 0 else r.getrandbits(32))

    def fill(em, k):
        p, n = em.arg32(0), em.arg32(1)
        em.wbytes(p, bytes(r.getrandbits(8) for _ in range(min(n, 0x100))))
    s = obj(c, 0x20, {0x48: pystub(c, 1, this=True, side=rd), 0x18: pystub(c, 2, this=True, side=fill)}, nslots=0x4c // 4)
    me = rnd(c, 0x20)
    c.emu.w32(me, rnd(c, 0x100))
    return [me, s]


def _g54eca0(c):
    clear_hooks(c)
    r = c.rng
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x30 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, lg)
    hr = r.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32) | 0x80000000, r.getrandbits(31)])   # includes the 0 / sign boundary
    dev = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x10: pystub(c, 7, ret=hr)}, nslots=0x14 // 4)
    me = rnd(c, 0x60)
    c.emu.w32(me + 4, dev)
    return [me]


S(0x518110, 'GUESS time-gated update or two-way slot sequence', 'thiscall', None, ret=None, gen=_g518110, note='batch34060')
S(0x52b430, 'GUESS read a counted array from a stream and clear its fields', 'thiscall', None, ret='al', gen=_g52b430, note='batch34060')
S(0x54eca0, 'GUESS reset block to defaults and query the COM-style device', 'thiscall', None, ret=None, gen=_g54eca0, note='batch34060')
